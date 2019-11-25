#pragma once
#include "GameObject.h"
#include "Player.h"
#include "Enemy.h"
#include "MoveManager.h"

class PhysicsManager :
	public GameObject
{
public:
	PhysicsManager(Player* p, Enemy* e, BulletManager* bm);
	~PhysicsManager();

	Player* player;
	Enemy* enemy;
	BulletManager* bm;

	virtual void LateUpdate();
};

