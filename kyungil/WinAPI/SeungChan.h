#pragma once
#include "GameNode.h"

class SeungChan  : public GameNode
{
private:
	
	void namePrint(void);
public:
	HRESULT init(void);
	void release(void);
	void update(void);
	void render(void);
};

