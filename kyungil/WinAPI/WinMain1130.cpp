#include "Stdafx.h"
#include "MainGame1130.h"
#define HW1     0

// # 전역 변수 #
HINSTANCE _hInstance;
HWND _hWnd;
POINT _ptMouse = { 0, 0 };

//==================
// # 함수 전방선언 #
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



#pragma region 윈도우 메인함수의 변수들
/*
    hInstance : 프로그램 인스턴스 핸들
    hPrevInstance : 이전에 실행된 인스턴스 핸들
    lpszCmdParam : 명령형으로 입력된 프로그램 인수(자)
    nCmdShow : 프로그램이 시작될 때 형태 (최소화 or 보통 크기 등등..)
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

    //===== 11.30 추가 =====
    //HRESULT hr;
    //hr = RegisterClass(&wndClass);
    //assert(SUCCEEDED(hr));
    //ㄴ assert(): 업계에서 많이 사용하는 함수
    // 코드를 읽어들이는 컴파일러를 오류가 발생하면 중지시키는 함수
    // 남발하면 실행이 안될가능성이 있음
    // 우리 작업은 코드줄이 짧기때문에 따로 안써도됨
    //======================

    //윈도우 클래스 등록
    RegisterClass(&wndClass);

#ifdef FULL_SCREEN

    DEVMODE dm;

    ZeroMemory(&dm, sizeof(DEVMODE));
    dm.dmSize = sizeof(DEVMODE);
    dm.dmBitsPerPel = 32;
    dm.dmPelsWidth = 1980;
    dm.dmPelsHeight = 1020;
    dm.dmDisplayFrequency = 60;         // 재생빈도 60Hz

    //우리가 설정한 플래그(옵션) 값 설정
    dm.dmFields = DM_BITSPERPEL | DM_PELSWIDTH | DM_PELSHEIGHT | DM_DISPLAYFREQUENCY;

    //화면이 종료되면 원래 해상도로 복귀
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

    //클라이언트 영역의 사이즈를 정확히 잡는다.
    setWindowSize(WINSTART_X, WINSTART_Y, WINSIZE_X, WINSIZE_Y);

#else

    //화면에 보여줄 윈도우 창 생성
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

    //클라이언트 영역의 사이즈를 정확히 잡는다.
    setWindowSize(WINSTART_X, WINSTART_Y, WINSIZE_X, WINSIZE_Y);

#endif

    //화면에 윈도우 창 보여주기
    ShowWindow(_hWnd, nCmdShow);

    //메인 게임 클래스 초기화 실패시 종료
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
    //윈도우 클래스 등록 해제
    UnregisterClass(WIN_NAME, hInstance);

    return message.wParam;
}

//윈도우 프로시저
LRESULT CALLBACK WndProc(HWND hWnd, UINT IMessage, WPARAM wParam, LPARAM lParam)
{
    return _mg->MainProc(hWnd, IMessage, wParam, lParam);
}

void setWindowSize(int x, int y, int width, int height) {
    RECT rc = { 0,0, width, height };

    //실제 윈도우 크기 조정
    //AdjustWindowRect(): 대상 객체, 사용할 윈도우 스타일, 메뉴여부
    AdjustWindowRect(&rc, WINSTYLE, false);

    //얻어온 렉트의 정보로 윈도우 사이즈 셋팅
    SetWindowPos(_hWnd, NULL, x, y,
        (rc.right - rc.left),
        (rc.bottom - rc.top),
        SWP_NOZORDER | SWP_NOMOVE);
    //ㄴ SWP_NOZORDER: 게임과 매우 인접한 매크로함수
    //  ㄴ 겹쳐졌을때 뒤에 있는 창을 어떻게 처리할지 정할떄 사용
}


/*

과제1. ★ 포트폴리오 예비 선정

1. 3개의 후보군을 추린다.
ㄴ 장르는 전부 다르게 추려낸다.

2. 선정된 후보군의 게임들의 리소스가 있는지 확인한다.
ㄴ GDI, GDI+, D2D
ㄴ bmp / png + 회전 / 아직사용할수없음

3. 추린 후보군을 분석해 내가 만들 분량과 기능 구상

ㄴ> 다음주에 제출

hint: 카메라 조심 -> 구현하기 굉장히 까다로움 -> 카메라가 중요한 게임은 하지말자~
        ㄴ 3D
        ㄴ 코드 덩어리

*/