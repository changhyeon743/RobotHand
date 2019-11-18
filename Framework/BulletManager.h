#pragma once
#include "GameObject.h"
#include "Bullet.h"
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

class BulletManager :
	public GameObject
{
public:
	BulletManager();
	~BulletManager();

	std::list<Bullet*> enemyBullets;
	Bullet* PushBackEnemyBullet(Bullet* b);
	void Destroy(Bullet* b);
	virtual void Update();
	virtual void LateUpdate();

	void PushBackDirection(float d);
	float PredictDirection();
	void Refresh();


private:
	std::list<Bullet*> destroyed;
	void Remove();

	vector<float> directions;

};

