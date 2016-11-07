#include "stdafx.h"
#include "DamageViewer.h"


DamageViewer::DamageViewer(MEnemy *object) : ZeroFont(30, "")
{
	this->object = object;
	this->SetPosX(object->Pos().x + ZeroMathMgr->RandFloat(0.f, object->Width()));
	this->SetPosY(object->Pos().y + (object->Height() * 0.2f));
	this->SetString("30!");
	this->SetColor(0xffff0000);

	foTime = 0;
	time = 0.f;
	activated = false;
}


DamageViewer::~DamageViewer()
{
}

void DamageViewer::Update(float eTime)
{
	if (activated && object != NULL)
	{
		ZeroFont::Update(eTime);

		if (time >= 0.5f)
		{
			activated = false;
			return;
		}

		this->AddPosY(-70.f * eTime);
		this->SetColorA(255 - (foTime += (int) (510.f * eTime) ));

		time += eTime;
	}
}

void DamageViewer::Render()
{
	if (activated)
		ZeroFont::Render();
}

bool DamageViewer::Activate()
{
	if (!activated)
	{
		activated = true;
		foTime = 0;
		time = 0.f;

		this->SetPosX(object->Pos().x + ZeroMathMgr->RandFloat(0.f, object->Width()));
		this->SetPosY(object->Pos().y + (object->Height() * 0.2f));
		this->SetString("30!");
		this->SetColor(0xffff0000);

		return true;
	} else {
		return false;
	}
}