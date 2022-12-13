#include "Stdafx.h"
#include "PixelScene.h"

HRESULT PixelScene::init(void)
{
    IMAGEMANAGER->addImage("¿ïÅüºÒÅü", "Resources/Images/BackGround/Mountain.bmp", WINSIZE_X, WINSIZE_Y, true, RGB(255,0,255));

    _pixel = new PixelCollision;
    _pixel->init();


    return S_OK;
}

void PixelScene::release(void)
{
    SAFE_DELETE(_pixel);
}

void PixelScene::update(void)
{
    _pixel->update();
}

void PixelScene::render(void)
{
    if (KEYMANAGER->isToggleKey(VK_F3)) {
        IMAGEMANAGER->findImage("¿ïÅüºÒÅü")->render(getMemDC());
    }
    _pixel->render();
}
