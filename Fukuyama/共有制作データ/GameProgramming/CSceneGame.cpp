#include"CSceneGame.h"
#include"CKey.h"

//�|�[�Y��ʂ̔���p
int PawsCount = 0;
void CSceneGame::Init(){
	//�e�N�X�`���ǂݍ���
	mTexture.Load("Image(kari).tga");
	mTexture2.Load("spray-icon.tga");
	m_PawsCount == 0;
	GameScene = 0;
}
void CSceneGame::Update(){
	switch (GameScene)
	{
	case 0:
		//�^�C�g�����
		mTexture2.DrawImage(-600, 600, -440, 450, 0, 90, 90, 0);
		if (GetKeyState(VK_RETURN) & 0x8000){
			//�v���C��ʂɈړ�
			GameScene = 1;
		}
		break;
	case 1:
		//�v���C���
		//�|�[�Y��ʂłȂ��ꍇ
		if (m_PawsCount == 0){
			mTexture.DrawImage(-600, 600, -440, 450, 0, 1200, 900, 0);
			if (CKey::Once('P')){
				//�|�[�Y��
				m_PawsCount = 1;
			}
		}
		else{
			if (CKey::Once('P')){
				//�|�[�Y����
				m_PawsCount = 0;
			}
			if (GetKeyState(' ') & 0x8000){
				//�^�C�g����ʂ�
				GameScene = 0;
				m_PawsCount = 0;
			}
		}
		break;

	}
}