#include "stdafx.h"
#include "Player.h"
#include "InputManager.h"
#include <math.h>


Player::Player(const wchar_t* path)
	:GameObject(path), hp(100.0f)
{

	moveSpeed = 3.0f;
	col = new CircleCollider(
		*transform, renderer->GetSprite().GetSize().x*0.5f);	//여기
	//this->bm = bm;
}


void Player::Update()
{
	
	
	Vector2 p = this->transform->position;
	//Vector2 e = enemy->transform->position;

	//enemy->pm->PushBackDirection(atan2(p.y - e.y, p.x - e.x));
}

void Player::Hit(float damage)
{
	hp -= damage;
	std::cout << "으악!!" << hp << "남음 ㅠㅠ" << std::endl;
}


Player::~Player()
{
}
