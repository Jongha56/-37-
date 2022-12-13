#include "Stdafx.h"
#include "MainGame1130.h"

HRESULT MainGame1130::init(void)
{
    GameNode::init(TRUE);


    return S_OK;
}

void MainGame1130::release(void)
{
    GameNode::release();
}

void MainGame1130::update(void)
{
    GameNode::update();

}

void MainGame1130::render(void)
{
    PatBlt(getMemDC(), 0, 0, WINSIZE_X, WINSIZE_Y, BLACKNESS);


    this->getBackBuffer()->render(getHDC(), 0, 0);
}
