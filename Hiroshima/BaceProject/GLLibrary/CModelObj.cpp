#include "CModelObj.h"
#include "CCollision.h"
#include <string.h>

CMeshObj::CMeshObj() : m_pVertexAry(NULL), m_pNormalAry(NULL), m_pTexCoordAry(NULL), m_colIdex(NULL), m_vertexNum(0), m_colmask(NULL), m_max(-1e10, -1e10, -1e10),m_min(1e10, 1e10, 1e10){
}
void CMeshObj::Render(CShader *shader) {
	m_material.Map(shader);

	glBindBuffer(GL_ARRAY_BUFFER, m_buffers[0]);
	GLint vertLoc = glGetAttribLocation(shader->GetProgram(), "Vertex");//���݃����N���Ă���v���O�������Ώ�
	glVertexAttribPointer(vertLoc, 3, GL_FLOAT, GL_FALSE, 0, 0);
	glEnableVertexAttribArray(vertLoc);

	glBindBuffer(GL_ARRAY_BUFFER, m_buffers[1]);
	GLint normalLoc = glGetAttribLocation(shader->GetProgram(), "Normal");//���݃����N���Ă���v���O�������Ώ�
	glVertexAttribPointer(normalLoc, 3, GL_FLOAT, GL_FALSE, 0,0);
	glEnableVertexAttribArray(normalLoc);

	glBindBuffer(GL_ARRAY_BUFFER, m_buffers[2]);
	GLint texLoc = glGetAttribLocation(shader->GetProgram(), "TexCoord");//���݃����N���Ă���v���O�������Ώ�
	glVertexAttribPointer(texLoc, 2, GL_FLOAT, GL_FALSE, 0, 0);
	glEnableVertexAttribArray(texLoc);

	glDrawArrays(GL_TRIANGLES,0,m_vertexNum);

	glDisableVertexAttribArray(vertLoc);
	glDisableVertexAttribArray(normalLoc);
	glDisableVertexAttribArray(texLoc);
	glBindBuffer(GL_ARRAY_BUFFER, 0);
	m_material.Unmap();

}
void CMeshObj::Release() {
	if(m_pVertexAry)  {delete[] m_pVertexAry; m_pVertexAry=NULL;}
	if(m_pNormalAry)  {delete[] m_pNormalAry; m_pNormalAry=NULL;}
	if(m_pTexCoordAry)  {delete[] m_pTexCoordAry; m_pTexCoordAry=NULL;}
	if (m_colmask) delete m_colmask;
	if (m_colIdex) delete[] m_colIdex;
	m_material.Release();
	glDeleteBuffers(3, m_buffers);
}
void CMeshObj::CreatCollsionIndex(int raw,int col){
	CVector3D *v = m_pVertexAry;
	m_col = col; m_raw = raw;

	m_colIdex = new std::vector < int >[m_raw*m_col];
	m_raw = m_raw;
	m_col = m_col;
	m_colmask = new unsigned long[(m_vertexNum / 3 / 32)+1];

	m_lenghZ= (m_max.z - m_min.z) / m_col;
	if (m_lenghZ == 0.0f) m_lenghZ = 1.0f;
	m_lenghX = (m_max.x - m_min.x) / m_raw;
	if (m_lenghX == 0.0f) m_lenghX = 1.0f;
	for (int i = 0; i < m_vertexNum; i += 3, v += 3) {
		
		float l = fminf(fminf(v[0].x, v[1].x), v[2].x);
		float r = fmaxf(fmaxf(v[0].x, v[1].x), v[2].x);
		float t = fmaxf(fmaxf(v[0].z, v[1].z), v[2].z);
		float b = fminf(fminf(v[0].z, v[1].z), v[2].z);

		int raws = (int)((l - m_min.x) / m_lenghX);
		if (raws >= m_raw) raws = m_raw - 1;
		int rawe = (int)((r - m_min.x) / m_lenghX);
		if (rawe >= m_raw) rawe = m_raw - 1;
		int cole = (int)((t - m_min.z) / m_lenghZ);
		if (cole >= m_col) cole = m_col - 1;
		int cols = (int)((b - m_min.z) / m_lenghZ);
		if (cols >= m_col) cols = m_col - 1;
		for (int lineZ = cols; lineZ <= cole; lineZ++) {
			for (int lineX = raws; lineX <= rawe; lineX++) {
				m_colIdex[lineZ*m_raw + lineX].push_back(i/3);
			}
		}

	}
}
bool CMeshObj::CollisionRay(CVector3D *c, CVector3D *n, const CVector3D &s, const CVector3D &e, float *pLength){
	CVector3D *v = m_pVertexAry;
	memset(m_colmask, 0, sizeof(unsigned long)*((m_vertexNum / 3 / 32) + 1));
	float l = min(s.x, e.x);
	float r = max(s.x, e.x);
	float t = max(s.z, e.z);
	float b = min(s.z, e.z);

	int raws = (int)((l - m_min.x) / m_lenghX);
	if (raws < 0) raws = 0;
	int rawe = (int)((r - m_min.x) / m_lenghX);
	if (rawe >= m_raw) rawe = m_raw - 1;
	int cole = (int)((t - m_min.z) / m_lenghZ);
	if (cole >= m_col) cole = m_col - 1;
	int cols = (int)((b - m_min.z) / m_lenghZ);
	if (cols < 0) cols = 0;

	bool hit = false;

	for (int lineZ = cols; lineZ <= cole; lineZ++) {
		for (int lineX = raws; lineX <= rawe; lineX++) {
			for (unsigned int i = 0; i < m_colIdex[lineZ*m_raw + lineX].size(); i++){
				int idx = m_colIdex[lineZ*m_raw + lineX][i];
				if (m_colmask[idx / 32] & (1 << (idx % 32))) continue;
				if (CCollision::IntersectTriangleRay(c, s, e, v[idx*3],v[idx*3 + 1], v[idx*3+2], pLength)){

					CVector3D e1 = v[idx * 3 + 1] - v[idx * 3];
					CVector3D e2 = v[idx * 3 + 2] - v[idx * 3];

					*n = CVector3D::Cross(e1, e2).GetNormalize();
					hit = true;
				}
				m_colmask[idx / 32] |= 1 << (idx % 32);
			}

		}
	}
	/*
	for (int i = 0; i < m_vertexNum; i += 3, v += 3) {
		if (CCollision::IntersectTriangleRay(c, s, e, v[0], v[1], v[2], pLength)){

			CVector3D e1 = v[1] - v[0];
			CVector3D e2 = v[2] - v[0];

			*n = CVector3D::Cross(e1, e2).GetNormalize();
			hit = true;
		}
	}
	*/

	return hit;
}


int CMeshObj::CollisionSphere(CCollTriangle *out, const CVector3D &center, float radius, int maxcnt){
	CVector3D *v = m_pVertexAry;
	memset(m_colmask, 0, sizeof(unsigned long)*((m_vertexNum / 3 / 32) + 1));
	float l = center.x-radius;
	float r = center.x + radius;
	float t = center.z + radius;
	float b = center.z - radius;

	int raws = (int)((l - m_min.x) / m_lenghX);
	if (raws < 0) raws = 0;
	int rawe = (int)((r - m_min.x) / m_lenghX);
	if (rawe >= m_raw) rawe = m_raw-1;
	int cole = (int)((t - m_min.z) / m_lenghZ);
	if (cole >= m_col) cole = m_col-1;
	int cols = (int)((b - m_min.z) / m_lenghZ);
	if (cols < 0) cols = 0;
	int cnt = 0;
	float dist;
	for (int lineZ = cols; lineZ <= cole; lineZ++) {
		for (int lineX = raws; lineX <= rawe; lineX++) {
			for (unsigned int i = 0; i < m_colIdex[lineZ*m_raw + lineX].size(); i++){
				int idx = m_colIdex[lineZ*m_raw + lineX][i];
				if (m_colmask[idx / 32] & (1 << (idx % 32))) continue;
				if (CCollision::CollisionTriangleSphere(v[idx*3], v[idx*3 + 1], v[idx*3 + 2], center, radius, NULL, &dist)) {
					out->m_dist = dist;

					CVector3D e1 = v[idx * 3 + 1] - v[idx * 3];
					CVector3D e2 = v[idx * 3 + 2] - v[idx * 3];

					out->m_normal = CVector3D::Cross(e1, e2);
					out->m_vertex[0] = v[idx * 3 + 0];
					out->m_vertex[1] = v[idx * 3 + 1];
					out->m_vertex[2] = v[idx * 3 + 2];
					if (out->m_normal.LengthSq() == 0) continue;
					out->m_normal.Normalize();
					out++;
					cnt++;
					if (cnt >= maxcnt) return cnt;
				}
				m_colmask[idx / 32] |= 1 << (idx % 32);
			}
		}
	}
	/*
	int cnt = 0;
	for (int i = 0; i < m_vertexNum; i+=3,v+=3)
	{
		float dist;
		if (CCollision::CollisionTriangleSphere(v[0], v[1], v[2], center, radius, NULL, &dist)) {
			out->m_dist = dist;

			CVector3D e1 = v[1] - v[0];
			CVector3D e2 = v[2] - v[0];

			out->m_normal = CVector3D::Cross(e1, e2).GetNormalize();
			out++;
			cnt++;
		}
	}
	*/
	return cnt;
}


int CMeshObj::CollisionCupsel(CCollTriangle *out, const CVector3D &top, const CVector3D &bottom, float radius, int maxcnt){
	CVector3D *v = m_pVertexAry;
	memset(m_colmask, 0, sizeof(unsigned long)*((m_vertexNum / 3 / 32) + 1));
	float l = min(top.x,bottom.x) - radius;
	float r = max(top.x, bottom.x) + radius;
	float t = max(top.z, bottom.z) + radius;
	float b = min(top.z, bottom.z) - radius;

	int raws = (int)((l - m_min.x) / m_lenghX);
	if (raws < 0) raws = 0;
	int rawe = (int)((r - m_min.x) / m_lenghX);
	if (rawe >= m_raw) rawe = m_raw - 1;
	int cole = (int)((t - m_min.z) / m_lenghZ);
	if (cole >= m_col) cole = m_col - 1;
	int cols = (int)((b - m_min.z) / m_lenghZ);
	if (cols < 0) cols = 0;
	int cnt = 0;
	float dist;
	for (int lineZ = cols; lineZ <= cole; lineZ++) {
		for (int lineX = raws; lineX <= rawe; lineX++) {
			for (unsigned int i = 0; i < m_colIdex[lineZ*m_raw + lineX].size(); i++){
				int idx = m_colIdex[lineZ*m_raw + lineX][i];
				if (m_colmask[idx / 32] & (1 << (idx % 32))) continue;
				if (CCollision::CollisionTriangleCapsule(v[idx * 3], v[idx * 3 + 1], v[idx * 3 + 2], top, bottom, radius, NULL, &dist)) {
					out->m_dist = dist;

					CVector3D e1 = v[idx * 3+1] - v[idx * 3];
					CVector3D e2 = v[idx * 3+2] - v[idx * 3];


					out->m_normal = CVector3D::Cross(e1, e2);
					if (out->m_normal.LengthSq() == 0) continue;
					out->m_normal.Normalize();
					out->m_vertex[0] = v[idx * 3 + 0];
					out->m_vertex[1] = v[idx * 3 + 1];
					out->m_vertex[2] = v[idx * 3 + 2];

					out++;
					cnt++;
					if (cnt >= maxcnt) return cnt;
				}
				m_colmask[idx / 32] |= 1 << (idx % 32);
			}
		}
	}
	/*
	int cnt = 0;
	for (int i = 0; i < m_vertexNum; i += 3, v += 3)
	{
		float dist;
		if (CCollision::CollisionTriangleCapsule(v[0], v[1], v[2], top, bottom, radius, NULL, &dist)) {
			out->m_dist = dist;

			CVector3D e1 = v[1] - v[0];
			CVector3D e2 = v[2] - v[0];

			out->m_normal = CVector3D::Cross(e1, e2).GetNormalize();
			out++;
			cnt++;
		}
	}
	*/
	return cnt;
}

void CMeshObj::LoadBinary(FILE *fp, const char *filePath) {
	fread(&m_vertexNum, sizeof(int), 1, fp);
	if (m_vertexNum <= 0) return;
	struct SMaterial {
		char m_name[128];
		char m_texName[128];
		CVector4D m_ambient;	//�A���r�G���g�J���[
		CVector4D m_diffuse;	//�f�t���[�Y�J���[
		CVector3D m_specular;	//�X�y�L�����[�J���[
		CVector3D m_emissive;	//���Ȕ���
		float m_shininess;		//�X�y�L�����[�W��
		SMaterial() {
			memset(this, 0, sizeof(SMaterial));
			m_shininess = 1.0f;
		}
	}mat;
	fread(&mat, sizeof(SMaterial), 1, fp);
	fread(&m_max, sizeof(CVector3D), 1, fp);
	fread(&m_min, sizeof(CVector3D), 1, fp);
	fread(&m_min, sizeof(CVector3D), 1, fp);
	fread(&m_lenghX, sizeof(float), 1, fp);
	fread(&m_lenghZ, sizeof(float), 1, fp);
	m_pVertexAry = new CVector3D[m_vertexNum];
	m_pNormalAry = new CVector3D[m_vertexNum];
	m_pTexCoordAry = new CVector2D[m_vertexNum];
	fread(m_pVertexAry, sizeof(CVector3D), m_vertexNum, fp);
	fread(m_pNormalAry, sizeof(CVector3D), m_vertexNum, fp);
	fread(m_pTexCoordAry, sizeof(CVector2D), m_vertexNum, fp);
	fread(&m_col, sizeof(int), 1, fp);
	fread(&m_raw, sizeof(int), 1, fp);

	glGenBuffers(3, m_buffers);
	glBindBuffer(GL_ARRAY_BUFFER, m_buffers[0]);
	glBufferData(GL_ARRAY_BUFFER, sizeof(CVector3D) * m_vertexNum, m_pVertexAry, GL_STATIC_DRAW);
	glBindBuffer(GL_ARRAY_BUFFER, m_buffers[1]);
	glBufferData(GL_ARRAY_BUFFER, sizeof(CVector3D) * m_vertexNum, m_pNormalAry, GL_STATIC_DRAW);
	glBindBuffer(GL_ARRAY_BUFFER, m_buffers[2]);
	glBufferData(GL_ARRAY_BUFFER, sizeof(CVector2D) * m_vertexNum, m_pTexCoordAry, GL_STATIC_DRAW);
	glBindBuffer(GL_ARRAY_BUFFER, 0);

	m_colIdex = new std::vector < int >[m_raw*m_col];
	m_colmask = new unsigned long[(m_vertexNum / 3 / 32) + 1];

	for (int i = 0; i < m_col*m_raw; i++) {
		int size;
		fread(&size, sizeof(unsigned long), 1, fp);
		int *idx = new int[size];
		fread(idx, sizeof(int), size, fp);
		for (int j = 0; j < size; j++) {
			m_colIdex[i].push_back(idx[j]);
		}
		delete idx;
	}
	m_material.m_ambient = mat.m_ambient;
	m_material.m_diffuse = mat.m_diffuse;
	m_material.m_specular = mat.m_specular;
	m_material.m_shininess = mat.m_shininess;
	m_material.m_emissive = mat.m_emissive;
	strcpy_s(m_materialname,sizeof(m_materialname),mat.m_name);
	if (mat.m_texName[0]) {

		char str[256];
		strcpy_s(str, 256, filePath);
		strcat_s(str,256, mat.m_texName);
		if (m_material.m_pTex) {
			m_material.Release();
		}
		m_material.m_pTex = new CTexture();
		if (!m_material.m_pTex->Load(str)) {
			if (m_material.m_pTex->Load(mat.m_texName)) {
				delete m_material.m_pTex;
				m_material.m_pTex = nullptr;
			}
		}
		
	}
	m_material.m_alpha = 1.0f;
}
CModelObj::CModelObj() :m_mesh(NULL){
}
CModelObj::~CModelObj() {
}

bool CModelObj::LoadBinary(const char *path) {
	MakePath(path);
	SObjModelHeader h;
	FILE *fp=nullptr;
	fopen_s(&fp, path, "rb");
	if (!fp) return false;
	fread(&h, sizeof(SObjModelHeader), 1, fp);
	if (h.fileType[0] == 'B' && h.fileType[1] == 'O') {
		m_materialCnt = h.m_materialCnt;
		m_col = h.m_col;
		m_raw = h.m_raw;
		m_mesh = new CMeshObj[m_materialCnt];
		for (int i = 0; i < m_materialCnt; i++) {
			m_mesh[i].LoadBinary(fp,m_filePath);
		}
	} else {
		return false;
	}
	fclose(fp);
	m_shader = new CShader("shader\\mesh.vert", "shader\\mesh.flag");

	return true;

}
bool CModelObj::Load(const char *path) {

	const char *p = strrchr(path, '.');
	if (strcmp(p, ".obb") == 0) {
		return LoadBinary(path);
	}
	return Load(path, 1, 1);
}
bool CModelObj::Load(const char *path,int raw,int col) {
	MakePath(path);
	m_col = col;
	m_raw = raw;
	//�t�@�C���|�C���^(fp)�̍쐬���J�����t�@�C���̃n���h����n���B
	FILE* fp;
	fopen_s(&fp,path,"r");
	//�t�@�C�����J���Ȃ������ꍇ�̓G���[��\����false��Ԃ�
	if(fp==NULL) {
		printf("�t�@�C��������܂���%s\n",path);
		return false;
	}
	//���W�f�[�^�p�J�E���^�[
	int	VCnt=0;
	//�@���f�[�^�p�J�E���^�[
	int	NCnt=0;
	//�e�N�X�`���[�R�[�h�p�J�E���^�[
	int	TCnt=0;
	//�ʃf�[�^�p�J�E���^�[
	int	FCnt=0;
	//�L�[���[�h�i�[�p
	char key[128];
	//�t�@�C���̖����łȂ���ΌJ��Ԃ�
	CMeshObj *m=NULL;
	while(!feof(fp)) {
		//key���N���A
		key[0]=0;
		//1�P��@�������ǂݍ���
		fscanf_s(fp,"%s",key,128);
		//�ǂݍ��񂾃L�[���[�h���uv�v�Ȃ���W�f�[�^�J�E���^�[���J�E���g�A�b�v
		if(strcmp(key,"v")==0) {
			VCnt++;
		} else 
		if(strcmp(key,"usemtl")==0) {
			char name[128];
			fscanf_s(fp,"%s",name,128);
			for(int i=0;i<m_materialCnt;i++) {
				if(strcmp(name,m_mesh[i].m_materialname)==0) {
					m = &m_mesh[i];
				}
			}
		}
		//�ǂݍ��񂾃L�[���[�h���uf�v�Ȃ�ʃf�[�^�J�E���^�[���J�E���g�A�b�v
		if(strcmp(key,"f")==0) {
			//���_�����J�E���g�A�b�v
			if(m) m->m_vertexNum+=3;
		} else 
		//�ǂݍ��񂾃L�[���[�h���uvn�v�Ȃ�@���f�[�^�J�E���^�[���J�E���g�A�b�v
		if(strcmp(key,"vn")==0) {
			NCnt++;
		} else 
		//�ǂݍ��񂾃L�[���[�h���uvt�v�Ȃ�e�N�X�`���[�R�[�h�f�[�^�J�E���^�[���J�E���g�A�b�v
		if(strcmp(key,"vt")==0) {
			TCnt++;
		} else 
		//�ǂݍ��񂾃L�[���[�h���umtllib�v�Ȃ�}�e���A���t�@�C���̓ǂݍ���
		if(strcmp(key,"mtllib")==0) {
			char str[PATH_SIZE];
			strcpy_s(str, PATH_SIZE, m_filePath);
			int l = strlen(str);
			fscanf_s(fp, "%s", &str[l], PATH_SIZE-l);
			LoadMaterial(str);
		}
	}
	printf("VCnt %d\n",VCnt);
	

	//���W�f�[�^�̐������z����쐬
	CVector3D *pVertex = new CVector3D[VCnt];
	//�@���f�[�^�̐������z����쐬
	CVector3D *pNormal = new CVector3D[NCnt];
	//�e�N�X�`���[�R�[�h�f�[�^�̐������z����쐬
	CVector2D *pTexCoord = new CVector2D[TCnt];
	
	for(int i=0;i<m_materialCnt;i++) {
		//�`��p���_�z����쐬
		m_mesh[i].m_pVertexAry = new CVector3D[m_mesh[i].m_vertexNum];
		//�`��p�@���z����쐬
		m_mesh[i].m_pNormalAry = new CVector3D[m_mesh[i].m_vertexNum];
		//�`��p�e�N�X�`���[�R�[�h�z����쐬
		m_mesh[i].m_pTexCoordAry = new CVector2D[m_mesh[i].m_vertexNum];
		m_mesh[i].m_vertexNum=0;

	}
	//�ǂݍ��񂾍��W�f�[�^��0���珇�ԂɊi�[���邽�߁A�J�E���^�[��0�ɖ߂�
	VCnt=0;
	NCnt=0;
	TCnt=0;
	//�ǂݏ����̈ʒu���t�@�C���̐擪�ɖ߂�
	fseek(fp,0,SEEK_SET);
	//�`��p���_�z��ւ̍��W�f�[�^�i�[��ԍ�
	int idx = 0;
	//�t�@�C���̖����łȂ���ΌJ��Ԃ�
	while(!feof(fp)) {
		//key���N���A
		key[0]=0;
		//�L�[���[�h�̓ǂݍ���
		fscanf_s(fp,"%s",key,128);
		//�u���v��ǂݍ��񂾂�A���W�f�[�^��ǂݍ���
		if(strcmp(key,"v")==0) {
			fscanf_s(fp,"%f %f %f",&pVertex[VCnt].x,&pVertex[VCnt].y,&pVertex[VCnt].z);
			//�ǂݍ��ݐ�����̃f�[�^��
			VCnt++;
		}else//�uvn�v��ǂݍ��񂾂�A�@���f�[�^��ǂݍ���
		if(strcmp(key,"vn")==0) {
			fscanf_s(fp,"%f %f %f",&pNormal[NCnt].x,&pNormal[NCnt].y,&pNormal[NCnt].z);
			//�ǂݍ��ݐ�����̃f�[�^��
			NCnt++;
		}else//�uvt�v��ǂݍ��񂾂�A�e�N�X�`���[�R�[�h�f�[�^��ǂݍ���
		if(strcmp(key,"vt")==0) {
			fscanf_s(fp,"%f %f",&pTexCoord[TCnt].x,&pTexCoord[TCnt].y);
			pTexCoord[TCnt].y = 1.0f - pTexCoord[TCnt].y;
			//�ǂݍ��ݐ�����̃f�[�^��
			TCnt++;
		} else 
		if(strcmp(key,"usemtl")==0) {
			char name[128];
			fscanf_s(fp,"%s",name,128);
			for(int i=0;i<m_materialCnt;i++) {
				if(strcmp(name,m_mesh[i].m_materialname)==0) {
					m = &m_mesh[i];
				}
			}
		}
		if(strcmp(key,"f")==0) {

			int d[3][3] = { 1, 1, 1, 1, 1, 1, 1, 1, 1 };
			char data[128];
			fgets(data, 255, fp);
			char *p = data + 1;
			char str[16];
			int strIdx = 0;
			int t = 0, c = 0;
			CVector3D v[3];
			while (*p) {
				if (*p == '/' || *p == ' ' || *p == '\n') {

					str[strIdx] = 0;
					if (strIdx != 0) d[t][c] = atoi(str);
					strIdx = 0;
					if (*p == '/') t++;
					else{
						c++;
						t = 0;
						if (c >= 3) {
							if (*(p + 1) != '\0') printf("�O�p�`�ȊO�̃|���S��������܂�");
							break;
						}
					}
				}
				else {
					str[strIdx] = *p;
					strIdx++;
				}
				p++;
			}
			m->m_pVertexAry[m->m_vertexNum] = v[0] = pVertex[d[0][0] - 1];			//���_�P�̍��W�f�[�^
			m->m_pVertexAry[m->m_vertexNum + 1] = v[1]  = pVertex[d[0][1] - 1];		//���_�Q�̍��W�f�[�^
			m->m_pVertexAry[m->m_vertexNum + 2] = v[2]  = pVertex[d[0][2] - 1];

			m->m_pNormalAry[m->m_vertexNum] = pNormal[d[2][0] - 1];			//���_�P�̖@���f�[�^
			m->m_pNormalAry[m->m_vertexNum + 1] = pNormal[d[2][1] - 1];		//���_�Q�̖@���f�[�^
			m->m_pNormalAry[m->m_vertexNum + 2] = pNormal[d[2][2] - 1];

			m->m_pTexCoordAry[m->m_vertexNum] = pTexCoord[d[1][0] - 1];			//���_�P�̃e�N�X�`���[�R�[�h�f�[�^
			m->m_pTexCoordAry[m->m_vertexNum + 1] = pTexCoord[d[1][1] - 1];		//���_�Q�̃e�N�X�`���[�R�[�h�f�[�^
			m->m_pTexCoordAry[m->m_vertexNum + 2] = pTexCoord[d[1][2] - 1];
			m->m_min.x = min(m->m_min.x, min(min(v[0].x, v[1].x), v[2].x));
			m->m_max.x = max(m->m_max.x, max(max(v[0].x, v[1].x), v[2].x));
			m->m_max.z = max(m->m_max.z, max(max(v[0].z, v[1].z), v[2].z));
			m->m_min.z = min(m->m_min.z, min(min(v[0].z, v[1].z), v[2].z));
			/*
			int v1,v2,v3;
			int n1,n2,n3;
			int t1,t2,t3;
			fscanf_s(fp,"%d/%d/%d %d/%d/%d %d/%d/%d",&v1,&t1,&n1,&v2,&t2,&n2,&v3,&t3,&n3);
			m->m_pVertexAry[m->m_vertexNum] = pVertex[v1-1];			//���_�P�̍��W�f�[�^
			m->m_pVertexAry[m->m_vertexNum+1] = pVertex[v2-1];		//���_�Q�̍��W�f�[�^
			m->m_pVertexAry[m->m_vertexNum+2] = pVertex[v3-1];		
			
			m->m_pNormalAry[m->m_vertexNum] = pNormal[n1-1];			//���_�P�̖@���f�[�^
			m->m_pNormalAry[m->m_vertexNum+1] = pNormal[n2-1];		//���_�Q�̖@���f�[�^
			m->m_pNormalAry[m->m_vertexNum+2] = pNormal[n3-1];		
			
			m->m_pTexCoordAry[m->m_vertexNum] = pTexCoord[t1-1];			//���_�P�̃e�N�X�`���[�R�[�h�f�[�^
			m->m_pTexCoordAry[m->m_vertexNum+1] = pTexCoord[t2-1];		//���_�Q�̃e�N�X�`���[�R�[�h�f�[�^
			m->m_pTexCoordAry[m->m_vertexNum+2] = pTexCoord[t3-1];		
			*/
			//�f�[�^�̊i�[���3�ړ�����
			m->m_vertexNum+=3;
		}
	}
	fclose(fp);


	for (int i = 0; i<m_materialCnt; i++) {
		m_mesh[i].CreatCollsionIndex(m_raw,m_col);

		glGenBuffers(3, m_mesh[i].m_buffers);
		glBindBuffer(GL_ARRAY_BUFFER, m_mesh[i].m_buffers[0]);
		glBufferData(GL_ARRAY_BUFFER, sizeof(CVector3D) * m_mesh[i].m_vertexNum, m_mesh[i].m_pVertexAry, GL_STATIC_DRAW);
		glBindBuffer(GL_ARRAY_BUFFER, m_mesh[i].m_buffers[1]);
		glBufferData(GL_ARRAY_BUFFER, sizeof(CVector3D) * m_mesh[i].m_vertexNum, m_mesh[i].m_pNormalAry, GL_STATIC_DRAW);
		glBindBuffer(GL_ARRAY_BUFFER, m_mesh[i].m_buffers[2]);
		glBufferData(GL_ARRAY_BUFFER, sizeof(CVector2D) * m_mesh[i].m_vertexNum, m_mesh[i].m_pTexCoordAry, GL_STATIC_DRAW);
		glBindBuffer(GL_ARRAY_BUFFER, 0);
	}


	m_shader = new CShader("shader\\mesh.vert","shader\\mesh.flag");

	
	//�ꎞ�f�[�^���
	delete[] pVertex;
	delete[] pNormal;
	delete[] pTexCoord;
	return true;
}

bool CModelObj::LoadMaterial(char *path) {
	char key[128];
	FILE* fp;
	fopen_s(&fp, path, "r");
	//�t�@�C�����J���Ȃ������ꍇ�̓G���[��\����false��Ԃ�
	if (fp == NULL) {
		printf("�t�@�C��������܂���%s\n", path);
		return false;
	}

	m_materialCnt = 0;
	while (!feof(fp)) {
		fscanf_s(fp, "%s", key, 128);
		if (strcmp(key, "newmtl") == 0)
			m_materialCnt++;
	}
	m_mesh = new CMeshObj[m_materialCnt];
	m_materialCnt = 0;
	CMeshObj *m = m_mesh;
	fseek(fp, 0, SEEK_SET);
	while (!feof(fp)) {
		key[0] = '\0';
		fscanf_s(fp, "%s", key, 128);
		if (strcmp(key, "newmtl") == 0) {
			m = &m_mesh[m_materialCnt];
			char name[128];
			fscanf_s(fp, "%s", name, 128);
			strcpy_s(m->m_materialname, 128, name);

			m_materialCnt++;
		}else
		if (strcmp(key, "Ka") == 0) {
			fscanf_s(fp, "%f %f %f", &m->m_material.m_ambient.x, &m->m_material.m_ambient.y, &m->m_material.m_ambient.z);
			m->m_material.m_ambient.a = 1.0f;
		}else
		if (strcmp(key, "Kd") == 0) {
			fscanf_s(fp, "%f %f %f", &m->m_material.m_diffuse.x, &m->m_material.m_diffuse.y, &m->m_material.m_diffuse.z);
			m->m_material.m_diffuse.a = 1.0f;
		}else
		if (strcmp(key, "Ks") == 0) {
			fscanf_s(fp, "%f %f %f", &m->m_material.m_specular.x, &m->m_material.m_specular.y, &m->m_material.m_specular.z);
		}else
		if (strcmp(key, "Ns") == 0) {
			fscanf_s(fp, "%f", &m->m_material.m_shininess);
		}else
		if (strcmp(key, "d") == 0) {
			float aplha;
			fscanf_s(fp, "%f", &aplha);
			m->m_material.m_ambient.a = aplha;
			m->m_material.m_diffuse.a = aplha;
		}else
		if (strcmp(key, "map_Kd") == 0) {

			char str[PATH_SIZE];
			strcpy_s(str, PATH_SIZE, m_filePath);
			int l = strlen(str);
			fscanf_s(fp, "%s", &str[l], PATH_SIZE-l);
			if (m->m_material.m_pTex) {
				m->m_material.Release();
			}
			m->m_material.m_pTex = new CTexture();
			m->m_material.m_pTex->Load(str);
		}
	}
	fclose(fp);
	return true;
}
void CModelObj::RenderM(CMatrix &m) {
//	UpdateMatrix();
	glPushMatrix();
	glMultMatrixf(m.f);
	m_shader->enable();
	SendShaderParam(m);


	for(int i=0;i<m_materialCnt;i++) {
		m_mesh[i].Render(m_shader);
	}
	m_shader->disable();
	glPopMatrix();


}

void CModelObj::Release() {
	for(int i=0;i<m_materialCnt;i++) {
		m_mesh[i].Release();
	}
	if (m_mesh) delete[] m_mesh;
	if (m_shader) delete m_shader;
}

bool CModelObj::CollisionRay(CVector3D *pCross, CVector3D *pNormal, const CVector3D &s, const CVector3D &e){
	CVector3D cross, normal;
	float length = 1e10;
	bool hit = false;
	CVector3D c, n;

	CMatrix inv = m_matrix.GetInverse();
	CVector3D s2 = inv * CVector4D(s, 1);
	CVector3D e2 = inv * CVector4D(e, 1);

	for (int i = 0; i<m_materialCnt; i++) {
		if (m_mesh[i].CollisionRay(&c, &n, s2,e2, &length))
			hit = true;
	}
	if (hit){
		if (pCross) {
			*pCross = m_matrix*CVector4D(c , 1);
		}
		if (pNormal) {
			*pNormal = CVector3D(m_matrix*CVector4D(n, 0)).GetNormalize();
		}
	}
	return hit;

}


int CModelObj::CollisionSphere(CCollTriangle *out, const CVector3D &center, float radius, int maxcnt){
	float scale = CVector3D(m_matrix.m00, m_matrix.m10, m_matrix.m20).Length();
	int cnt = 0;
	CCollTriangle *o = out;
	CVector3D p = m_matrix.GetInverse() * CVector4D(center, 1);
	float r = radius / scale;

	for (int i = 0; i<m_materialCnt; i++) {
		int c = m_mesh[i].CollisionSphere(o, p, r, maxcnt);
		o += c;
		cnt += c;
		if (cnt > maxcnt) break;

	}
	o = out;
	for (int i = 0; i < cnt; i++, o++) {
		o->m_dist *= scale;
		o->Transform(m_matrix);

	}
	return cnt;
}


int CModelObj::CollisionCupsel(CCollTriangle *out, const CVector3D &top, const CVector3D &bottom, float radius, int maxcnt){
	float scale = CVector3D(m_matrix.m00, m_matrix.m10, m_matrix.m20).Length();
	int cnt = 0;
	CCollTriangle *o = out;
	CMatrix inv = m_matrix.GetInverse();
	CVector3D t = inv * CVector4D(top, 1);
	CVector3D b = inv * CVector4D(bottom, 1);
	float r = radius / scale;

	for (int i = 0; i<m_materialCnt; i++) {
		int c = m_mesh[i].CollisionCupsel(o, t, b, r,maxcnt);
		o += c;
		cnt += c;
		if (cnt > maxcnt) break;

	}
	o = out;
	for (int i = 0; i < cnt; i++, o++) {
		o->m_dist *= scale;
		o->Transform(m_matrix);

	}
	return cnt;
}