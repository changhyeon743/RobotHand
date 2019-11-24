#pragma once
#include "GameObject.h"
#include "BulletManager.h"			//����
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

	int score;

	void Hit(float damage);


	CircleCollider* col;
};

