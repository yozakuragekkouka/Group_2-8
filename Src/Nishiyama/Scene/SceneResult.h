#pragma once
#include "Scene.h"
#include "../NumberFont/NumberFont.h"

#define RESULT_BG_PATH		"Data/Image/SceneResult/Result_BG.png"
#define TEXT_PATH			"Data/Image/SceneResult/Text.png"

#define RESULT_BMG_PATH		"Data/Sound/SceneResult/SceneResult.mp3"
#define RESULT_TAP_PATH		"Data/Sound/SceneResult/決定ボタンを押す47.mp3"

#define TEXT_WIDHT			(500)	//テキストの横幅
#define TEXT_HEIGHT			(200)	//テキストの縦幅



class SceneResult : public SceneBase
{
private:
	c_Number scorefont[4];
	int Result_BG_Hndl;		//背景画像格納変数
	int TextHndl;			//テキスト画像格納変数
	int TextPosX, TextPosY;	//テキストの座標変数

	int ClownHndl;			//冠画像変数
	int PlayerHndl[5];		//プレイヤー画像格納変数

	int BGM_Hndl;			//BGM格納変数
	int TAPSound_Hndl;		//決定音格納変数

	int MousePosX, MousePosY;	//マウスの座標格納変数

public:
	void Init();

	void Step();

	void Draw();

	void Fin();
};
