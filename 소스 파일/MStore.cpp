#include "stdafx.h"
#include "MStore.h"

MStore::MStore() : ZeroSprite("Texture/UI/Store/%s.png", "shopbackground")
{
	SetPos(ZeroCameraMgr->Pos().x + (ZeroApp->GetWindowWidth() / 2 - Width() / 2),
		ZeroCameraMgr->Pos().y + (ZeroApp->GetWindowHeight() / 2 - Height() / 2));

	mStoreItem[0] = new MStoreItem("Texture/UI/Store/Heart_1.png", StoreItem::hp, basicCosts[0]);
	mStoreItem[1] = new MStoreItem("Texture/UI/Store/Paru_1.png", StoreItem::paru, basicCosts[1]);
	mStoreItem[2] = new MStoreItem("Texture/UI/Store/Gun_1.png", StoreItem::gun, basicCosts[2]);
	mStoreItem[3] = new MStoreItem("Texture/UI/Store/Ganimedesu_1.png", StoreItem::water, basicCosts[3]);
	mStoreItem[4] = new MStoreItem("Texture/UI/Store/Grad_1.png", StoreItem::grenade, basicCosts[4]);

	Load();

	m_bUpdate = false;
}

MStore::~MStore()
{
}

MStore* MStore::GetInstance()
{
	static MStore instance;
	return &instance;
}

void MStore::Update(float eTime)
{
	ZeroSprite::Update(eTime);

	if (ZeroInputMgr->GetKey(VK_LBUTTON) == INPUTMGR_KEYUP)
	{
		if (ZeroCameraMgr->Pos().x + ZeroInputMgr->GetClientPoint().x >= this->Pos().x + this->Width() - 60.0f && ZeroCameraMgr->Pos().x + ZeroInputMgr->GetClientPoint().x <= this->Pos().x + this->Width())
		{
			if (ZeroCameraMgr->Pos().y + ZeroInputMgr->GetClientPoint().y >= this->Pos().y && ZeroCameraMgr->Pos().y + ZeroInputMgr->GetClientPoint().y <= this->Pos().y + 60.f)
			{
				m_bUpdate = false;
			}
		}

	}

	SetPos(ZeroCameraMgr->Pos().x + (ZeroApp->GetWindowWidth() / 2 - Width() / 2),
		ZeroCameraMgr->Pos().y + (ZeroApp->GetWindowHeight() / 2 - Height() / 2));

	for (int i = 0; i < 5; ++i)
	{
		switch (mStoreItem[i]->tag)
		{
		case StoreItem::hp:
			mStoreItem[i]->SetPos(this->Pos().x + 60.0f, this->Pos().y + 60.0f);
			break;
		case StoreItem::paru:
			mStoreItem[i]->SetPos(this->Pos().x + 392.0f, this->Pos().y + 60.0f);
			break;
		case StoreItem::gun:
			mStoreItem[i]->SetPos(this->Pos().x + 724.0f, this->Pos().y + 60.0f);
			break;
		case StoreItem::water:
			mStoreItem[i]->SetPos(this->Pos().x + 206.0f, this->Pos().y + 335.0f);
			break;
		case StoreItem::grenade:
			mStoreItem[i]->SetPos(this->Pos().x + 579.0f, this->Pos().y + 335.0f);
			break;
		}
	}
}

void MStore::Render()
{
	ZeroSprite::Render();

	for (int i = 0; i < 5; ++i)
		mStoreItem[i]->Render();
}

void MStore::Save()
{
	write = fopen("SaveFile/Store.txt", "W");
	for (int i = 0; i < 5; ++i)
	{
		fprintf(read, "%d %d %d", i, mStoreItem[i]->increase, basicCosts[i]);
	}
}

void MStore::Load()
{
	read = fopen("SaveFile/Store.txt", "r");
	int i = 0;
	while (fscanf(read, "%d %d %d", &i, &(mStoreItem[i]->increase), &basicCosts[i]) != EOF) {}
	printf("Store Load Finish");
}