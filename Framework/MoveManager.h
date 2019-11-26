#pragma once
#include "GameObject.h"
#include "InputManager.h"
#include "Player.h"
#include "Enemy.h"
#include "BulletManager.h"

class MoveManager :
	public GameObject
{
private:
	bool movingRight;
public:
	MoveManager(Player* p, Enemy* e, BulletManager* bm);
	virtual void Update();
	virtual void LateUpdate();
	MoveManager();
	~MoveManager();
	int delay;

	Vector2 depart;
	Vector2 destination;
	Player* p;
	Enemy* e;
	BulletManager* bm;
};

