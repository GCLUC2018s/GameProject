#include "CModelX.h"
#include "windows.h"
#include "CFPS.h"
#include "CCollision.h"

CFrameBone::CFrameBone(CFrameBone &f, CFrameBone *parent, CFrameBone *prev){
	SetNo(f.GetNo());
	SetMatrix(f.GetMatrix());
	SetType(f.GetType());
	copyToken(f.GetToken());
	copyName(f.GetName());
	pMesh = f.pMesh;
	matrixOffset = f.matrixOffset;
	pParent = parent;
	pPrev = prev;
	if (f.pChild) {
		pChild = new CFrameBone(*static_cast<CFrameBone*>(f.pChild), this,nullptr);
	}
	if (f.pNext) {
		pNext = new CFrameBone(*static_cast<CFrameBone*>(f.pNext), parent,this);
	}
	
}
void CFrameBone::calcBoneMatrix(CMatrix *out){
	boneMatrix = sMatrix * matrixOffset;

	out[GetNo()] = boneMatrix;
}
void CFrameBone::calcMatrix(CMatrix *revMatrix){
	if (GetParent()) sMatrix = ((CFrameBone*)GetParent())->GetSMatrix() * GetMatrix()*revMatrix[no];
	else sMatrix = GetMatrix()*revMatrix[no];

	if(GetChild()) ((CFrameBone*)GetChild())->calcMatrix(revMatrix);
	if (GetNext()) ((CFrameBone*)GetNext())->calcMatrix(revMatrix);
	
}
CMaterialX::CMaterialX( CXMaterial &m,char *path){

	memcpy(m_ambient.v, &m.faceColor, sizeof(float) * 4);
	memcpy(m_diffuse.v, &m.faceColor, sizeof(float) * 4);

	m_shininess = m.power;
	memcpy(m_emissive.v, &m.emissiveColor, sizeof(float) * 3);
	memcpy(m_specular.v, &m.specularColor, sizeof(float) * 3);

	if(strlen(m.filename)) {
		m_pTex = new CTexture();
		char str[256];
		strcpy_s(str, 256, path);
		strcat_s(str, 256, m.filename);

		if (!m_pTex->Load(m.filename)) {
			delete m_pTex;
			m_pTex = NULL;
		}
	} else {
		m_pTex = NULL;
	}
}
CSkinWeights::CSkinWeights(CXModelLoader &loader, CXMesh &mesh){
	weight = new SSkinWeight[mesh.nVertices];
	memset(weight,0,sizeof(SSkinWeight)*mesh.nVertices);
	std::vector<CXSkinWeights*> *skin = &mesh.skinweights;
	std::vector<CXSkinWeights*>::iterator it = skin->begin();
	while(it!=skin->end()) {
		CXSkinWeights* s = *it;
		int bonenum = loader.GetFrameNum(s->transformNodeName);
		for(int i=0;i<s->nWeights;i++) {
			int j;
			for(j=0;j<4;j++) {
				if(weight[s->vertexIndices[i]].weight.f[j] == 0.0f) break;
			}
			if (j <= 3) {
				weight[s->vertexIndices[i]].bone.f[j] = (float)bonenum;
				weight[s->vertexIndices[i]].weight.f[j] = s->weights[i];
			}

		}
		it++;

	}

}
CSkinWeights::~CSkinWeights() {
	SAFE_DELETE_ARRAY(weight);
}
CPoly::CPoly( CXModelLoader &loader,  CXMesh &mesh,CSkinWeights *skinWeights,int matNo){
	m_pVertex = NULL;

	
	material = loader.GetMaterialNum(mesh.meshMaterialList->material[matNo]);
	faceCnt = 0;
	for(int i=0;i<mesh.meshMaterialList->nFaceIndexes;i++) {
		if(mesh.meshMaterialList->faceIndexes[i]==matNo) faceCnt++;
	}
	vertexCnt = faceCnt*3;
	
	bNormal = (mesh.meshNormal) ? true : false;

	
	bTexCode = (mesh.meshTextureCoords) ? true:false;

	bWeight = (skinWeights) ? true:false;

	m_pVertex = new MY_VERTEX[vertexCnt];
	for(int i=0,j=0;i<mesh.meshMaterialList->nFaceIndexes;i++) {
		if(mesh.meshMaterialList->faceIndexes[i]==matNo) {
			for(int k=0;k<3;k++,j++) {
				m_pVertex[j].vPos.x = mesh.vertices[mesh.faces[i].idx[k]].x;
				m_pVertex[j].vPos.y = mesh.vertices[mesh.faces[i].idx[k]].y;
				m_pVertex[j].vPos.z = mesh.vertices[mesh.faces[i].idx[k]].z;
				if(bNormal) {
					m_pVertex[j].vNorm.x = mesh.meshNormal->normals[mesh.meshNormal->faceNormals[i].idx[k]].x;
					m_pVertex[j].vNorm.y = mesh.meshNormal->normals[mesh.meshNormal->faceNormals[i].idx[k]].y;
					m_pVertex[j].vNorm.z = mesh.meshNormal->normals[mesh.meshNormal->faceNormals[i].idx[k]].z;
				}
				if(bTexCode) {
					m_pVertex[j].vTex.x = mesh.meshTextureCoords->textureCoords[mesh.faces[i].idx[k]].u;
					m_pVertex[j].vTex.y = mesh.meshTextureCoords->textureCoords[mesh.faces[i].idx[k]].v;
				}
				if(bWeight) {
					memcpy(m_pVertex[j].bBoneIndex,&skinWeights->weight[mesh.faces[i].idx[k]].bone,sizeof(float)*4);
					memcpy(m_pVertex[j].bBoneWeight,&skinWeights->weight[mesh.faces[i].idx[k]].weight,sizeof(float)*4);
				}
			}
		}
	}
//	printWeight();
	glGenBuffers(1,&buffer);
	glBindBuffer(GL_ARRAY_BUFFER,buffer);
	glBufferData(GL_ARRAY_BUFFER,sizeof(MY_VERTEX)*vertexCnt,m_pVertex,GL_STATIC_DRAW);
	delete[] m_pVertex;
	m_pVertex = NULL;
	glBindBuffer(GL_ARRAY_BUFFER,0);


	
}
CPoly::~CPoly() {
	glDeleteBuffers(1,&buffer);
	SAFE_DELETE_ARRAY(m_pVertex);

}
void CPoly::draw(CShader *shader) {
	int offSet = 0;
	glBindBuffer(GL_ARRAY_BUFFER,buffer);
	GLint vertLoc = glGetAttribLocation(shader->GetProgram(), "Vertex");
	glVertexAttribPointer(vertLoc, 3, GL_FLOAT, GL_FALSE, sizeof(MY_VERTEX), (const void*)offSet);
	glEnableVertexAttribArray(vertLoc);
	offSet += sizeof(SVector3D);


	GLint normalLoc = glGetAttribLocation(shader->GetProgram(), "Normal");
	if (normalLoc>=0) {
		glVertexAttribPointer(normalLoc, 3, GL_FLOAT, GL_FALSE, sizeof(MY_VERTEX), (const void*)offSet);
		glEnableVertexAttribArray(normalLoc);
	}
	offSet += sizeof(SVector3D);

	GLint texLoc = glGetAttribLocation(shader->GetProgram(), "TexCoord");
	if (texLoc >= 0) {
		glVertexAttribPointer(texLoc, 2, GL_FLOAT, GL_FALSE, sizeof(MY_VERTEX), (const void*)offSet);
		glEnableVertexAttribArray(texLoc);
	}
	offSet += sizeof(SVector2D);

	GLint weightLoc = glGetAttribLocation(shader->GetProgram(), "weights");
	if (weightLoc >= 0) {
		glEnableVertexAttribArray(weightLoc);
		glVertexAttribPointer(weightLoc, 4, GL_FLOAT, GL_TRUE, sizeof(MY_VERTEX), (void*)offSet);
	}
	offSet += sizeof(float) * 4;
	GLint indexLoc = glGetAttribLocation(shader->GetProgram(), "indices");
	if (indexLoc>=0) {
		glEnableVertexAttribArray(indexLoc);
		glVertexAttribPointer(indexLoc, 4, GL_FLOAT, GL_FALSE, sizeof(MY_VERTEX), (void*)offSet);
	}

	glDrawArrays(GL_TRIANGLES,0,vertexCnt);
	if (vertLoc >= 0) glDisableVertexAttribArray(vertLoc);
	if (normalLoc >= 0) glDisableVertexAttribArray(normalLoc);
	if (texLoc >= 0) glDisableVertexAttribArray(texLoc);

	if (indexLoc >= 0) glDisableVertexAttribArray(indexLoc);
	if (weightLoc >= 0) glDisableVertexAttribArray(weightLoc);

	glBindBuffer(GL_ARRAY_BUFFER, 0);
}

bool CPoly::CollisionRay(CVector3D *c, CVector3D *n, const CVector3D &s, const CVector3D &e, float *pLength){
	glBindBuffer(GL_ARRAY_BUFFER, buffer);
	MY_VERTEX *v = (MY_VERTEX*)glMapBuffer(GL_ARRAY_BUFFER, GL_READ_ONLY);
	bool hit = false;
	for (int i = 0; i < vertexCnt; i+=3,v+=3) {
		if (CCollision::IntersectTriangleRay(c, s, e, v[0].vPos, v[1].vPos, v[2].vPos, pLength)){

			CVector3D e1 = (CVector3D)v[1].vPos - (CVector3D)v[0].vPos;
			CVector3D e2 = (CVector3D)v[2].vPos - (CVector3D)v[0].vPos;

			*n = CVector3D::Cross(e1, e2).GetNormalize();
			hit = true;
		}
	}
	glUnmapBuffer(GL_ARRAY_BUFFER);
	glBindBuffer(GL_ARRAY_BUFFER, 0);
	return hit;
}
int CPoly::CollisionSphere(CCollTriangle *out, const CVector3D &center, float radius){
	glBindBuffer(GL_ARRAY_BUFFER, buffer);
	MY_VERTEX *v = (MY_VERTEX*)glMapBuffer(GL_ARRAY_BUFFER, GL_READ_ONLY);
	int cnt = 0;
	for (int i = 0; i < vertexCnt; i += 3, v += 3) {
		float dist;
		if (CCollision::CollisionTriangleSphere(v[0].vPos, v[1].vPos, v[2].vPos, center, radius, NULL, &dist)) {
			out->m_dist = dist;

			CVector3D e1 = (CVector3D)v[1].vPos - (CVector3D)v[0].vPos;
			CVector3D e2 = (CVector3D)v[2].vPos - (CVector3D)v[0].vPos;

			out->m_normal = CVector3D::Cross(e1, e2).GetNormalize();
			out->m_vertex[0] = v[0].vPos;
			out->m_vertex[1] = v[1].vPos;
			out->m_vertex[2] = v[2].vPos;
			out++;
			cnt++;
		}
	}
	glUnmapBuffer(GL_ARRAY_BUFFER);
	glBindBuffer(GL_ARRAY_BUFFER, 0);
	return cnt;
}

int CPoly::CollisionCupsel(CCollTriangle *out, const CVector3D &top, const CVector3D &bottom, float radius){
	glBindBuffer(GL_ARRAY_BUFFER, buffer);
	MY_VERTEX *v = (MY_VERTEX*)glMapBuffer(GL_ARRAY_BUFFER, GL_READ_ONLY);
	int cnt = 0;
	for (int i = 0; i < vertexCnt; i += 3, v += 3) {
		float dist;
		if (CCollision::CollisionTriangleCapsule(v[0].vPos, v[1].vPos, v[2].vPos, top, bottom, radius, NULL, &dist)) {
			out->m_dist = dist;

			CVector3D e1 = (CVector3D)v[1].vPos - (CVector3D)v[0].vPos;
			CVector3D e2 = (CVector3D)v[2].vPos - (CVector3D)v[0].vPos;

			out->m_normal = CVector3D::Cross(e1, e2).GetNormalize();
			out->m_vertex[0] = v[0].vPos;
			out->m_vertex[1] = v[1].vPos;
			out->m_vertex[2] = v[2].vPos;
			out++;
			cnt++;
		}
	}
	glUnmapBuffer(GL_ARRAY_BUFFER);
	glBindBuffer(GL_ARRAY_BUFFER, 0);
	return cnt;
}
CAnimation::CAnimation() {
}
CAnimation::CAnimation(std::vector<CXAnimationSet*> &a){
	pAnimation = new std::vector < CXAnimationSet* > ;
	for(unsigned int i = 0; i<a.size(); i++) {
		pAnimation->push_back(new CXAnimationSet(*a[i]));
	}
	jam=-1;
	pAnimData = NULL;
	pBoneRoot = NULL;
}
CAnimation::~CAnimation(){
}
void CAnimation::Release() {
	if (pAnimation){
		for (std::vector<CXAnimationSet*>::iterator it = pAnimation->begin(); it != pAnimation->end(); it++) {
			SAFE_DELETE(*it);
		}
		pAnimation->clear();
		delete pAnimation;
		pAnimation = NULL;
	}
}
CMatrix CAnimation::calcMatrix(CXAnimationKey &key,float t){
	CMatrix m[2],result;
	int i;
	for(i=0;i<key.nKeys;i++) {
		if(key.keys[i].time>=(int)(t)) break;
	}
//	if(i==0) return key.keys[0].matrix;

	m[0] = key.keys[i].matrix;
	m[1] = key.keys[i+1].matrix;
	float r = (float)(key.keys[i+1].time-(t+1)) / (key.keys[i+1].time - key.keys[i].time);

	if(r>1.0) {
		printf("over");
	}
	result = m[0] * r + m[1] * (1.0f-r);
	return result;

}
void CAnimation::changeAnimation(int j,bool l,bool check,int blendFrame){
	if(check) {
		if( jam == j) return;
	}
	loop = l;
	jam = j;
	time = 0;
	speed =1.0f;
	endTime = GetEndTime(jam);
	blend = 0.0f;
	blendS = 1.0f/blendFrame;
	saveBlendMatrix();
}
void CAnimation::saveBlendMatrix(){	
	CXAnimationSet* a = (*pAnimation)[jam];
	for(unsigned int i=0;i<a->animations.size();i++){
		CFrameBone *b = (CFrameBone*)CXFrame::GetFrameByName(a->animations[i]->boneName,pBoneRoot);
		if(b) {
			b->saveBlendMatrix();
		}

	}
}
void CAnimation::updateMatrix(){
	if(jam==-1 || pBoneRoot==NULL) return;
	CXAnimationSet* a;
	float frame;
	if(pAnimData) {
		a = (*pAnimation)[0];
		frame = time+pAnimData[jam].start;
	} else {
		a = (*pAnimation)[jam];
		frame = time;
	}
	for(unsigned int i=0;i<a->animations.size();i++){
		CFrameBone *b = (CFrameBone*)CXFrame::GetFrameByName(a->animations[i]->boneName,pBoneRoot);
		if(b) {
			b->SetMatrix(calcMatrix(*a->animations[i]->animationkey,frame));
			if(blend<1.0f) b->calcBlendMatrix(blend);
		}

	}
	
//	CXFrame::printMatrix(pBoneRoot);
}
int CAnimation::GetEndTime(int j){
	if(pAnimData) {
		return pAnimData[j].end-pAnimData[j].start;
	}
	if(j>=(int)pAnimation->size()) return -1;
	CXAnimationSet* a = (*pAnimation)[j];
	int e = 0;
	for(unsigned int i=0;i<a->animations.size();i++){
		int m = a->animations[i]->animationkey->keys[a->animations[i]->animationkey->nKeys-1].time;
		if(e < m) e = m;
	}
	return e;
}
void CAnimation::upDate(){
	time += speed*60*CFPS::GetDeltaTime();
	if(time>=endTime-1.0f) {
		if(loop) {
			time = 0;
		} else {
			time = endTime-1.0f;
		}
	}
	blend += blendS;
	if(blend>1.0f) blend = 1.0f;
}

CMesh::CMesh(CXModelLoader &loader,  CXMesh &mesh,CSkinWeights *bone){
	matrix = mesh.GetMatrix();
	for(int i=0;i<mesh.meshMaterialList->nMaterials;i++) {
		polyList.push_back(new CPoly(loader,mesh,bone,i));
	}
	if(bone) {
		for(unsigned int i=0;i<mesh.skinweights.size();i++) {
			boneList.push_back(new CBoneOffset(*mesh.skinweights[i]));
		}
	}

}
CMesh::~CMesh() {
	
	for(std::vector<CPoly*>::iterator it = polyList.begin();it!=polyList.end();it++) {
		SAFE_DELETE(*it);
	}
	polyList.clear();
	
	for(std::vector<CBoneOffset*>::iterator it = boneList.begin();it!=boneList.end();it++) {
		SAFE_DELETE(*it);
	}
	boneList.clear();

}
void CMesh::draw(std::vector<CMaterialX*> &materialList,CShader *shader,CFrameBone *pFrameRoot,CMatrix *boneMatrix,int boneNum) {


	if (shader) {
		if(boneList.size()>0) {
			for(unsigned int i=0;i<boneList.size();i++) {
				CFrameBone *b = (CFrameBone*)CXFrame::GetFrameByName(boneList[i]->transformNodeName,pFrameRoot);
				b->seMatrixOffset(boneList[i]->matrixOffset);
				b->calcBoneMatrix(boneMatrix);
			}
			glUniform1i(glGetUniformLocation(shader->GetProgram(), "useSkin"), 1);
			int MatrixLocation = glGetUniformLocation(shader->GetProgram(), "Transforms");
			glUniformMatrix4fv(MatrixLocation, boneNum, GL_FALSE, boneMatrix[0].f);
		} else {
			glUniform1i(glGetUniformLocation(shader->GetProgram(), "useSkin"), 0);

		}
	}
	//pFrameRoot->calcBoneMatrix();
	CMatrix mat;
	glGetFloatv(GL_MODELVIEW_MATRIX,mat.f);
	std::vector<CPoly*>::iterator it;
	for(it=polyList.begin();it!=polyList.end();it++) {
		if((*it)->material!=-1) {
			materialList[(*it)->material]->Map(shader);
		}
		(*it)->draw(shader);
		if((*it)->material!=-1) {
			materialList[(*it)->material]->Unmap();
		}

	}
	
}

bool CMesh::CollisionRay(CVector3D *c, CVector3D *n, const CVector3D &s, const CVector3D &e, float *pLength){
	for (unsigned int i = 0; i < polyList.size(); i++) {
		if (polyList[i]->CollisionRay(c, n, s, e, pLength)) return true;
	}
	return false;
}
int CMesh::CollisionSphere(CCollTriangle *out, const CVector3D &center, float radius){
	int cnt = 0;
	for (unsigned int i = 0; i < polyList.size(); i++) {
		cnt += polyList[i]->CollisionSphere(out, center, radius);
		out += cnt;
	}
	return cnt;

}

int CMesh::CollisionCupsel(CCollTriangle *out, const CVector3D &top, const CVector3D &bottom, float radius){
	int cnt = 0;
	for (unsigned int i = 0; i < polyList.size(); i++) {
		cnt += polyList[i]->CollisionCupsel(out, top,bottom, radius);
		out += cnt;
	}
	return cnt;

}
CModelX::CModelX() : pMeshList(NULL), pMaterialList(NULL), pFrameRoot(NULL), boneMatrix(NULL), revMatrix(NULL), animation(NULL){

}

CModelX::~CModelX(){
	if (animation) {
		delete animation;
		animation = NULL;
	}
	if (revMatrix) {
		delete[] revMatrix;
		revMatrix = NULL;
	}
	if (boneMatrix) {
		delete[] boneMatrix;
		boneMatrix = NULL;
	}

	if (pFrameRoot) pFrameRoot->release();
}
CModelX::CModelX(const CModelX &m){
	*this = m;
}	

void CModelX::operator = (const CModelX &m){
	CModel::operator=(m);
	pMeshList = m.pMeshList;
	pMaterialList = m.pMaterialList;
	pFrameRoot = new CFrameBone(*m.pFrameRoot,nullptr,nullptr);
	boneNum = m.boneNum;
	if (m.animation) {
		animation = new CAnimation();
		memcpy(animation, m.animation, sizeof(CAnimation));
		revMatrix = new CMatrix[boneNum];
		boneMatrix = new CMatrix[boneNum];
		animation->attachFrame(pFrameRoot);
	}
}
void CModelX::Release(){
	if (pMeshList) {
		for (std::vector<CMesh*>::iterator it = pMeshList->begin(); it != pMeshList->end(); it++) {
			SAFE_DELETE(*it);
		}
		pMeshList->clear();
		delete pMeshList;
		pMeshList = NULL;
	}
	if (pMaterialList) {
		for (std::vector<CMaterialX*>::iterator it = pMaterialList->begin(); it != pMaterialList->end(); it++) {
			(*it)->Release();
			delete (*it);
		}
		pMaterialList->clear();
		delete pMaterialList;
		pMaterialList = NULL;
	}
	if(pFrameRoot) pFrameRoot->release();
	pFrameRoot=NULL;
	SAFE_DELETE(boneMatrix);
	if (animation){
		animation->Release();
		SAFE_DELETE(animation);
	}
	SAFE_DELETE(m_shader);
}
void CModelX::UpdateAnimationMatrix() {

	if (animation) {
		animation->updateMatrix();
		pFrameRoot->calcMatrix(revMatrix);
	}
}

void CModelX::RenderM(CMatrix &m) {

	glPushMatrix();
	glMultMatrixf(m.f);
	if(m_shader) {
		m_shader->enable();

		SendShaderParam(m);
	}
	UpdateAnimationMatrix();


	//pFrameRoot->SetMatrix(matrix);

	if (animation && animation->jam >= 0) {
		std::vector<CMesh*>::iterator it;
		for(it=pMeshList->begin();it!=pMeshList->end();it++) {
			(*it)->draw(*pMaterialList,m_shader,pFrameRoot,boneMatrix,boneNum);
		}
	} else {
		drawMesh(pFrameRoot, m_matrix);
	}
	glPopMatrix();
	if(m_shader) m_shader->disable();

}


void CModelX::drawMesh(CFrameBone *f,CMatrix m){

	glPushMatrix();
	glMultMatrixf(f->matrix.f);
	CMatrix mat = m * f->matrix;

	if (f->GetType() == eMesh) {

		CMatrix mModelView;
		glGetFloatv(GL_MODELVIEW_MATRIX, mModelView.f);
		glUniformMatrix4fv(glGetUniformLocation(m_shader->GetProgram(), "ModelViewMatrix"), 1, GL_FALSE, mModelView.f);
		glUniformMatrix4fv(glGetUniformLocation(m_shader->GetProgram(), "WorldMatrix"), 1, false, mat.f);

		f->pMesh->draw(*pMaterialList, m_shader, pFrameRoot, boneMatrix, boneNum);
	}
	if (f->GetChild()) {
		drawMesh((CFrameBone*)f->GetChild(), mat);
	}
	glPopMatrix();
	if (f->GetNext()) {
		drawMesh((CFrameBone*)f->GetNext(),m);
	}
}
void CModelX::createMesh(CFrameBone *f, CXModelLoader &loader){
	if (f->GetType() == eMesh) {
		CXMesh *m = (CXMesh*)f->pMesh;
		CSkinWeights *weight = NULL;
		if (m->nFaces != 0) {
			if (0 < loader.animationSet.size()) {
				if (m->skinweights.size() > 0){
					weight = new CSkinWeights(loader, *m);
				}
			}
			if (0 < loader.animationSet.size()) {
				for (unsigned int j = 0; j < m->skinweights.size(); j++) {
					CFrameBone *f = (CFrameBone*)CXFrame::GetFrameByName(m->skinweights[j]->transformNodeName, pFrameRoot);
					f->seMatrixOffset(m->skinweights[j]->matrixOffset);
				}
			}
			f->pMesh = new CMesh(loader, *m, weight);
			pMeshList->push_back(f->pMesh);
			if (weight){
				delete weight;
			}
		}
	}
	if (f->GetChild()) {
		createMesh((CFrameBone*)f->GetChild(), loader);
	}
	if (f->GetNext()) {
		createMesh((CFrameBone*)f->GetNext(), loader);
	}
}
void CModelX::createFrame(CXFrame *xf, CFrameBone *f, int *num){
	if (xf->GetType() == eMesh) {
		f->pMesh = (CMesh*)xf;
	}
	(*num)++;
	printf("%s %s No%d\n",f->GetToken(),f->GetName(),f->GetNo());
	if(xf->GetChild()) {
		CFrameBone *c=new CFrameBone();
		*c = *xf->GetChild();
		if(!f->GetChild()) f->SetChild(c);
		c->SetParent(f);
		createFrame(xf->GetChild(), c, num);
	}
	if(xf->GetNext()) {
		CFrameBone *c=new CFrameBone();
		*c = *xf->GetNext();
		f->SetNext(c);
		c->SetPrev(f);
		c->SetParent(f->GetParent());
		createFrame(xf->GetNext(), c, num);
	}
}
bool CModelX::Load(CXModelLoader &loader){
	MakePath(loader.m_filePath);
	boneNum = 0;
//	printf("f\n");
//	CXFrame::printFrame(pFrameRoot,0);


	pMeshList = new std::vector < CMesh* >;
	pFrameRoot = new CFrameBone();
	*pFrameRoot = *loader.pRoot;
	createFrame(loader.pRoot, pFrameRoot, &boneNum);
	createMesh(pFrameRoot, loader);
	if (0<loader.animationSet.size()) {

		boneMatrix = new CMatrix[boneNum];
		revMatrix = new CMatrix[boneNum];

		animation = new CAnimation(loader.animationSet);
		animation->attachFrame(pFrameRoot);
//		CXFrame::printMatrix(pFrameRoot);
		
		

		//アニメーション用
		m_shader = new CShader("shader\\skinmesh.vert","shader\\mesh.flag");
	} else {
		animation = NULL;
		//アニメーション無し用
		m_shader = new CShader("shader\\mesh.vert","shader\\mesh.flag");
	}
	pMaterialList = new std::vector < CMaterialX* > ;
	for(unsigned int i=0;i<loader.materials.size();i++)
		pMaterialList->push_back(new CMaterialX(*loader.materials[i],m_filePath));
	
return true;

}
bool CModelX::Load(const char* filePath){
	CXModelLoader loader(filePath);
	return Load(loader);

}

void CModelX::UpdateAnimation(){
	if(animation) {
		animation->upDate();
	}
}

CMatrix CModelX::GetFrameMatrix(const char *name,bool local){
	CFrameBone *f = (CFrameBone*)CFrameBone::GetFrameByName(name,pFrameRoot);
	return (local) ? f->GetSMatrix() : GetMatrix() * f->GetSMatrix();
}
CMatrix CModelX::GetFrameMatrix(int no,bool local){
	CFrameBone *f = (CFrameBone*)CFrameBone::GetFrameByNo(no,pFrameRoot);
	return (local) ? f->GetSMatrix() : GetMatrix() * f->GetSMatrix();
}

void CModelX::SetFrameRevMatrix(const char *name, CMatrix &m){
	if (!revMatrix) return;
	CFrameBone *f = (CFrameBone*)CFrameBone::GetFrameByName(name, pFrameRoot);
	if(f)revMatrix[f->GetNo()] = m;
}
void CModelX::SetFrameRevMatrix(int no, CMatrix &m){
	if (!revMatrix) return;
	CFrameBone *f = (CFrameBone*)CFrameBone::GetFrameByNo(no, pFrameRoot);
	if (f)revMatrix[f->GetNo()] = m;
}
CMaterial *CModelX::GetMaterial(int no, int mesh ) {
	if (mesh == -1) {
		return (*pMaterialList)[no];
	}
	return (*pMaterialList)[(*pMeshList)[mesh]->polyList[no]->material];

}

bool CModelX::CollisionRay(CVector3D *pCross, CVector3D *pNormal, const CVector3D &s, const CVector3D &e){
	CVector3D cross, normal;
	float lengh = 1e10;
	bool hit = false;
	CVector3D c, n;

	CMatrix inv = m_matrix.GetInverse();
	CVector3D s2 = inv * CVector4D(s, 1);
	CVector3D e2 = inv * CVector4D(e, 1);
	for (unsigned int i = 0; i < pMeshList->size(); i++) {
		if ((*pMeshList)[i]->CollisionRay(&c, &n, s2, e2, &lengh)){
			hit = true;
		}
	}
	if (hit){
		if (pCross) {
			*pCross = m_matrix * CVector4D(cross,1);
		}
		if (pNormal) {
			*pNormal = CVector3D(m_matrix*CVector4D(normal,0)).GetNormalize();
		}
	}
	return hit;

}
int CModelX::CollisionSphere(CCollTriangle *out, const CVector3D &center, float radius, int maxcnt){
	float scale = CVector3D(m_matrix.m00, m_matrix.m10, m_matrix.m20).Length();
	int cnt = 0;
	CCollTriangle *o = out;
	CVector3D p = m_matrix.GetInverse()* CVector4D(center, 1);
	float r = radius / scale;

	for (unsigned int i = 0; i < pMeshList->size(); i++) {
		int c = (*pMeshList)[i]->CollisionSphere(o, p, r);
		o += c;
		cnt += c;

	}
	o = out;
	for (int i = 0; i < cnt; i++, o++) {
		o->m_dist *= scale;
		o->m_normal = (m_matrix*o->m_normal).GetNormalize();

	}
	return cnt;

}

int CModelX::CollisionCupsel(CCollTriangle *out, const CVector3D &top, const CVector3D &bottom, float radius, int maxcnt){
	float scale = CVector3D(m_matrix.m00, m_matrix.m10, m_matrix.m20).Length();
	int cnt = 0;
	CCollTriangle *o = out;
	CMatrix inv = m_matrix.GetInverse();
	CVector4D t = inv * CVector4D(top, 1);
	CVector4D b = inv * CVector4D(bottom, 1);
	float r = radius / scale;

	for (unsigned int i = 0; i < pMeshList->size(); i++) {
		int c = (*pMeshList)[i]->CollisionCupsel(o, t, b, r);
		o += c;
		cnt += c;

	}
	o = out;
	for (int i = 0; i < cnt; i++, o++) {
		o->m_dist *= scale;
		o->Transform(m_matrix);

	}
	return cnt;


}