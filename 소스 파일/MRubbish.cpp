#include "stdafx.h"
#include "MRubbish.h"
#include "MRubbishManager.h"

MRubbish::MRubbish(MPlayer *_player) : ZeroSprite("Texture/Example/Object/Rubbish/%s.png", "junk"), gotten(false)
{
	player = _player;
}

MRubbish::~MRubbish()
{
}

void MRubbish::Update(float eTime)
{
	ZeroSprite::Update(eTime);

	if (this->IsOverlapped(player))
	{
		gotten = true;
	}
}

void MRubbish::Render()
{
	ZeroSprite::Render();
}