#pragma once
#include "Zero.h"

class MDoctor : public ZeroAnimation
{
public:
	ZeroVec beforePos;

	bool initialized;

	// 이동 관련
	vector<bool> moveFinish;
	bool oneTime;
	int moveIndex;
	int direction;
	// 1 2 3 4
	float gapX, gapY;

public:
	MDoctor();
	~MDoctor();

	void Update(float eTime);
	void Render();

	void NextMove();
	void GoTo(float x, float y, float eTime, float speed = 1.0f);
	void ChangeDirection();
};

