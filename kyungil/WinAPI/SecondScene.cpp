#include "Stdafx.h"
#include "SecondScene.h"

HRESULT SecondScene::init(void)
{
	IMAGEMANAGER->addImage("배경루프", "Resources/Images/BackGround/Repeating_BackGround.bmp", 1570, WINSIZE_Y);

	_offsetX = _offsetY = 0;
	_bgSpeed = 0;

	_ps = new PixelScene;
	_ps->init();

	_tempSound = new TempSoundScene;
	_tempSound->init();

	return S_OK;
}

void SecondScene::release(void)
{
	_ps->release();
	SAFE_DELETE(_tempSound);
}

void SecondScene::update(void)
{
	_bgSpeed += 3;
	_ps->update();
	_tempSound->update();
}

void SecondScene::render(void)
{
	IMAGEMANAGER->loopRender("배경루프", getMemDC(),
		&RectMake(0, 0, WINSIZE_X, WINSIZE_Y), _bgSpeed, 0);

	//SetBkMode(): 투명하게 해주는 함수
	//ㄴ 글자 뒤로 배경이 보이게 한다.
	SetBkMode(getMemDC(), TRANSPARENT);

	char str[128];
	wsprintf(str, "기존 폰트");
	TextOut(getMemDC(), 230, 350, str, strlen(str));

	HFONT font;
	HFONT oldFont;
	//ㄴ H~ 가 붙으면 그려줄놈이랑 지워줄 놈이 필요

	/*
	font = CreateFont
	(
	1. 문자크기, 문자폭, 문자 기울기, 문자 방향, 문자 굵기, 
	기울기(true, false), 밑줄, 취소선, 
	2. 문자 세팅, 출력 정확도, 클리핑 정확도, 출력의 질, 자간, 3. 폰트		
	)
	게임에서는 1, 2, 3 번만 주로 사용
	*/

	font = CreateFont
	(
		70, 0, 0, 0, 600,
		0, 0, 1,
		HANGUL_CHARSET, 0, 0, 0, 0, TEXT("휴먼굴림")
	);
	//HANGUL_CHARSET - 멀티바이트
	//HANGUEL_CHARSET - 유니코드

	oldFont = (HFONT)SelectObject(getMemDC(), font);

	wsprintf(str, "새로운 폰트");
	TextOut(getMemDC(), 100, 400, str, strlen(str));

	SelectObject(getMemDC(), oldFont);
	DeleteObject(font);

	_ps->render();

}

/*
과제 1. 폰트 매니저 완성

- 3개의 함수 원형을 건들지 않고 (추가 x, 변수 x) 기능 구현을 한다.
- 출력되는 문장의 종류는 3가지
ㄴ 1. 전체 버퍼를 읽어 들여서 바로 출력되는 방식
ㄴ 2. 하나씩 버퍼를 읽어 들여서 출력하는 방식
ㄴ 3. 스킵 기능이 들어간 출력 방식

※ 편의성 + 호환성


과제 2. 캐릭터 공격 및 방어

- 필수: 이미지 (배경, 체력 바, 플레이어 (대기, 공격, 방어), 적 (대기, 공격, 피격))
- 기본형식은 대전게임처럼 배치 (+ 체력바)
- 플레이어 (1p) 는 공격 및 방어를 할 수 있고 적은 허수아비로 설정한다.
ㄴ 허수아비는 공격 및 피격 모션이 존재한다.(+ 대기)
- 플레이어는 상시 조종 <-> 적은 공격 On / Off 기능만 (이동 x)
- 공격, 방어, 피격 등이 발생하면 상황에 맞는 결과를 화면에 렌더링
ㄴ 막기, 빗나감, 치명타 등
- 데미지도 표기한다.
*/