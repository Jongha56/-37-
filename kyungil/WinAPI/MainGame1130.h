#pragma once
#include "GameNode.h"
#include "StartScene.h"
#include "SecondScene.h"
#include "HW1201.h"

class MainGame1130 : public GameNode
{
private:
	StartScene* _start;
	SecondScene* _second;
	HW1201* _hw;

	GameNode* _currentScene;


public:
	HRESULT init(void);
	void release(void);
	void update(void);
	void render(void);


	MainGame1130() :_currentScene(nullptr) {}
	~MainGame1130() {}
};

