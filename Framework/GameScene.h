#pragma once
#include "Scene.h"
#include "Player.h"
#include "Enemy.h"
#include "InputManager.h"
#include "MoveManager.h"

class GameScene :
	public Scene
{
public:
	GameScene();
	~GameScene();
	BulletManager* bm;
	virtual void Initialize();
	Player* player;
	GameObject* background;
	Enemy* enemy;

	MoveManager* mm;
};
