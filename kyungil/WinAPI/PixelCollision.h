#pragma once
#include "GameNode.h"
//�ȼ��浹�� ���� �� - ĳ���Ͱ��� �浹���� ���
class PixelCollision : public GameNode
{
private:
	GImage* _pixelTank;

	RECT _rc;

	int _probeY;
	float _x, _y;
	//�ȼ��浹�� �ʹ� ������ ���� �߿���



public:
	HRESULT init(void);
	void release(void);
	void update(void);
	void render(void);




	PixelCollision() {}
	~PixelCollision() {}
};

