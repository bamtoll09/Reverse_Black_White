#include "stdafx.h"
#include "MMonster.h"

MMonster::MMonster(float frameSpeed) : MEnemy(frameSpeed)
{
}

MMonster::~MMonster()
{
}

void MMonster::Update(float eTime)
{
	MEnemy::Update(eTime);
}

void MMonster::Render()
{
	MEnemy::Render();
}