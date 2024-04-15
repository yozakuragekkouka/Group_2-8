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
	"Data/Image/ScenePlay/�g�����v�X�y�[�h_1.png",
	"Data/Image/ScenePlay/�g�����v�X�y�[�h_2.png",
	"Data/Image/ScenePlay/�g�����v�X�y�[�h_3.png",
	"Data/Image/ScenePlay/�g�����v�X�y�[�h_4.png",
	"Data/Image/ScenePlay/�g�����v�X�y�[�h_5.png",
	"Data/Image/ScenePlay/�g�����v�X�y�[�h_6.png",
	"Data/Image/ScenePlay/�g�����v�X�y�[�h_7.png",
	"Data/Image/ScenePlay/�g�����v�X�y�[�h_8.png",
	"Data/Image/ScenePlay/�g�����v�X�y�[�h_9.png",
	"Data/Image/ScenePlay/�g�����v�X�y�[�h_10.png",
	"Data/Image/ScenePlay/�g�����v�X�y�[�h_11.png",
	"Data/Image/ScenePlay/�g�����v�X�y�[�h_12.png",
	"Data/Image/ScenePlay/�g�����v�X�y�[�h_13.png"
	},
	{
	"Data/Image/ScenePlay/�g�����v�N���[�o�[_1.png",
	"Data/Image/ScenePlay/�g�����v�N���[�o�[_2.png",
	"Data/Image/ScenePlay/�g�����v�N���[�o�[_3.png",
	"Data/Image/ScenePlay/�g�����v�N���[�o�[_4.png",
	"Data/Image/ScenePlay/�g�����v�N���[�o�[_5.png",
	"Data/Image/ScenePlay/�g�����v�N���[�o�[_6.png",
	"Data/Image/ScenePlay/�g�����v�N���[�o�[_7.png",
	"Data/Image/ScenePlay/�g�����v�N���[�o�[_8.png",
	"Data/Image/ScenePlay/�g�����v�N���[�o�[_9.png",
	"Data/Image/ScenePlay/�g�����v�N���[�o�[_10.png",
	"Data/Image/ScenePlay/�g�����v�N���[�o�[_11.png",
	"Data/Image/ScenePlay/�g�����v�N���[�o�[_12.png",
	"Data/Image/ScenePlay/�g�����v�N���[�o�[_13.png"
	},
	{
	"Data/Image/ScenePlay/�g�����v�n�[�g_1.png",
	"Data/Image/ScenePlay/�g�����v�n�[�g_2.png",
	"Data/Image/ScenePlay/�g�����v�n�[�g_3.png",
	"Data/Image/ScenePlay/�g�����v�n�[�g_4.png",
	"Data/Image/ScenePlay/�g�����v�n�[�g_5.png",
	"Data/Image/ScenePlay/�g�����v�n�[�g_6.png",
	"Data/Image/ScenePlay/�g�����v�n�[�g_7.png",
	"Data/Image/ScenePlay/�g�����v�n�[�g_8.png",
	"Data/Image/ScenePlay/�g�����v�n�[�g_9.png",
	"Data/Image/ScenePlay/�g�����v�n�[�g_10.png",
	"Data/Image/ScenePlay/�g�����v�n�[�g_11.png",
	"Data/Image/ScenePlay/�g�����v�n�[�g_12.png",
	"Data/Image/ScenePlay/�g�����v�n�[�g_13.png"
	},
	{
	"Data/Image/ScenePlay/�g�����v�_�C��_1.png",
	"Data/Image/ScenePlay/�g�����v�_�C��_2.png",
	"Data/Image/ScenePlay/�g�����v�_�C��_3.png",
	"Data/Image/ScenePlay/�g�����v�_�C��_4.png",
	"Data/Image/ScenePlay/�g�����v�_�C��_5.png",
	"Data/Image/ScenePlay/�g�����v�_�C��_6.png",
	"Data/Image/ScenePlay/�g�����v�_�C��_7.png",
	"Data/Image/ScenePlay/�g�����v�_�C��_8.png",
	"Data/Image/ScenePlay/�g�����v�_�C��_9.png",
	"Data/Image/ScenePlay/�g�����v�_�C��_10.png",
	"Data/Image/ScenePlay/�g�����v�_�C��_11.png",
	"Data/Image/ScenePlay/�g�����v�_�C��_12.png",
	"Data/Image/ScenePlay/�g�����v�_�C��_13.png"
	},
};

constexpr char CARD_BACK_PATH[128] = "Data/Image/ScenePlay/�g�����v����_����.png";

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