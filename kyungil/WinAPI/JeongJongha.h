#pragma once
#include "GameNode.h"
class JeongJongha : public GameNode
{
private:
	char* xName[10];
public:
	HRESULT init(void);
	void release(void);
	void update(void);
	void render(void);

	JeongJongha() {}
	~JeongJongha() {}
};

