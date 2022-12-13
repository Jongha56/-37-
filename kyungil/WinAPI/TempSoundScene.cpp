#include "Stdafx.h"
#include "TempSoundScene.h"

// mp3, wave
HRESULT TempSoundScene::init(void)
{
    TEMPSOUNDMANAGER->addMp3FileWithKey("����", "Resources/Sounds/endingBgm_01.mp3");




    return S_OK;
}

void TempSoundScene::update()
{
    if (KEYMANAGER->isOnceKeyDown('P')) {
        TEMPSOUNDMANAGER->playSoundWithKey("����");
    }
    if (KEYMANAGER->isOnceKeyDown('A')) {
        TEMPSOUNDMANAGER->playEffectSoundWave("Resources/Sounds/endingBgm.wav");
    }
}
