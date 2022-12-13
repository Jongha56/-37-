#pragma once
#include "SingletonBase.h"
#include "GImage.h"

/*
STL �� �ٽ�
(Ʃ�õ� Ű, ���� ����Ѵ�.)
- Ű, ���� ���� ����
�� ù��° first
�� �ι�° second

- ���� �߰��ϴ� ����� insert�� ����ϰ� Ű�� ������ ���ÿ� �߰��ؾ��ϴ�
pair or make_pair�� ����Ѵ�.
*/

class ImageManager : public SingletonBase <ImageManager>
{
private:
	typedef map<string, GImage*> mapImageLiszt;
	typedef map<string, GImage*>::iterator mapIamgeIter;
	mapImageLiszt _mImageList;
	
public:
	HRESULT init(void);
	void relese(void);
	
	GImage* addImage(string strKey, int width, int height);
	GImage* addImage(string strKey, const char* fileName, int width, int height, bool isTrans = false, COLORREF transColor = RGB(0, 0, 0));
	GImage* addImage(string strKey, const char* fileName, float x, float y, int width, int height, bool isTrans = false, COLORREF transColor = RGB(0, 0, 0));
	GImage* addFrameImage(string strKey, const char* fileName, int width, int height, int maxFrameX, int maxFrameY, bool isTrans = false, COLORREF transColor = RGB(0, 0, 0));
	GImage* addFrameImage(string strKey, const char* fileName, float x, float y, int width, int height, int maxFrameX, int maxFrameY, bool isTrans = false, COLORREF transColor = RGB(0, 0, 0));
	
	GImage* findImage(string strKey);
	bool deleteImage(string strKey);
	bool deleteAll();

	void render(string strKey, HDC hdc);
	void render(string strKey, HDC hdc, int destX, int destY);
	void render(string strKey, HDC hdc, int destX, int destY, int sourX, int sourY, int sourWidth, int sourHeight);
	
	void alphaRender(string strKey, HDC hdc, BYTE alpha); // BYTE: 0 ~ 255���� ǥ��
	void alphaRender(string strKey, HDC hdc, int destX, int destY, BYTE alpha);
	void alphaRender(string strKey, HDC hdc, int destX, int destY, int sourX, int sourY, int sourWidth, int sourHeight, BYTE alpha); // ����Ʈ
	
	void frameRender(string strKey, HDC hdc, int destX, int destY);
	void frameRender(string strKey, HDC hdc, int destX, int destY, int currentFrameX, int currentFrameY);

	void loopRender(string strKey, HDC hdc, const LPRECT drawArea, int offsetX, int offsetY);
	void loopAlphaRender(string strKey, HDC hdc, const LPRECT drawArea, int offsetX, int offsetY, BYTE alpha);
	//�� ƴ���� ���Բ� �̾���̰�, �̹����� Ŭ���� ����

	ImageManager() {}
	~ImageManager() {}
};

