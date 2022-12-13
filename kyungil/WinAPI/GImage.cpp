#include "Stdafx.h"
#include "GImage.h"

GImage::GImage() : _imageInfo(nullptr),
_fileName(nullptr),
_isTrans(false),
_transColor(RGB(0, 0, 0)),
_blendImage(nullptr)

{
	//!Do Nothing
}

HRESULT GImage::init(int width, int height)
{
	//재초기화 방지용 / 이미지 정보에 값이 들어 있다면 해제부터 하겠다.
	if (_imageInfo != nullptr) this->release();

	HDC hdc = GetDC(_hWnd);

	_imageInfo = new IMAGE_INFO;
	_imageInfo->loadType = LOAD_EMPTY;
	_imageInfo->resID = 0;
	_imageInfo->hMemDc = CreateCompatibleDC(hdc);
	_imageInfo->hBit = (HBITMAP)CreateCompatibleBitmap(hdc,width, height);
	_imageInfo->hOBit = (HBITMAP)SelectObject(_imageInfo->hMemDc, _imageInfo->hBit);
	_imageInfo->width = width;
	_imageInfo->height = height;

	_fileName = nullptr;
	_isTrans = false;
	_transColor = RGB(0, 0, 0);

	//리소스 얻어오는 데 실패
	if (_imageInfo->hBit == 0)
	{
		release();
		return E_FAIL;
	}

	//DC 해제
	ReleaseDC(_hWnd, hdc);

	return S_OK;
}

HRESULT GImage::init(const DWORD resID, int width, int height, bool isTrans, COLORREF transColor)
{
	if (_imageInfo != nullptr) this->release();

	HDC hdc = GetDC(_hWnd);

	_imageInfo = new IMAGE_INFO;
	_imageInfo->loadType = LOAD_RESOURCE;
	_imageInfo->resID = resID;
	_imageInfo->hMemDc = CreateCompatibleDC(hdc);
	_imageInfo->hBit = (HBITMAP)LoadBitmap(_hInstance,MAKEINTRESOURCE(_imageInfo->resID));
	_imageInfo->hOBit = (HBITMAP)SelectObject(_imageInfo->hMemDc, _imageInfo->hBit);
	_imageInfo->width = width;
	_imageInfo->height = height;

	_fileName = nullptr;
	_isTrans = isTrans;
	_transColor = transColor;

	//리소스 얻어오는 데 실패
	if (_imageInfo->hBit == 0)
	{
		release();
		return E_FAIL;
	}

	//DC 해제
	ReleaseDC(_hWnd, hdc);

	return S_OK;
}

HRESULT GImage::init(const char* fileName, int width, int height, bool isTrans, COLORREF transColor)
{
	if (_imageInfo != nullptr) this->release();

	HDC hdc = GetDC(_hWnd);

	_imageInfo = new IMAGE_INFO;
	_imageInfo->loadType = LOAD_FILE;
	_imageInfo->resID = 0;
	_imageInfo->hMemDc = CreateCompatibleDC(hdc);
	_imageInfo->hBit = (HBITMAP)LoadImage(_hInstance, fileName, IMAGE_BITMAP, width, height, LR_LOADFROMFILE);
	_imageInfo->hOBit = (HBITMAP)SelectObject(_imageInfo->hMemDc, _imageInfo->hBit);
	_imageInfo->width = width;
	_imageInfo->height = height;

	// 예외처리
	int len = strlen(fileName);
	_fileName = new char[len + 1];
	//_s가 붙으면 추가형. 인자를 추가해 조금 더 안전하게 쓰겠다.
	strcpy_s(_fileName, len + 1, fileName);

	_isTrans = isTrans;
	_transColor = transColor;

	//리소스 얻어오는 데 실패
	if (_imageInfo->hBit == 0)
	{
		release();
		return E_FAIL;
	}

	//DC 해제
	ReleaseDC(_hWnd, hdc);
	return S_OK;
}

HRESULT GImage::init(const char* fileName, float x, float y, int width, int height, bool isTrans, COLORREF transColor)
{

	if (_imageInfo != nullptr) this->release();

	HDC hdc = GetDC(_hWnd);

	_imageInfo = new IMAGE_INFO;
	_imageInfo->loadType = LOAD_FILE;
	_imageInfo->resID = 0;
	_imageInfo->hMemDc = CreateCompatibleDC(hdc);
	_imageInfo->hBit = (HBITMAP)LoadImage(_hInstance, fileName, IMAGE_BITMAP, width, height, LR_LOADFROMFILE);
	_imageInfo->hOBit = (HBITMAP)SelectObject(_imageInfo->hMemDc, _imageInfo->hBit);
	_imageInfo->x = x;
	_imageInfo->y = y;
	_imageInfo->width = width;
	_imageInfo->height = height;

	// 예외처리
	int len = strlen(fileName);
	_fileName = new char[len + 1];
	//_s가 붙으면 추가형. 인자를 추가해 조금 더 안전하게 쓰겠다.
	strcpy_s(_fileName, len + 1, fileName);

	_isTrans = isTrans;
	_transColor = transColor;

	//리소스 얻어오는 데 실패
	if (_imageInfo->hBit == 0)
	{
		release();
		return E_FAIL;
	}

	//DC 해제
	ReleaseDC(_hWnd, hdc);

	return S_OK;
}

HRESULT GImage::init(const char* fileName, int width, int height, int maxFrameX, int maxFrameY, bool isTrans, COLORREF transColor)
{

	if (_imageInfo != nullptr) this->release();

	HDC hdc = GetDC(_hWnd);

	_imageInfo = new IMAGE_INFO;
	_imageInfo->loadType = LOAD_FILE;
	_imageInfo->resID = 0;
	_imageInfo->hMemDc = CreateCompatibleDC(hdc);
	_imageInfo->hBit = (HBITMAP)LoadImage(_hInstance, fileName, IMAGE_BITMAP, width, height, LR_LOADFROMFILE);
	_imageInfo->hOBit = (HBITMAP)SelectObject(_imageInfo->hMemDc, _imageInfo->hBit);
	
	_imageInfo->width = width;
	_imageInfo->height = height;
	_imageInfo->currentFrameX = 0;
	_imageInfo->currentFrameY = 0;
	_imageInfo->maxFrameX = maxFrameX - 1;
	_imageInfo->maxFrameY = maxFrameY - 1;
	_imageInfo->frameWidth = width / maxFrameX;
	_imageInfo->frameHeight = height / maxFrameY;

	// 예외처리
	int len = strlen(fileName);
	_fileName = new char[len + 1];
	//_s가 붙으면 추가형. 인자를 추가해 조금 더 안전하게 쓰겠다.
	strcpy_s(_fileName, len + 1, fileName);

	_isTrans = isTrans;
	_transColor = transColor;

	//리소스 얻어오는 데 실패
	if (_imageInfo->hBit == 0)
	{
		release();
		return E_FAIL;
	}

	//DC 해제
	ReleaseDC(_hWnd, hdc);

	return S_OK;
}

HRESULT GImage::init(const char* fileName, float x, float y, int width, int height, int maxFrameX, int maxFrameY, bool isTrans, COLORREF transColor)
{
	if (_imageInfo != nullptr) this->release();

	HDC hdc = GetDC(_hWnd);

	_imageInfo = new IMAGE_INFO;
	_imageInfo->loadType = LOAD_FILE;
	_imageInfo->resID = 0;
	_imageInfo->hMemDc = CreateCompatibleDC(hdc);
	_imageInfo->hBit = (HBITMAP)LoadImage(_hInstance, fileName, IMAGE_BITMAP, width, height, LR_LOADFROMFILE);
	_imageInfo->hOBit = (HBITMAP)SelectObject(_imageInfo->hMemDc, _imageInfo->hBit);

	_imageInfo->width = width;
	_imageInfo->height = height;
	_imageInfo->x = x;
	_imageInfo->y = y;
	_imageInfo->currentFrameX = 0;
	_imageInfo->currentFrameY = 0;
	_imageInfo->maxFrameX = maxFrameX - 1;
	_imageInfo->maxFrameY = maxFrameY - 1;
	_imageInfo->frameWidth = width / maxFrameX;
	_imageInfo->frameHeight = height / maxFrameY;

	// 예외처리
	int len = strlen(fileName);
	_fileName = new char[len + 1];
	//_s가 붙으면 추가형. 인자를 추가해 조금 더 안전하게 쓰겠다.
	strcpy_s(_fileName, len + 1, fileName);

	_isTrans = isTrans;
	_transColor = transColor;

	//리소스 얻어오는 데 실패
	if (_imageInfo->hBit == 0)
	{
		release();
		return E_FAIL;
	}

	//DC 해제
	ReleaseDC(_hWnd, hdc);



	return S_OK;
}

HRESULT GImage::initforAlphaBlend(void)
{
	HDC hdc = GetDC(_hWnd);
	_blendfunc.BlendFlags = 0; // 속성과 나중에 사용하기 위해 0으로 초기화
	_blendfunc.AlphaFormat = 0; // 특정조건에서만 사용하기위해 0으로 초기화
	_blendfunc.BlendOp = AC_SRC_OVER; //   혼합연산 (비트맵 + 알파값(픽셀)을 넣겠다라는뜻) 

	_blendImage = new IMAGE_INFO;

	_blendImage = new IMAGE_INFO;
	_blendImage->loadType = LOAD_FILE;
	_blendImage->resID = 0;
	_blendImage->hMemDc = CreateCompatibleDC(hdc);
	_blendImage->hBit = (HBITMAP)CreateCompatibleBitmap(hdc, _imageInfo->width, _imageInfo->height);
	_blendImage->hOBit = (HBITMAP)SelectObject(_blendImage->hMemDc, _blendImage->hBit);
	_blendImage->width = WINSIZE_X;
	_blendImage->height = WINSIZE_Y;


	ReleaseDC(_hWnd, hdc);

	return S_OK;


}

void GImage::setTransColor(bool isTrans, COLORREF transColor)
{
	_isTrans = isTrans;
	_transColor = transColor;
}

//외부
void GImage::release(void)
{
	if (_imageInfo)
	{
		//이미지 삭제
		SelectObject(_imageInfo->hMemDc, _imageInfo->hOBit);
		DeleteObject(_imageInfo->hBit);
		DeleteDC(_imageInfo->hMemDc);

		//포인터 삭제
		SAFE_DELETE(_imageInfo);
		SAFE_DELETE_ARRAY(_fileName);

		//투명컬러키 초기화
		_isTrans = false;
		_transColor = RGB(0, 0, 0);
	}
	if (_blendImage)
	{

		SelectObject(_blendImage->hMemDc, _blendImage->hOBit);
		DeleteObject(_blendImage->hBit);
		DeleteDC(_blendImage->hMemDc);
		SAFE_DELETE(_blendImage);

	}
}

//0,0
void GImage::render(HDC hdc)
{
	if (_isTrans)
	{
		//GdiTransparentBlt(): 비트맵을 불러올 때 특정 색상을 제외하고 복사
		GdiTransparentBlt
		(
			hdc,				//복사할 장소의 DC(화면에 보여지는 DC)
			0,					//복사될 좌표 시작(x)
			0,					//복사될 좌표 시작(y)
			_imageInfo->width,	//복사될 이미지 가로크기
			_imageInfo->height,	//복사될 이미지 세로크기
			_imageInfo->hMemDc, //복사될 대상 메모리 DC
			0,0,				//복사 시작 시점
			_imageInfo->width,	//복사 영역 가로크기
			_imageInfo->height,	//복사 영역 세로크기
			_transColor			//복사할 때 제외할 색상
		);
	}
	else
	{
		//BitBlt(): DC 간의 영역끼리 서로 고속복사를 해준다.
		//SRCCOPY: 소스 영역을 대상 영역에 복사한다.
		BitBlt(hdc, 0, 0, _imageInfo->width, _imageInfo->height, _imageInfo->hMemDc, 0, 0, SRCCOPY);
	}
}

// destX, destY
void GImage::render(HDC hdc, int destX, int destY)
{
	if (_isTrans)
	{
		//GdiTransparentBlt(): 비트맵을 불러올 때 특정 색상을 제외하고 복사
		GdiTransparentBlt
		(
			hdc,				//복사할 장소의 DC(화면에 보여지는 DC)
			destX,				//복사될 좌표 시작(x)
			destY,				//복사될 좌표 시작(y)
			_imageInfo->width,	//복사될 이미지 가로크기
			_imageInfo->height,	//복사될 이미지 세로크기
			_imageInfo->hMemDc, //복사될 대상 메모리 DC
			0, 0,				//복사 시작 시점
			_imageInfo->width,	//복사 영역 가로크기
			_imageInfo->height,	//복사 영역 세로크기
			_transColor			//복사할 때 제외할 색상
		);
	}
	else
	{
		//BitBlt(): DC 간의 영역끼리 서로 고속복사를 해준다.
		//SRCCOPY: 소스 영역을 대상 영역에 복사한다.
		BitBlt(hdc, destX, destY, _imageInfo->width, _imageInfo->height, _imageInfo->hMemDc, 0, 0, SRCCOPY);
	}
}
// 이미지 클리핑
// ㄴ 원본 이미지 지정 -> 지정좌표로부터 가로, 세로 크기를 잘라 내가 원하는 좌표에 출력
void GImage::render(HDC hdc, 
	int destX, int destY,  //복사될 자표 시작
	int sourX, int sourY,  //복사 시작 시점
	int sourWidth, int sourHeight //복사될 이미지 크기
)
{

	if (_isTrans)
	{
		//GdiTransparentBlt(): 비트맵을 불러올 때 특정 색상을 제외하고 복사
		GdiTransparentBlt
		(
			hdc,				//복사할 장소의 DC(화면에 보여지는 DC)
			destX,				//복사될 좌표 시작(x)
			destY,				//복사될 좌표 시작(y)
			sourWidth,			//복사될 이미지 가로크기
			sourHeight,			//복사될 이미지 세로크기
			_imageInfo->hMemDc,
			sourX, sourY,		//복사 시작 시점      
			sourWidth,			//복사 범위
			sourHeight,			
			_transColor			//복사할 때 제외할 색상
		);
	}
	else
	{
		//BitBlt(): DC 간의 영역끼리 서로 고속복사를 해준다.
		//SRCCOPY: 소스 영역을 대상 영역에 복사한다.
		BitBlt(hdc, destX, destY, sourWidth, sourHeight, _imageInfo->hMemDc, sourX, sourY, SRCCOPY);
	}


}

void GImage::alphaRender(HDC hdc, BYTE alpha)
{
	if (!_blendImage) initforAlphaBlend();

	// 적용하려는 대상 객체 = 인자로 넘겨줄 alpha를 넘겨주겠다
	_blendfunc.SourceConstantAlpha = alpha;
	// 배경색 없앤후 알파블랜딩 할건지?
	if (_isTrans)
	{
		// 1. 출력해야 될 DC에 그려져 있는 내용을 블랜드 이미지에 그린다.
		BitBlt
		(
			_blendImage->hMemDc,
			0, 0,
			_imageInfo->width,
			_imageInfo->height,
			hdc,
			0, 0,
			SRCCOPY

		);

		// 2. 원본 이미지의 배경을 없앤후 블랜드 이미지에 그린다.
		GdiTransparentBlt
		(
			_blendImage->hMemDc,
			0,0,
			_imageInfo->width,
			_imageInfo->height,
			_imageInfo->hMemDc,
			0,0,
			_imageInfo->width,
			_imageInfo->height,
			_transColor



		);
		//3. 블랜드 이미지를 화면에 그린다.
		AlphaBlend
		(
		
			hdc,
			0,0,
			_imageInfo->width,
			_imageInfo->height,
			_blendImage->hMemDc,
			0,0,
			_imageInfo->width,
			_imageInfo->height,
			_blendfunc
		);
	}
	else
	{
		AlphaBlend(hdc, 0, 0, _imageInfo->width, _imageInfo->height, _imageInfo->hMemDc, 0, 0, _imageInfo->width, _imageInfo->height,
			_blendfunc);

	}
}
// 동작방식
// ㄴ화면 dc -> 메모리 복사 -> 배경색(알파) -> dc로 넘겨줌

void GImage::alphaRender(HDC hdc, int destX, int destY, BYTE alpha)
{

	if (!_blendImage) initforAlphaBlend();

	// 적용하려는 대상 객체 = 인자로 넘겨줄 alpha를 넘겨주겠다
	_blendfunc.SourceConstantAlpha = alpha;
	// 배경색 없앤후 알파블랜딩 할건지?
	if (_isTrans)
	{
		// 1. 출력해야 될 DC에 그려져 있는 내용을 블랜드 이미지에 그린다.
		BitBlt
		(
			_blendImage->hMemDc,
			0, 0,
			_imageInfo->width,
			_imageInfo->height,
			hdc,
			destX, destY,
			SRCCOPY

		);

		// 2. 원본 이미지의 배경을 없앤후 블랜드 이미지에 그린다.
		GdiTransparentBlt
		(
			_blendImage->hMemDc,
			0, 0,
			_imageInfo->width,
			_imageInfo->height,
			_imageInfo->hMemDc,
			0, 0,
			_imageInfo->width,
			_imageInfo->height,
			_transColor



		);
		//3. 블랜드 이미지를 화면에 그린다.
		AlphaBlend
		(

			hdc,
			_imageInfo->x = destX,
			_imageInfo->y = destY,
			_imageInfo->width,
			_imageInfo->height,
			_blendImage->hMemDc,
			0, 0,
			_imageInfo->width,
			_imageInfo->height,
			_blendfunc
		);
	}
	else
	{
		AlphaBlend(hdc, destX, destY, _imageInfo->width, _imageInfo->height, _imageInfo->hMemDc, 0, 0, _imageInfo->width, _imageInfo->height,
			_blendfunc);

	}
}

// 당장은 쓸데가 없으므로 나중에 완성.
void GImage::alphaRender(HDC hdc, int destX, int destY, int sourX, int sourY, int sourWidth, int sourHeight, BYTE alpha)
{


}

void GImage::frameRender(HDC hdc, int destX, int destY)
{

	if (_isTrans)
	{
		//GdiTransparentBlt(): 비트맵을 불러올 때 특정 색상을 제외하고 복사
		GdiTransparentBlt
		(
			hdc,				//복사할 장소의 DC(화면에 보여지는 DC)
			destX,				//복사될 좌표 시작(x)
			destY,				//복사될 좌표 시작(y)
			_imageInfo->frameWidth,		//복사될 이미지 가로크기
			_imageInfo->frameHeight,	//복사될 이미지 세로크기
			_imageInfo->hMemDc,
			_imageInfo->currentFrameX* _imageInfo->frameWidth,
			_imageInfo->currentFrameY* _imageInfo->frameHeight,
			_imageInfo->frameWidth,
			_imageInfo->frameHeight,//복사 시작 시점      
			_transColor			//복사할 때 제외할 색상
		);
	}
	else
	{
		//BitBlt(): DC 간의 영역끼리 서로 고속복사를 해준다.
		//SRCCOPY: 소스 영역을 대상 영역에 복사한다.
		BitBlt(hdc, destX, destY, _imageInfo->frameWidth,		//복사될 이미지 가로크기
			_imageInfo->frameHeight, _imageInfo->hMemDc,
			_imageInfo->currentFrameX * _imageInfo->frameWidth,
			_imageInfo->currentFrameY * _imageInfo->frameHeight, SRCCOPY);
		
	}

}

void GImage::frameRender(HDC hdc, int destX, int destY, int currentFrameX, int currentFrameY)
{
	// 이미지 예외처리

	_imageInfo->currentFrameX = currentFrameX;
	_imageInfo->currentFrameY = currentFrameY;

	if (currentFrameX > _imageInfo->maxFrameX)
	{
		_imageInfo->currentFrameX = _imageInfo->maxFrameX;


	}
	if (currentFrameY > _imageInfo->maxFrameY)
	{
		_imageInfo->currentFrameY = _imageInfo->maxFrameY;


	}

	if (_isTrans)
	{
		//GdiTransparentBlt(): 비트맵을 불러올 때 특정 색상을 제외하고 복사
		GdiTransparentBlt
		(
			hdc,				//복사할 장소의 DC(화면에 보여지는 DC)
			destX,				//복사될 좌표 시작(x)
			destY,				//복사될 좌표 시작(y)
			_imageInfo->frameWidth,		//복사될 이미지 가로크기
			_imageInfo->frameHeight,	//복사될 이미지 세로크기
			_imageInfo->hMemDc,
			_imageInfo->currentFrameX * _imageInfo->frameWidth,
			_imageInfo->currentFrameY * _imageInfo->frameHeight,
			_imageInfo->frameWidth,
			_imageInfo->frameHeight,//복사 시작 시점      
			_transColor			//복사할 때 제외할 색상
		);
	}
	else
	{
		//BitBlt(): DC 간의 영역끼리 서로 고속복사를 해준다.
		//SRCCOPY: 소스 영역을 대상 영역에 복사한다.
		BitBlt(hdc, destX, destY, _imageInfo->frameWidth,		//복사될 이미지 가로크기
			_imageInfo->frameHeight, _imageInfo->hMemDc,
			_imageInfo->currentFrameX * _imageInfo->frameWidth,
			_imageInfo->currentFrameY * _imageInfo->frameHeight, SRCCOPY);

	}

}

void GImage::loopRender(HDC hdc, const LPRECT drawArea, int offsetX, int offsetY)
{
	//offset 값이 음수일 경우 보정
	//ㄴ abs() 함수는 무겁기때문에 상대적으로 가벼운 조건식으로 절대값만들어줌
	if (offsetX < 0) offsetX = _imageInfo->width + (offsetX % _imageInfo->width);
	if (offsetY < 0) offsetY = _imageInfo->height + (offsetY % _imageInfo->height);

	//그려지는 영역 미리 세팅
	RECT rcSour;
	int sourWidth;
	int sourHeight;

	//그려지는 DC 영역 (화면 크기)
	RECT rcDest;

	//그려야 할 전체 영역 세팅
	int drawAreaX = drawArea->left;
	int drawAreaY = drawArea->top;
	int drawAreaW = drawArea->right - drawArea->left;
	int drawAreaH = drawArea->bottom - drawArea->top;

	//=== 세로 루프 ===
	for (int y = 0; y < drawAreaH; y += sourHeight) {
		//소스 영역의 높이 계산
		rcSour.top = (y + offsetY) % _imageInfo->height;
		rcSour.bottom = _imageInfo->height;
		sourHeight = rcSour.bottom - rcSour.top;

		//소스 영역이 그리는 화면을 넘어 갔다면
		//ㄴ 화면 밖으로 나갔다.
		if (y + sourHeight > drawAreaH) {
			//넘어간 그림의 값만큼 바텀값을 올려준다.
			rcSour.bottom -= (y + sourHeight) - drawAreaH;
			sourHeight = rcSour.bottom - rcSour.top;
		}

		//그려지는 영역
		rcDest.top = y + drawAreaY;
		rcDest.bottom = rcDest.top + sourHeight;


		//=== 가로 루프 ===
		for (int x = 0; x < drawAreaW; x += sourWidth) {
			//소스 영역의 높이 계산
			rcSour.left = (x + offsetX) % _imageInfo->width;
			rcSour.right = _imageInfo->width;
			sourWidth = rcSour.right - rcSour.left;

			//소스 영역이 그리는 화면을 넘어 갔다면
			//ㄴ 화면 밖으로 나갔다.
			if (x + sourWidth > drawAreaW) {
				//넘어간 그림의 값만큼 바텀값을 올려준다.
				rcSour.right -= (x + sourWidth) - drawAreaW;
				sourWidth = rcSour.right - rcSour.left;
			}

			//그려지는 영역
			rcDest.left = x + drawAreaX;
			rcDest.right = rcDest.left + sourWidth;

			render(hdc, 
				rcDest.left, rcDest.top,
				rcSour.left, rcSour.top,
				sourWidth, sourHeight);
		}// End for
	}
}

void GImage::loopAlphaRender(HDC hdc, const LPRECT drawArea, int offsetX, int offsetY, BYTE alpha)
{
}
