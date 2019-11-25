#pragma once
#include "GameObject.h"
#include "Enemy.h"

using namespace std;

class Player :
	public GameObject
{
public:
	Player(const wchar_t* path);			//����
	~Player();

	float hp;
	float moveSpeed;	//�̵� �ӵ�
	double direction;
	virtual void Update();	//������Ʈ ó��

	Bullet* target;
	int score;

	void Hit(Bullet* b);


	CircleCollider* col;
	bool CheckOutOfScreen();
};

