#include "Stdafx.h"
#include "JeongJongha.h"

HRESULT JeongJongha::init(void)
{
	xName[0] = "정종하";
	xName[1] = "정종하";
	xName[2] = "정종하";
	xName[3] = "정종하";
	xName[4] = "정종하";
	xName[5] = "정종하";
	xName[6] = "정종하";
	xName[7] = "정종하";
	xName[8] = "정종하";
	xName[9] = "정종하";

	return S_OK;
}

void JeongJongha::release(void)
{
}

void JeongJongha::update(void)
{
}

void JeongJongha::render(void)
{
	for (int i = 0; i < 10; i++) {
		TextOut(getMemDC(), i*30, i * 20, xName[i], strlen(xName[i]));
	}
}
