#pragma once
#include "MBullet.h"

#define BM MBulletManager::GetInstance()

class MBulletManager
{
public:
	list<MBullet*> mBulletManager;
public:
	MBulletManager();
	~MBulletManager();

	static MBulletManager *GetInstance();

	MBullet *addMBullet(const char* imagePath, float x, float y, float speed, float degree = 0.0f, float limit = 0.0f);
	void popMBullet(MBullet *bullet);
};

