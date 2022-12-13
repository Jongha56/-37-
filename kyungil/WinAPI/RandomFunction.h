#pragma once
#include "SingletonBase.h"

class RandomFunction : public SingletonBase <RandomFunction>
{
public:
	RandomFunction()
	{
		//API 공용함수
		//GetTickCount(): API 함수로 OS 가 부팅된 후의 경과 시간을 체크
		//ㄴ 밀리세컨 단위로 체크가 가능하며 밀리세컨 단위로 시간값을
		//반환하기 때문에 규모가 크지 않은 난수에 좋다.
		srand(GetTickCount64()); //난수 시드 초기화
	}
	~RandomFunction() {};

	//11.16 추가 -> 의미는 없지만 코드의 통일성을 부여하기위해 추가
	HRESULT init() { return S_OK; }
	
	inline int getInt(int num) {
		return rand() % num;
	}

	inline int getFromIntTo(int fromNum, int toNum) {
		return rand() % (toNum - fromNum + 1) + fromNum;
	}

	inline float getFloat(void) {
		return (float)rand() / (float)RAND_MAX;
	}

	inline float getFloat(float num) {
		return (float)rand() / (float)RAND_MAX * num;
	}

	inline float getFromFloatTo(float fromNum, float toNum) {
		float rnd = (float)rand() / (float)RAND_MAX;
		return (rnd * (toNum - fromNum) + fromNum);
	}
};