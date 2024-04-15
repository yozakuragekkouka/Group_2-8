#pragma once
#include "Scene.h"
#include "../Card/Card.h"
#include "../NumberFont/NumberFont.h"

//�v���C�V�[���w�i
constexpr char PLAY_BG_PATH[128] = "Data/Image/ScenePlay/PlaySceneBackImage.png";

constexpr char PLAYER_IMAGE_PATH[5][128] =
{
	"Data/Image/ScenePlay/�v���C���[1.png",
	"Data/Image/ScenePlay/�v���C���[2.png",
	"Data/Image/ScenePlay/�v���C���[3.png",
	"Data/Image/ScenePlay/�v���C���[4.png",
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
