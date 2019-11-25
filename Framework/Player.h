#pragma once
#include "GameObject.h"
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

	Bullet* target;
	int score;

	void Hit(Bullet* b);


	CircleCollider* col;
	bool CheckOutOfScreen();
};

