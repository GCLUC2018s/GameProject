#include "CModelSX.h"

CSPoly::~CSPoly(){
	glDeleteBuffers(3, m_buffer);
}
void CSPoly::create(CXSModelLoader &loader,int materialNo){
	
	m_vertexCnt = 0;
	for(int i=0;i<loader.m_faceNum;i++) {
		if(loader.m_materialList[i] == materialNo) m_vertexCnt++;
	}
	m_vertexCnt*=3;
	CVector3D *vertex = new CVector3D[m_vertexCnt];
	CVector3D *normal = NULL;
	CXSTexCoord *texCoord = NULL;
	if (loader.m_normal)
		normal = new CVector3D[m_vertexCnt];
	m_useNormal = (loader.m_normal != NULL) ? true : false;

	if (loader.m_texCoord) 
		texCoord = new CXSTexCoord[m_vertexCnt];
	
	m_useTex = (loader.m_texCoord != NULL) ? true:false;
	CVector3D *v = vertex;
	CVector3D *n = normal;
	CXSTexCoord *t = texCoord;
	for(int i=0;i<loader.m_faceNum;i++) {
		if(loader.m_materialList[i] != materialNo) continue;
		for(int j=0;j<3;j++) {
			v[j].x = loader.m_vertex[loader.m_vertexIndex[i*3+j]].x;
			v[j].y = loader.m_vertex[loader.m_vertexIndex[i*3+j]].y;
			v[j].z = loader.m_vertex[loader.m_vertexIndex[i*3+j]].z;
		}
		v+=3;
		if(n) {
			for(int j=0;j<3;j++) {
				n[j].x = loader.m_normal[loader.m_normalIndex[i*3+j]].x;
				n[j].y = loader.m_normal[loader.m_normalIndex[i*3+j]].y;
				n[j].z = loader.m_normal[loader.m_normalIndex[i*3+j]].z;
			}
			n+=3;
		}
		if(t) {
			for(int j=0;j<3;j++) {
				t[j].u = loader.m_texCoord[loader.m_vertexIndex[i*3+j]].u;
				t[j].v = loader.m_texCoord[loader.m_vertexIndex[i*3+j]].v;
			}
			t+=3;
		}
		
	}
	glGenBuffers(3, m_buffer);
	glBindBuffer(GL_ARRAY_BUFFER,m_buffer[0]);
	glBufferData(GL_ARRAY_BUFFER, sizeof(CVector3D)*m_vertexCnt, vertex, GL_STATIC_DRAW);
	if (m_useNormal) {
		glBindBuffer(GL_ARRAY_BUFFER, m_buffer[1]);
		glBufferData(GL_ARRAY_BUFFER, sizeof(CVector3D)*m_vertexCnt, normal, GL_STATIC_DRAW);
	}
	if (m_useTex) {
		glBindBuffer(GL_ARRAY_BUFFER, m_buffer[2]);
		glBufferData(GL_ARRAY_BUFFER, sizeof(CXSTexCoord)*m_vertexCnt, texCoord, GL_STATIC_DRAW);
	}
	if (vertex) delete[] vertex;
	if (normal) delete[] normal;
	if (texCoord) delete[] texCoord;
	glBindBuffer(GL_ARRAY_BUFFER, 0);

}
void CSPoly::draw(CShader *s){
	GLint vertLoc = glGetAttribLocation(s->GetProgram(), "Vertex");//現在リンクしているプログラムが対象
	GLint normalLoc = glGetAttribLocation(s->GetProgram(), "Normal");//現在リンクしているプログラムが対象
	GLint texLoc = glGetAttribLocation(s->GetProgram(), "TexCoord");//現在リンクしているプログラムが対象

	glBindBuffer(GL_ARRAY_BUFFER, m_buffer[0]);
	glVertexAttribPointer(vertLoc, 3, GL_FLOAT, GL_FALSE, 0, 0);
	glEnableVertexAttribArray(vertLoc);


	if (m_useNormal) {

		glBindBuffer(GL_ARRAY_BUFFER, m_buffer[1]);
		glVertexAttribPointer(normalLoc, 3, GL_FLOAT, GL_FALSE, 0, 0);
		glEnableVertexAttribArray(normalLoc);
	}

	if (m_useTex) {

		glBindBuffer(GL_ARRAY_BUFFER, m_buffer[2]);
		glVertexAttribPointer(texLoc, 2, GL_FLOAT, GL_FALSE, 0,0);
		glEnableVertexAttribArray(texLoc);
	}


	glDrawArrays(GL_TRIANGLES,0,m_vertexCnt);
	
	glDisableVertexAttribArray(vertLoc);
	glDisableVertexAttribArray(normalLoc);
	glDisableVertexAttribArray(texLoc);

	glBindBuffer(GL_ARRAY_BUFFER, 0);
	
}

bool CSPoly::rayTest(CVector3D *c, CVector3D *n, const CVector3D &s, const CVector3D &e, float *pLength){
	glBindBuffer(GL_ARRAY_BUFFER, m_buffer[0]);
	CVector3D *v = (CVector3D*)glMapBuffer(GL_ARRAY_BUFFER, GL_READ_ONLY);
	bool hit = false;
	for (int i = 0; i < m_vertexCnt; i+=3,v+=3)
	{
		if (CCollision::IntersectTriangleRay(c, s, e, v[0], v[1], v[2], pLength)){

			CVector3D e1 = v[1] - v[0];
			CVector3D e2 = v[2] - v[0];

			*n = CVector3D::Cross(e1, e2).GetNormalize();
			hit = true;
			break;
		}
	}
	glUnmapBuffer(GL_ARRAY_BUFFER);
	glBindBuffer(GL_ARRAY_BUFFER, 0);
	return hit;
	
}
int	CSPoly::sphereTest(CCollTriangle *out, const CVector3D &center, float radius, int maxcnt){
	glBindBuffer(GL_ARRAY_BUFFER, m_buffer[0]);
	CVector3D *v = (CVector3D*)glMapBuffer(GL_ARRAY_BUFFER, GL_READ_ONLY);
	int cnt = 0;
	for (int i = 0; i < m_vertexCnt; i += 3, v += 3)
	{
		float l;
		if (CCollision::CollisionTriangleSphere(v[0], v[1], v[2], center, radius,NULL,&l)){
			
			CVector3D e1 = v[1] - v[0];
			CVector3D e2 = v[2] - v[0];
			out->m_normal = CVector3D::Cross(e1, e2).GetNormalize();
			out->m_dist = l;
			out->m_vertex[0] = v[0];
			out->m_vertex[1] = v[1];
			out->m_vertex[2] = v[2];
			out++;
			cnt++;
			if (cnt >= maxcnt) break;
		}
	}
	glUnmapBuffer(GL_ARRAY_BUFFER);
	glBindBuffer(GL_ARRAY_BUFFER, 0);
	return cnt;

}
int	CSPoly::cupselTest(CCollTriangle *out, const CVector3D &top, const CVector3D &bottom, float radius, int maxcnt){
	glBindBuffer(GL_ARRAY_BUFFER, m_buffer[0]);
	CVector3D *v = (CVector3D*)glMapBuffer(GL_ARRAY_BUFFER, GL_READ_ONLY);
	int cnt = 0;
	for (int i = 0; i < m_vertexCnt; i += 3, v += 3)
	{
		float l;
		if (CCollision::CollisionTriangleCapsule(v[0], v[1], v[2], top, bottom, radius ,NULL, &l)){

			CVector3D e1 = v[1] - v[0];
			CVector3D e2 = v[2] - v[0];
			out->m_normal = CVector3D::Cross(e1, e2).GetNormalize();
			out->m_dist = l;
			out->m_vertex[0] = v[0];
			out->m_vertex[1] = v[1];
			out->m_vertex[2] = v[2];
			out++;
			cnt++;
			if (cnt >= maxcnt) break;
		}
	}
	glUnmapBuffer(GL_ARRAY_BUFFER);
	glBindBuffer(GL_ARRAY_BUFFER, 0);
	return cnt;

}

CModelSX::CModelSX() : m_poly(NULL),m_material(NULL){
}

CModelSX::~CModelSX() {
}
void CModelSX::Release() {
	delete[] m_poly;
	for (int i = 0; i < m_materialNum; i++) m_material[i].Release();
	delete[] m_material;
	delete m_shader;

}
bool CModelSX::Load(const char *filePath){
	CXSModelLoader loader(filePath);
	MakePath(loader.m_filePath);
	m_material = new CMaterial[loader.m_materialNum];
	m_materialNum = loader.m_materialNum;
	m_poly = new CSPoly[m_materialNum];
	for(int i=0;i<m_materialNum;i++) {
		CMaterial *m = &m_material[i];
		memcpy(m->m_ambient.v, &loader.m_material[i].faceColor, sizeof(float) * 4);
		memcpy(m->m_diffuse.v, &loader.m_material[i].faceColor, sizeof(float) * 4);
	
		m->m_shininess = loader.m_material[i].power;
		memcpy(m->m_emissive.v, &loader.m_material[i].emissiveColor, sizeof(float) * 3);
		memcpy(m->m_specular.v, &loader.m_material[i].specularColor, sizeof(float) * 3);
		m->m_alpha = 1.0f;
		if(loader.m_material[i].filePath[0]) {

			char str[PATH_SIZE];
			strcpy_s(str, PATH_SIZE, m_filePath);
			strcat_s(str, PATH_SIZE, loader.m_material[i].filePath);

			m->m_pTex = new CTexture();
			m->m_pTex->Load(str);
		}
		m_poly[i].create(loader,i);
	}
	m_shader = new CShader("shader\\mesh.vert","shader\\mesh.flag");
	return true;
}
void CModelSX::RenderM(CMatrix &m){
	m_shader->enable();


	glPushMatrix();
	glMultMatrixf(m.f);

	SendShaderParam(m);


	for(int i=0;i<m_materialNum;i++) {
		m_material[i].Map(m_shader);
		

		m_poly[i].draw(m_shader);
		
		m_material[i].Unmap();
	}
	m_shader->disable();
	glPopMatrix();

}

bool CModelSX::CollisionRay(CVector3D *c, CVector3D *n, const CVector3D &s, const CVector3D &e){
	CMatrix inv = m_matrix.GetInverse();
	CVector3D s2 = inv * CVector4D(s, 1);
	CVector3D e2 = inv * CVector4D(e,1);

	float length=1e10;
	for (int i = 0; i<m_materialNum; i++) {
		if (m_poly[i].rayTest(c, n, s2, e2,&length)) {
			*c = m_matrix * CVector4D(*c,1);
			*n = CVector3D(m_matrix * CVector4D(*n, 0)).GetNormalize();
			return true;
		}
	}	
	return false;
		
}

int CModelSX::CollisionSphere(CCollTriangle *out, const CVector3D &center, float radius, int maxcnt){
	float scale = CVector3D (m_matrix.m00,m_matrix.m10,m_matrix.m20).Length();
	radius = radius / scale;
	CVector3D center2 = m_matrix.GetInverse()*CVector4D(center,1);
	for (int i = 0; i<m_materialNum; i++) {
		int n = m_poly[i].sphereTest(out, center2, radius, maxcnt);
		for(int i=0;i<n;i++) {
			out[i].m_dist = out[i].m_dist * scale;
			out[i].Transform(m_matrix);
		}
		return n;
	}
	return 0;
		
}
int CModelSX::CollisionCupsel(CCollTriangle *out, const CVector3D &top, const CVector3D &bottom, float radius, int maxcnt){
	float scale = CVector3D (m_matrix.m00,m_matrix.m10,m_matrix.m20).Length();
	radius = radius / scale;
	CVector3D t = m_matrix.GetInverse() * CVector4D(top,1);
	CVector3D b = m_matrix.GetInverse() * CVector4D(bottom, 1);

	for (int i = 0; i<m_materialNum; i++) {
		int n = m_poly->cupselTest(out, t, b, radius,maxcnt);
		for(int i=0;i<n;i++) {
			out[i].m_dist = out[i].m_dist * scale;
			out[i].Transform(m_matrix);
		}
		return n;
	}
	return 0;
		
}