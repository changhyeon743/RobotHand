#pragma once
#include "GameObject.h"
#include "CircleCollider.h"
#include "BulletManager.h"
#include <cstdlib>

#include "Player.h"

class Enemy :
	public GameObject
{
public:
	Enemy(const wchar_t* path, BulletManager* bm);
	~Enemy();

	int count;
	int maxCount;

	float hp;
	void Shoot();
	void Shoot(float dir);

	virtual void Update();

	BulletManager* bm;				//¿©±â
	CircleCollider* col;
};

