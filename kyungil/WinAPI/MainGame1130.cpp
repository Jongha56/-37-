#include "Stdafx.h"
#include "MainGame1130.h"

HRESULT MainGame1130::init(void)
{
    GameNode::init(TRUE);

    //IMAGEMANAGER->addImage("데드 스페이스", "Resources/Images/BackGround/DeadSpace.bmp", WINSIZE_X, WINSIZE_Y);
    //IMAGEMANAGER->addImage("배경 루프", "Resources/Images/BackGround/Repeating_BackGround.bmp", 1570, WINSIZE_Y);

    _start = new StartScene;
    _start->init();

    _second = new SecondScene;
    _second->init();

    _hw = new HW1201;
    _hw->init();

    //핵심
    _currentScene = _hw;

    assert(_currentScene != nullptr);
    //ㄴ <-> or <!-!> : 이런식으로 협업을할때 assert를 사용한 것을 따로 표시해둠
    //static_assert
    /*
    포폴할때 1 ~ 2 번정도 사용 추천 - 우리는 사용하지 않지만 업계에서 많이사용하기떄문에
    면접에서 많이 물어봄
    ㄴ 보통 코어에 사용하고 예외처리할때는 사용하지 않는다
    ★★★★★★★★★★★★★★★★★
    ▶ assert

    - "디버깅 모드(개발자 모드)"에서 동작하는 오류 검출용 함수
    ㄴ 릴리즈 모드에서는 동작하지 않는다.

    - assert 함수가 걸리게 되면 버그에 발생 위치와 콜 스택, 그리고 변수에 대한
    잘못된 참조값을 볼 수 있다. (프로그래머가 예외처리를 했으면)

    - 동작방식
    ㄴ Expression -> false -> assert error
    
    ※ 대부분의 문법이 true일때 동작하게 설계되어있지만 assert는 거짓일때 동작한다.
    일어나면 안되는 조건이 아니라 꼭 일어나야 하는 조건을 명시

    EX) assert(A != NULL)
    ㄴ A가 NULL이 아니면 true 가 나오게 되므로 pass
    ㄴ A가 NULL이 맞다면 false 가 나오게 되므로 assert error


    assert()        : C문법 (컴파일 타임을 지나 프로그램을 실행시키고 문제를 파악(런타임))
    static_assert() : C++문법 (컴파일 중에 문제를 파악 (컴파일 타임) -> (컴파일 타임 -> 상수)
                        ㄴ 컴파일이 되지 않고 출력문구에 오류 출력
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
    //    if (MessageBox(_hWnd, "게임을 종료하시겠습니까?", "종료확인", MB_OKCANCEL) == IDOK)
    //    {
    //        PostQuitMessage(0);
    //    }
    //    //디버깅 일시정지
    //    //system("pause");
    //}

    //_bgSpeed += 4;
    //if (_alphaA == 0 || _alphaA == 255) _isAlphaIncrease = !_isAlphaIncrease;
    //if (_isAlphaIncrease) _alphaA++; else _alphaA--;
}

void MainGame1130::render(void)
{
    //PatBlt(): 사각형 영역에 주어진 브러시로 채우는 함수
    PatBlt(getMemDC(), 0, 0, WINSIZE_X, WINSIZE_Y, BLACKNESS);

    //IMAGEMANAGER->alphaRender("데드 스페이스", getMemDC(), _alphaA);

    //디버깅
    //cout << _alphaA << endl;

    //IMAGEMANAGER->loopRender("배경 루프", getMemDC(),
    //    &RectMake(0, 0, WINSIZE_X, WINSIZE_Y),
    //    _bgSpeed, 0);
    
    _currentScene->render();






    //벡버퍼의 내용을 HDC에 그린다.
    this->getBackBuffer()->render(getHDC(), 0, 0);
}
