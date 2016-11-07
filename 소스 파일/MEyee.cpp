#include "stdafx.h"
#include "MEyee.h"

MEyee::MEyee(float frameSpeed) : MMonster(frameSpeed), isLeaded(false), attackMode(0), radius(500.0f), radian(0.0f)
{
	tag = Enemy::eyee;
	patternTime = 0.0f;
	hp = 12;
	damage = 3;
	speed = 75.0f;

	for (int i=0; i<14; ++i)
		PushSprite("Texture/Object/Enemy/Monster/Eyee/%04d.png", i+1);

	//SetColor(0xffff0000);
	Start();
	patternTime = (float)ZeroMathMgr->RandInt(1, 4);
}

MEyee::~MEyee()
{
}

void MEyee::Update(float eTime)
{
	MMonster::Update(eTime);

	
	if (attackMode)
	{
		if (!isLeaded)
		{
			Chase(eTime);
		}
	} else if (times >= patternTime) {
		initialized = false;
		patternTime = (float)ZeroMathMgr->RandInt(1, 3);
		times = 0.0f;
	} else if (!isLeaded) {
		Chase(eTime, 0);
	}
}

void MEyee::Render()
{
	MMonster::Render();
}

void MEyee::Attack(MPlayer *player)
{
	if (this->Pos().Distance(player->Pos()) <= radius)
	{
		this->player = player;
		attackMode = 1;
	}
}

void MEyee::Chase(float eTime)
{
	radian = atan2f(player->Pos().y - this->Pos().y, player->Pos().x - this->Pos().x);

	AddPosX(speed * cosf(radian) * eTime);
	AddPosY(speed * sinf(radian) * eTime);
}

void MEyee::Chase(float eTime, int num)
{
	if (!initialized)
	{
		radian = atan2f(this->Pos().y + ZeroMathMgr->RandFloat(-35.0f, 35.0f) - this->Pos().y, this->Pos().x + ZeroMathMgr->RandFloat(-35.0f, 35.0f) - this->Pos().x);

		initialized = true;
	}

	AddPosX(speed * cosf(radian) * eTime);
	AddPosY(speed * sinf(radian) * eTime);
}