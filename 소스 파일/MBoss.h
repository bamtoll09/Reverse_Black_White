#pragma once
#include "MEnemy.h"

class MBoss : public MEnemy
{
public:
	MBoss();
	~MBoss();

	void Update(float eTime);
	void Render();
};

