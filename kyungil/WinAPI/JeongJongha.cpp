#include "Stdafx.h"
#include "JeongJongha.h"

HRESULT JeongJongha::init(void)
{
	xName[0] = "������";
	xName[1] = "������";
	xName[2] = "������";
	xName[3] = "������";
	xName[4] = "������";
	xName[5] = "������";
	xName[6] = "������";
	xName[7] = "������";
	xName[8] = "������";
	xName[9] = "������";

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
