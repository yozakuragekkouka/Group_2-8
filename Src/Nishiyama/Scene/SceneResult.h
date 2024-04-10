#pragma once
#include "Scene.h"

#define RESULT_BG_PATH		"Data/Image/SceneResult/Result_BG.png"


class SceneResult : public SceneBase
{
private:
	int Result_BG_Hndl = 0;
public:
	void Init();

	void Step();

	void Draw();

	void Fin();
};
