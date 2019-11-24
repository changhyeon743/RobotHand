#include "stdafx.h"
#include "Player.h"
#include "InputManager.h"
#include <math.h>


Player::Player(const wchar_t* path)
	:GameObject(path), hp(100.0f), score(0)
{

	moveSpeed = 3.0f;
	col = new CircleCollider(
		*transform, renderer->GetSprite().GetSize().x*0.5f);	//¿©±â
	//this->bm = bm;
}


void Player::Update()
{
	score++;
	
	Vector2 p = this->transform->position;
	//Vector2 e = enemy->transform->position;

	//enemy->pm->PushBackDirection(atan2(p.y - e.y, p.x - e.x));
}

void Player::Hit(float damage)
{
	std::wstring item = L"Á¡¼ö: ";
	item.append(std::to_wstring(score));
	LPCWSTR content = L"·Îºó½¼ÀÌ ÀâÇû½À´Ï´Ù.";

	MessageBoxW(NULL, item.c_str(), content, MB_OK | MB_ICONINFORMATION);
	score = 0;
	//hp -= damage;
	//std::cout << "À¸¾Ç!!" << hp << "³²À½ ¤Ð¤Ð" << std::endl;
}

Player::~Player()
{
}
