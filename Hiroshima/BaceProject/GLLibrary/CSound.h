#pragma once
#include "GL.h"
#include "CVector.h"
#include <mmsystem.h>
#include <xaudio2.h>
#include <map>
class CSoundBase {
	int	m_layer;
	int m_current;
	IXAudio2SourceVoice** m_pSourceVoice;
	BYTE* m_pWavBuffer;//波形データ（フォーマット等を含まない、純粋に波形データのみ）
	DWORD m_dwWavSize;//波形データのサイズ

public:
	bool Load(char *path,int layer);
	int Play(bool boLoop=false);
	int Play3D(CVector3D pos,bool boLoop = false);
	void Stop(int layer=-1);
	void Pause(int layer = -1);
	void Volume(float volumes, int layer=-1);
	void Ratio(float ratio, int layer = -1);
};
class CSound {
	std::map<std::string,CSoundBase*> m_list;
	IXAudio2* m_pXAudio2;
	IXAudio2MasteringVoice* m_pMasteringVoice;
	static CSound *m_instance;
	friend class CSoundBase;
public:
	CSound();
	~CSound();
	static CSound* GetInstance() {
		if (!m_instance) m_instance = new CSound();
		return m_instance;
	}
	static void ClearInstance() {
		if (!m_instance) return;
		delete m_instance;
		m_instance = nullptr;
	}
	CSoundBase* GetSound(char *name) {
		if (!m_list[name]) m_list[name] = new CSoundBase();
		return m_list[name];
	}
};

