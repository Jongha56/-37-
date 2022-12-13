#pragma once
#include "GameNode.h"
//픽셀충돌은 보통 맵 - 캐릭터간의 충돌에만 사용
class PixelCollision : public GameNode
{
private:
	GImage* _pixelTank;

	RECT _rc;

	int _probeY;
	float _x, _y;
	//픽셀충돌을 초반 세팅이 아주 중요함



public:
	HRESULT init(void);
	void release(void);
	void update(void);
	void render(void);




	PixelCollision() {}
	~PixelCollision() {}
};

