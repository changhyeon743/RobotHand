#include "stdafx.h"
#include "Framework.h"
#include "GameScene.h"
#include "Math.h"
#include "StartScene.h"

int main()
{
	Framework& f = Framework::GetInstance();
	f.Run(new StartScene(),L"�κ��� ���ϱ�", 320, 580, false);

	//f.Run(new GameScene(),L"�κ��� ���ϱ�", 320, 580, false);
	return 0;
}