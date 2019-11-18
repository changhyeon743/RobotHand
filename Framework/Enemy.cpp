#include "stdafx.h"
#include "Enemy.h"
#include "Math.h"


Enemy::Enemy(const wchar_t * path, BulletManager* bm ) : GameObject(path), bm(bm)
{
	col = new CircleCollider(*transform, renderer->GetSprite().GetSize().x*0.5f);
	count = 0;
	maxCount = 100;
}

Enemy::~Enemy()
{
	SAFE_DELETE(col);
}



void Enemy::Shoot()
{
	
	//printf("%f", atan2(p.y - e.y, p.x - e.x));
	Bullet* b = bm->PushBackEnemyBullet(
		new Bullet(L"resources/player/hand.png", 800.0f, 0.0f, bm->PredictDirection() , 0.00f, 1.0f)
	);
	b->transform->SetScale(0.2f, 0.2f);

	b->transform->position = transform->position;
}

void Enemy::Shoot(float dir)
{
	Bullet* b = bm->PushBackEnemyBullet(
			new Bullet(L"resources/player/hand.png", 300.0f, 0.0f, dir, 0.00f, 1.0f)
		);
	b->transform->SetScale(0.1f, 0.1f);

	b->transform->position = transform->position;
}



void Enemy::Update()
{
	if (count < maxCount) {
		count++;
	}
	else {
		maxCount = rand() % 200 + 80;
		Shoot();
		std::cout << bm->PredictDirection() << endl;
		count = 0;
		bm->Refresh();
	}
	//Shoot();
}
