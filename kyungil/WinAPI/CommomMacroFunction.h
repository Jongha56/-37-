#pragma once
//도형 함수

//POINT
inline POINT PointMake(int x, int y) {
	POINT pt = { x,y };
	return pt;
}

//bool(정수가 아님) vs BOOL(0,1 정수) 모호함 발생할 수 있음

//선그리기
inline void LineMake(HDC hdc, int startX, int startY, int endX, int endY) {
	MoveToEx(hdc, startX, startY, NULL);
	LineTo(hdc, endX, endY);
}

//RECT 만들기
inline RECT RectMake(int x, int y, int width, int height) {
	RECT rc = { x, y, x + width, y + height };
	return rc;
}

//사각형 그리기 (렉탱글 함수 사용)
inline void DrawRectMake(HDC hdc, RECT rc) {
	Rectangle(hdc, rc.left, rc.top, rc.right, rc.bottom);
}

//RECT 중심점 만들기
inline RECT RectMakeCenter(int x, int y, int width, int height) {
	RECT rc = { x - width / 2, y - height / 2, x + width / 2, y + height / 2 };
	return rc;
}


//사각형 그리기 (렉탱글 함수 사용)
inline void RectangleMake(HDC hdc, int x, int y, int width, int height) {
	Rectangle(hdc, x, y, width, height);
}

//타원 그리기 (일립스 함수 사용)
inline void EllipseMake(HDC hdc, int x, int y, int width, int height) {
	Ellipse(hdc, x, y, x + width, y + height);
}

//타원 센터점 중심으로 그리기 (일립스 함수 사용)
inline void EllipseMakeCenter(HDC hdc, int x, int y, int width, int height) {
	Ellipse(hdc, x - width / 2, y - height / 2, x + width / 2, y + height / 2);
}
