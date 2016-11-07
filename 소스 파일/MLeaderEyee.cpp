#include "stdafx.h"
#include "MLeaderEyee.h"

MLeaderEyee::MLeaderEyee(float frameSpeed) : MEyee(frameSpeed), margin(70.0f)
{
	tag = Enemy::leader_eyee;
	for (int i = 0; i < 4; ++i)
	{
		eyees[i] = nullptr;
		pos[i] = ZeroVec();
	}
}

MLeaderEyee::~MLeaderEyee()
{
}

void MLeaderEyee::Update(float eTime)
{
	MEyee::Update(eTime);
	
	if (eyees[0] != nullptr)
		pos[0] = ZeroVec(this->Pos().x - margin, this->Pos().y - margin); // ¢Ø
	if (eyees[1] != nullptr)
		pos[1] = ZeroVec(this->Pos().x + this->Width() + margin, this->Pos().y - margin); // ¢Ö
	if (eyees[2] != nullptr)
		pos[2] = ZeroVec(this->Pos().x - margin, this->Pos().y + this->Height() + margin); // ¢×
	if (eyees[3] != nullptr)
		pos[3] = ZeroVec(this->Pos().x + this->Width() + margin, this->Pos().y + this->Height() + margin); // ¢Ù

	Chase(eTime);
}

void MLeaderEyee::Render()
{
	MEyee::Render();
}

void MLeaderEyee::Together(MEyee *eyee)
{
	for (int i = 0; i < 4; ++i)
	{
		if (eyees[i] == nullptr)
		{
			if (!eyee->isLeaded && this->Pos().Distance(eyee->Pos()) <= radius)
			{
				eyee->isLeaded = true;
				eyees[i] = eyee;
			}
		}
	}
}

void MLeaderEyee::Chase(float eTime)
{
	for (int i = 0; i < 4; ++i)
	{
		if (eyees[i] != nullptr)
		{
			radian = atan2f(this->pos[i].y - eyees[i]->Pos().y, this->pos[i].x - eyees[i]->Pos().x);

			eyees[i]->AddPosX(speed * cosf(radian) * eTime);
			eyees[i]->AddPosY(speed * sinf(radian) * eTime);
		}
	}
}