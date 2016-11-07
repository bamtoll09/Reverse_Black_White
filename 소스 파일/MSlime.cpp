#include "stdafx.h"
#include "MSlime.h"
#include "MBulletManager.h"

MSlime::MSlime(float frameSpeed) : MMonster(frameSpeed), bulletSpeed(400.0f), moveTime(0.0f)
{
	tag = Enemy::slime;
	patternTime = 1.0f;
	hp = 24;
	damage = 10;
	speed = 100.0f;

	PushSprite("Texture/Object/Enemy/Monster/Slime/00%d.png", 1);
	PushSprite("Texture/Object/Enemy/Monster/Slime/00%d.png", 2);
	PushSprite("Texture/Object/Enemy/Monster/Slime/00%d.png", 3);
	PushSprite("Texture/Object/Enemy/Monster/Slime/00%d.png", 4);
	PushSprite("Texture/Object/Enemy/Monster/Slime/00%d.png", 5);
	PushSprite("Texture/Object/Enemy/Monster/Slime/00%d.png", 6);
	Start();

	moveTime = ZeroMathMgr->RandFloat(1.0f, 3.5f);

	switch (ZeroMathMgr->RandInt(1, 4))
	{
	case 1: direction = 1; break;
	case 2: direction = 2; break;
	case 3: direction = 3; break;
	case 4: direction = 4; break;
	}
}

MSlime::~MSlime()
{
}

void MSlime::Update(float eTime)
{
	MMonster::Update(eTime);

	if (patternTime >= 1.0f)
	{
		attack = true;
		patternTime = 0.0f;
	}

	if (times >= moveTime)
	{
		switch (ZeroMathMgr->RandInt(1, 4))
		{
		case 1: direction = 1; break;
		case 2: direction = 2; break;
		case 3: direction = 3; break;
		case 4: direction = 4; break;
		}

		moveTime = ZeroMathMgr->RandFloat(1.0f, 3.5f);
		times = 0.0f;
	}
	
	switch (direction)
	{
	case 1: AddPosX(-speed * eTime); break;
	case 2: AddPosX(speed * eTime); break;
	case 3: AddPosY(-speed * eTime); break;
	case 4: AddPosY(speed * eTime); break;
	}

	patternTime += eTime;
}

void MSlime::Render()
{
	MMonster::Render();
}