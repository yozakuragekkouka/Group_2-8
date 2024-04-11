#pragma once
#include "Scene.h"
#include "../Shapes/Shapes.h"
#include "../Sound/Sound.h"

<<<<<<< Updated upstream
constexpr char TITLE_BG_PATH[128] = "Data/Image/SceneTitle/TitleBackGround.png";
constexpr char TITLE_SOLO_TEXT_PATH[128] = "Data/Image/SceneTitle/TitleBottan.png";
constexpr char TITLE_MULTI_TEXT_PATH[128] = "Data/Image/SceneTitle/TitleBottan.png";
=======
constexpr int TITLE_IMAGE_NUM = 1;		//タイトル画像枚数

constexpr char TITLE_BG_PATH[128] = "Data/Image/SceneTitle/TitleBackGround.png";		//タイトル背景パス
constexpr char TITLE_SOLO_TEXT_PATH[128] = "Data/Image/SceneTitle/TitleBottan1.png";		//タイトルボタン(一人)パス
constexpr char TITLE_MULTI_TEXT_PATH[128] = "Data/Image/SceneTitle/TitleBottan2.png";		//タイトルボタン(複数人)パス
constexpr char TITLE_BOTTAN_SELECT_PATH[128] = "Data/Image/SceneTitle/BottanSelect.png";		//ボタンセレクトパス
>>>>>>> Stashed changes
constexpr char TITLE_MULTI_CARD_PATH[4][128] =

{
	"Data/Image/ScenePlay/トランプスペード_1.png",
	"Data/Image/ScenePlay/トランプスペード_2.png",
	"Data/Image/ScenePlay/トランプスペード_3.png",
	"Data/Image/ScenePlay/トランプスペード_4.png"
};


class SceneTitle : public SceneBase
{
private:
	int multiNum;	
	int m_Imagehandle[1] = { 0 };		//タイトル画像ハンドル
	int m_SelectBottan_x = 0;			//セレクトボタンｘ座標
	int m_SelectBottan_y = 0;			//セレクトボタンy座標

	Rect_Data TitleImage;

	Rect_Data TitleSoloText;
	Rect_Data TitleMultiText;
	Rect_Data Card[4];

	BGM_Data TitleBGM;

public:
	void Init();

	void Step();

	void Draw();

	void Fin();

	int BottanAnimation();

};