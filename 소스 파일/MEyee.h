#pragma once
#include "MMonster.h"
#include "MPlayer.h"

class MEyee : public MMonster
{
public:
	MPlayer *player;

	bool isLeaded, initialized;
	int attackMode;
	float radius, radian;

public:
	MEyee(float frameSpeed);
	~MEyee();

	void Update(float eTime);
	void Render();

	void Attack(MPlayer *player);
	void Chase(float eTime);
	void Chase(float eTime, int num);
};

