#pragma once
#include "Scene.h"
#include "../Card/Card.h"

//�v���C�V�[���w�i
constexpr char PLAY_BG_PATH[128] = "Data/Image/ScenePlay/PlaySceneBackImage.png";

class ScenePlay : public SceneBase
{
private:
	Rect_Data Back;

	CardManager card;

public:
	void Init();
	void Step();
	void Draw();
	void Fin();
};
