#include "stdafx.h"
#include "MEnemyManager.h"

MEnemyManager::MEnemyManager() { }

MEnemyManager::~MEnemyManager() { }

MEnemyManager *MEnemyManager::GetInstance()
{
	static MEnemyManager instance;
	return &instance;
}

MEnemy *MEnemyManager::addMEnemy(float frameSpeed, int type)
{
	MEnemy *mEnemy = new MEnemy(frameSpeed);

	switch (type)
	{
	case Enemy::slime: mEnemy = new MSlime(frameSpeed); break;
	case Enemy::eyee: mEnemy = new MEyee(frameSpeed); break;
	case Enemy::leader_eyee: mEnemy = new MLeaderEyee(frameSpeed); break;
	case Enemy::raindow: break;
	}
	mEnemyManager.push_back(mEnemy);
	return mEnemy;
}

void MEnemyManager::popMEnemy(MEnemy *mEnemy)
{
	mEnemyManager.remove(mEnemy);
}

edi MEnemyManager::findDeadMEnemy()
{
	int i = 0;
	for (auto node = mEnemyManager.begin(); node != mEnemyManager.end(); ++node)
	{
		if ((*node)->dead)
		{
			return edi{ i, *node };
		}

		++i;
	}
	return edi{ -1, nullptr };
}