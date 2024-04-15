#pragma once
#include "Scene.h"
#include "../Card/Card.h"
#include "../NumberFont/NumberFont.h"
#include "../Sound/Sound.h"

//プレイシーン背景
constexpr char PLAY_BG_PATH[128] = "Data/Image/ScenePlay/PlaySceneBackImage.png";
constexpr char PLAY_MENU_BG_PATH[128] = "Data/Image/ScenePlay/画像8.png";
<<<<<<< Updated upstream
=======
//プレイシーンBGM
constexpr char PLAY_BGM_PATH[128] = "Data/Sound/ScenePlay/ScenePlay_Main_Sound.mp3";
//メニューボタン
constexpr char MENU_BOTTAN_TITLE_PATH[128] = "Data/Image/ScenePlay/ReturnTitleBottan.png";
constexpr char MENU_BOTTAN_RETRY_PATH[128] = "Data/Image/ScenePlay/RetryBottan.png";
>>>>>>> Stashed changes

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

	BGM_Data PlayBGM;

	//メニュー画像ハンドル
	int m_MenuHadnle[3];
	//メニューフラグ
	int m_MenuFlag = 0;
	//メニューフレーム
	int m_MenuFlame;
	//ボタン座標
	int m_TitleBottan_x;
	int m_TitleBottan_y;
	int m_RetryBottan_x;
	int m_RetryBottan_y;
public:
	void Init();
	void Step();
	void Draw();
	void Fin();
};
