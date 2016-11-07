#pragma once
#include "Zero.h"
#include "MEnemy.h"

class DamageViewer : public ZeroFont
{
public:
	MEnemy *object;

	int foTime; // FadeOut Time
	float time;
	bool activated;
public:
	DamageViewer(MEnemy *object);
	~DamageViewer();

	void Update(float eTime);
	void Render();

	bool Activate();
};

