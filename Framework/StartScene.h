#pragma once
#include "Scene.h"
#include "Background.h"

class StartScene :
	public Scene
{
public:
	StartScene();
	virtual void Initialize();
	Background* background;
	~StartScene();
};

