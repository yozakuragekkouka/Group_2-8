#pragma once
#include "Scene.h"
#include "../Card/Card.h"
#include "../NumberFont/NumberFont.h"

//プレイシーン背景
constexpr char PLAY_BG_PATH[128] = "Data/Image/ScenePlay/PlaySceneBackImage.png";

constexpr char PLAYER_IMAGE_PATH[5][128] =
{
	"Data/Image/ScenePlay/プレイヤー1.png",
	"Data/Image/ScenePlay/プレイヤー2.png",
	"Data/Image/ScenePlay/プレイヤー3.png",
	"Data/Image/ScenePlay/プレイヤー4.png",
	"Data/Image/ScenePlay/CPU_400.png"
};

constexpr float PLAYER_EXTEND_RATE = 0.5f;

class ScenePlay : public SceneBase
{
private:
	c_Number scorefont[4];
	Rect_Data Player[5];

	Rect_Data Back;

	CardManager card;


public:
	void Init();
	void Step();
	void Draw();
	void Fin();
};
