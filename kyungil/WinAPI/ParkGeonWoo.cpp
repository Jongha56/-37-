#include "Stdafx.h"
#include "ParkGeonWoo.h"

HRESULT ParkGeonWoo::init(void)
{
	xName[0] = "�ڰǿ�";
	xName[1] = "�ڰǿ�";
	xName[2] = "�ڰǿ�";
	xName[3] = "�ڰǿ�";
	xName[4] = "�ڰǿ�";
	xName[5] = "�ڰǿ�";
	xName[6] = "�ڰǿ�";
	xName[7] = "�ڰǿ�";
	xName[8] = "�ڰǿ�";
	xName[9] = "�ڰǿ�";

	return S_OK;
}

void ParkGeonWoo::release(void)
{
}

void ParkGeonWoo::update(void)
{
}

void ParkGeonWoo::render(void)
{
	for (int i = 0; i < 10; i++)
	{
		TextOut(getMemDC(), 590 - i * 30, i * 20, xName[i], strlen(xName[i]));
	}
}
