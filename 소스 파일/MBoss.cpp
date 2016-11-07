#include "stdafx.h"
#include "MBoss.h"

MBoss::MBoss() : MEnemy(5.0f)
{
}

MBoss::~MBoss()
{
}

void MBoss::Update(float eTime)
{
	MEnemy::Update(eTime);
}

void MBoss::Render()
{
	MEnemy::Render();
}