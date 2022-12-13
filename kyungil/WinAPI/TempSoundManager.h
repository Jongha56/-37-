#pragma once
#include "SingletonBase.h"
#include <mmsystem.h>
//�� ������ ���� ��� ���̺귯��
//�� PlaySound()�� ����ϱ����� ������
#include <mciapi.h>
//�� MCI(Media Control Interface): ��ǻ�Ϳ� ������ ��Ƽ�̵�� ��ġ
//�� mciSendString()�� ����ϱ� ���� ������

#pragma comment(lib, "Winmm.lib")
//�� Window Multi Media
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

