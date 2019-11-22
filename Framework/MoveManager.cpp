#include "stdafx.h"
#include "MoveManager.h"


MoveManager::MoveManager(Player * p, Enemy * e, BulletManager* bm) : p(p), e(e), bm(bm)
{
}

void MoveManager::Update()
{
	if (InputManager::GetMyKeyState(VK_UP)) {
		p->transform->position.y -= p->moveSpeed;
	}
	if (InputManager::GetMyKeyState(VK_DOWN)) {
		p->transform->position.y += p->moveSpeed;
	}
	if (InputManager::GetMyKeyState(VK_RIGHT)) {
		p->transform->position.x += p->moveSpeed;
	}
	if (InputManager::GetMyKeyState(VK_LEFT)) {
		p->transform->position.x -= p->moveSpeed;
	}

	if (InputManager::GetKeyDown(VK_LBUTTON)) {
		destination = InputManager::GetMouseVector2();
	}

	p->transform->position.x = destination.x;
	p->transform->position.y = destination.y;


	Vector2 player = p->transform->position;
	Vector2 enemy = e->transform->position;
	
	bm->PushBackDirection(atan2(player.y - enemy.y, player.x - enemy.x));
}

MoveManager::MoveManager()
{
}


MoveManager::~MoveManager()
{
}
