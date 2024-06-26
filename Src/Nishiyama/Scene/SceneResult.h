#pragma once
#include "Scene.h"
#include "../NumberFont/NumberFont.h"

#define RESULT_BG_PATH		"Data/Image/SceneResult/Result_BG.png"
#define TEXT_PATH			"Data/Image/SceneResult/Text.png"

#define RESULT_BMG_PATH		"Data/Sound/SceneResult/SceneResult.mp3"
#define RESULT_TAP_PATH		"Data/Sound/SceneResult/è{^ð·47.mp3"

#define TEXT_WIDHT			(500)	//eLXgÌ¡
#define TEXT_HEIGHT			(200)	//eLXgÌc



class SceneResult : public SceneBase
{
private:
	c_Number scorefont[4];
	int Result_BG_Hndl;		//wiæi[Ï
	int TextHndl;			//eLXgæi[Ï
	int TextPosX, TextPosY;	//eLXgÌÀWÏ

	int ClownHndl;			//¥æÏ
	int PlayerHndl[5];		//vC[æi[Ï

	int BGM_Hndl;			//BGMi[Ï
	int TAPSound_Hndl;		//è¹i[Ï

	int MousePosX, MousePosY;	//}EXÌÀWi[Ï

public:
	void Init();

	void Step();

	void Draw();

	void Fin();
};
