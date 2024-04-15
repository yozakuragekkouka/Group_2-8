#pragma once
#include "Scene.h"
#include "../Card/Card.h"
#include "../NumberFont/NumberFont.h"
#include "../Sound/Sound.h"

//�v���C�V�[���w�i
constexpr char PLAY_BG_PATH[128] = "Data/Image/ScenePlay/PlaySceneBackImage.png";
constexpr char PLAY_MENU_BG_PATH[128] = "Data/Image/ScenePlay/�摜8.png";
<<<<<<< Updated upstream
=======
//�v���C�V�[��BGM
constexpr char PLAY_BGM_PATH[128] = "Data/Sound/ScenePlay/ScenePlay_Main_Sound.mp3";
//���j���[�{�^��
constexpr char MENU_BOTTAN_TITLE_PATH[128] = "Data/Image/ScenePlay/ReturnTitleBottan.png";
constexpr char MENU_BOTTAN_RETRY_PATH[128] = "Data/Image/ScenePlay/RetryBottan.png";
>>>>>>> Stashed changes

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

	BGM_Data PlayBGM;

	//���j���[�摜�n���h��
	int m_MenuHadnle[3];
	//���j���[�t���O
	int m_MenuFlag = 0;
	//���j���[�t���[��
	int m_MenuFlame;
	//�{�^�����W
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
