#pragma once
class GImage
{
public:
	enum IMAGE_LOAD_KIND
	{
		LOAD_RESOURCE = 0, LOAD_FILE,	//리소스로 로딩, 파일로 로딩
		LOAD_EMPTY, LOAD_END		//빈 비트맵 로딩
	};

	/*
	BYTE: unsigned char
	WORD: unsigned short
	DWORD: unsigned long
	*/
	typedef struct tagImage
	{
		DWORD		resID;		//리소스 ID
		HDC			hMemDc;		//메모리 DC
		HBITMAP		hBit;		//비트맵
		HBITMAP		hOBit;		//올드 비트맵

		float      x;		     //이미지 x좌표(레프트)
		float      y;		    //이미지 y좌표(탑)
		int			width;		//이미지 가로크기
		int			height;		//이미지 세로크기
		int			currentFrameX; //현재 프레임 x좌표
		int			currentFrameY; // 현재 프레임 y좌표
		int         maxFrameX;		//최대프레임 x좌표
		int         maxFrameY;		// 최대 프레임 Y좌표
		int          frameWidth;     // 1개의프레임 가로
		int          frameHeight;   // 1개의 프레임 세로

		BYTE		loadType;	//이미지 로드 타입



		tagImage()
		{
			resID = 0;
			hMemDc = nullptr;
			hBit = nullptr;
			hOBit = nullptr;
			x = 0;
			y = 0;
			width = 0;
			height = 0;

			currentFrameX = 0;
			currentFrameY = 0;
			maxFrameX = 0;
			maxFrameY = 0;
			frameWidth = 0;
			frameHeight = 0;
			loadType = LOAD_RESOURCE;
		}
	}IMAGE_INFO, * LPIMAGE_INFO;

private:
	LPIMAGE_INFO	_imageInfo;		//이미지 정보
	char* _fileName;		//이미지 이름
	bool			_isTrans;		//배경색
	COLORREF		_transColor;	//배경색 없앨 RGB (RGB(255,0,255))

	BLENDFUNCTION _blendfunc;       // 알파블랜드 기능
	LPIMAGE_INFO  _blendImage;       // 알파블랜드 기능



	/*
	COLORREF
	ㄴ 윈도우즈에서는 색상값을 표현하기 위해 COLORREF 라는 데이터형을 사용한다.
		ㄴ 부호 없는 32비트 정수형
	ㄴ R,G,B 각각 1바이트(8비트)이며 0 ~ 255 범위의 농도(표현)를 가진다.
	*/

public:
	//WinAPI 자료형이 혼합된 형태
	HRESULT init(int width, int height);
	//bool isTrans = false에서 bool을 BOOL로 바꾸면 함수 오버로딩 규칙에 걸려 아래 함수를 호출한다.
	//함수 오버로딩 규칙 조심.
	HRESULT init(const DWORD resID, int width, int height, bool isTrans = false,
		COLORREF transColor = RGB(0, 0, 0));
	HRESULT init(const char* fileName, int width, int height, bool isTrans = false,
		COLORREF transColor = RGB(0, 0, 0));
	//  프레임 이미지 파일로 초기화
	// 여기부터
	HRESULT init(const char* fileName, float x, float y, int width, int height, bool isTrans = false, COLORREF transColor = RGB(0, 0, 0));
	HRESULT init(const char* fileName, int width, int height, int maxFrameX, int maxFrameY, bool isTrans = false, COLORREF transColor = RGB(0, 0, 0));

	HRESULT init(const char* fileName, float x, float y, int width, int height, int maxFrameX, int maxFrameY,
		// 여기 확인
		bool isTrans = false, COLORREF transColor = RGB(0, 0, 0));

	HRESULT initforAlphaBlend(void);



	void setTransColor(bool isTrans, COLORREF transColor);

	void release(void);

	void render(HDC hdc);
	void render(HDC hdc, int destX, int destY);

	void render(HDC hdc, int destX, int destY, int sourX, int sourY, int sourWidth, int sourHeight);
	void alphaRender(HDC hdc, BYTE alpha); // byte ~ 255까지 표현
	void alphaRender(HDC hdc, int destX, int destY, BYTE alpha);
	void alphaRender(HDC hdc, int destX, int destY, int sourX, int sourY, int sourWidth, int sourHeight, BYTE alpha); // 이펙트
	//이미지, 이미지(위치값), 알파블랜딩, 프레임, 애니메이션, 클리핑(최적화 - 컬링(3D))
	void frameRender(HDC hdc, int destX, int destY);
	void frameRender(HDC hdc, int destX, int destY, int currentFrameX, int currentFrameY);

	void loopRender(HDC hdc, const LPRECT drawArea, int offsetX, int offsetY);
	//ㄴ offset: 화면을 옮겨주는 속도
	//ㄴ 맵을 이동하면 잘라서 옮기는 작업
	void loopAlphaRender(HDC hdc, const LPRECT drawArea, int offsetX, int offsetY, BYTE alpha);


	// ===========
	// 인라인 함수
	// ==========


	inline HDC getMemDC(void) { return _imageInfo->hMemDc; }
	inline float getX(void) { return _imageInfo->x; }
	inline void setX(float x) { _imageInfo->x = x; }

	// 
	inline float getY(void) { return _imageInfo->y; }
	inline void setY(float y) { _imageInfo->y = y; }


	// 이미지 센터좌표
	inline void setCenter(float x, float y)
	{
		_imageInfo->x = x = (_imageInfo->width / 2);
		_imageInfo->y = y = (_imageInfo->height / 2);


	}

	// 이미지 가로, 세로크기
	inline int getWidth(void) { return _imageInfo->width; }
	inline int getHegiht(void) { return _imageInfo->height; }

	// 바운딩 박스 (충돌용 렉트)
	inline RECT boundingBox(void)
	{

		RECT rc =
		{

		(int)_imageInfo->x,
		(int)_imageInfo->y,
		(int)_imageInfo->x + _imageInfo->width,
		(int)_imageInfo->y + _imageInfo->height

		};
		return rc;

	}

	inline int getFrameX(void) { return _imageInfo->currentFrameX; }
	inline void setFrameX(int frameX)
	{
		_imageInfo->currentFrameX = frameX;
		if (frameX > _imageInfo->maxFrameX)
		{
			_imageInfo->currentFrameX = _imageInfo->maxFrameX;
		}

	}
	inline int getFrameY(void) { return _imageInfo->currentFrameY; }
	inline void setFrameY(int frameY)
	{
		_imageInfo->currentFrameY = frameY;
		if (frameY > _imageInfo->maxFrameY)
		{
			_imageInfo->currentFrameY = _imageInfo->maxFrameY;
		}

	}
	// 이미지 1프레임 가로, 세로
	inline int getFrameWidth(void) { return _imageInfo->frameWidth; }
	inline int getFrameHeight(void) { return _imageInfo->frameHeight; }

	// 최대프레임 x y갯수
	inline int getmaxFrameX(void) { return _imageInfo->maxFrameX; }
	inline int getmaxFrameY(void) { return _imageInfo->maxFrameY; }

	HBITMAP getHBit() { return _imageInfo->hBit; }




	GImage();
	~GImage() {}
};

