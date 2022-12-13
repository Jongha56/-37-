#pragma once

//과제
class FontManager
{

public:
	//멀티바이트
	void drawText(HDC hdc, int destX, int destY, char* fontName, int fontSize,
		int fontWeight, char* printString, int length, COLORREF color);
	
	//유니코드 - 단일객체
	void drawText(HDC hdc, int destX, int destY, char* fontName, int font,
		int fontWeight, LPCWSTR printString, int length, COLORREF color);
	
	//유니코드 - 복수객체
	void drawText(HDC hdc, int destX, int destY, char* fontName, int font,
		int fontWeight, LPCWSTR* printStringArr, int length, COLORREF color);

	FontManager() {}
	~FontManager() {}
};

/*
이미지가 많이 들어가면 -> D2D 라이트

단일이미지 -> window에서 제공하는 HFONT 사용
*/