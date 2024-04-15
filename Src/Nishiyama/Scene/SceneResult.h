#pragma once
#include "Scene.h"

#define RESULT_BG_PATH		"Data/Image/SceneResult/Result_BG.png"
#define TEXT_PATH			"Data/Image/SceneResult/Text.png"

#define TEXT_WIDHT			(500)	//�e�L�X�g�̉���
#define TEXT_HEIGHT			(200)	//�e�L�X�g�̏c��

class SceneResult : public SceneBase
{
private:
	int Result_BG_Hndl;		//�w�i�摜�i�[�ϐ�
	int TextHndl;			//�e�L�X�g�摜�i�[�ϐ�
	int TextPosX, TextPosY;	//�e�L�X�g�̍��W�ϐ�

	int MousePosX, MousePosY;	//�}�E�X�̍��W�i�[�ϐ�

public:
	void Init();

	void Step();

	void Draw();

	void Fin();
};
