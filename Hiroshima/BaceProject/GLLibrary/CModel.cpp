#include "CModel.h"
#include "CLight.h"
#include "CCamera.h"

#include "CModelX.h"
#include "CModelSX.h"
#include "CModelObj.h"
//#include "CModelFbx.h"
#include "CModelField.h"


void CModel::RenderBuilbord() {
	RenderBuilbord(CCamera::GetCurrent()->GetBuilbordMatrix());
}
void CModel::UpdateMatrix() {
	CMatrix RX,RY,RZ;
	RX.RotationX(m_rot.x+m_baserot.x);
	RY.RotationY(m_rot.y+m_baserot.y);
	RZ.RotationZ(m_rot.z+m_baserot.z);
	m_rotMtx = RZ * RY * RX;
	m_transMtx.Transelate(m_pos.x,m_pos.y,m_pos.z);
	m_scaleMtx.Scale(m_scale.x,m_scale.y,m_scale.z);
	m_matrix = m_transMtx * m_rotMtx * m_scaleMtx;
}
void CModel::SendShaderParam(CMatrix &m) {
	/*
	  ライト設定
	*/
	glUniform3fv(glGetUniformLocation(m_shader->GetProgram(),"lightPos"),CLight::LIGHT_MAX,(float*)CLight::GetPosPointer());
	glUniform3fv(glGetUniformLocation(m_shader->GetProgram(),"lightDir"),CLight::LIGHT_MAX,(float*)CLight::GetDirPointer());
	glUniform3fv(glGetUniformLocation(m_shader->GetProgram(),"lightAmbientColor"),CLight::LIGHT_MAX,(float*)CLight::GetAmbientColorPointer());
	glUniform3fv(glGetUniformLocation(m_shader->GetProgram(),"lightDiffuseColor"),CLight::LIGHT_MAX,(float*)CLight::GetDiffuseColorPointer());
	glUniform1fv(glGetUniformLocation(m_shader->GetProgram(),"lightAttenuation"),CLight::LIGHT_MAX,(float*)CLight::GetAttenuationPointer());
	glUniform1fv(glGetUniformLocation(m_shader->GetProgram(),"lightRadiationAngle"),CLight::LIGHT_MAX,(float*)CLight::GetRadiationAnglePointer());
	glUniform1iv(glGetUniformLocation(m_shader->GetProgram(),"lightType"),CLight::LIGHT_MAX,(int*)CLight::GetTypeColorPointer());
	glUniform1i(glGetUniformLocation(m_shader->GetProgram(),"lighting"),CLight::GetLighting());
	const CLight::SFog& fog = CLight::GetFogParam();
	glUniform4fv(glGetUniformLocation(m_shader->GetProgram(), "fogColor"), 1, (float*)&fog.m_Color);
	glUniform1f(glGetUniformLocation(m_shader->GetProgram(), "fogNear"), fog.m_Near);
	glUniform1f(glGetUniformLocation(m_shader->GetProgram(), "fogFar"), fog.m_Far);

	
	/*
	  視線設定
	*/
	CVector3D vec=CCamera::GetCurrent()->GetDir();
	int eyeId = glGetUniformLocation(m_shader->GetProgram(),"eyeVec");  //カメラ向きを設定
	glUniform3fv(eyeId,1,(float*)&vec);
	/*
	視線設定
	*/
	CVector3D pos = CCamera::GetCurrent()->GetPos();
	int eyePosId = glGetUniformLocation(m_shader->GetProgram(), "eyePos");  //カメラ位置を設定
	glUniform3fv(eyePosId, 1, (float*)&pos);

		
	/*
	  ワールドトランスフォーム
	*/
	int worldId = glGetUniformLocation(m_shader->GetProgram(),"WorldMatrix"); 
	glUniformMatrix4fv(worldId,1,false,m.f);

	
	CMatrix mProj, mModelView;
	glGetFloatv(GL_MODELVIEW_MATRIX, mModelView.f);
	glGetFloatv(GL_PROJECTION_MATRIX, mProj.f);
	glUniformMatrix4fv(glGetUniformLocation(m_shader->GetProgram(), "ProjectionMatrix"), 1, GL_FALSE, mProj.f);
	glUniformMatrix4fv(glGetUniformLocation(m_shader->GetProgram(), "ModelViewMatrix"), 1, GL_FALSE, mModelView.f);

}

void CModel::MakePath(const char* filenPath) {
	strcpy_s(m_filePath, PATH_SIZE, filenPath);
	char* p = strrchr(m_filePath, '/');
	if(!p) p = strrchr(m_filePath, '\\');
	if (p) *(p+1) = '\0';
	else strcpy_s(m_filePath,PATH_SIZE,"");

}
CModel* CModel::CreateModel(char* path){
	CModel *m=NULL;
	char *c = strchr(path, '.')+1;
	if (strcmp(c, "x")==0) {
		FILE *fp;
		fopen_s(&fp, path, "r");
		if (!fp) return NULL;
		fclose(fp);
		char buf[256];
		fgets(buf, 255, fp);
		if (1) {
			m = new CModelX();
		} else {
			m = new CModelSX();
		}
	} else if (strcmp(c, "obj") == 0 || strcmp(c, "obb") == 0) {
		m = new CModelObj();
	} else if (strcmp(c, "fbx")==0) {
//		m = new CModelFBX();
		printf("FBXはサポート外\n");
	} else if (strcmp(c, "field") == 0) {
		m = new CModelField();
	}
	if (!m) return NULL;
	if (m->Load(path)) {
		return m;
	}
	delete m;
	return NULL;
}

CMaterial::CMaterial() : m_ambient(0, 0, 0, 0), m_diffuse(0, 0, 0, 0), m_specular(0,0,0),
							m_emissive(0, 0, 0), m_shininess(1), m_alpha(1.0f), m_st(0,0),m_pTex(NULL){

}
void CMaterial::Release(){
	if (m_pTex) {
		m_pTex->Release();
		delete m_pTex;
		m_pTex = NULL;
	}
}
void CMaterial::Map(CShader *shader){
	if (shader) {
		int AmbientId = glGetUniformLocation(shader->GetProgram(), "Ambient");
		glUniform4fv(AmbientId, 1, (GLfloat*)&m_ambient);

		int DiffuseId = glGetUniformLocation(shader->GetProgram(), "Diffuse");
		glUniform4fv(DiffuseId, 1, (GLfloat*)&m_diffuse);

		int PowId = glGetUniformLocation(shader->GetProgram(), "Pow");
		glUniform1f(PowId, m_shininess);

		int SpecularId = glGetUniformLocation(shader->GetProgram(), "Specular");
		glUniform3fv(SpecularId, 1, (GLfloat*)&m_specular);


		int EmissiveId = glGetUniformLocation(shader->GetProgram(), "Emissive");
		glUniform3fv(EmissiveId, 1, (GLfloat*)&m_emissive);
		glUniform1f(glGetUniformLocation(shader->GetProgram(), "alpha"), m_alpha);
		if (m_pTex) {
			glUniform1i(glGetUniformLocation(shader->GetProgram(), "uSetex"), 1);
			glUniform2fv(glGetUniformLocation(shader->GetProgram(), "stscroll"), 1, m_st.v);
			m_pTex->MapTexture();
		}
		else {
			glUniform1i(glGetUniformLocation(shader->GetProgram(), "uSetex"), 0);
		}
		GLint samplerId = glGetUniformLocation(shader->GetProgram(), "sampler");
		glUniform1i(samplerId, 0);//GL_TEXTURE0を適用

		glUniformMatrix4fv(glGetUniformLocation(shader->GetProgram(), "ShadowTextureMatrix"), 1, FALSE, CLight::m_shadowMatrix.f);
		glUniform1i(glGetUniformLocation(shader->GetProgram(), "depth_tex"), 7);
		glUniform1f(glGetUniformLocation(shader->GetProgram(), "shadow_ambient"), 0.7f);

	} else {
		glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, (GLfloat*)&m_ambient);
		glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, (GLfloat*)&m_diffuse);
		glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, (GLfloat*)&m_specular);
		if (m_pTex) {
			m_pTex->MapTexture();
		}
	}



}
void CMaterial::Unmap(){
	if (m_pTex) {
		m_pTex->UnmapTexture();
	}
}
