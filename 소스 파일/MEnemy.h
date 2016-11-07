#pragma once
#include "Zero.h"

namespace Enemy
{
	enum Type
	{
		slime,
		eyee,
		leader_eyee,
		raindow
	};
}

class MEnemy : public ZeroAnimation
{
public:
	bool initialized, attack;
	int hp;
	int damage;
	float times, speed;
	int tag;

public:
	bool dead;
	//DamageViewer *damageViewer[3];

public:
	MEnemy(float frameSpeed);
	virtual ~MEnemy();

	void Update(float eTime);
	void Render();

	void Damaged(int damage);
};

