#include "stdafx.h"
#include "MPlayer.h"
#include "MInventory.h"

MPlayer::MPlayer() : ZeroAnimation(5.0f), direction(0), befo_direction(0), speed(250.0f)
{
	for (int i = 1; i <= 4; ++i) // 1: down, 2: right, 3: up, 4: left
	{
		for (int j = 1; j <= 4; ++j)
		{
			PushSprite("Texture/Object/Character/Player/walk/walk%d-%d.png", i, j); // 0 ~ 15
		}
	}

	for (int i = 1; i <= 4; ++i) // 1: down, 2: right, 3: up, 4: left
	{
		for (int j = 1; j <= 4; ++j)
		{
			PushSprite("Texture/Object/Character/Player/basic/attack%d-%d.png", i, j); // 16 ~ 31
		}
	}

	for (int i = 1; i <= 4; ++i) // 1: down, 2: right, 3: up, 4: left
	{
		for (int j = 1; j <= 5; ++j)
		{
			PushSprite("Texture/Object/Character/Player/hit/hit%d-%d.png", i, j); // 32 ~ 51
		}
	}
	
	//m_vRectCollider = new ZeroRect();

	w = a = s = d = vcX = vcY = 0.f;

	equiped = false;
	isAttacking = false;
	attack = false;
	attacked = false;
	attackTime = 0.f;

	carryingItem = 0;
}

MPlayer::~MPlayer()
{
}

void MPlayer::Update(float eTime)
{
	ZeroAnimation::Update(eTime);
	

	// 이동 구현
	speedXeTime = speed * eTime;

	if (ZeroInputMgr->GetKey(VK_UP) == INPUTMGR_KEYON) // w 입력
	{
		w = 1.f;
	} else {
		w = 0.f;
	}

	if (ZeroInputMgr->GetKey(VK_LEFT) == INPUTMGR_KEYON) // a 입력
	{
		a = 1.f;
	} else {
		a = 0.f;
	}

	if (ZeroInputMgr->GetKey(VK_DOWN) == INPUTMGR_KEYON) // s 입력
	{
		s = 1.f;
	} else {
		s = 0.f;
	}

	if (ZeroInputMgr->GetKey(VK_RIGHT) == INPUTMGR_KEYON) // d 입력
	{
		d = 1.f;
	} else {
		d = 0.f;
	}

	if (w == 1 && a == 1 && s == 0 && d == 0) // ↖
		w = a = 0.707f;
	else if (w == 1 && a == 0 && s == 0 && d == 1) // ↗
		w = d = 0.707f;
	else if (w == 0 && a == 1 && s == 1 && d == 0) // ↙
		s = a = 0.707f;
	else if (w == 0 && a == 0 && s == 1 && d == 1) // ↘
		s = d = 0.707f;

	vcX = (-1 * a * speedXeTime) + (d * speedXeTime);
	vcY = (-1 * w * speedXeTime) + (s * speedXeTime);

	/*
	float tempX = powf(vcX, 2.f);
	float tempY = powf(vcY, 2.f);
	float temp = tempX + tempY;

	if (temp > powf(speedXeTime, 2.f)) // 만약 원 밖으로 나갈 때 <이동>
	{
	temp -= powf(speedXeTime, 2.f);

	tempX = temp * (tempX / (tempX + tempY));
	tempY = temp * (tempY / (tempX + tempY));

	if (vcX != 0.f)
	vcX = sqrtf(powf(vcX, 2.f) - tempX);
	if (vcY != 0.f)
	vcY = sqrtf(powf(vcY, 2.f) - tempY);
	}

	if (vcX != 0.f || vcY != 0.f)
	printf("vcX: %f, vcY: %f, temp: %f, speedXeTime: %f\n", vcX, vcY, temp, speedXeTime);
	*/

	this->AddPosX(vcX); // a, d
	this->AddPosY(vcY); // w, s

	if (this->Pos().x < 0.0f)
		this->SetPosX(0.0f);
	else if (this->Pos().x + this->Width() > ZeroCameraMgr->Width())
		this->SetPosX(ZeroCameraMgr->Width() - this->Width());
	if (this->Pos().y < 0.0f)
		this->SetPosY(0.0f);
	else if (this->Pos().y + this->Height() > ZeroCameraMgr->Height())
		this->SetPosY(ZeroCameraMgr->Height() - this->Height());


	// 인벤토리 선택 구현
	if (ZeroInputMgr->GetKey('0') == INPUTMGR_KEYON)
		this->SetPos(0.f, 0.f);

	if (ZeroInputMgr->GetKey('1') == INPUTMGR_KEYDOWN)
	{
		if (!equiped)
			equiped = true;
		carryingItem = INVEN->ChangeItem(0);
	}
	else if (ZeroInputMgr->GetKey('2') == INPUTMGR_KEYDOWN)
	{
		if (!equiped)
			equiped = true;
		carryingItem = INVEN->ChangeItem(1);
	}


	// 아이템 사용 구현
	switch (carryingItem)
	{
	case 1: // sword
	{
		if (!isAttacking)
		{
			if (ZeroInputMgr->GetKey('Z') == INPUTMGR_KEYDOWN)
			{
				if (!attacked)
				{
					printf("ATTACK!\n");
					attacked = true;
					isAttacking = true;
					SetLooping(false);
				}
			}
		}

		break;
	}
	//case 2: // apple
	//{
	//	break;
	//}
	}


	// 애니메이션 구현
	if (w == 0 && a == 0 && s == 0 && d == 0)
	{
		if (!attacked || (attacked && currentFrame >= numberOfFrames))
		{
			Stop();
		}
	}
	else
	{
		Start();
	}
	
	direction = 0;
	if (direction == 0)
	{
		if (w != s)
		{
			if (ZeroInputMgr->GetKey(VK_UP) == INPUTMGR_KEYON)
				direction = 1;
			if (ZeroInputMgr->GetKey(VK_DOWN) == INPUTMGR_KEYON)
				direction = 3;
		}
		if (a != d)
		{
			if (ZeroInputMgr->GetKey(VK_LEFT) == INPUTMGR_KEYON)
				direction = 2;
			if (ZeroInputMgr->GetKey(VK_RIGHT) == INPUTMGR_KEYON)
				direction = 4;
		}
	}

	if (numberOfFrames >= 37)
	{
		if (currentFrame >= numberOfFrames-1)
			attacked = false;
	}

	if (attacked)
	{
		AttackAnimation();
	}
	else
		ChangeDirection();

	printf("%d %d %f\n", isRunning, attacked, currentFrame);
	
	/*
	m_vRectCollider->top = this->Pos().y;
	m_vRectCollider->left = this->Pos().x;
	m_vRectCollider->bottom = this->Pos().y + this->Height();
	m_vRectCollider->right = this->Pos().x + this->Width();
	*/
}

void MPlayer::Render()
{
	ZeroAnimation::Render();

	switch (carryingItem)
	{
	case 1: // sword
		break;
	case 2:
		break;
	case 3:
		break;
	}
}

void MPlayer::ChangeDirection()
{
	if (equiped || (direction != 0 && direction != befo_direction))
	{
		if (!attacked)
		{
			if (carryingItem == 1)
			{

				// up
				if (direction == 1)
				{
					this->currentFrame = 24; // 24 ~ 27
					this->startFrame = (int) this->currentFrame;
					this->numberOfFrames = 28;
				}

				// left
				else if (direction == 2)
				{
					this->currentFrame = 28; // 28 ~ 31
					this->startFrame = (int) this->currentFrame;
					this->numberOfFrames = 32;
				}

				// down
				else if (direction == 3)
				{
					this->currentFrame = 16; // 16 ~ 19
					this->startFrame = (int) this->currentFrame;
					this->numberOfFrames = 20;
				}

				// rights
				else if (direction == 4)
				{
					this->currentFrame = 20; // 20 ~ 23
					this->startFrame = (int) this->currentFrame;
					this->numberOfFrames = 24;
				}
			}
			else {
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
		}
	}

	equiped = false;

	befo_direction = direction;
}


void MPlayer::AttackAnimation()
{
	if (isAttacking)
	{
		if (numberOfFrames == 12 || numberOfFrames == 28)
		{
			this->currentFrame = 42.0f; // 42 ~ 46
			this->startFrame = (int) this->currentFrame;
			this->numberOfFrames = 47;
		}

		// left
		else if (numberOfFrames == 16 || numberOfFrames == 32)
		{
			this->currentFrame = 47; // 47 ~ 51
			this->startFrame = (int) this->currentFrame;
			this->numberOfFrames = 51;
		}

		// down
		else if (numberOfFrames == 4 || numberOfFrames == 20)
		{
			this->currentFrame = 32; // 32 ~ 36
			this->startFrame = (int) this->currentFrame;
			this->numberOfFrames = 37;
		}

		// rights
		else if (numberOfFrames == 8 || numberOfFrames == 24)
		{
			this->currentFrame = 37; // 37 ~ 41
			this->startFrame = (int) this->currentFrame;
			this->numberOfFrames = 42;
		}
		isAttacking = false;
	}
}