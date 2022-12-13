#pragma once
#include "GameNode.h"
class KimDongKyu : public GameNode
{
private:

	char* xName[10];

public:
	HRESULT init(void);
	void release(void);
	void update(void);
	void render(void);

	KimDongKyu() {}
	~KimDongKyu() {}
};

