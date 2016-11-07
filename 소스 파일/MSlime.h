#pragma once
#include "MMonster.h"

class MSlime : public MMonster
{
public:
	int direction;
	float bulletSpeed, moveTime;

public:
	MSlime(float frameSpeed);
	~MSlime();

	void Update(float eTime);
	void Render();
};

