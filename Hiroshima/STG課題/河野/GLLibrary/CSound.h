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
	LPDIRECTSOUNDBUFFER *mp_secondary;     // セカンダリサウンドバッファ
	IDirectSound3DBuffer8** mp_3Dbuffer; // ３Ｄバッファオブジェクトへのインタフェース
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
	@brief	音量の設定
	@param	volumes			[in] 音量(【最小】0.0～1.0【デフォルト】) 
	**/
	void Volume(float volumes, int layer=-1);
	/*!
	@brief	再生速度の設定
	@param	rato			[in] 速度(【遅い】0.0～1.0【デフォルト】～【早い】)
	**/
	void Frequency(float ratio, int layer=-1);
	/*!
	@brief	パンの設定
	@param	pan			[in] パン(【左】-1.0～0.0【中心】～1.0【右】)
	**/
	void Pan(float pan, int layer = -1);


	bool CheckEnd(int layer = 0);
};
class CSound {
	LPDIRECTSOUND8          lpDS;     // DirectSound8
	LPDIRECTSOUNDBUFFER lpPrimary;       // プライマリサウンドバッファ
	LPDIRECTSOUND3DLISTENER8 lpDS3DListener; // リスナーオブジェクト
	std::map<std::string, CSoundBase*> m_list;
	static CSound *m_instance;
	friend class CSoundBase;
public:
	CSound();
	~CSound();
	/*!
	@brief	サウンドマネージャーの取得
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
	@brief	サウンドオブジェクトの取得
	@param	name			[in]識別名
	**/
	CSoundBase* GetSound(const char *name) {
		if (!m_list[name]) m_list[name] = new CSoundBase();
		return m_list[name];
	}
	/*!
	@brief	サウンドオブジェクトの破棄
	@param	name			[in]識別名
	**/
	void ReleaseSound(const char *name);
	/*!
	@brief	リスナーの更新
	**/
	void UpdateListener();
	/*!
	@brief	リスナーの取得
	**/
	LPDIRECTSOUND3DLISTENER8 GetListener() {
		return lpDS3DListener;
	}
};

#define SOUND(name)	CSound::GetInstance()->GetSound(name)
