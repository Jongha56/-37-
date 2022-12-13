#include "Stdafx.h"
#include "MainGame1130.h"

HRESULT MainGame1130::init(void)
{
    GameNode::init(TRUE);

    //IMAGEMANAGER->addImage("���� �����̽�", "Resources/Images/BackGround/DeadSpace.bmp", WINSIZE_X, WINSIZE_Y);
    //IMAGEMANAGER->addImage("��� ����", "Resources/Images/BackGround/Repeating_BackGround.bmp", 1570, WINSIZE_Y);

    _start = new StartScene;
    _start->init();

    _second = new SecondScene;
    _second->init();

    _hw = new HW1201;
    _hw->init();

    //�ٽ�
    _currentScene = _hw;

    assert(_currentScene != nullptr);
    //�� <-> or <!-!> : �̷������� �������Ҷ� assert�� ����� ���� ���� ǥ���ص�
    //static_assert
    /*
    �����Ҷ� 1 ~ 2 ������ ��� ��õ - �츮�� ������� ������ ���迡�� ���̻���ϱ⋚����
    �������� ���� ���
    �� ���� �ھ ����ϰ� ����ó���Ҷ��� ������� �ʴ´�
    �ڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡ�
    �� assert

    - "����� ���(������ ���)"���� �����ϴ� ���� ����� �Լ�
    �� ������ ��忡���� �������� �ʴ´�.

    - assert �Լ��� �ɸ��� �Ǹ� ���׿� �߻� ��ġ�� �� ����, �׸��� ������ ����
    �߸��� �������� �� �� �ִ�. (���α׷��Ӱ� ����ó���� ������)

    - ���۹��
    �� Expression -> false -> assert error
    
    �� ��κ��� ������ true�϶� �����ϰ� ����Ǿ������� assert�� �����϶� �����Ѵ�.
    �Ͼ�� �ȵǴ� ������ �ƴ϶� �� �Ͼ�� �ϴ� ������ ���

    EX) assert(A != NULL)
    �� A�� NULL�� �ƴϸ� true �� ������ �ǹǷ� pass
    �� A�� NULL�� �´ٸ� false �� ������ �ǹǷ� assert error


    assert()        : C���� (������ Ÿ���� ���� ���α׷��� �����Ű�� ������ �ľ�(��Ÿ��))
    static_assert() : C++���� (������ �߿� ������ �ľ� (������ Ÿ��) -> (������ Ÿ�� -> ���)
                        �� �������� ���� �ʰ� ��¹����� ���� ���
    */



    //_alphaA = 0;
    //_isAlphaIncrease = false;
    //_offsetX = _offsetY = 0;
    //_bgSpeed = 0;

    return S_OK;
}

void MainGame1130::release(void)
{
    GameNode::release();
    SAFE_DELETE(_start);
    SAFE_DELETE(_second);
    SAFE_DELETE(_hw);
}

void MainGame1130::update(void)
{
    GameNode::update();

    _currentScene->update();

    if (KEYMANAGER->isOnceKeyDown(VK_RETURN)) _currentScene = _second;
    if (KEYMANAGER->isOnceKeyDown(VK_MBUTTON)) _currentScene = _start;
    if (KEYMANAGER->isOnceKeyDown(VK_F2)) _currentScene = _hw;


    //if (KEYMANAGER->isOnceKeyDown('Q')) {
    //    if (MessageBox(_hWnd, "������ �����Ͻðڽ��ϱ�?", "����Ȯ��", MB_OKCANCEL) == IDOK)
    //    {
    //        PostQuitMessage(0);
    //    }
    //    //����� �Ͻ�����
    //    //system("pause");
    //}

    //_bgSpeed += 4;
    //if (_alphaA == 0 || _alphaA == 255) _isAlphaIncrease = !_isAlphaIncrease;
    //if (_isAlphaIncrease) _alphaA++; else _alphaA--;
}

void MainGame1130::render(void)
{
    //PatBlt(): �簢�� ������ �־��� �귯�÷� ä��� �Լ�
    PatBlt(getMemDC(), 0, 0, WINSIZE_X, WINSIZE_Y, BLACKNESS);

    //IMAGEMANAGER->alphaRender("���� �����̽�", getMemDC(), _alphaA);

    //�����
    //cout << _alphaA << endl;

    //IMAGEMANAGER->loopRender("��� ����", getMemDC(),
    //    &RectMake(0, 0, WINSIZE_X, WINSIZE_Y),
    //    _bgSpeed, 0);
    
    _currentScene->render();






    //�������� ������ HDC�� �׸���.
    this->getBackBuffer()->render(getHDC(), 0, 0);
}
