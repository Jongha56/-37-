#include "Stdafx.h"
#include "MainGame1130.h"

HRESULT MainGame1130::init(void)
{
    GameNode::init(TRUE);
    _j = new JeongJongha;
    _j->init();

    return S_OK;
}

void MainGame1130::release(void)
{
    GameNode::release();
    SAFE_DELETE(_j);
}

void MainGame1130::update(void)
{
    GameNode::update();

}

void MainGame1130::render(void)
{
    PatBlt(getMemDC(), 0, 0, WINSIZE_X, WINSIZE_Y, BLACKNESS);

    _j->render();

    this->getBackBuffer()->render(getHDC(), 0, 0);
}
