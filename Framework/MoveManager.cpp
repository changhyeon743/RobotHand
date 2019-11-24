#include "stdafx.h"
#include "MoveManager.h"




MoveManager::MoveManager(Player * p, Enemy * e, BulletManager* bm) : p(p), e(e), bm(bm), moving(false)
{
	destination = p->transform->position;
	depart = destination;
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

	if (InputManager::GetKeyDown(VK_RBUTTON)) {
		destination = InputManager::GetMouseVector2();
		depart = p->transform->position;
	}
	if (InputManager::GetKeyDown(VK_SPACE)) {
		Vector2 mouse = InputManager::GetMouseVector2();
		Vector2 player = p->transform->position;

		float a = atan2(mouse.y - player.y, mouse.x - player.x);
		p->transform->position.x += cos(a) * 100;
		p->transform->position.y += sin(a) * 100;
	}

	
	if (p->transform->position.GetDistance(destination) > 1) {
		float yy = destination.y - depart.y;
		float xx = destination.x - depart.x;
		float distance = sqrtf(yy*yy + xx*xx);
		float dirX = xx / distance;
		float dirY = yy / distance;
		p->transform->position.x += dirX * 2;
		p->transform->position.y += dirY * 2;

	}
	
	

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
