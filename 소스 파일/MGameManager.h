#pragma once

#define GM MGameManager::GetInstance();

class MGameManager
{
public:
	bool textOn;

public:
	MGameManager();
	~MGameManager();

	static MGameManager *GetInstance();
};

