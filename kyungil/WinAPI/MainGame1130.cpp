#include "Stdafx.h"
#include "MainGame1130.h"

HRESULT MainGame1130::init(void)
{
    GameNode::init(TRUE);
    _j = new JeongJongha;
    _j->init();
    _k = new KimDongKyu;
    _k->init();
    _n = new SeungChan;
    _n->init();

    return S_OK;
}

void MainGame1130::release(void)
{
    GameNode::release();
    SAFE_DELETE(_j);
    SAFE_DELETE(_k);
    SAFE_DELETE(_n);
}

void MainGame1130::update(void)
{
    GameNode::update();

}

void MainGame1130::render(void)
{
    PatBlt(getMemDC(), 0, 0, WINSIZE_X, WINSIZE_Y, BLACKNESS);

    _k->render();
    _j->render();
    _n->render();

    this->getBackBuffer()->render(getHDC(), 0, 0);
}
