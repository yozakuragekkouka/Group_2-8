#pragma once
#include "Scene.h"
#include "../Card/Card.h"

//プレイシーン背景
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
