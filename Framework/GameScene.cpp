#include "stdafx.h"
#include "GameScene.h"
#include "PhysicsManager.h"


GameScene::GameScene()
{
}


GameScene::~GameScene()
{
}

void GameScene::Initialize()
{
	//background
	//	= PushBackGameObject(
	//		new GameObject(L"resources/background.jpg"));

	

	player = (Player*)PushBackGameObject(new Player(L"resources/player/Player.png"));		//여기
	player->transform->SetPosition(160.0f, 100.0f);

	bm = (BulletManager*)PushBackGameObject(new BulletManager());	//여기
	Enemy* e = (Enemy*)PushBackGameObject( new Enemy( L"resources/player/enemy.png", bm));
	e->transform->SetPosition(160.0f, 500.0f);

	//player->SetEnemy(e);
	
	
	PhysicsManager* physicsManager = (PhysicsManager*)PushBackGameObject(new PhysicsManager(player, e, bm));
	mm = (MoveManager*)PushBackGameObject(new MoveManager(player,e, bm));
}
