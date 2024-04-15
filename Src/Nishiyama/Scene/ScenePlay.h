#pragma once
#include "Scene.h"
#include "../Card/Card.h"
#include "../NumberFont/NumberFont.h"

//プレイシーン背景
constexpr char PLAY_BG_PATH[128] = "Data/Image/ScenePlay/PlaySceneBackImage.png";
constexpr char PLAY_MENU_BG_PATH[128] = "Data/Image/ScenePlay/画像8.png";
//プレイシーンBGM
constexpr char PLAY_BGM_PATH[128] = "Data/Sound/ScenePlay/ScenePlay_Main_Sound.mp3";

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

	//ｂｇｍハンドル
	int m_bgmHandle;
	//メニュー画像ハンドル
	int m_MenuHadnle[2];
	//メニューフラグ
	int m_MenuFlag;
	//メニューフレーム
	int m_MenuFlame;

public:
	void Init();
	void Step();
	void Draw();
	void Fin();
};
