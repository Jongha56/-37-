#include "Stdafx.h"
#include "MainGame1130.h"
#define HW1     0

// # ���� ���� #
HINSTANCE _hInstance;
HWND _hWnd;
POINT _ptMouse = { 0, 0 };

//==================
// # �Լ� ���漱�� #
//==================
LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);
void setWindowSize(int x, int y, int width, int height);

#if HW1 == 0
MainGame1130* _mg;

#elif HW1 == 1
MainGame1129_1* _mg;

#elif HW1 == 2
MainGame1129_2* _mg;

#endif



#pragma region ������ �����Լ��� ������
/*
    hInstance : ���α׷� �ν��Ͻ� �ڵ�
    hPrevInstance : ������ ����� �ν��Ͻ� �ڵ�
    lpszCmdParam : ��������� �Էµ� ���α׷� �μ�(��)
    nCmdShow : ���α׷��� ���۵� �� ���� (�ּ�ȭ or ���� ũ�� ���..)
*/
#pragma endregion

int APIENTRY WinMain(HINSTANCE hInstance,
    HINSTANCE hPrevInstance,
    LPSTR lpszCmdParam,
    int nCmdShow)
{
#if HW1 == 0
    _mg = new MainGame1130();
#elif HW1 == 1
    _mg = new MainGame1129_1;
#elif HW1 == 2
    _mg = new MainGame1129_2;

#endif
    _hInstance = hInstance;

    WNDCLASS wndClass;
    wndClass.cbClsExtra = 0;
    wndClass.cbWndExtra = 0;
    wndClass.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
    wndClass.hCursor = LoadCursor(NULL, IDC_ARROW);
    wndClass.hIcon = LoadIcon(NULL, IDI_APPLICATION);
    wndClass.hInstance = hInstance;
    wndClass.lpfnWndProc = (WNDPROC)WndProc;
    wndClass.lpszClassName = WIN_NAME;
    wndClass.lpszMenuName = NULL;
    wndClass.style = CS_HREDRAW | CS_VREDRAW;

    //===== 11.30 �߰� =====
    //HRESULT hr;
    //hr = RegisterClass(&wndClass);
    //assert(SUCCEEDED(hr));
    //�� assert(): ���迡�� ���� ����ϴ� �Լ�
    // �ڵ带 �о���̴� �����Ϸ��� ������ �߻��ϸ� ������Ű�� �Լ�
    // �����ϸ� ������ �ȵɰ��ɼ��� ����
    // �츮 �۾��� �ڵ����� ª�⶧���� ���� �Ƚᵵ��
    //======================

    //������ Ŭ���� ���
    RegisterClass(&wndClass);

#ifdef FULL_SCREEN

    DEVMODE dm;

    ZeroMemory(&dm, sizeof(DEVMODE));
    dm.dmSize = sizeof(DEVMODE);
    dm.dmBitsPerPel = 32;
    dm.dmPelsWidth = 1980;
    dm.dmPelsHeight = 1020;
    dm.dmDisplayFrequency = 60;         // ����� 60Hz

    //�츮�� ������ �÷���(�ɼ�) �� ����
    dm.dmFields = DM_BITSPERPEL | DM_PELSWIDTH | DM_PELSHEIGHT | DM_DISPLAYFREQUENCY;

    //ȭ���� ����Ǹ� ���� �ػ󵵷� ����
    if (ChangeDisplaySettings(&dm, CDS_FULLSCREEN) != DISP_CHANGE_SUCCESSFUL) {
        ChangeDisplaySettings(&dm, 0);
    }

    _hWnd = CreateWindow
    (
        WIN_NAME,
        WIN_NAME,
        WINSTYLE,
        WINSTART_X,
        WINSTART_Y,
        WINSIZE_X,
        WINSIZE_Y,
        NULL,
        (HMENU)NULL,
        hInstance,
        NULL
    );

    //Ŭ���̾�Ʈ ������ ����� ��Ȯ�� ��´�.
    setWindowSize(WINSTART_X, WINSTART_Y, WINSIZE_X, WINSIZE_Y);

#else

    //ȭ�鿡 ������ ������ â ����
    _hWnd = CreateWindow
    (
        WIN_NAME,
        WIN_NAME,
        WINSTYLE,
        WINSTART_X,
        WINSTART_Y,
        WINSIZE_X,
        WINSIZE_Y,
        NULL,
        (HMENU)NULL,
        hInstance,
        NULL
    );

    //Ŭ���̾�Ʈ ������ ����� ��Ȯ�� ��´�.
    setWindowSize(WINSTART_X, WINSTART_Y, WINSIZE_X, WINSIZE_Y);

#endif

    //ȭ�鿡 ������ â �����ֱ�
    ShowWindow(_hWnd, nCmdShow);

    //���� ���� Ŭ���� �ʱ�ȭ ���н� ����
    if (FAILED(_mg->init())) {
        return 0;
    }

    MSG message;

    while (GetMessage(&message, 0, 0, 0))
    {
        TranslateMessage(&message);
        DispatchMessage(&message);
    }

    _mg->release();
    //������ Ŭ���� ��� ����
    UnregisterClass(WIN_NAME, hInstance);

    return message.wParam;
}

//������ ���ν���
LRESULT CALLBACK WndProc(HWND hWnd, UINT IMessage, WPARAM wParam, LPARAM lParam)
{
    return _mg->MainProc(hWnd, IMessage, wParam, lParam);
}

void setWindowSize(int x, int y, int width, int height) {
    RECT rc = { 0,0, width, height };

    //���� ������ ũ�� ����
    //AdjustWindowRect(): ��� ��ü, ����� ������ ��Ÿ��, �޴�����
    AdjustWindowRect(&rc, WINSTYLE, false);

    //���� ��Ʈ�� ������ ������ ������ ����
    SetWindowPos(_hWnd, NULL, x, y,
        (rc.right - rc.left),
        (rc.bottom - rc.top),
        SWP_NOZORDER | SWP_NOMOVE);
    //�� SWP_NOZORDER: ���Ӱ� �ſ� ������ ��ũ���Լ�
    //  �� ���������� �ڿ� �ִ� â�� ��� ó������ ���ҋ� ���
}


/*

����1. �� ��Ʈ������ ���� ����

1. 3���� �ĺ����� �߸���.
�� �帣�� ���� �ٸ��� �߷�����.

2. ������ �ĺ����� ���ӵ��� ���ҽ��� �ִ��� Ȯ���Ѵ�.
�� GDI, GDI+, D2D
�� bmp / png + ȸ�� / ��������Ҽ�����

3. �߸� �ĺ����� �м��� ���� ���� �з��� ��� ����

��> �����ֿ� ����

hint: ī�޶� ���� -> �����ϱ� ������ ��ٷο� -> ī�޶� �߿��� ������ ��������~
        �� 3D
        �� �ڵ� ���

*/