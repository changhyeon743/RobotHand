#include "stdafx.h"
#include "BulletManager.h"
#include "Scene.h"			//¾À ÀÎÅ¬·çµå

BulletManager::BulletManager()
{
	srand((unsigned int)time(NULL));

	
}
BulletManager::~BulletManager()
{
}
Bullet* BulletManager
::PushBackEnemyBullet(Bullet* b)
{
	Scene::GetCurrentScene().PushBackGameObject(b);
	enemyBullets.push_back(b);
	return b;
}
void BulletManager::Destroy(Bullet* b)
{
	destroyed.push_back(b);
}
void BulletManager::Update()
{
	for (auto& i : enemyBullets)
	{
		if (i->CheckOutOfScreen() != NONE) {
			if (i->CheckOutOfScreen() != DOWN) {
				i->angle -= 3.14f;
			}
			else {

				Destroy(i);
			}
		}
	}
}
void BulletManager::Remove()
{
	for (auto& i : destroyed)
	{
		i->Destroy();
		enemyBullets.remove(i);
		Scene::GetCurrentScene().Destroy(i);
	}
	destroyed.clear();
}
void BulletManager::LateUpdate()
{
	Remove();
}


void BulletManager::PushBackDirection(float d)
{
	directions.push_back(d);
}

float BulletManager::PredictDirection()
{
	if (!directions.empty())
		return directions.back() + (rand() % 3 + -1) * (rand() % 3 + 1) * 0.05f;
	else
		return 0.0f;
	/*float xSum = 0, ySum = 0, xxSum = 0, xySum = 0, slope, intercept;
	std::vector<float> xData;
	for (long i = 0; i < directions.size(); i++)
	{
		xData.push_back(directions[i]);
	}
	for (long i = 0; i < directions.size(); i++)
	{
		xSum += xData[i];
		ySum += directions[i];
		xxSum += xData[i] * xData[i];
		xySum += xData[i] * directions[i];
	}
	return ( directions.size() + 1 ) * (directions.size() * xySum - xSum * ySum) / (directions.size() * xxSum - xSum * xSum);*/
}

void BulletManager::Refresh() {
	directions.clear();
}