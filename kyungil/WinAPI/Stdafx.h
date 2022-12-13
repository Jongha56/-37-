#pragma once
//����� - 4005: DXGI �� �׷��� �������̽����� ��ũ�� �����Ͽ� ���� ��µǴ� ���
#pragma warning(disable : 4005)

//! ���带 ����ϱ� ���� ���̺귯����ũ
#pragma comment(lib, "msimg32.lib") 

//SDKDDKVer.h �� ���α׷����� ������ os�� ���� window ������� �ڵ忡 ���Ե�
//�Լ�, ������� �����ϴµ� ����� �ȴ�. (�ܺζ��̺귯�� ����ϴµ� �ʿ��� ��� - �ܺζ��̺귯���� c++�� �ڵ� ��ȯ)
#include <SDKDDKVer.h>

// ���� ������ �ʴ� ������ Windows ������� ���� 
#define WIN32_LEAN_AND_MEAN
//GDI+�� ����Ϸ��� ������� <ole2.h>�� �����;� �Ѵ�.

//! Windows ��� ����
#include <windows.h>

//������ �ܼ�â
//#pragma comment(linker, "/entry:WinMainCRTStartup /subsystem:console")

//! C ��Ÿ�� ��� ����
#include <stdio.h>
#include <stdlib.h>
#include <memory.h> //�޸� �����Լ� 5������ ��� (ex: zeromemory)

//11.15 �߰�
#include <time.h>


/*
MBCS (Multi Byte Character Set)
- ��Ƽ ����Ʈ
�� ������ ����ϴ� ������ ���ڿ�
�� ��Ƽ ����Ʈ �ڵ�� ����� �ƽ�Ű �ڵ忡 ���ԵǴ� ���ڴ� 1����Ʈ,
���Ե��� �ʴ� ���ڴ� 2����Ʈ ó���� �Ѵ�.

WBCS (Wide Byte Character Set)
- ���� �ڵ�
�� ��� ���ڸ� 2����Ʈ�� ó���Ѵ�.


VS ������ ���ڿ� ǥ��
- �츮�� ������ �ϴ� VS ���� ��쿡�� MBCS / WBCS �� ������� ����Ұ��� ��ø� ����� �Ѵ�.

�����ڵ�: ���ڿ��� "" �� ���ΰ� L�� ���δ�.

��Ƽ����Ʈ: ���ڿ��� "" �� ���θ� ��

�����ڵ� < - > ��Ƽ����Ʈ �̽��� ���ؼ��� ���ڿ� ǥ�� ����� �� ������ ��� �ϱ� ������
�߰� ��ũ�� ���� _T�� ����Ѵ�.
*/
#include <tchar.h> //���ڼ��� �ٲ��ִ� �߰� ��ũ�� �ڷ���

//! C++ ��Ÿ�� ��� ����
#include <iostream>

/*
c++ 11 ���� �߰��� �ð� ���� ���̺귯�� (STL)
�� ���� C ��Ÿ�ӿ��� �����ϴ� time �Լ����� �پ��� / Ȯ��� ��� ����
- ����:
�� ���е��� ���� (���� �и� �� ����)
	�� time �Լ��� �� ������ ���� ���� ����
- OS �� ���������� �����Ѵ�.
*/
#include <chrono>
#include <random> 
#include <vector> //�����迭
#include <map> //�����Ʈ���� ����� key�� value�� ���� �ڷ���
#include <cmath>

/*
unordered_map: Hash �ڷᱸ�� (C# ���� ���� ���)
�� �Ϲ��� ��Ȳ������ map���� �˻� �ӵ��� �� ������ (1��1 ��Ī�����̱� ������) 
�� �ߺ��� �����͸� ������� �ʴ´�.
�� ��, ���� �����Ͱ� ������ (Key) ��� �浹�� �߻��� ���� ���� -> ���� �����Ͱ� ���� �� map�� ȿ����
*/
#include <unordered_map>
#include <string> 

//== 11.16 �߰� ==
//bitset: ��Ʈ ������ �� �� ���� ������ �ִ� �Լ��� �����Ѵ�.(STL)
//�� reset(), set(), flip(), all(), any(), size() ����� ��Ʈ ���꿡 ���� �����ϰ��ִ�.
#include <bitset>

//STL �� ����ϱ����� ���
//using std::vector;
//using std::bitset;
using namespace std;

//================

// ���߿� �������ּ��� - 11.30 ����
#include <cassert>
/*
C	-> assert
�� C���� ����ϴ� assert �� C++ ���� ������.
C++	-> assert

*/

//=====================================================
//! ����� ���� �������
#include "CommomMacroFunction.h"

//11.15 �߰�
#include "RandomFunction.h"

//11.16 �߰�
#include "KeyManager.h"

//11.28 �߰�
#include "ImageManager.h"

//12.1 �߰�
#include "TempSoundManager.h"

//=========
//! �̱���
//=========
#define RND RandomFunction::getSingleton()
#define KEYMANAGER KeyManager::getSingleton()
#define IMAGEMANAGER ImageManager::getSingleton()
#define TEMPSOUNDMANAGER TempSoundManager::getSingleton()

//=====================================================

/*
//! D2D / D3D ��� ����
#include <D2D1.h>			    //������ ���� ����������
#include <D2D1helper.h>		    //������ ���� ����������
#include <D3DX9.h>			    
#include <D3DX11.h>			    
#include <D3D11shader.h>	    //11���ʹ� �Ⱦ����� shade �� �����ؾ���
#include <dinput.h>			    //Direct���� �Է°����Լ�

//���̺귯�� ��ũ
#pragma comment(lib, "D2D1.lib")	
#pragma comment(lib, "D3D9.lib")	
#pragma comment(lib, "D3DX9.lib")
#pragma comment(lib, "D3D11.lib")
#pragma comment(lib, "D3DX11.lib")
#pragma comment(lib, "dinput8.lib")
#pragma comment(lib, "dxguid.lib")

ID2D1Factory*					_ID2DFactory = nullptr;			//�׷����°Ÿ� ��¦ �ٲ��ִ� �߸Ź��
ID2D1HwndRenderTarget*			_ID2DRenderTarget = nullptr;	//PNG�� �޾ƿ� �� �ִ� �Լ�
*/


//============================ 11.14
// # ��ũ�� # (������â �ʱ�ȭ)
//============================

//11.29 �߰�
//! ��üȭ��
#define FULL_SCREEN1	

#ifdef FULL_SCREEN

#define WIN_NAME		(LPSTR)(TEXT("WindowsAPI"))
#define WINSTART_X		0
#define WINSTART_Y		0
// GetSystemMetrics(): ���ڷ� ���޵Ǵ� �ý��� ���� ������ ��ȯ�Ѵ�.
	//�� SM_CXSCREEN: ���� ȭ�� ���� �ػ� X�� ��ȯ
	//�� SM_CYSCREEN: ���� ȭ�� ���� �ػ� Y�� ��ȯ
#define WINSIZE_X		GetSystemMetrics(SM_CXSCREEN)
#define WINSIZE_Y		GetSystemMetrics(SM_CYSCREEN)
//WS_POPUPWINDOW: �˾� ������ ����
//WS_MAXIMIZE: ������ ������ �ִ�ȭ
#define WINSTYLE		WS_POPUPWINDOW | WS_MAXIMIZE

#else

#define WIN_NAME		(LPSTR)(TEXT("WindowsAPI"))
#define WINSTART_X		400
#define WINSTART_Y		100
#define WINSIZE_X		1280
#define WINSIZE_Y		800
//#define WINSIZE_X		540*1.5
//#define WINSIZE_Y		444*1.5
//WS_CAPTION: Ÿ��Ʋ�ٸ� ������ ���� �ɼ�
//WS_SYSMENU: ���� ǥ���ٿ� ��Ʈ�� �޴� ���� â�� ����� �ɼ� ( _ �� X )
#define WINSTYLE		WS_CAPTION | WS_SYSMENU

#endif



//================
// # ��ũ�� �Լ� #
//================
#define SAFE_DELETE(p)			{if(p) {delete (p); (p) = nullptr;}}
#define SAFE_DELETE_ARRAY(p)	{if(p) {delete[] (p); (p) = nullptr;}}
#define SAFE_RELEASE(p)			{if(p) {(p)->release(); (p) = nullptr;}}

//===============
// # ���� ���� #
//===============
//extern Ű����� �ٸ� ��� or cpp ���� ������ �����ϱ� ���� ����Ѵ�
//�� ���� ������ Ű���带 �����ص� �⺻���� extern ȭ �Ǵ� ��찡 �ִ�. (VS ����)
extern HINSTANCE		_hInstance;
extern HWND				_hWnd;
extern POINT			_ptMouse;
//�� X��ǥ�� Y��ǥ�� ����� ��ǥ�� �����Ҷ� ���
//�� 2D ���� ��ǥ�� �����ϱ� ���� ������ ����ü






