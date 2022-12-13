#pragma once
//경고무시 - 4005: DXGI 등 그래픽 인터페이스에서 매크로 관련하여 많이 출력되는 경고
#pragma warning(disable : 4005)

//! 블랜드를 사용하기 위한 라이브러리링크
#pragma comment(lib, "msimg32.lib") 

//SDKDDKVer.h 는 프로그램에서 지원할 os에 따라 window 헤더에서 코드에 포함될
//함수, 상수등을 제어하는데 사용이 된다. (외부라이브러리 사용하는데 필요한 헤더 - 외부라이브러리를 c++로 자동 변환)
#include <SDKDDKVer.h>

// 거의 사용되지 않는 내용을 Windows 헤더에서 제외 
#define WIN32_LEAN_AND_MEAN
//GDI+를 사용하려면 헤더파일 <ole2.h>을 꺼내와야 한다.

//! Windows 헤더 파일
#include <windows.h>

//디버깅용 콘솔창
//#pragma comment(linker, "/entry:WinMainCRTStartup /subsystem:console")

//! C 런타임 헤더 파일
#include <stdio.h>
#include <stdlib.h>
#include <memory.h> //메모리 조작함수 5개정도 사용 (ex: zeromemory)

//11.15 추가
#include <time.h>


/*
MBCS (Multi Byte Character Set)
- 멀티 바이트
ㄴ 기존에 사용하던 형태의 문자열
ㄴ 멀티 바이트 코드는 영어같은 아스키 코드에 포함되는 문자는 1바이트,
포함되지 않는 문자는 2바이트 처리를 한다.

WBCS (Wide Byte Character Set)
- 유니 코드
ㄴ 모든 문자를 2바이트로 처리한다.


VS 에서의 문자열 표현
- 우리가 개발을 하는 VS 같은 경우에는 MBCS / WBCS 중 어느것을 사용할건지 명시를 해줘야 한다.

유니코드: 문자열을 "" 로 감싸고 L을 붙인다.

멀티바이트: 문자열을 "" 로 감싸면 끝

유니코드 < - > 멀티바이트 이식을 위해서는 문자열 표현 방식을 다 변경해 줘야 하기 때문에
중간 매크로 형인 _T를 사용한다.
*/
#include <tchar.h> //문자셋을 바꿔주는 중간 매크로 자료형

//! C++ 런타임 헤더 파일
#include <iostream>

/*
c++ 11 에서 추가된 시간 관련 라이브러리 (STL)
ㄴ 기존 C 런타임에서 제공하는 time 함수보다 다양한 / 확장된 기능 지원
- 장점:
ㄴ 정밀도가 높다 (나노 밀리 초 단위)
	ㄴ time 함수는 초 단위의 값만 측정 가능
- OS 와 독립적으로 동작한다.
*/
#include <chrono>
#include <random> 
#include <vector> //동적배열
#include <map> //레드블랙트리를 기반한 key와 value를 가진 자료형
#include <cmath>

/*
unordered_map: Hash 자료구조 (C# 에서 많이 사용)
ㄴ 일반적 상황에서는 map보다 검색 속도가 더 빠르다 (1대1 매칭구조이기 때문에) 
ㄴ 중복된 데이터를 허용하지 않는다.
ㄴ 단, 유사 데이터가 많을시 (Key) 헤시 충돌이 발생해 성능 저하 -> 유사 데이터가 많을 시 map이 효과적
*/
#include <unordered_map>
#include <string> 

//== 11.16 추가 ==
//bitset: 비트 연산을 좀 더 쉽게 관리해 주는 함수를 지원한다.(STL)
//ㄴ reset(), set(), flip(), all(), any(), size() 등등을 비트 연산에 한해 지원하고있다.
#include <bitset>

//STL 을 사용하기위해 사용
//using std::vector;
//using std::bitset;
using namespace std;

//================

// 나중에 설명해주세요 - 11.30 설명
#include <cassert>
/*
C	-> assert
ㄴ C에서 사용하는 assert 가 C++ 보다 가볍다.
C++	-> assert

*/

//=====================================================
//! 사용자 정의 헤더파일
#include "CommomMacroFunction.h"

//11.15 추가
#include "RandomFunction.h"

//11.16 추가
#include "KeyManager.h"

//11.28 추가
#include "ImageManager.h"

//12.1 추가
#include "TempSoundManager.h"

//=========
//! 싱글톤
//=========
#define RND RandomFunction::getSingleton()
#define KEYMANAGER KeyManager::getSingleton()
#define IMAGEMANAGER ImageManager::getSingleton()
#define TEMPSOUNDMANAGER TempSoundManager::getSingleton()

//=====================================================

/*
//! D2D / D3D 헤더 파일
#include <D2D1.h>			    //랜더링 고정 파이프라인
#include <D2D1helper.h>		    //랜더링 고정 파이프라인
#include <D3DX9.h>			    
#include <D3DX11.h>			    
#include <D3D11shader.h>	    //11부터는 안쓰더라도 shade 를 지정해야함
#include <dinput.h>			    //Direct에서 입력관련함수

//라이브러리 링크
#pragma comment(lib, "D2D1.lib")	
#pragma comment(lib, "D3D9.lib")	
#pragma comment(lib, "D3DX9.lib")
#pragma comment(lib, "D3D11.lib")
#pragma comment(lib, "D3DX11.lib")
#pragma comment(lib, "dinput8.lib")
#pragma comment(lib, "dxguid.lib")

ID2D1Factory*					_ID2DFactory = nullptr;			//그려지는거만 살짝 바꿔주는 야매방식
ID2D1HwndRenderTarget*			_ID2DRenderTarget = nullptr;	//PNG를 받아올 수 있는 함수
*/


//============================ 11.14
// # 매크로 # (윈도우창 초기화)
//============================

//11.29 추가
//! 전체화면
#define FULL_SCREEN1	

#ifdef FULL_SCREEN

#define WIN_NAME		(LPSTR)(TEXT("WindowsAPI"))
#define WINSTART_X		0
#define WINSTART_Y		0
// GetSystemMetrics(): 인자로 전달되는 시스템 설정 정보를 반환한다.
	//ㄴ SM_CXSCREEN: 현재 화면 기준 해상도 X축 반환
	//ㄴ SM_CYSCREEN: 현재 화면 기준 해상도 Y축 반환
#define WINSIZE_X		GetSystemMetrics(SM_CXSCREEN)
#define WINSIZE_Y		GetSystemMetrics(SM_CYSCREEN)
//WS_POPUPWINDOW: 팝업 윈도우 생성
//WS_MAXIMIZE: 윈도우 사이즈 최대화
#define WINSTYLE		WS_POPUPWINDOW | WS_MAXIMIZE

#else

#define WIN_NAME		(LPSTR)(TEXT("WindowsAPI"))
#define WINSTART_X		400
#define WINSTART_Y		100
#define WINSIZE_X		1280
#define WINSIZE_Y		800
//#define WINSIZE_X		540*1.5
//#define WINSIZE_Y		444*1.5
//WS_CAPTION: 타이틀바를 가지기 위한 옵션
//WS_SYSMENU: 제목 표시줄에 컨트롤 메뉴 상자 창을 만드는 옵션 ( _ ㅁ X )
#define WINSTYLE		WS_CAPTION | WS_SYSMENU

#endif



//================
// # 매크로 함수 #
//================
#define SAFE_DELETE(p)			{if(p) {delete (p); (p) = nullptr;}}
#define SAFE_DELETE_ARRAY(p)	{if(p) {delete[] (p); (p) = nullptr;}}
#define SAFE_RELEASE(p)			{if(p) {(p)->release(); (p) = nullptr;}}

//===============
// # 전역 변수 #
//===============
//extern 키워드는 다른 헤더 or cpp 에서 변수를 공유하기 위해 사용한다
//ㄴ 전역 변수는 키워드를 생략해도 기본으로 extern 화 되는 경우가 있다. (VS 버전)
extern HINSTANCE		_hInstance;
extern HWND				_hWnd;
extern POINT			_ptMouse;
//ㄴ X좌표와 Y좌표를 평면의 좌표에 정의할때 사용
//ㄴ 2D 에서 좌표를 설정하기 아주 적합한 구조체






