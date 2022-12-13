#pragma once
#include "SingletonBase.h"
#include <mmsystem.h>
//ㄴ 윈도우 내장 재생 라이브러리
//ㄴ PlaySound()를 사용하기위해 가져옴
#include <mciapi.h>
//ㄴ MCI(Media Control Interface): 컴퓨터에 장착된 멀티미디어 장치
//ㄴ mciSendString()를 사용하기 위해 가져옴

#pragma comment(lib, "Winmm.lib")
//ㄴ Window Multi Media
class TempSoundManager : public SingletonBase <TempSoundManager>
{
public:
	HRESULT init();

	void addMp3FileWithKey(string key, string fileName);
	void addWaveFileWithKey(string key, string fileName);
	void playEffectSoundWave(char* fileName);
	void playSoundWithKey(string key);
	void stopMp3WithKey(string key);

	TempSoundManager() {}
	~TempSoundManager() {}

};

