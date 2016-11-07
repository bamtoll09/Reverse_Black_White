#include "stdafx.h"
#include "MEnemy.h"
#include "MRubbishManager.h"
#include "MEnemyManager.h"

MEnemy::MEnemy(float frameSpeed) : ZeroAnimation(frameSpeed), initialized(false), attack(false),
															  hp(100), damage(0), tag(0), speed(0.0f), dead(false)
{
	/*for (int i = 0; i < 3; i++)
	{
		damageViewer[i] = new DamageViewer(this);
	}*/
}

MEnemy::~MEnemy() { }

void MEnemy::Update(float eTime)
{
	ZeroAnimation::Update(eTime);

	// ÃÊ±âÈ­
	/*if (!initialized)
	{
		

		initialized = true;
	}*/

	if (!dead && hp <= 0)
	{
		dead = true;
		printf("dead\n");
		//RM->addRubbish()->SetPos(Pos().x, Pos().y);
		//EM->popMEnemy(this);
	}

	if (this->Pos().x < 0.0f)
		this->SetPosX(0.0f);
	else if (this->Pos().x + this->Width() > ZeroCameraMgr->Width())
		this->SetPosX(ZeroCameraMgr->Width() - this->Width());
	if (this->Pos().y < 0.0f)
		this->SetPosY(0.0f);
	else if (this->Pos().y + this->Height() > ZeroCameraMgr->Height())
		this->SetPosY(ZeroCameraMgr->Height() - this->Height());

	times += eTime;
}

void MEnemy::Render()
{
	ZeroAnimation::Render();

	
	/*for (int i = 0; i < 3; i++)
	{
		damageViewer[i]->Render();
	}*/
}

void MEnemy::Damaged(int damage)
{
	hp -= damage;
	
	/*for (int i = 0; i < 3; i++)
	{
		if (damageViewer[i]->Activate())
			break;
	}*/
}