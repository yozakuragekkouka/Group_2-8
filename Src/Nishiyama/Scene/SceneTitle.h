#pragma once
#include "Scene.h"
#include "../Shapes/Shapes.h"
#include "../Sound/Sound.h"

constexpr char TITLE_BG_PATH[128] = "Data/Image/SceneTitle/TitleBackGround.png";
constexpr char TITLE_SOLO_TEXT_PATH[128] = "Data/Image/SceneTitle/TitleBottan1.png";
constexpr char TITLE_MULTI_TEXT_PATH[128] = "Data/Image/SceneTitle/TitleBottan2.png";

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
};