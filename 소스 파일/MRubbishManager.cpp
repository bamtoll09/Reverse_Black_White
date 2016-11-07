#include "stdafx.h"
#include "MRubbishManager.h"

//MRubbishManager* MRubbishManager::instance{ nullptr };
MRubbishManager::MRubbishManager() { }

MRubbishManager::~MRubbishManager() { }

MRubbishManager *MRubbishManager::GetInstance()
{
	static MRubbishManager instance;
	return &instance;
}

void MRubbishManager::SetPlayer(MPlayer *_player)
{
	player = _player;
}

MRubbish* MRubbishManager::addRubbish(string _tag)
{
	MRubbish *p = new MRubbish(player);
	p->tag = _tag;
	mRubbishManager.push_back(p);
	return p;
}

void MRubbishManager::popRubbish(MRubbish* rubbish)
{
	mRubbishManager.remove(rubbish);
}

gri MRubbishManager::findGottenRubbish()
{
	int i = 0;
	for (auto node = mRubbishManager.begin(); node != mRubbishManager.end(); ++node)
	{
		if ((*node)->gotten)
		{
			return gri{ i, *node };
		}

		++i;
	}
	return gri{ -1, nullptr };
}