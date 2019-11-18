#pragma once
#include "GameObject.h"
#include "InputManager.h"
#include "Player.h"
#include "Enemy.h"
#include "BulletManager.h"

class MoveManager :
	public GameObject
{
public:
	MoveManager(Player* p, Enemy* e, BulletManager* bm);
	virtual void Update();
	MoveManager();
	~MoveManager();

	Player* p;
	Enemy* e;
	BulletManager* bm;
};

