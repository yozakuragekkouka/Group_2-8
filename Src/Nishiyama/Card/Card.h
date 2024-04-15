#pragma once
#include "../Shapes/Shapes.h"

constexpr int Card_sizeX = 54;
constexpr int Card_sizeY = 80;

constexpr float Card_FirstPosX = 150.0f;
constexpr float Card_FirstPosY = 150.0f;

constexpr float Card_spaceX = 20.0f;
constexpr float Card_spaceY = 20.0f;

constexpr float WAIT_FRAME = 60;

enum class Mark
{
	Spade,
	Clover,
	Heart,
	Dia,

	MarkNum
};

constexpr char CARD_PATH[(int)Mark::MarkNum][13][128] =
{
	{
	"Data/Image/ScenePlay/トランプスペード_1.png",
	"Data/Image/ScenePlay/トランプスペード_2.png",
	"Data/Image/ScenePlay/トランプスペード_3.png",
	"Data/Image/ScenePlay/トランプスペード_4.png",
	"Data/Image/ScenePlay/トランプスペード_5.png",
	"Data/Image/ScenePlay/トランプスペード_6.png",
	"Data/Image/ScenePlay/トランプスペード_7.png",
	"Data/Image/ScenePlay/トランプスペード_8.png",
	"Data/Image/ScenePlay/トランプスペード_9.png",
	"Data/Image/ScenePlay/トランプスペード_10.png",
	"Data/Image/ScenePlay/トランプスペード_11.png",
	"Data/Image/ScenePlay/トランプスペード_12.png",
	"Data/Image/ScenePlay/トランプスペード_13.png"
	},
	{
	"Data/Image/ScenePlay/トランプクローバー_1.png",
	"Data/Image/ScenePlay/トランプクローバー_2.png",
	"Data/Image/ScenePlay/トランプクローバー_3.png",
	"Data/Image/ScenePlay/トランプクローバー_4.png",
	"Data/Image/ScenePlay/トランプクローバー_5.png",
	"Data/Image/ScenePlay/トランプクローバー_6.png",
	"Data/Image/ScenePlay/トランプクローバー_7.png",
	"Data/Image/ScenePlay/トランプクローバー_8.png",
	"Data/Image/ScenePlay/トランプクローバー_9.png",
	"Data/Image/ScenePlay/トランプクローバー_10.png",
	"Data/Image/ScenePlay/トランプクローバー_11.png",
	"Data/Image/ScenePlay/トランプクローバー_12.png",
	"Data/Image/ScenePlay/トランプクローバー_13.png"
	},
	{
	"Data/Image/ScenePlay/トランプハート_1.png",
	"Data/Image/ScenePlay/トランプハート_2.png",
	"Data/Image/ScenePlay/トランプハート_3.png",
	"Data/Image/ScenePlay/トランプハート_4.png",
	"Data/Image/ScenePlay/トランプハート_5.png",
	"Data/Image/ScenePlay/トランプハート_6.png",
	"Data/Image/ScenePlay/トランプハート_7.png",
	"Data/Image/ScenePlay/トランプハート_8.png",
	"Data/Image/ScenePlay/トランプハート_9.png",
	"Data/Image/ScenePlay/トランプハート_10.png",
	"Data/Image/ScenePlay/トランプハート_11.png",
	"Data/Image/ScenePlay/トランプハート_12.png",
	"Data/Image/ScenePlay/トランプハート_13.png"
	},
	{
	"Data/Image/ScenePlay/トランプダイヤ_1.png",
	"Data/Image/ScenePlay/トランプダイヤ_2.png",
	"Data/Image/ScenePlay/トランプダイヤ_3.png",
	"Data/Image/ScenePlay/トランプダイヤ_4.png",
	"Data/Image/ScenePlay/トランプダイヤ_5.png",
	"Data/Image/ScenePlay/トランプダイヤ_6.png",
	"Data/Image/ScenePlay/トランプダイヤ_7.png",
	"Data/Image/ScenePlay/トランプダイヤ_8.png",
	"Data/Image/ScenePlay/トランプダイヤ_9.png",
	"Data/Image/ScenePlay/トランプダイヤ_10.png",
	"Data/Image/ScenePlay/トランプダイヤ_11.png",
	"Data/Image/ScenePlay/トランプダイヤ_12.png",
	"Data/Image/ScenePlay/トランプダイヤ_13.png"
	},
};

constexpr char CARD_BACK_PATH[128] = "Data/Image/ScenePlay/トランプ裏面_ちび.png";

class CardManager
{
private:
	int Now_Player;

	bool canOpen;
	int currentOpenNum;

	int wait_count;

	int CPU_count;

	Rect_Data Card[(int)Mark::MarkNum][13];
	Rect_Data Card_Back[(int)Mark::MarkNum][13];
	bool isDead[(int)Mark::MarkNum][13];
	bool isOpen_now[(int)Mark::MarkNum][13];

	bool isOpened[(int)Mark::MarkNum][13];

public:
	void Init();
	void Step();
	void Draw();
	void Fin();

	void CardOpen();
	void CardOpen_CPU();
	bool Judge();

	bool AllCard_isDead();

	int GetNow_Player() const { return Now_Player; }
};