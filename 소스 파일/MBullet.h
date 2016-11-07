#pragma once
#include "Zero.h"

class MBullet :	public ZeroSprite
{
public:
	ZeroVec firstPos;

	float x, y, speed, degree, limit, radian;
	float speedXeTime;

public:
	MBullet(const char* imagePath, float x, float y, float speed, float degree = 0.0f, float limit = 0.0f);
	~MBullet();

	void Update(float eTime);
	void Render();
};

