#include "stdafx.h"
#include "MoveManager.h"
#include "Framework.h"

#include "GameScene.h"
#include "StartScene.h"

MoveManager::MoveManager(Player * p, Enemy * e, BulletManager* bm) : p(p), e(e), bm(bm), movingRight(false), delay(0)
{
	destination = p->transform->position;
	depart = destination;
}

void MoveManager::LateUpdate()
{
	/*if (p->target != NULL) {
		if (p->target != nullptr) {
			p->transform->position = p->target->transform->position;
		}
		 
	}

	*/
	if (p->target != nullptr) {
		p->transform->position = p->target->transform->position;
	}
}


void MoveManager::Update()
{
	if (delay > 0) {
		delay--;
	}
	if (p->CheckOutOfScreen()) {
		std::wstring item = L"Á¡¼ö: ";
		item.append(std::to_wstring(p->score));
		LPCWSTR content = L"·Îºó½¼ÀÌ ÀâÇû½À´Ï´Ù.";

		MessageBoxW(NULL, item.c_str(), content, MB_OK | MB_ICONINFORMATION);
		
		Scene::ChangeScene(new StartScene());
	}
	

	if (InputManager::GetKeyDown(VK_RBUTTON)) {
		destination = InputManager::GetMouseVector2();
		depart = p->transform->position;
	}
	if (InputManager::GetKeyDown(VK_SPACE)) {
		if (delay == 0) {
			Vector2 mouse = InputManager::GetMouseVector2();
			Vector2 player = p->transform->position;


			float a = atan2(mouse.y - player.y, mouse.x - player.x);
			p->transform->position.x += cos(a) * 80;
			p->transform->position.y += sin(a) * 80;


			destination = p->transform->position;
			delay = 400;
		}
	}

	if (InputManager::GetKeyDown('S')) {
		destination = p->transform->position;
	}

	
	if (p->transform->position.GetDistance(destination) > 1) {
		float yy = destination.y - depart.y;
		float xx = destination.x - depart.x;
		float distance = sqrtf(yy*yy + xx*xx);
		float dirX = xx / distance;
		float dirY = yy / distance;
		p->transform->position.x += dirX * 2.5f;
		p->transform->position.y += dirY * 2.5f;
	}


	int sw = Framework::GetInstance().GetWinApp().GetScreenWidth();
	int bw = (int)e->renderer->GetSprite().GetSize().x;
	Vector2 pos = e->transform->position;
	
	if (pos.x < bw) {
		movingRight = true;
	}
	else if (pos.x > sw - bw) {
		movingRight = false;
	}

	if (p->score >= 400) {
		e->transform->position.x += (movingRight ? 2 : -2);
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
