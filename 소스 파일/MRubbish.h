#pragma once
#include "Zero.h"
#include "MPlayer.h"

class MRubbish : public ZeroSprite
{
private:
	MPlayer *player;

public:
	bool gotten;

public:
	MRubbish(MPlayer *_player);
	~MRubbish();

	void Update(float eTime);
	void Render();
};

