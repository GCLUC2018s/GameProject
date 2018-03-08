#include "CSound.h"

#pragma comment(lib, "dsound.lib")
#pragma comment(lib, "winmm.lib")

CSoundBase::CSoundBase():mp_secondary(nullptr), mp_3Dbuffer(nullptr), mp_wf(nullptr),current(0), layer_max(0){

}
CSoundBase::~CSoundBase() {
	Stop();
	for (int i = 0; i < layer_max; i++) {
		if (mp_secondary[i]) mp_secondary[i]->Release();
		if (mp_3Dbuffer[i]) mp_3Dbuffer[i]->Release();
	}
	if(mp_secondary) delete[] mp_secondary;
	if(mp_3Dbuffer) delete[] mp_3Dbuffer;
	if(mp_wf) free(mp_wf);
}
bool CSoundBase::Load(char* file, int layer,bool is3D)
{
	if (!CSound::GetInstance()->lpDS) return FALSE;
	HRESULT ret;
	MMCKINFO mSrcWaveFile;
	MMCKINFO mSrcWaveFmt;
	MMCKINFO mSrcWaveData;

	// WAV�t�@�C�������[�h
	HMMIO hSrc;
	hSrc = mmioOpenA((LPSTR)file, NULL, MMIO_ALLOCBUF | MMIO_READ | MMIO_COMPAT);
	if (!hSrc) {
		printf("WAV�t�@�C�����[�h�G���[\n");
		return FALSE;
	}

	// 'WAVE'�`�����N�`�F�b�N
	ZeroMemory(&mSrcWaveFile, sizeof(mSrcWaveFile));
	ret = mmioDescend(hSrc, &mSrcWaveFile, NULL, MMIO_FINDRIFF);
	if (mSrcWaveFile.fccType != mmioFOURCC('W', 'A', 'V', 'E')) {
		printf("WAVE�`�����N�`�F�b�N�G���[\n");
		mmioClose(hSrc, 0);
		return FALSE;
	}

	// 'fmt '�`�����N�`�F�b�N
	ZeroMemory(&mSrcWaveFmt, sizeof(mSrcWaveFmt));
	ret = mmioDescend(hSrc, &mSrcWaveFmt, &mSrcWaveFile, MMIO_FINDCHUNK);
	if (mSrcWaveFmt.ckid != mmioFOURCC('f', 'm', 't', ' ')) {
		printf("fmt �`�����N�`�F�b�N�G���[\n");
		mmioClose(hSrc, 0);
		return FALSE;
	}

	// �w�b�_�T�C�Y�̌v�Z
	int iSrcHeaderSize = mSrcWaveFmt.cksize;
	if (iSrcHeaderSize < sizeof(WAVEFORMATEX))
		iSrcHeaderSize = sizeof(WAVEFORMATEX);

	// �w�b�_�������m��
	mp_wf = (LPWAVEFORMATEX)malloc(iSrcHeaderSize);
	if (!mp_wf) {
		printf("�������m�ۃG���[\n");
		mmioClose(hSrc, 0);
		return FALSE;
	}
	ZeroMemory(mp_wf, iSrcHeaderSize);

	// WAVE�t�H�[�}�b�g�̃��[�h
	ret = mmioRead(hSrc, (char*)mp_wf, mSrcWaveFmt.cksize);
	if (FAILED(ret)) {
		printf("WAVE�t�H�[�}�b�g���[�h�G���[\n");
		mmioClose(hSrc, 0);
		return FALSE;
	}
	printf("�`�����l����       = %d\n", mp_wf->nChannels);
	printf("�T���v�����O���[�g = %d\n", mp_wf->nSamplesPerSec);
	printf("�r�b�g���[�g       = %d\n", mp_wf->wBitsPerSample);


	// fmt�`�����N�ɖ߂�
	mmioAscend(hSrc, &mSrcWaveFmt, 0);

	// data�`�����N��T��
	while (1) {
		// ����
		ret = mmioDescend(hSrc, &mSrcWaveData, &mSrcWaveFile, 0);
		if (FAILED(ret)) {
			printf("data�`�����N��������Ȃ�\n");
			mmioClose(hSrc, 0);
			return FALSE;
		}
		if (mSrcWaveData.ckid == mmioStringToFOURCCA("data", 0))
			break;
		// ���̃`�����N��
		ret = mmioAscend(hSrc, &mSrcWaveData, 0);
	}
	printf("�f�[�^�T�C�Y       = %d\n", mSrcWaveData.cksize);

	mp_secondary = new LPDIRECTSOUNDBUFFER[layer];
	mp_3Dbuffer = new IDirectSound3DBuffer8*[layer];
	memset(mp_3Dbuffer, 0, sizeof(IDirectSound3DBuffer8*)*layer);
	memset(mp_secondary, 0, sizeof(LPDIRECTSOUNDBUFFER)*layer);
	// �T�E���h�o�b�t�@�̍쐬
	DSBUFFERDESC dsdesc;
	ZeroMemory(&dsdesc, sizeof(DSBUFFERDESC));
	dsdesc.dwSize = sizeof(DSBUFFERDESC);
	if(is3D) dsdesc.dwFlags = DSBCAPS_CTRLFREQUENCY | DSBCAPS_CTRLVOLUME | DSBCAPS_CTRLFREQUENCY | DSBCAPS_CTRL3D;
	else dsdesc.dwFlags = DSBCAPS_CTRLFREQUENCY | DSBCAPS_CTRLVOLUME | DSBCAPS_CTRLFREQUENCY | DSBCAPS_CTRLPAN;

	dsdesc.dwBufferBytes = mSrcWaveData.cksize;
	dsdesc.lpwfxFormat = mp_wf;
	dsdesc.guid3DAlgorithm = DS3DALG_DEFAULT;
	ret = CSound::GetInstance()->lpDS->CreateSoundBuffer(&dsdesc, &mp_secondary[0], NULL);
	if (FAILED(ret)) {
		printf("�T�E���h�o�b�t�@�̍쐬�G���[ %x %d\n",ret,ret);
		mmioClose(hSrc, 0);
		return FALSE;
	}

	
	// ���b�N�J�n
	LPVOID pMem1, pMem2;
	DWORD dwSize1, dwSize2;
	ret = mp_secondary[0]->Lock(0, mSrcWaveData.cksize, &pMem1, &dwSize1, &pMem2, &dwSize2, 0);
	if (FAILED(ret)) {
		printf("���b�N���s\n");
		mmioClose(hSrc, 0);
		return FALSE;
	}
	if (is3D)
		mp_secondary[0]->QueryInterface(IID_IDirectSound3DBuffer8, (LPVOID*)&mp_3Dbuffer[0]);

	// �f�[�^��������
	mmioRead(hSrc, (char*)pMem1, dwSize1);
	mmioRead(hSrc, (char*)pMem2, dwSize2);
	
	// ���b�N����
	mp_secondary[0]->Unlock(pMem1, dwSize1, pMem2, dwSize2);
	
	for (int i = 1; i < layer; i++) {
		ret = CSound::GetInstance()->lpDS->DuplicateSoundBuffer(
			mp_secondary[0],
			&mp_secondary[i]
			);
		if (FAILED(ret)) {
			printf("�������s\n");
		}
		if (is3D)
			mp_secondary[i]->QueryInterface(IID_IDirectSound3DBuffer8, (LPVOID*)&mp_3Dbuffer[i]);
	}


	// WAV�����
	mmioClose(hSrc, 0);

	layer_max = layer;
	return true;
}
int CSoundBase::Play(bool boLoop) {
	if (layer_max == 0) return -1;
	Stop(current);
	if (boLoop) {
		mp_secondary[current]->Play(0, 0, DSBPLAY_LOOPING);
	} else {
		mp_secondary[current]->Play(0, 0, 0);

	}
	int c = current;
	current = (current + 1) % layer_max;
	return c;
}

void CSoundBase::Resume(bool boLoop, int layer) {
	if (layer_max == 0) return;
	if (boLoop) {
		mp_secondary[layer]->Play(0, 0, DSBPLAY_LOOPING);
	}
	else {
		mp_secondary[layer]->Play(0, 0, 0);
	}
}
int CSoundBase::Play3D(CVector3D pos, bool boLoop) {
	if (layer_max == 0) return -1;
	Stop(current);
	SetPos(pos, current);
	if (boLoop) {
		mp_secondary[current]->Play(0, 0, DSBPLAY_LOOPING);
	}
	else {
		mp_secondary[current]->Play(0, 0, 0);

	}
	int c = current;
	current = (current + 1) % layer_max;
	return c;
}

void CSoundBase::SetPos(CVector3D pos, int layer) {
	if (layer_max == 0) return;
	if (layer == -1) {
		for (int i = 0; i < layer_max;i++)
			if (mp_3Dbuffer[i]) mp_3Dbuffer[i]->SetPosition(-pos.x, pos.y, -pos.z, DS3D_IMMEDIATE);
	} else {
		if (mp_3Dbuffer[layer]) mp_3Dbuffer[layer]->SetPosition(-pos.x, pos.y, -pos.z, DS3D_IMMEDIATE);
	}
}
void CSoundBase::Stop(int layer){
	if (layer_max == 0) return;
	if (layer == -1) {
		for (int i = 0; i < layer_max; i++) {
			mp_secondary[i]->Stop();
			mp_secondary[i]->SetCurrentPosition(0);
		}
	} else {
		mp_secondary[layer]->Stop();
		mp_secondary[layer]->SetCurrentPosition(0);
	}
}
void CSoundBase::Pause(int layer){
	if (layer_max == 0) return;
	if (layer == -1) {
		for (int i = 0; i < layer_max; i++)
			mp_secondary[i]->Stop();
	}
	else {
		mp_secondary[layer]->Stop();
	}
}
void CSoundBase::Frequency(float ratio, int layer) {
	if (layer_max == 0) return;
	int f = (int)(mp_wf->nSamplesPerSec * ratio);
	if (f<DSBFREQUENCY_MIN || f>DSBFREQUENCY_MAX) return;
	if (layer == -1) {
		for (int i = 0; i < layer_max; i++)
			mp_secondary[i]->SetFrequency(f);
	}
	else {
		mp_secondary[layer]->SetFrequency(f);
	}
}

void CSoundBase::Volume(float volumes, int layer)
{
	if (layer_max == 0) return;
	if (volumes<0) return;
	int v = (int)((1.0f - volumes) *  DSBVOLUME_MIN);
	if (layer == -1) {
		for (int i = 0; i < layer_max; i++)
			mp_secondary[i]->SetVolume(v);
	}
	else {
		mp_secondary[layer]->SetVolume(v);
	}
}

void CSoundBase::Pan(float pan, int layer) {
	if (layer_max == 0) return;
	if (pan<-1.0f || pan>1.0f) return;
	int p = (int)(pan * DSBPAN_RIGHT);
	if (layer == -1) {
		for (int i = 0; i < layer_max; i++)
			mp_secondary[i]->SetPan(p);
	}
	else {
		mp_secondary[layer]->SetPan(p);
	}

}

bool CSoundBase::CheckEnd(int layer)
{
	HRESULT ret;
	DWORD state;
	ret = mp_secondary[layer]->GetStatus(&state);
	if (state != DSBSTATUS_PLAYING) return true;
	return false;
}


CSound*	CSound::m_instance=nullptr;

CSound::CSound():lpDS(nullptr), lpPrimary(nullptr),lpDS3DListener(nullptr){
	HRESULT ret;
	// COM�̏�����
	CoInitialize(NULL);
	// DirectSound8���쐬
	ret = DirectSoundCreate8(NULL, &lpDS, NULL);
	if (FAILED(ret)) {
		printf("�T�E���h�I�u�W�F�N�g�쐬���s\n");
		return;
	}

	// �������[�h
	ret = lpDS->SetCooperativeLevel(GL::hWnd, DSSCL_EXCLUSIVE | DSSCL_PRIORITY);
	if (FAILED(ret)) {
		printf("�������x���ݒ莸�s\n");
		return;
	}

	WAVEFORMATEX wf;

	// �v���C�}���T�E���h�o�b�t�@�̍쐬
	DSBUFFERDESC dsdesc;
	ZeroMemory(&dsdesc, sizeof(DSBUFFERDESC));
	dsdesc.dwSize = sizeof(DSBUFFERDESC);
	dsdesc.dwFlags = DSBCAPS_CTRL3D | DSBCAPS_PRIMARYBUFFER;
	dsdesc.dwBufferBytes = 0;
	dsdesc.lpwfxFormat = NULL;
	ret = lpDS->CreateSoundBuffer(&dsdesc, &lpPrimary, NULL);
	if (FAILED(ret)) {
		printf("�v���C�}���T�E���h�o�b�t�@�쐬���s\n");
		return;
	}

	// �v���C�}���o�b�t�@�̃X�e�[�^�X������
	wf.cbSize = sizeof(WAVEFORMATEX);
	wf.wFormatTag = WAVE_FORMAT_PCM;
	wf.nChannels = 2;
	wf.nSamplesPerSec = 44100;
	wf.wBitsPerSample = 16;
	wf.nBlockAlign = wf.nChannels * wf.wBitsPerSample / 8;
	wf.nAvgBytesPerSec = wf.nSamplesPerSec * wf.nBlockAlign;
	ret = lpPrimary->SetFormat(&wf);
	if (FAILED(ret)) {
		printf("�v���C�}���o�b�t�@�̃X�e�[�^�X���s\n");
		return;
	}


	ret = lpPrimary->QueryInterface(IID_IDirectSound3DListener8, (LPVOID*)&lpDS3DListener);
	if (FAILED(ret)) {
		printf("���X�i�[�擾���s\n");
		return;
	}
	
	lpDS3DListener->SetDopplerFactor(DS3D_DEFAULTDOPPLERFACTOR, DS3D_DEFERRED);
	lpDS3DListener->SetRolloffFactor(DS3D_DEFAULTROLLOFFFACTOR, DS3D_DEFERRED);
	lpDS3DListener->SetVelocity(0, 0, 0, DS3D_DEFERRED);
	lpDS3DListener->SetDistanceFactor(1.0f, DS3D_DEFERRED);
	lpDS3DListener->CommitDeferredSettings();


}
CSound::~CSound() {
	auto it = m_list.begin();
	while (it != m_list.end()) {
		if (it->second) delete it->second;
		it++;
	}
	if (lpPrimary) {
		lpPrimary->Release();
		lpPrimary = NULL;
	}

	if (lpDS) {
		lpDS->Release();
		lpDS = NULL;
	}
	// COM�̏I��
	CoUninitialize();
}

void CSound::ReleaseSound(const char * name)
{
	auto it = m_list.find(name);
	if (it == m_list.end()) return;
	if (it->second) delete it->second;
	m_list.erase(it);
}

void CSound::UpdateListener() {
	if (!lpDS3DListener) return;
}