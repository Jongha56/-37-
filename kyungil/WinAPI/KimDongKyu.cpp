#include "Stdafx.h"
#include "KimDongKyu.h"

HRESULT KimDongKyu::init(void)
{
	for (int i = 0; i < 10; i++)
	{
		xName[i] = "±èµ¿±Ô";
	}
	return S_OK;
}

void KimDongKyu::release(void)
{
}

void KimDongKyu::update(void)
{
}

void KimDongKyu::render(void)
{
	for (int i = 0; i < 10; i++) {
		TextOut(getMemDC(), (i+10) * 32, (i+10) * 20, xName[i], strlen(xName[i]));
	}
}
