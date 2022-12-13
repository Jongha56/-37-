#pragma once
#include "GameNode.h"
#include "JeongJongha.h"
#include "KimDongKyu.h"
#include "ParkGeonWoo.h"

class MainGame1130 : public GameNode
{
private:
	JeongJongha* _j;
	KimDongKyu* _k;
	ParkGeonWoo* _p;

public:
	HRESULT init(void);
	void release(void);
	void update(void);
	void render(void);


	MainGame1130() {}
	~MainGame1130() {}
};

