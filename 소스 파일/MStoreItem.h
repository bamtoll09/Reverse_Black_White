#pragma once
#include "Zero.h"

namespace StoreItem
{
	enum Type
	{
		hp,
		paru,
		gun,
		water,
		grenade
	};
}

class MStoreItem : public ZeroSprite
{
private:
	FILE *read, *write;

public:
	int tag;
	int basicCost;
	int cost;
	int increase;
public:
	ZeroSprite *wood, *rubbish;
	ZeroFont *woodCost, *rubbishCost;
public:
	MStoreItem(const char* imagePath, int tag, int basicCost);
	~MStoreItem();

	void Update(float eTime);
	void Render();
};

