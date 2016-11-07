#pragma once
#include "MEyee.h"

class MLeaderEyee : public MEyee
{
public:
	MEyee *eyees[4];
	ZeroVec pos[4];

	float margin;

public:
	MLeaderEyee(float frameSpeed);
	~MLeaderEyee();

	void Update(float eTime);
	void Render();

	void Together(MEyee *eyee);
	void Chase(float eTime);
};

