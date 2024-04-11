#pragma once
#include "Scene.h"

#define RESULT_BG_PATH		"Data/Image/SceneResult/Result_BG.png"
#define TEXT_PATH			"Data/Image/SceneResult/Text.png"


class SceneResult : public SceneBase
{
private:
	int Result_BG_Hndl;		//�w�i�摜�i�[�ϐ�
	int TextHndl;			//�e�L�X�g�摜�i�[�ϐ�

public:
	void Init();

	void Step();

	void Draw();

	void Fin();
};
