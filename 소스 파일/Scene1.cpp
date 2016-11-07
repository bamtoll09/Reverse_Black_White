#include "stdafx.h"
#include "Scene1.h"
#include <math.h>
#include "MInventory.h"
#include "MChatWindow.h"
#include "MStore.h"
#include "MEnemyManager.h"
#include "MRubbishManager.h"
#include "MBulletManager.h"

Scene1::Scene1() : initialized(false)
{
	mPlayer = new MPlayer();
	mPlayer->SetPos(0.f, 0.f);
	RM->SetPlayer(mPlayer);

	mSlime = (MSlime*)EM->addMEnemy(5.0f, Enemy::slime);
	mSlime->SetPos(100, 100);

	mEyee = (MEyee*)EM->addMEnemy(5.0f, Enemy::eyee);
	mEyee->SetPos(200, 200);

	mLeaderEyee = (MLeaderEyee*)EM->addMEnemy(5.0f, Enemy::leader_eyee);
	mLeaderEyee->SetPos(300, 300);

	mDoctor = new MDoctor();
	
	PushScene(mPlayer);

	PushScene(mSlime);
	PushScene(mEyee);
	PushScene(mLeaderEyee);

	/*for (int i=0; i<3; ++i)
		PushScene(mSlime->damageViewer[i]);*/

	PushScene(mDoctor);

	for (int i=0; i<INVEN->size; ++i)
	{
		PushScene(INVEN->inventory[i]);
		PushScene(INVEN->item_count[i]);
	}

	PushScene(CHAT_WIN->nameSprite);
	PushScene(CHAT_WIN->talkSprite);
	PushScene(CHAT_WIN->nextSprite);
	PushScene(CHAT_WIN->name);

	for (int i = 0; i < 5; ++i)
		PushScene(STORE->mStoreItem[i]);

	PushScene(bg = new ZeroSprite("Texture/Object/Map/background.png"));

	ZeroCameraMgr->SetCameraOn();
	ZeroCameraMgr->SetTarget(mPlayer);
	ZeroCameraMgr->SetScreen(bg->Width(), bg->Height());

	hit = false;
	enemyDeadInfo = {};
	gottenRubbishInfo = {};
}


Scene1::~Scene1()
{
}

void Scene1::Update(float eTime)
{
	ZeroIScene::Update(eTime);

	//ÃÊ±âÈ­
	/*if (!initialized)
	{
		

		initialized = true;
	}*/
	
	if (ZeroInputMgr->GetKey('3') == INPUTMGR_KEYDOWN)
		CHAT_WIN->SetEnable();

	if (ZeroInputMgr->GetKey('4') == INPUTMGR_KEYDOWN)
		STORE->m_bUpdate = !STORE->m_bUpdate;

	if (mSlime != NULL)
	{
		if (IsExistScene(mSlime))
		{
			if (mSlime->IsOverlapped(mPlayer) && !hit && mPlayer->attack)
			{
				printf("HIT!\n");
				
				//printf("%f %f\n", mPlayer->Pos().x, mPlayer->Pos().y);
				mSlime->Damaged(8);
				hit = true;
			}
			else if (mPlayer->attacked) hit = false;
		}
	}

	for (auto node = EM->mEnemyManager.begin(); node != EM->mEnemyManager.end(); ++node)
	{
		if ((*node)->dead)
		{
			MRubbish *rb = RM->addRubbish("apple");
			PushScene(rb);
			rb->SetPos((*node)->Pos().x + (*node)->Width() / 2 - rb->Width() / 2, (*node)->Pos().y + (*node)->Height() - rb->Height());
			EM->popMEnemy((*node));
			PopScene((*node));
			continue;
		}

		switch ((*node)->tag)
		{
		case Enemy::slime:
			
			if ((MSlime*)(*node)->attack)
			{
				for (int i = 0; i < 8; ++i)
					PushScene(BM->addMBullet("Texture/Object/Bullet/Sattack.png", (*node)->Pos().x + (*node)->Width() / 2, (*node)->Pos().y + (*node)->Height() / 2, ((MSlime*)(*node))->bulletSpeed, (float)(0 + (i * 45)), 200.0f));
				((MSlime*)(*node))->attack = false;
			}
			break;

		case Enemy::eyee:
			
			((MEyee*)(*node))->Attack(mPlayer);
			break;

		case Enemy::leader_eyee:

			((MLeaderEyee*)(*node))->Attack(mPlayer);
			for (auto iter = EM->mEnemyManager.begin(); iter != EM->mEnemyManager.end(); ++iter)
			{
				if ((*iter)->tag == Enemy::eyee)
				{
					((MLeaderEyee*)(*node))->Together((MEyee*)(*iter));
				}
			}
			break;
		}
	}

	//if ((enemyDeadInfo = EM->findDeadMEnemy()).index > -1)
	//{
	//	//auto it = EM->mEnemyManager.begin();
	//	//advance(it, num);
	//	
	//}

	if ((gottenRubbishInfo = RM->findGottenRubbish()).index > -1)
	{
		if (gottenRubbishInfo.iter->tag.compare("apple") == 0)
		{
			INVEN->ChangeImage(INVEN->inventory[1], INVEN->item[2]);
			INVEN->InsertItem(2);
		}

		RM->popRubbish(gottenRubbishInfo.iter);
		PopScene(gottenRubbishInfo.iter);
	}

	INVEN->Update(eTime);

	if (STORE->m_bUpdate)
		STORE->Update(eTime);

	if (CHAT_WIN->enable)
		CHAT_WIN->Update(eTime);
}

void Scene1::Render()
{
	ZeroIScene::Render();

	bg->Render();

	for (auto iter = EM->mEnemyManager.begin(); iter != EM->mEnemyManager.end(); ++iter)
	{
		(*iter)->Render();
	}

	for (auto iter = RM->mRubbishManager.begin(); iter != RM->mRubbishManager.end(); ++iter)
	{
		(*iter)->Render();
	}

	for (auto iter = BM->mBulletManager.begin(); iter != BM->mBulletManager.end(); ++iter)
	{
		(*iter)->Render();
	}

	mDoctor->Render();

	mPlayer->Render();

	/*for (auto iter = EM->mEnemyManager.begin(); iter != EM->mEnemyManager.end(); ++iter)	
	{
		for (int i=0; i<3; ++i)
			(*iter)->damageViewer[i]->Render();
	}	*/

	INVEN->Render();

	if (STORE->m_bUpdate)
		STORE->Render();

	if (CHAT_WIN->enable)
		CHAT_WIN->Render();
}

float Scene1::Distance(float x1, float y1, float x2, float y2)
{
	return sqrtf(powf((x1 - x2), 2.f) + ((y1 - y2), 2.f));
}