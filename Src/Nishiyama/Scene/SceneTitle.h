#pragma once
#include "Scene.h"
#include "../Shapes/Shapes.h"
#include "../Sound/Sound.h"

<<<<<<< Updated upstream
constexpr char TITLE_BG_PATH[128] = "Data/Image/SceneTitle/TitleBackGround.png";
constexpr char TITLE_SOLO_TEXT_PATH[128] = "Data/Image/SceneTitle/TitleBottan.png";
constexpr char TITLE_MULTI_TEXT_PATH[128] = "Data/Image/SceneTitle/TitleBottan.png";
=======
constexpr int TITLE_IMAGE_NUM = 1;		//�^�C�g���摜����

constexpr char TITLE_BG_PATH[128] = "Data/Image/SceneTitle/TitleBackGround.png";		//�^�C�g���w�i�p�X
constexpr char TITLE_SOLO_TEXT_PATH[128] = "Data/Image/SceneTitle/TitleBottan1.png";		//�^�C�g���{�^��(��l)�p�X
constexpr char TITLE_MULTI_TEXT_PATH[128] = "Data/Image/SceneTitle/TitleBottan2.png";		//�^�C�g���{�^��(�����l)�p�X
constexpr char TITLE_BOTTAN_SELECT_PATH[128] = "Data/Image/SceneTitle/BottanSelect.png";		//�{�^���Z���N�g�p�X
>>>>>>> Stashed changes
constexpr char TITLE_MULTI_CARD_PATH[4][128] =

{
	"Data/Image/ScenePlay/�g�����v�X�y�[�h_1.png",
	"Data/Image/ScenePlay/�g�����v�X�y�[�h_2.png",
	"Data/Image/ScenePlay/�g�����v�X�y�[�h_3.png",
	"Data/Image/ScenePlay/�g�����v�X�y�[�h_4.png"
};


class SceneTitle : public SceneBase
{
private:
	int multiNum;	
	int m_Imagehandle[1] = { 0 };		//�^�C�g���摜�n���h��
	int m_SelectBottan_x = 0;			//�Z���N�g�{�^�������W
	int m_SelectBottan_y = 0;			//�Z���N�g�{�^��y���W

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