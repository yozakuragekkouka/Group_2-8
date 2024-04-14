#pragma once
#include "Scene.h"
#include "../Card/Card.h"
#include "../NumberFont/NumberFont.h"

//プレイシーン背景
constexpr char PLAY_BG_PATH[128] = "Data/Image/ScenePlay/PlaySceneBackImage.png";

class ScenePlay : public SceneBase
{
private:
	c_Number scorefont[4];

	Rect_Data Back;

	CardManager card;

	int mousepoint;

public:
	void Init();
	void Step();
	void Draw();
	void Fin();

	//マウスポインタ描画処理
	void DrawMousePointa();
};
