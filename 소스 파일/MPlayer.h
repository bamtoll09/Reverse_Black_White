#pragma once
#include "Zero.h"

class MPlayer : public ZeroAnimation
{
public:
	//ZeroRect *m_vRectCollider;

	// �̵� ����
	int direction, befo_direction;
	// 1 2 3 4
	float w, a, s, d;
	float speed;
	float vcX, vcY;
	float speedXeTime;

	// ���� ����
	bool equiped;
	bool attack;
	bool attacked;
	bool isAttacking;
	float attackTime;

	// ������ ����
	int carryingItem;
	
public:
	MPlayer();
	~MPlayer();

	void Update(float eTime);
	void Render();

	void ChangeDirection();
	void AttackAnimation();
};

