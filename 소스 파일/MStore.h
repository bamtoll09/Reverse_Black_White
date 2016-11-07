#pragma once
#include "Zero.h"
#include "MStoreItem.h"

#define STORE MStore::GetInstance()

class MStore : public ZeroSprite
{
private:
	FILE *read, *write;

	int basicCosts[5];
public:
	MStoreItem *mStoreItem[5];
public:
	MStore();
	~MStore();

	void Update(float eTime);
	void Render();

	static MStore *GetInstance();

	void Save();
	void Load();
};

