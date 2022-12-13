#pragma once
#include "GameNode.h"

class MainGame1130 : public GameNode
{
private:



public:
	HRESULT init(void);
	void release(void);
	void update(void);
	void render(void);


	MainGame1130() {}
	~MainGame1130() {}
};

