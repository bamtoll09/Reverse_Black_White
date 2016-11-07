#pragma once
#include "MEnemy.h"

class MMonster : public MEnemy
{
public:
	float patternTime;

public:
	MMonster(float frameSpeed);
	~MMonster();

	void Update(float eTime);
	void Render();
};

