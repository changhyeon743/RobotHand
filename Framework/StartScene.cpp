#include "stdafx.h"
#include "StartScene.h"


StartScene::StartScene()
{
}

void StartScene::Initialize()
{
	background = (Background*) PushBackGameObject(new Background());
	background->transform->SetPosition(160, 290);
}


StartScene::~StartScene()
{
}
