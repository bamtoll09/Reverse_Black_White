#pragma once
#include "Zero.h"

#define CHAT_WIN MChatWindow::GetInstance()

class MChatWindow : public ZeroFont
{
private:	
	FILE *read;
	vector<vector<string>> texts;
	vector<string> names;
	char path[20];
	char buf[256];
	int pos, line;
	int temp1, temp2;

public:
	ZeroSprite *nameSprite;
	ZeroSprite *talkSprite;
	ZeroSprite *nextSprite;
	ZeroFont *name;

	string text;
	bool enable;
	bool next;
	bool finish;

public:
	MChatWindow();
	~MChatWindow();

	void Update(float eTime);
	void Render();

	static MChatWindow *GetInstance();

	void SetEnable();
	void Setting();
	void LoadTextFiles(const char *fileName);
};

