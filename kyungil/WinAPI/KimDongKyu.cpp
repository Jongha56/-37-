#include "Stdafx.h"
#include "KimDongKyu.h"

HRESULT KimDongKyu::init(void)
{
	for (int i = 0; i < 10; i++)
	{
		xName[i] = "�赿��";
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
		TextOut(getMemDC(), i * 40, i * 20, xName[i], strlen(xName[i]));
	}
}
