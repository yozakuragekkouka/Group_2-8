#pragma once
#include "Scene.h"
#include "../NumberFont/NumberFont.h"

#define RESULT_BG_PATH		"Data/Image/SceneResult/Result_BG.png"
#define TEXT_PATH			"Data/Image/SceneResult/Text.png"

#define RESULT_BMG_PATH		"Data/Sound/SceneResult/SceneResult.mp3"
#define RESULT_TAP_PATH		"Data/Sound/SceneResult/����{�^��������47.mp3"

#define TEXT_WIDHT			(500)	//�e�L�X�g�̉���
#define TEXT_HEIGHT			(200)	//�e�L�X�g�̏c��



class SceneResult : public SceneBase
{
private:
	c_Number scorefont[4];
	int Result_BG_Hndl;		//�w�i�摜�i�[�ϐ�
	int TextHndl;			//�e�L�X�g�摜�i�[�ϐ�
	int TextPosX, TextPosY;	//�e�L�X�g�̍��W�ϐ�

	int ClownHndl;			//���摜�ϐ�
	int PlayerHndl[5];		//�v���C���[�摜�i�[�ϐ�

	int BGM_Hndl;			//BGM�i�[�ϐ�
	int TAPSound_Hndl;		//���艹�i�[�ϐ�

	int MousePosX, MousePosY;	//�}�E�X�̍��W�i�[�ϐ�

public:
	void Init();

	void Step();

	void Draw();

	void Fin();
};
