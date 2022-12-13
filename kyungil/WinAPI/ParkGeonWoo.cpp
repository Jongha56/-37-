#include "Stdafx.h"
#include "ParkGeonWoo.h"

HRESULT ParkGeonWoo::init(void)
{
	xName[0] = "박건우";
	xName[1] = "박건우";
	xName[2] = "박건우";
	xName[3] = "박건우";
	xName[4] = "박건우";
	xName[5] = "박건우";
	xName[6] = "박건우";
	xName[7] = "박건우";
	xName[8] = "박건우";
	xName[9] = "박건우";

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
