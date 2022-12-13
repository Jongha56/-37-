#pragma once
#include "GameNode.h"
class TempSoundScene : public GameNode
{
public:
	HRESULT init(void);
	void update();

	TempSoundScene() {}
	~TempSoundScene() {}
};

/*

※ 과제 제출은 내일 점심까지
 
과제1. 포트폴리오 기획서 마무리

- 내일 과제와 함께 제출


과제2. 포트폴리오 선행 작업 시작

- 구조와 설계 + 리소스 까지


과제3. 블랙홀 구현

- 키 입력을 통해 움직이는 객체가 있고 그 객체로 투사체가 빨려든다.
- 투사체의 갯수는 최소 200개 이상
- 모여든 투사체는 집중되지 않고 자신이 가지고 있는 방향으로 그대로 흘러간다.
*/