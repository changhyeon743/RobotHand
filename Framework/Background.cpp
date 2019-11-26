#include "stdafx.h"
#include "Background.h"
#include "InputManager.h"
#include "Scene.h"
#include "GameScene.h"

Background::Background() :GameObject(L"resources/background/start.png")
{
}


Background::~Background()
{
}

void Background::Update()
{
	if (InputManager::GetKeyPressed(VK_SPACE)) {
		Scene::ChangeScene(new GameScene());
	}
}
