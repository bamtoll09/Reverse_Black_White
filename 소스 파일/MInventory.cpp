#include "stdafx.h"
#include "MInventory.h"

//MInventory* MInventory::instance{ nullptr }; // 수현찡

MInventory::MInventory() : ZeroSprite("Texture/UI/Inventory/%s.png", "Inven_bg5"), initialized(false), size(3)
{
	// fs
	{
		read = fopen(".\\SaveFile\\Inventory.txt", "r");
		if (read == NULL)
		{
			printf("MInventory: SaveFile does not exist!\n");

			write = fopen(".\\SaveFile\\Inventory.txt", "w");

			for (int i = 0; i < size; i++) // 0으로 초기화
			{
				for (int j = 0; j < 3; j++)
				{
					if (i == 0) // 기본 칼
						inventoryDB[i][j] = 1;
				}
			}

			for (int i = 0; i < size; i++) // 값 저장
			{
				for (int j = 0; j < 3; j++)
					fprintf(write, "%d ", inventoryDB[i][j]);

				fprintf(write, "\n");
			}
			fclose(write);
		}
		else {
			for (int i = 0; i < size; i++) // 값 불러오기
				for (int j = 0; j < 3; j++)
					fscanf(read, "%d", &inventoryDB[i][j]);
			fclose(read);
		}

		//for (int i = 0; i < size; i++) // 값 처리 로그
		//	for (int j = 0; j < 3; j++)
		//		printf("%d ", inventoryDB[i][j]);
	}

	// 생성자
	// 아이템 세팅
	SetPos(ZeroCameraMgr->Pos().x + 784.0f, ZeroCameraMgr->Pos().y);

	pos[0] = 818.0f;
	pos[1] = 909.0f;
	pos[2] = 1000.0f;
	pos[3] = 1091.0f;
	pos[4] = 1182.0f;

	tempSprite = new ZeroSprite("Texture/Example/UI/Inventory/%s.png", "Item_Empty");

	item[0] = new ZeroSprite("Texture/UI/Inventory/%s.png", "box"); // Item_Empty
	item[1] = new ZeroSprite("Texture/Example/UI/Inventory/%s.png", "Item_Sword");
	item[2] = new ZeroSprite("Texture/Example/UI/Inventory/%s.png", "Item_Apple");
	item[3] = new ZeroSprite("Texture/Example/UI/Inventory/%s.png", "Item_Banana");
	item[4] = new ZeroSprite("Texture/UI/Inventory/%s.png", "box");

	item[0]->tag = "0";
	item[1]->tag = "1";
	item[2]->tag = "2";
	item[3]->tag = "3";
	item[4]->tag = "4";

	for (int i = 0; i < size; ++i)
	{
		inventory[i] = new ZeroSprite("Texture/UI/Inventory/%s.png", "box");
		inventory[i]->tag = "0";
		inventory[i]->SetPos(ZeroCameraMgr->Pos().x + pos[i], ZeroCameraMgr->Pos().y + 17.0f);
	}

	// 아이템 갯수 세팅
	for (int i = 0; i < size; i++)
	{
		item_count[i] = new ZeroFont(24, "", "210 인사동사거리 R", "Texture/Font/TTInsadongsageriR.ttf");
		item_count[i]->SetColor(0xff000000);
		item_count[i]->SetHeight(30.0f);

		item_count[i]->SetPos(inventory[i]->Pos().x + inventory[i]->Width() - 5.0f - item_count[i]->Width(),
			inventory[i]->Pos().y + inventory[i]->Height() - 5.0f - item_count[i]->Height());
		
		if (inventoryDB[i][2] < 10)
			item_count[i]->SetWidth(12.0f);
		else
			item_count[i]->SetWidth(24.0f);
		//printf("%f, %f\n", item_count[i]->Width(), item_count[i]->Height());
	}

	Setting();
}


MInventory::~MInventory()
{
}

MInventory *MInventory::GetInstance()
{
	static MInventory instance;
	return &instance;
}

void MInventory::Update(float eTime)
{
	ZeroSprite::Update(eTime);

	for (int i = 0; i < size; ++i)
	{
		inventory[i]->SetPos(ZeroCameraMgr->Pos().x + pos[i], ZeroCameraMgr->Pos().y + 17.0f);
	}

	SetPos(ZeroCameraMgr->Pos().x + 784.0f, ZeroCameraMgr->Pos().y);

	for (int i = 0; i < size; ++i)
	{
		item_count[i]->SetPos(inventory[i]->Pos().x + inventory[i]->Width() - 5.0f - item_count[i]->Width(),
			inventory[i]->Pos().y + inventory[i]->Height() - 5.0f - item_count[i]->Height());
	}
	if (initialized)
	{
		initialized = true;
	}
}

void MInventory::Render()
{
	ZeroSprite::Render();

	for (int i = 0; i < size; ++i)
	{
		inventory[i]->Render();
		item_count[i]->Render();
	}
}

void MInventory::Setting()
{
	for (int i = 0; i < size; i++)
	{
		if (inventoryDB[i][0] != 0 && inventoryDB[i][1] != 0 && inventoryDB[i][2] != 0) // 아이템 위치
		{
			ChangeImage(inventory[i], item[inventoryDB[i][1]]);
			if (inventoryDB[i][2] > 1)
			{
				item_count[i]->SetString(inventoryDB[i][2]);

				item_count[i]->SetPos(inventory[i]->Pos().x + inventory[i]->Width() - 10.0f - item_count[i]->Width(),
					inventory[i]->Pos().y + inventory[i]->Height() - 10.0f - item_count[i]->Height());
				//printf("%f, %f\n", item_count[i]->Width(), item_count[i]->Height());
			}
		}
	}
}

void MInventory::Save()
{
	save = fopen(".\\SaveFile\\Inventory.txt", "w");

	for (int i = 0; i < size; i++) // 값 저장
	{
		for (int j = 0; j < 3; j++)
			fprintf(save, "%d ", inventoryDB[i][j]);

		fprintf(save, "\n");
	}
	fclose(save);
}

bool MInventory::Load()
{
	load = fopen(".\\SaveFile\\Inventory.txt", "r");
	if (load == NULL)
	{
		printf("MInventory: SaveFile does not exist!\n");
		return false;
	} else {
		for (int i = 0; i < size; i++) // 값 불러오기
			for (int j = 0; j < 3; j++)
				fscanf(load, "%d", &inventoryDB[i][j]);
		fclose(load);
		return true;
	}
}

void MInventory::ChangeImage(ZeroSprite *temp1, ZeroSprite *temp2)
{
	tempSprite = temp1;
	temp1->tag = temp2->tag;
	temp1->texture = temp2->texture;
	temp1->SetPos(tempSprite->Pos().x, tempSprite->Pos().y);
}

int MInventory::ChangeItem(int invenIndex)
{
	return stoi(inventory[invenIndex]->tag); // string to int
}

void MInventory::InsertItem(int itemCode)
{
	for (int i = 0; i < size; ++i)
	{
		if (inventoryDB[i][0] != 0 && inventoryDB[i][1] == itemCode)
		{
			++inventoryDB[i][2];

			if (inventoryDB[i][2] > 1)
			{
				item_count[i]->SetString(inventoryDB[i][2]);

				item_count[i]->SetPos(inventory[i]->Pos().x + inventory[i]->Width() - 10.0f - item_count[i]->Width(),
					inventory[i]->Pos().y + inventory[i]->Height() - 10.0f - item_count[i]->Height());
				//printf("%f, %f\n", item_count[i]->Width(), item_count[i]->Height());
			}
			Save();
			return;
		}
	}

	for (int i = 0; i < size; ++i)
	{
		if (inventory[i]->tag.compare("0") == 0)
		{
			ChangeImage(inventory[i], item[itemCode]);
			Save();
			return;
		}
	}
}