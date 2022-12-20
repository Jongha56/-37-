#pragma once
#include "GameNode.h"
#include "JeongJongha.h"
#include "KimDongKyu.h"
#include "SeungChan.h"
#include "ParkGeonWoo.h"

class MainGame : public GameNode
{
private:
	JeongJongha* _j;
	KimDongKyu* _k;
	SeungChan* _n;
	ParkGeonWoo* _p;
public:
	HRESULT init(void);
	void release(void);
	void update(void);
	void render(void);


	MainGame() {}
	~MainGame() {}
};

