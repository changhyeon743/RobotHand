#include "stdafx.h"
#include "Player.h"
#include "InputManager.h"
#include <math.h>
#include "Framework.h"

Player::Player(const wchar_t* path)
	:GameObject(path), hp(100.0f), score(0)
{

	moveSpeed = 3.0f;
	col = new CircleCollider(
		*transform, renderer->GetSprite().GetSize().x*0.5f);	//여기
	//this->bm = bm;
}


void Player::Update()
{
	score++;
	
	Vector2 p = this->transform->position;
	//Vector2 e = enemy->transform->position;

	//enemy->pm->PushBackDirection(atan2(p.y - e.y, p.x - e.x));
}

void Player::Hit(Bullet* b)
{
	target = b;
	//hp -= damage;
	//std::cout << "으악!!" << hp << "남음 ㅠㅠ" << std::endl;
}

Player::~Player()
{
}

bool Player::CheckOutOfScreen()
{
	int sw = Framework::GetInstance().GetWinApp().GetScreenWidth();
	int sh = Framework::GetInstance().GetWinApp().GetScreenHeight();
	
	int bw = (int) this->renderer->GetSprite().GetSize().x;
	int bh = (int)renderer->GetSprite().GetSize().y;

	std::cout << transform->position.y << "/" << sh - bh - 50 << std::endl;
	return transform->position.y > sh -bh - 50;
}