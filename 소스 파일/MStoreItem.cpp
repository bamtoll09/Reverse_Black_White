#include "stdafx.h"
#include "MStoreItem.h"

MStoreItem::MStoreItem(const char* imagePath, int tag, int basicCost) : ZeroSprite(imagePath)
{
	this->tag = tag;
	this->basicCost = basicCost;
	this->cost = this->basicCost * this->increase + this->basicCost;
	this->increase = 0;

	rubbish = new ZeroSprite("Texture/UI/Store/%s.png", "rubbish");
	rubbish->SetPos(this->Pos().x + this->Width() - rubbish->Width() - 30.0f,
		this->Pos().y + this->Height() - rubbish->Height() - 30.0f);

	rubbishCost = new ZeroFont(24, "", "210 인사동사거리 R", "Texture/Font/TTInsadongsageriR.ttf");
	rubbishCost->SetString(cost);
	rubbishCost->SetPos(rubbish->Pos().x + 35.0f, rubbish->Pos().y + 5.0f);
}

MStoreItem::~MStoreItem()
{
}

void MStoreItem::Update(float eTime)
{
	ZeroSprite::Update(eTime);

	if (ZeroInputMgr->GetKey(VK_LBUTTON) == INPUTMGR_KEYUP)
	{
		if (ZeroCameraMgr->Pos().x + ZeroInputMgr->GetClientPoint().x >= this->Pos().x && ZeroCameraMgr->Pos().x + ZeroInputMgr->GetClientPoint().x <= this->Pos().x + 80.0f)
		{
			if (ZeroCameraMgr->Pos().y + ZeroInputMgr->GetClientPoint().y >= this->Pos().y && ZeroCameraMgr->Pos().y + ZeroInputMgr->GetClientPoint().y <= this->Pos().y + 80.0f)
			{
				++increase;
				printf("increase: %d\n", increase);
			}
		}
	}

	rubbish->SetPos(this->Pos().x + this->Width() - rubbish->Width() - 30.0f,
		this->Pos().y + this->Height() - rubbish->Height() - 30.0f);
}

void MStoreItem::Render()
{
	ZeroSprite::Render();
}