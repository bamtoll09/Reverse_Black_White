#pragma once
#include "Zero.h"
#include "MPlayer.h"
#include "MDoctor.h"
#include "MEnemyManager.h"
#include "MRubbishManager.h"

class Scene1 : public ZeroIScene
{
private:
	MPlayer *mPlayer;
	MDoctor *mDoctor;
	MSlime *mSlime;
	MEyee *mEyee;
	MLeaderEyee *mLeaderEyee;

	ZeroSprite *bg;

	bool initialized;
	bool hit;
	EnemyDeadInfo enemyDeadInfo;
	GottenRubbishInfo gottenRubbishInfo;

public:
	Scene1();
	~Scene1();

	void Update(float eTime);
	void Render();

	float Distance(float x1, float y1, float x2, float y2);
};

