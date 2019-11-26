#include "stdafx.h"
#include "Bullet.h"
#include "TimeManager.h"
#include "Framework.h"
#define PI 3.141592f


Bullet::Bullet(const wchar_t* path,
	float speed, float speedRate,
	float angle, float angleRate,
	float damage)
	:GameObject(path),
	speed(speed), speedRate(speedRate),
	angle(angle), angleRate(angleRate),
	damage(damage)
{
	this->speed = speed;
	col = new CircleCollider(
		*transform, renderer->GetSprite().GetSize().x*0.5f);	//����
}


Bullet::~Bullet()
{
}

void Bullet::Update()
{
	//�� ������ ����� �Լ�
	Move();
	
	

}

void Bullet::Move()
{
	//������ �� ����� �Լ�
	float rad = angle;

	transform->position.x
		+= (speed*cosf(rad)
			*TimeManager::GetDeltaTime());
	transform->position.y
		+= (speed*sinf(rad)
			*TimeManager::GetDeltaTime());

	angle += angleRate;
	speed += speedRate;
}

void Bullet::Destroy()
{
	
	//������ �� ������ �Լ�
}


Direction Bullet::CheckOutOfScreen()
{
	int sw = Framework::GetInstance().GetWinApp().GetScreenWidth();
	int sh = Framework::GetInstance().GetWinApp().GetScreenHeight();
	int bw = (int)renderer->GetSprite().GetSize().x;
	int bh = (int)renderer->GetSprite().GetSize().y;
	Vector2 pos = transform->position;
	Vector2 scale = transform->scale;

	if (pos.x < scale.x * bw * (-1.0f)) {
		return LEFT;
	}
	else if (pos.x > scale.x * bw + sw) {
		return RIGHT;
	}
	else if (pos.y < scale.y * bh * (-1.0f)){
		return UP;
	}
	else if (pos.y > scale.y * bh + sh - 90){
		return DOWN;
	}
	else {
		return NONE;
	}
}