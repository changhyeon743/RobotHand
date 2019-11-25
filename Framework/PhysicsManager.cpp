#include "stdafx.h"
#include "PhysicsManager.h"


PhysicsManager::PhysicsManager(Player * p, Enemy * e, BulletManager * bm) : player(p), enemy(e), bm(bm)
{
}

PhysicsManager::~PhysicsManager()
{
}

void PhysicsManager::LateUpdate()
{
	if (!bm || !enemy || !player) return;

	for (Bullet* i : bm->enemyBullets) {
		if (i->col->Intersected(*player->col)) {
			std::cout << "hit" << std::endl;
			player->Hit(i);
			//bm->Destroy(i);
		}
	}
}
