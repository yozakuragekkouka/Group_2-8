#pragma once
#include "Scene.h"
#include "../Card/Card.h"
#include "../NumberFont/NumberFont.h"

//�v���C�V�[���w�i
constexpr char PLAY_BG_PATH[128] = "Data/Image/ScenePlay/PlaySceneBackImage.png";
constexpr char PLAY_MENU_BG_PATH[128] = "Data/Image/ScenePlay/�摜8.png";
//�v���C�V�[��BGM
constexpr char PLAY_BGM_PATH[128] = "Data/Sound/ScenePlay/ScenePlay_Main_Sound.mp3";

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

	//�������n���h��
	int m_bgmHandle;
	//���j���[�摜�n���h��
	int m_MenuHadnle[2];
	//���j���[�t���O
	int m_MenuFlag;
	//���j���[�t���[��
	int m_MenuFlame;

public:
	void Init();
	void Step();
	void Draw();
	void Fin();
};
