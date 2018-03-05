#include "CShadow.h"

CShadow *CShadow::m_shadow=nullptr;

CShadow::CShadow(int screenWidth, int screenHeight,float length,int texWidth, int texHeight): m_state(eNone) {
	
	m_screenWidth = screenWidth;
	m_screenHeight = screenHeight;
	m_texHeight = texHeight;
	m_texWidth = texWidth;
	m_length = length;

	glActiveTexture(GL_TEXTURE0);

	// �J���[�o�b�t�@�p�̃e�N�X�`����p�ӂ���
	glGenTextures(1, &m_effectBuffer);
	glBindTexture(GL_TEXTURE_2D, m_effectBuffer);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, m_screenWidth, m_screenHeight, 0, GL_RGBA, GL_UNSIGNED_BYTE, 0);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glBindTexture(GL_TEXTURE_2D, 0);

	// �f�v�X�o�b�t�@�p�̃����_�[�o�b�t�@��p�ӂ���
	glGenRenderbuffersEXT(1, &m_depthrenderbuffer);
	glBindRenderbufferEXT(GL_RENDERBUFFER_EXT, m_depthrenderbuffer);
	glRenderbufferStorageEXT(GL_RENDERBUFFER_EXT, GL_DEPTH_COMPONENT, m_screenWidth, m_screenHeight);
	glBindRenderbufferEXT(GL_RENDERBUFFER_EXT, 0);

	// �t���[���o�b�t�@�I�u�W�F�N�g���쐬����
	glGenFramebuffersEXT(1, &m_effectFrameBuffer);
	glBindFramebufferEXT(GL_FRAMEBUFFER_EXT, m_effectFrameBuffer);

	// �t���[���o�b�t�@�I�u�W�F�N�g�ɃJ���[�o�b�t�@�Ƃ��ăe�N�X�`������������
	glFramebufferTexture2DEXT(GL_FRAMEBUFFER_EXT, GL_COLOR_ATTACHMENT0_EXT, GL_TEXTURE_2D, m_effectBuffer, 0);

	// �t���[���o�b�t�@�I�u�W�F�N�g�Ƀf�v�X�o�b�t�@�Ƃ��ă����_�[�o�b�t�@����������
	glFramebufferRenderbufferEXT(GL_FRAMEBUFFER_EXT, GL_DEPTH_ATTACHMENT_EXT, GL_RENDERBUFFER_EXT, m_depthrenderbuffer);


	glGenTextures(1, &m_edgeBuffer);
	glBindTexture(GL_TEXTURE_2D, m_edgeBuffer);

	glTexImage2D(GL_TEXTURE_2D, 0, GL_DEPTH_COMPONENT, m_screenWidth, m_screenHeight, 0,
		GL_DEPTH_COMPONENT, GL_UNSIGNED_BYTE, 0);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP);


	glFramebufferTexture2DEXT(GL_FRAMEBUFFER, GL_DEPTH_ATTACHMENT_EXT,
		GL_TEXTURE_2D, m_edgeBuffer, 0);


	glBindFramebufferEXT(GL_FRAMEBUFFER, m_edgeBuffer);


	// �t���[���o�b�t�@�I�u�W�F�N�g�̌�������������
	glBindFramebufferEXT(GL_FRAMEBUFFER_EXT, 0);
	glBindTexture(GL_TEXTURE_2D, 0);

	



	// �V�F�[�_�v���O�����̍쐬
	m_effectShader = new CShader("shader/effect.vert", "shader/effect.frag");
	m_noeffectShader = new CShader("shader/effect.vert", "shader/noeffect.frag");
	m_depthShader = new CShader("shader/showdepth.vert", "shader/showdepth.frag");



	
	glGenTextures(1, &m_texBuffer);
	//�[�x�o�b�t�@�i�[�p�e�N�X�`���[���쐬

	glActiveTexture(GL_TEXTURE7);
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, m_texBuffer);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_BORDER);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_BORDER);
	static const GLfloat border[] = { 1.0, 1.0, 1.0, 1.0 };
	glTexParameterfv(GL_TEXTURE_2D, GL_TEXTURE_BORDER_COLOR, border);

	glTexImage2D(GL_TEXTURE_2D, 0, GL_DEPTH_COMPONENT, m_texWidth, m_texHeight, 0,
		GL_DEPTH_COMPONENT, GL_UNSIGNED_BYTE, 0);

	//�t���[���o�b�t�@���쐬
	glGenFramebuffers(1, &m_frameBuffer);
	glBindFramebuffer(GL_FRAMEBUFFER, m_frameBuffer);
	glClearDepth(1.0f);

	//�t���[���o�b�t�@�̐[�x�o�b�t�@���e�N�X�`���[��
	glFramebufferTexture2D(GL_FRAMEBUFFER, GL_DEPTH_ATTACHMENT, GL_TEXTURE_2D, m_texBuffer, 0);

	glBindFramebuffer(GL_FRAMEBUFFER, 0);
	glBindTexture(GL_TEXTURE_2D, 0);
	glActiveTexture(GL_TEXTURE0);

}
CShadow::~CShadow() {
	glDeleteFramebuffers(1,&m_frameBuffer);
	glDeleteTextures(1,&m_texBuffer);

	glDeleteTextures(1, &m_edgeBuffer);

	glDeleteFramebuffers(1, &m_effectFrameBuffer);
	glDeleteTextures(1, &m_effectBuffer);

	glDeleteRenderbuffers(1, &m_depthrenderbuffer);

	delete m_depthShader;
	delete m_effectShader;
	delete m_noeffectShader;
}
void CShadow::Render(std::function<void()> render,bool shadow,bool autoCamera, bool edge, bool effect,bool clear) {
	GLint viewport[4];
	glGetIntegerv(GL_VIEWPORT, viewport);

	if (shadow) {
		if (autoCamera) AutoCamera();
		glPushAttrib(GL_ALL_ATTRIB_BITS);

		//��������̃����_�����O
		glMatrixMode(GL_PROJECTION);
		glPushMatrix();
		glLoadMatrixf(m_lightProj.f);
		glMatrixMode(GL_MODELVIEW);
		glPushMatrix();
		glLoadMatrixf(m_lightView.f);

		glViewport(0, 0, m_texWidth, m_texHeight);

		glBindFramebuffer(GL_FRAMEBUFFER, m_frameBuffer);

		if (clear) glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		// �J���[����
		glColorMask(GL_FALSE, GL_FALSE, GL_FALSE, GL_FALSE);
		//���C�e�B���O����
		glDisable(GL_LIGHTING);
		CLight::SetLighting(false);

		//�O�ʃJ�����O
		glCullFace(GL_FRONT);
		m_state = eShadow;
		render();


		glEnable(GL_TEXTURE_2D);
		// �e�N�X�`�����[�h�Ɉڍs
		glMatrixMode(GL_TEXTURE);
		glActiveTexture(GL_TEXTURE7);



		static  const CMatrix texMat(0.5f, 0.0f, 0.0f, 0.5f,
			0.0f, 0.5f, 0.0f, 0.5f,
			0.0f, 0.0f, 0.5f, 0.5f,
			0.0f, 0.0f, 0.0f, 1.0f);
		CLight::m_shadowMatrix = texMat * m_lightProj*m_lightView *
			CCamera::GetCurrent()->GetMatrix().GetInverse();

		glLoadMatrixf(CLight::m_shadowMatrix.f);

		// �t���[���o�b�t�@�I�u�W�F�N�g����������
		glBindFramebufferEXT(GL_FRAMEBUFFER_EXT, m_effectFrameBuffer);
		//glBindFramebuffer(GL_FRAMEBUFFER, 0);
		glViewport(viewport[0], viewport[1], viewport[2], viewport[3]);
		// �J���[�o�b�t�@�ƃf�v�X�o�b�t�@���N���A
		if (clear)  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		glColorMask(GL_TRUE, GL_TRUE, GL_TRUE, GL_TRUE);
		glCullFace(GL_BACK);
		m_state = eDisplay;
		CLight::SetLighting(true);

		glPopAttrib();

		//�ʏ탌���_�����O
		glMatrixMode(GL_PROJECTION);
		glPopMatrix();
		glMatrixMode(GL_MODELVIEW);
		glPopMatrix();

		glActiveTexture(GL_TEXTURE7);
		glBindTexture(GL_TEXTURE_2D, m_texBuffer);

		glActiveTexture(GL_TEXTURE0);
		render();
		glActiveTexture(GL_TEXTURE7);
		glBindTexture(GL_TEXTURE_2D, 0);
		glActiveTexture(GL_TEXTURE0);
		glFlush();
	} else {
		// �t���[���o�b�t�@�I�u�W�F�N�g����������
		glBindFramebufferEXT(GL_FRAMEBUFFER_EXT, m_effectFrameBuffer);
		// �J���[�o�b�t�@�ƃf�v�X�o�b�t�@���N���A
		if(clear) glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		render();
		glFlush();
	}

	// �t���[���o�b�t�@�I�u�W�F�N�g�̌�������������
	glBindFramebufferEXT(GL_FRAMEBUFFER_EXT, 0);
	glViewport(0,0, m_screenWidth, m_screenHeight);
	// �A�e�t���ƉB�ʏ��������͍s��Ȃ�
	glDisable(GL_LIGHTING);
	glDisable(GL_DEPTH_TEST);
	CShader *s = effect ? m_effectShader : m_noeffectShader;
	// �e�N�X�`���}�b�s���O��L���ɂ���
	glBindTexture(GL_TEXTURE_2D, m_effectBuffer);
	glEnable(GL_TEXTURE_2D);
	s->enable();
	glUniform1i(glGetUniformLocation(s->GetProgram(), "tDiffuse"), 0);
	/* �S��ʂɎl�p�`��`�� */
	glBegin(GL_QUADS);
	glVertex2d(0.0, 0.0);
	glVertex2d(1.0, 0.0);
	glVertex2d(1.0, 1.0);
	glVertex2d(0.0, 1.0);
	glEnd();
	s->disable();


	if (edge) {

		/* �e�N�X�`���I�u�W�F�N�g���������� */
		glBindTexture(GL_TEXTURE_2D, m_edgeBuffer);
		m_depthShader->enable();
		glUniform1i(glGetUniformLocation(m_depthShader->GetProgram(), "depth"), 0);
		glUniform2f(glGetUniformLocation(m_depthShader->GetProgram(), "vScreenSize"), viewport[2], viewport[3]);
		/* �S��ʂɎl�p�`��`�� */
		glBegin(GL_QUADS);
		glVertex2d(0.0, 0.0);
		glVertex2d(1.0, 0.0);
		glVertex2d(1.0, 1.0);
		glVertex2d(0.0, 1.0);
		glEnd();
		m_depthShader->disable();
	}

	// �e�N�X�`���}�b�s���O�𖳌��ɂ���
	glDisable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, 0);
	glBindFramebuffer(GL_FRAMEBUFFER, 0);
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_LIGHTING);
	m_state = eNone;
}

void CShadow::DrawDepthTex(int w, int h)
{
	//glUseProgram(0);
	glMatrixMode(GL_PROJECTION);
	glPushMatrix();
	glLoadIdentity();
	glOrtho(0, w, 0, h, -1, 1);
	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();
	glLoadIdentity();

	glDisable(GL_LIGHTING);
	glColor4f(1, 1, 1, 1);
	glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_2D, m_texBuffer);
	glEnable(GL_TEXTURE_2D);

	glNormal3d(0, 0, -1);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0); glVertex3f(0.05*w, 0.05*h, 0);
	glTexCoord2d(1, 0); glVertex3f(0.05*w + 150, 0.05*h, 0);
	glTexCoord2d(1, 1); glVertex3f(0.05*w + 150, 0.05*h + 150, 0);
	glTexCoord2d(0, 1); glVertex3f(0.05*w, 0.05*h + 150, 0);
	glEnd();
	glBindTexture(GL_TEXTURE_2D, 0);
	glDisable(GL_TEXTURE_2D);
	glMatrixMode(GL_PROJECTION);
	glPopMatrix();
	glMatrixMode(GL_MODELVIEW);
	glPopMatrix();
}
void CShadow::AutoCamera() {
	CVector3D d = CCamera::GetCurrent()->GetDir();
	CVector3D ld = CCamera::GetCurrent()->GetPos() + CCamera::GetCurrent()->GetDir() * m_length;
	ld.y = 0;
	CVector3D lp = ld - CLight::GetDirPointer()[0] * m_length/2;
	CMatrix mProj, mView;
	mProj.Ortho(-m_length, m_length, -m_length, m_length, 0.05f, m_length*5);
	mView.LookAtView(lp, ld, CVector3D(0, 1, 0));
	SetLightProjectionMatrix(mProj);
	SetLightViewMatrix(mView);
}