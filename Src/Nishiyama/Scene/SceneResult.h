#pragma once
#include "Scene.h"

#define RESULT_BG_PATH		"Data/Image/SceneResult/Result_BG.png"
#define TEXT_PATH			"Data/Image/SceneResult/Text.png"


class SceneResult : public SceneBase
{
private:
	int Result_BG_Hndl;		//”wŒi‰æ‘œŠi”[•Ï”
	int TextHndl;			//ƒeƒLƒXƒg‰æ‘œŠi”[•Ï”

public:
	void Init();

	void Step();

	void Draw();

	void Fin();
};
