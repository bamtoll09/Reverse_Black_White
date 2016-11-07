#include "stdafx.h"
#include "MBullet.h"
#include "MBulletManager.h"

MBullet::MBullet(const char* imagePath, float x, float y, float speed, float degree, float limit) : ZeroSprite(imagePath)
{
	firstPos = ZeroVec(x, y);
	this->x = x;
	this->y = y;
	this->speed = speed;
	this->degree = degree;
	this->limit = limit;
	radian = D3DXToRadian(degree);

	SetPos(x, y);
	SetRot(degree);
}

MBullet::~MBullet()
{
}

void MBullet::Update(float eTime)
{
	ZeroSprite::Update(eTime);

	speedXeTime = speed * eTime;

	AddPosX(speedXeTime * cosf(radian));
	AddPosY(speedXeTime * sinf(radian));

	if (limit != 0.0f)
	{
		if (firstPos.Distance(this->Pos()) > limit)
			BM->popMBullet(this);
	}

	if (this->Pos().x + this->Width() < 0.0f || this->Pos().x > ZeroCameraMgr->Width()
		|| this->Pos().y + this->Height() < 0.0f || this->Pos().y > ZeroCameraMgr->Height())
		BM->popMBullet(this);
}

void MBullet::Render()
{
	ZeroSprite::Render();
}