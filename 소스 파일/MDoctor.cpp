#include "stdafx.h"
#include "MDoctor.h"

MDoctor::MDoctor() : ZeroAnimation(5.0f), initialized(false), oneTime(false), moveIndex(0), gapX(0.0f), gapY(0.0f)
{
	for (int i = 1; i <= 4; ++i) // 1: down, 2: right, 3: up, 4: left
	{
		for (int j = 1; j <= 4; ++j)
		{
			PushSprite("Texture/Object/Character/Doctor/walk/walk%d-%d.png", i, j);
		}
	}

	moveFinish.push_back(false);

	SetPos(0.0f, 0.0f);
}

MDoctor::~MDoctor()
{
}

void MDoctor::Update(float eTime)
{
	ZeroAnimation::Update(eTime);
	
	if (!initialized)
	{
		beforePos = this->Pos();

		initialized = true;
	}

	if (beforePos == this->Pos())
		Stop();
	else if (!isRunning)
		Start();

	beforePos = this->Pos();

	if (!moveFinish[0])
		GoTo(300.0f, 300.0f, eTime, 0.25f);
	else if (!moveFinish[1])
		GoTo(0.0f, 0.0f, eTime, 0.25f);
}

void MDoctor::Render()
{
	ZeroAnimation::Render();
}

void MDoctor::NextMove()
{
	++moveIndex;
}

void MDoctor::GoTo(float x, float y, float eTime, float speed)
{
	if (!moveFinish[moveIndex])
	{
		if (!oneTime)
		{
			gapX = x - this->Pos().x;
			gapY = y - this->Pos().y;

			direction = 0;
			// up down
			if (gapY < 0)
				direction = 1;
			else if (gapY > 0)
				direction = 3;

			// left right
			if (gapX < 0)
				direction = 2;
			else if (gapX > 0)
				direction = 4;

			ChangeDirection();

			oneTime = true;
		}

		if (gapX < 0)
		{
			if (this->Pos().x < x)
			{
				oneTime = false;
				moveFinish[moveIndex] = true;
				moveFinish.push_back(false);
				NextMove();
			}
			else
			{
				this->AddPos(gapX * eTime * speed, gapY * eTime * speed);
			}
		}
		else if (gapX > 0)
		{
			if (this->Pos().x > x)
			{
				oneTime = false;
				moveFinish[moveIndex] = true;
				moveFinish.push_back(false);
				NextMove();
			}
			else
			{
				this->AddPos(gapX * eTime * speed, gapY * eTime * speed);
			}
		}
	}
}

void MDoctor::ChangeDirection()
{
	// up
	if (direction == 1)
	{
		this->currentFrame = 8; // 8 ~ 11
		this->startFrame = (int) this->currentFrame;
		this->numberOfFrames = 12;
	}

	// left
	else if (direction == 2)
	{
		this->currentFrame = 12; // 12 ~ 15
		this->startFrame = (int) this->currentFrame;
		this->numberOfFrames = 16;
	}

	// down
	else if (direction == 3)
	{
		this->currentFrame = 0; // 0 ~ 3
		this->startFrame = (int) this->currentFrame;
		this->numberOfFrames = 4;
	}

	// rights
	else if (direction == 4)
	{
		this->currentFrame = 4; // 4 ~ 7
		this->startFrame = (int) this->currentFrame;
		this->numberOfFrames = 8;
	}
}