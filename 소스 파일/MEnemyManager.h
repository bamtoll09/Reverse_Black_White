#pragma once
#include <list>
#include <algorithm>
#include "MEnemy.h"
#include "MSlime.h"
#include "MLeaderEyee.h"

#define EM MEnemyManager::GetInstance()

using namespace std;

struct EnemyDeadInfo {
	int index;
	MEnemy* iter;
} typedef edi;

class MEnemyManager
{
public:
	list<MEnemy*> mEnemyManager;

public:
	MEnemyManager();
	~MEnemyManager();

	static MEnemyManager *GetInstance();
	MEnemy *addMEnemy(float frameSpeed, int type = Enemy::slime);
	void popMEnemy(MEnemy *mEnemy);
	edi findDeadMEnemy();
};

