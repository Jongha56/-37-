#pragma once

//����
class FontManager
{

public:
	//��Ƽ����Ʈ
	void drawText(HDC hdc, int destX, int destY, char* fontName, int fontSize,
		int fontWeight, char* printString, int length, COLORREF color);
	
	//�����ڵ� - ���ϰ�ü
	void drawText(HDC hdc, int destX, int destY, char* fontName, int font,
		int fontWeight, LPCWSTR printString, int length, COLORREF color);
	
	//�����ڵ� - ������ü
	void drawText(HDC hdc, int destX, int destY, char* fontName, int font,
		int fontWeight, LPCWSTR* printStringArr, int length, COLORREF color);

	FontManager() {}
	~FontManager() {}
};

/*
�̹����� ���� ���� -> D2D ����Ʈ

�����̹��� -> window���� �����ϴ� HFONT ���
*/