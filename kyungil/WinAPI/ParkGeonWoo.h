#pragma once
#include "GameNode.h"

class ParkGeonWoo : public GameNode
{
public:
	HRESULT init(void);
	void release(void);
	void update(void);
	void render(void);

	ParkGeonWoo() {}
	~ParkGeonWoo() {}

private:
	char* xName[10];
};



