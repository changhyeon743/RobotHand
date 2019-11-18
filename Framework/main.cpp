#include "stdafx.h"
#include "Framework.h"
#include "GameScene.h"
#include "Math.h"

int main()
{
	Framework& f = Framework::GetInstance();
	f.Run(new GameScene(),L"≈∏¿Ã∆≤", 320, 580, false);
	return 0;
}