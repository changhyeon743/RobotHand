#pragma once
#include "GameObject.h"
#include "BulletManager.h"			//여기
#include "Enemy.h"

using namespace std;

class Player :
	public GameObject
{
public:
	Player(const wchar_t* path);			//여기
	~Player();

	float hp;
	float moveSpeed;	//이동 속도
	double direction;
	virtual void Update();	//업데이트 처리

	int score;

	void Hit(float damage);


	CircleCollider* col;
};

