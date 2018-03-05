#pragma once
#include <dsound.h>
#include "GL.h"
#include "CVector.h"
#include <mmsystem.h>
#include <xaudio2.h>
#include <map>
#include <thread>

class CCamera;
class CSoundBase {
	LPDIRECTSOUNDBUFFER *mp_secondary;     // �Z�J���_���T�E���h�o�b�t�@
	IDirectSound3DBuffer8** mp_3Dbuffer; // �R�c�o�b�t�@�I�u�W�F�N�g�ւ̃C���^�t�F�[�X
	LPWAVEFORMATEX mp_wf;
	int current;
	int layer_max;
public:
	CSoundBase();
	~CSoundBase();
	bool Load(char *path, int layer=1,bool is3D=false);
	int Play(bool boLoop=false);
	void Resume(bool boLoop=false,int layer=0);
	int Play3D(CVector3D pos,bool boLoop = false);
	void SetPos(CVector3D pos, int layer = -1);
	void Stop(int layer=-1);
	void Pause(int layer=-1);

	/*!
	@brief	���ʂ̐ݒ�
	@param	volumes			[in] ����(�y�ŏ��z0.0�`1.0�y�f�t�H���g�z) 
	**/
	void Volume(float volumes, int layer=-1);
	/*!
	@brief	�Đ����x�̐ݒ�
	@param	rato			[in] ���x(�y�x���z0.0�`1.0�y�f�t�H���g�z�`�y�����z)
	**/
	void Frequency(float ratio, int layer=-1);
	/*!
	@brief	�p���̐ݒ�
	@param	pan			[in] �p��(�y���z-1.0�`0.0�y���S�z�`1.0�y�E�z)
	**/
	void Pan(float pan, int layer = -1);


	bool CheckEnd(int layer = 0);
};
class CSound {
	LPDIRECTSOUND8          lpDS;     // DirectSound8
	LPDIRECTSOUNDBUFFER lpPrimary;       // �v���C�}���T�E���h�o�b�t�@
	LPDIRECTSOUND3DLISTENER8 lpDS3DListener; // ���X�i�[�I�u�W�F�N�g
	std::map<std::string, CSoundBase*> m_list;
	static CSound *m_instance;
	friend class CSoundBase;
public:
	CSound();
	~CSound();
	/*!
	@brief	�T�E���h�}�l�[�W���[�̎擾
	**/
	static CSound* GetInstance() {
		if (!m_instance) m_instance = new CSound();
		return m_instance;
	}
	static void ClearInstance() {
		if (!m_instance) return;
		delete m_instance;
		m_instance = nullptr;
	}
	/*!
	@brief	�T�E���h�I�u�W�F�N�g�̎擾
	@param	name			[in]���ʖ�
	**/
	CSoundBase* GetSound(const char *name) {
		if (!m_list[name]) m_list[name] = new CSoundBase();
		return m_list[name];
	}
	/*!
	@brief	�T�E���h�I�u�W�F�N�g�̔j��
	@param	name			[in]���ʖ�
	**/
	void ReleaseSound(const char *name);
	/*!
	@brief	���X�i�[�̍X�V
	**/
	void UpdateListener();
	/*!
	@brief	���X�i�[�̎擾
	**/
	LPDIRECTSOUND3DLISTENER8 GetListener() {
		return lpDS3DListener;
	}
};

#define SOUND(name)	CSound::GetInstance()->GetSound(name)
