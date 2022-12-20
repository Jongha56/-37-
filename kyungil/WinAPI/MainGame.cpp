#include "Stdafx.h"
#include "MainGame.h"

HRESULT MainGame::init(void)
{
    GameNode::init(TRUE);
    _j = new JeongJongha;
    _j->init();
    _k = new KimDongKyu;
    _k->init();
    _n = new SeungChan;
    _n->init();
    _p = new ParkGeonWoo;
    _p->init();

    return S_OK;
}

void MainGame::release(void)
{
    GameNode::release();
    SAFE_DELETE(_j);
    SAFE_DELETE(_k);
    SAFE_DELETE(_n);
    SAFE_DELETE(_p);
}

void MainGame::update(void)
{
    GameNode::update();

}

void MainGame::render(void)
{
    PatBlt(getMemDC(), 0, 0, WINSIZE_X, WINSIZE_Y, BLACKNESS);

    _k->render();
    _j->render();
    _n->render();
    _p->render();

    this->getBackBuffer()->render(getHDC(), 0, 0);
}
