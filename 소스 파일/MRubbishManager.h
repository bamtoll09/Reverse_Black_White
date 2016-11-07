#pragma once
#include <list>
#include <algorithm>
#include "MRubbish.h"
#include "MPlayer.h"

#define RM MRubbishManager::GetInstance()

using namespace std;

struct GottenRubbishInfo {
	int index;
	MRubbish* iter;
} typedef gri;

class MRubbishManager
{
private:
	MPlayer *player;

public:
	list<MRubbish*> mRubbishManager;

public:
	MRubbishManager();
	~MRubbishManager();

	static MRubbishManager *GetInstance();

	MRubbish *addRubbish(string _tag);
	void popRubbish(MRubbish *rubbish);
	gri findGottenRubbish();

	void SetPlayer(MPlayer *_player);
};

