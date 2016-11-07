#include "stdafx.h"
#include "MChatWindow.h"

MChatWindow::MChatWindow() : ZeroFont(40, "", "210 인사동사거리 R", "Texture/Font/TTInsadongsageriR.ttf"), path(".\\TextFile\\"), pos(0), line(0), temp1(0), temp2(0), next(false), finish(false), enable(false)
{
	nameSprite = new ZeroSprite("Texture/UI/ChatWindow/%s.png", "name");
	nameSprite->SetPos(ZeroCameraMgr->Pos().x + 20.7f, ZeroCameraMgr->Pos().y + 527.0f);
	
	talkSprite = new ZeroSprite("Texture/UI/ChatWindow/%s.png", "talk");
	talkSprite->SetPos(ZeroCameraMgr->Pos().x + 20.7f, ZeroCameraMgr->Pos().y + 628.2f);

	nextSprite = new ZeroSprite("Texture/UI/ChatWindow/%s.png", "semo");
	nextSprite->SetPos(ZeroCameraMgr->Pos().x + 1172.0f, ZeroCameraMgr->Pos().y + 908.0f);

	name = new ZeroFont(40, "", "210 인사동사거리 R", "Texture/Font/TTInsadongsageriR.ttf");
	name->SetWrapArea(175, 60);
	name->SetColor(0xffffffff);
	name->SetFormat(DT_CENTER);
	name->SetPos(nameSprite->Pos().x + 25.0f, nameSprite->Pos().y + 25.0f);

	SetWrapArea(1000, 300);
	SetColor(0xffffffff);
	SetFormat(DT_WORDBREAK);
	SetPos(talkSprite->Pos().x + 50.0f, talkSprite->Pos().y + 50.0f);

	LoadTextFiles("Test.txt");

	Setting();
}

MChatWindow::~MChatWindow()
{
}

MChatWindow* MChatWindow::GetInstance()
{
	static MChatWindow instance;
	return &instance;
}

void MChatWindow::Update(float eTime)
{
	ZeroFont::Update(eTime);

	if (enable)
	{
		if (texts[pos].size()-1 == line)
		{
			finish = true;
			next = false;
		}
		else
		{
			finish = false;
			next = true;
		}

		if (ZeroInputMgr->GetKey(VK_SPACE) == INPUTMGR_KEYDOWN)
		{
			if (finish)
			{
				++pos;
				finish = false;
				enable = false;
			}
			else if (next)
			{
				++line;
				next = false;
				Setting();
			}
		}

		printf("%d %d\n", texts[pos].size()-1, line);

		nameSprite->SetPos(ZeroCameraMgr->Pos().x + 20.7f, ZeroCameraMgr->Pos().y + 527.0f);
		talkSprite->SetPos(ZeroCameraMgr->Pos().x + 20.7f, ZeroCameraMgr->Pos().y + 628.2f);
		nextSprite->SetPos(ZeroCameraMgr->Pos().x + 1172.0f, ZeroCameraMgr->Pos().y + 908.0f);
		name->SetPos(nameSprite->Pos().x + 25.0f, nameSprite->Pos().y + 25.0f);
		SetPos(talkSprite->Pos().x + 50.0f, talkSprite->Pos().y + 50.0f);
	}
}

void MChatWindow::Render()
{
	if (enable)
	{
		nameSprite->Render();
		talkSprite->Render();

		ZeroFont::Render();
		name->Render();

		nextSprite->Render();
	}
}

void MChatWindow::SetEnable()
{
	if (!enable)
	{
		if (texts.size() != pos)
		{
			Setting();
			enable = true;
		}
	}
}

void MChatWindow::Setting()
{
	SetString(texts[pos][line]);
	name->SetString(names[pos]);

	printf("%s\n", GetString());
}

void MChatWindow::LoadTextFiles(const char *fileName)
{
	texts.push_back(vector<string>());

	read = fopen(strcat(path, fileName), "r");
	if (read == NULL)
	{
		printf("MChatWindow: TextFile does not exist!\n%s", fileName);
	}
	else {
		fscanf(read, "%s :\n", buf);
		names.push_back(buf);
		int count = 0;
		while (fgets(buf, 256, read) != NULL)
		{
			if (texts[temp1].size() != 0)
				texts[temp1][temp2].append(buf);
			else
				texts[temp1].push_back(buf);
			++count;

			if (count > 2)
			{
				++temp2;
				count = 0;
				texts[temp1].push_back("");
			}
		}
		++temp1;
		fclose(read);
	}
}