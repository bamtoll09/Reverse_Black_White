#include "stdafx.h"
#include "MGameManager.h"

MGameManager::MGameManager() : textOn(false)
{
}

MGameManager::~MGameManager()
{
}
MGameManager *MGameManager::GetInstance()
{
	MGameManager instance;
	return &instance;
}