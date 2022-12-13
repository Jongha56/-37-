#include "Stdafx.h"
#include "GameNode.h"


HRESULT GameNode::init(void)
{
	//�Լ��� ���������� ���� �Ǿ����� �˸��� S_OK
	return S_OK; //Success OK
}

HRESULT GameNode::init(bool managerInit)
{
    _hdc = GetDC(_hWnd);
    _managerInit = managerInit;
    if (managerInit) {
        //Ÿ�̸� �ʱ�ȭ
        //SetTimer(): ������ �ֱ⸶�� ������ �Լ��� �����Ű�� �Լ�
        //�� �ڵ�, Ÿ�̸� ��ȣ, Ÿ�̸� �ֱ�, �ֱ⸶�� ����� �Լ�
        SetTimer(_hWnd, 1, 10, NULL);

        //Ű�Ŵ��� �ʱ�ȭ
        KEYMANAGER->init();
        //������� �ʱ�ȭ
        RND->init();
        IMAGEMANAGER->init();
        TEMPSOUNDMANAGER->init();
    }

    return S_OK;
}

void GameNode::release(void)
{
    if (_managerInit) {
        //Ÿ�̸� ����
        //�� Ÿ�̸Ӵ� new�� ���� �������� �ʰ� �����ϸ� �޸� ���� �߻��Ѵ�.
        //�� ��� Ÿ�̸Ӵ� ����ϸ� �ݵ�� �����ؾ� �Ѵ�.
        //�� �ڵ�, Ÿ�̸� ��ȣ
        KillTimer(_hWnd, 1);

        //Ű�Ŵ��� �̱��� ����
        KEYMANAGER->releaseSingleton();
        //������� �̱��� ����
        RND->releaseSingleton();
        IMAGEMANAGER->relese();
        IMAGEMANAGER->releaseSingleton();
        TEMPSOUNDMANAGER->releaseSingleton();
    }
    ReleaseDC(_hWnd, _hdc);
}

void GameNode::update(void)
{
	//���۸� ó���� ���� Ÿ�̸Ӱ� ���� ������ �⺻ �Լ� ���
	//���� ��ħ
	InvalidateRect(_hWnd, NULL, false);
}

void GameNode::render(void)
{
	//�׷��ָ� ��ӹ޴� Ŭ�����鵵 �׸��� �׸��� �����ϱ⋚���� render�� ����ΰ� �ڽ�Ŭ�������� �ۼ��ؾ��Ѵ�.
}

LRESULT GameNode::MainProc(HWND hWnd, UINT IMessage, WPARAM wParam, LPARAM lParam)
{
    HDC hdc;
    PAINTSTRUCT ps;


    switch (IMessage)
    {
    case WM_TIMER:
        this->update();
        break;

    case WM_PAINT:
        hdc = BeginPaint(hWnd, &ps);
        //�̰��� ��¿� ���� �ڵ��� �ϸ� �ȴ�.

        this->render();

        EndPaint(hWnd, &ps);
        break;

    case WM_MOUSEMOVE:
        _ptMouse.x = LOWORD(lParam);
        _ptMouse.y = HIWORD(lParam);
        break;

    case WM_KEYDOWN:
        switch (wParam)
        {
        case VK_ESCAPE:
            PostMessage(hWnd, WM_DESTROY, 0, 0);
            break;

        defalut:
            break;
        }
        break;

    case WM_DESTROY:
        PostQuitMessage(0);
        return 0;
    }
    return (DefWindowProc(hWnd, IMessage, wParam, lParam));
}
