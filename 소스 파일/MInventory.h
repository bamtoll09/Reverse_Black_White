#pragma once
#include "Zero.h"

#define INVEN MInventory::GetInstance()

namespace Inven
{
	enum Type
	{
		empty,
		sword,
		apple,
		banana
	};
}

class MInventory : public ZeroSprite
{
public:
	bool initialized;
	int size; // ������ ���� ���� ��
	FILE *read, *write;
	FILE *save, *load;

public:
	ZeroSprite *tempSprite;
	// 0: empty, 1: sword, 2: apple, 3: banana
	ZeroSprite *item[5]; // ������ �̹���
	ZeroFont *item_count[3]; // ������ ����
	ZeroSprite *inventory[5]; // �κ��丮

public:
	int inventoryDB[3][3]; // ������ ��ġ, ������ �ڵ�, ������ ����
	float pos[5];

public:
	MInventory();
	~MInventory();

	static MInventory *GetInstance();

	void Update(float eTime);
	void Render();

	void Save();
	bool Load();

	void Setting();

	// temp1.image <- temp2.image
	void ChangeImage(ZeroSprite *temp1, ZeroSprite *temp2);
	int ChangeItem(int invenIndex);
	void InsertItem(int itemCode);
};