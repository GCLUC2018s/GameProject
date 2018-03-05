#include "CSound.h"
#include "CCamera.h"
#pragma comment(lib,"winmm")
#pragma comment(lib,"XAudio2.lib")

bool CSoundBase::Load(char* path,int layer)
{
	m_layer = layer;
	m_current = 0;
	m_pSourceVoice = new IXAudio2SourceVoice*[layer];
		HMMIO hMmio=NULL;//Windows�}���`���f�B�AAPI�̃n���h��(Windows�}���`���f�B�AAPI��WAV�t�@�C���֌W�̑���p��API)
		DWORD dwWavSize=0;//WAV�t�@�C�����@WAV�f�[�^�̃T�C�Y�iWAV�t�@�C����WAV�f�[�^�Ő�߂��Ă���̂ŁA�قڃt�@�C���T�C�Y�Ɠ���j
		WAVEFORMATEX* pwfex;//WAV�̃t�H�[�}�b�g ��j16�r�b�g�A44100Hz�A�X�e���I�Ȃ�
		MMCKINFO ckInfo;//�@�`�����N���
		MMCKINFO riffckInfo;// �ŏ㕔�`�����N�iRIFF�`�����N�j�ۑ��p
		PCMWAVEFORMAT pcmWaveForm;
		//WAV�t�@�C�����̃w�b�_�[���i���f�[�^�ȊO�j�̊m�F�Ɠǂݍ���
		hMmio=mmioOpenA(path, NULL, MMIO_ALLOCBUF | MMIO_READ);
		//�t�@�C���|�C���^��RIFF�`�����N�̐擪�ɃZ�b�g����
		mmioDescend( hMmio, &riffckInfo, NULL, 0 );
		// �t�@�C���|�C���^��'f' 'm' 't' ' ' �`�����N�ɃZ�b�g����
		ckInfo.ckid = mmioFOURCC('f', 'm', 't', ' ');
		mmioDescend( hMmio, &ckInfo, &riffckInfo, MMIO_FINDCHUNK );
		//�t�H�[�}�b�g��ǂݍ���
		mmioRead( hMmio, (HPSTR) &pcmWaveForm,sizeof(pcmWaveForm));
		pwfex = (WAVEFORMATEX*)new CHAR[ sizeof(WAVEFORMATEX) ];
		memcpy( pwfex, &pcmWaveForm, sizeof(pcmWaveForm) );
		pwfex->cbSize = 0;	
		mmioAscend( hMmio, &ckInfo, 0 );
		// WAV�t�@�C�����̉��f�[�^�̓ǂݍ���	
		ckInfo.ckid = mmioFOURCC('d', 'a', 't', 'a');
		mmioDescend( hMmio, &ckInfo, &riffckInfo, MMIO_FINDCHUNK );//�f�[�^�`�����N�ɃZ�b�g
		dwWavSize = ckInfo.cksize;
		m_pWavBuffer=new BYTE[ dwWavSize ];
		DWORD dwOffset=ckInfo.dwDataOffset;
		mmioRead( hMmio, (HPSTR)m_pWavBuffer,dwWavSize);
		m_dwWavSize=dwWavSize;

	for(int i=0;i<m_layer;i++) {
		//�\�[�X�{�C�X�Ƀf�[�^���l�ߍ���	
		if(FAILED(CSound::GetInstance()->m_pXAudio2->CreateSourceVoice(&m_pSourceVoice[i],pwfex)))
		{
			MessageBox(0,L"�\�[�X�{�C�X�쐬���s",0,MB_OK);
			return FALSE;
		}
	}
	return TRUE;
}

int CSoundBase::Play(bool boLoop) {
	XAUDIO2_BUFFER buffer = { 0 };
	buffer.pAudioData = m_pWavBuffer;
	buffer.Flags = XAUDIO2_END_OF_STREAM;
	buffer.AudioBytes = m_dwWavSize;
	if (boLoop)
	{
		buffer.LoopCount = XAUDIO2_LOOP_INFINITE;
	}
	if (FAILED(m_pSourceVoice[m_current]->SubmitSourceBuffer(&buffer)))
	{
		MessageBox(0, L"�\�[�X�{�C�X�ɃT�u�~�b�g���s", 0, MB_OK);
		return -1;
	}
	int c = m_current;
	m_pSourceVoice[m_current]->Start(0, XAUDIO2_COMMIT_NOW);
	m_current = (m_current + 1) % m_layer;

	return c;

}
int CSoundBase::Play3D(CVector3D pos, bool boLoop){
	XAUDIO2_BUFFER buffer={0};
	buffer.pAudioData=m_pWavBuffer;
	buffer.Flags=XAUDIO2_END_OF_STREAM;
	buffer.AudioBytes=m_dwWavSize;
	if(boLoop)
	{
		buffer.LoopCount = XAUDIO2_LOOP_INFINITE;
	}
	if(FAILED(m_pSourceVoice[m_current]->SubmitSourceBuffer(&buffer)))
	{
		MessageBox(0,L"�\�[�X�{�C�X�ɃT�u�~�b�g���s",0,MB_OK);
		return -1;
	}
	int c=m_current;
	CVector3D vec = CCamera::GetCurrent()->GetPos() - pos;
	float volumes = 1.0f - vec.Length()/30;
	if (volumes <= 0) volumes = 0;
	m_pSourceVoice[m_current]->SetVolume(volumes, XAUDIO2_COMMIT_NOW);
	m_pSourceVoice[m_current]->Start(0,XAUDIO2_COMMIT_NOW);
	m_current = (m_current+1) % m_layer;

	return c;

}
void CSoundBase::Stop(int layer){
	if(layer == -1) {
		for(int i=0;i<m_layer;i++) {
			m_pSourceVoice[i]->Stop(0,XAUDIO2_COMMIT_NOW);
			m_pSourceVoice[i]->FlushSourceBuffers();
		}
	} else {
		m_pSourceVoice[layer]->Stop(0,XAUDIO2_COMMIT_NOW);
		m_pSourceVoice[layer]->FlushSourceBuffers();
	}
}
void CSoundBase::Pause(int layer){
	if(layer == -1) {
		for(int i=0;i<m_layer;i++) {
			m_pSourceVoice[i]->Stop(0,XAUDIO2_COMMIT_NOW);
		}
	} else {
		m_pSourceVoice[layer]->Stop(0,XAUDIO2_COMMIT_NOW);
	}
}
void CSoundBase::Ratio(float ratio, int layer) {
	if (layer == -1) {
		for (int i = 0; i<m_layer; i++) {
			m_pSourceVoice[i]->SetFrequencyRatio(ratio);
		}
	}
	else {
		m_pSourceVoice[layer]->SetFrequencyRatio(ratio);
	}
}

void CSoundBase::Volume(float volumes, int layer)
{
	if (layer == -1) {
		for (int i = 0; i<m_layer; i++) {
			m_pSourceVoice[i]->SetVolume(volumes, XAUDIO2_COMMIT_NOW);
		}
	}
	else {
		m_pSourceVoice[layer]->SetVolume(volumes, XAUDIO2_COMMIT_NOW);
	}
}

CSound*	CSound::m_instance=nullptr;

CSound::CSound(){
	CoInitializeEx(NULL,COINIT_MULTITHREADED);	

	if(FAILED(XAudio2Create(&m_pXAudio2)))
	{
		CoUninitialize();
		return;
	}
	if( FAILED(m_pXAudio2->CreateMasteringVoice(&m_pMasteringVoice)))
	{
		CoUninitialize();	
		return;
	}

}
CSound::~CSound() {
	for (auto v : m_list) {
		delete v.second;
	}
	m_list.clear();
}