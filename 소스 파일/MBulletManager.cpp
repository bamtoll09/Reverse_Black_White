#include "stdafx.h"
#include "MBulletManager.h"

MBulletManager::MBulletManager()
{
}

MBulletManager::~MBulletManager()
{
}

MBulletManager* MBulletManager::GetInstance()
{
	static MBulletManager instance;
	return &instance;
}

MBullet* MBulletManager::addMBullet(const char* imagePath, float x, float y, float speed, float degree, float limit)
{
	MBullet *bullet = new MBullet(imagePath, x, y, speed, degree, limit);
	mBulletManager.push_back(bullet);
	return bullet;
}

void MBulletManager::popMBullet(MBullet *bullet)
{
	mBulletManager.remove(bullet);
}