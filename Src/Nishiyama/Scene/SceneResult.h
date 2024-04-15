#pragma once
#include "Scene.h"

#define RESULT_BG_PATH		"Data/Image/SceneResult/Result_BG.png"
#define TEXT_PATH			"Data/Image/SceneResult/Text.png"

#define TEXT_WIDHT			(500)	//テキストの横幅
#define TEXT_HEIGHT			(200)	//テキストの縦幅

class SceneResult : public SceneBase
{
private:
	int Result_BG_Hndl;		//背景画像格納変数
	int TextHndl;			//テキスト画像格納変数
	int TextPosX, TextPosY;	//テキストの座標変数

	int MousePosX, MousePosY;	//マウスの座標格納変数

public:
	void Init();

	void Step();

	void Draw();

	void Fin();
};
