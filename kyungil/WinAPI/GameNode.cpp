#include "Stdafx.h"
#include "GameNode.h"


HRESULT GameNode::init(void)
{
	//함수가 성공적으로 실행 되었음을 알리는 S_OK
	return S_OK; //Success OK
}

HRESULT GameNode::init(bool managerInit)
{
    _hdc = GetDC(_hWnd);
    _managerInit = managerInit;
    if (managerInit) {
        //타이머 초기화
        //SetTimer(): 일정한 주기마다 정해진 함수를 실행시키는 함수
        //ㄴ 핸들, 타이머 번호, 타이머 주기, 주기마다 실행될 함수
        SetTimer(_hWnd, 1, 10, NULL);

        //키매니저 초기화
        KEYMANAGER->init();
        //랜덤펑션 초기화
        RND->init();
        IMAGEMANAGER->init();
        TEMPSOUNDMANAGER->init();
    }

    return S_OK;
}

void GameNode::release(void)
{
    if (_managerInit) {
        //타이머 해제
        //ㄴ 타이머는 new와 같이 삭제하지 않고 종료하면 메모리 릭이 발생한다.
        //ㄴ 고로 타이머는 사용하면 반드시 삭제해야 한다.
        //ㄴ 핸들, 타이머 번호
        KillTimer(_hWnd, 1);

        //키매니저 싱글톤 해제
        KEYMANAGER->releaseSingleton();
        //랜덤펑션 싱글톤 해제
        RND->releaseSingleton();
        IMAGEMANAGER->relese();
        IMAGEMANAGER->releaseSingleton();
        TEMPSOUNDMANAGER->releaseSingleton();
    }
    ReleaseDC(_hWnd, _hdc);
}

void GameNode::update(void)
{
	//버퍼링 처리와 고성능 타이머가 없기 때문에 기본 함수 사용
	//새로 고침
	InvalidateRect(_hWnd, NULL, false);
}

void GameNode::render(void)
{
	//그려주면 상속받는 클래스들도 그림을 그리고 시작하기떄문에 render는 비워두고 자식클래스에서 작성해야한다.
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
        //이곳에 출력에 관한 코딩을 하면 된다.

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
