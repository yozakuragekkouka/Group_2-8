#include <math.h>

#include "DxLib.h"
#include "../../Common.h"
#include "../Input/Input.h"
#include "../Score/ScoreManager/ScoreManager.h"
#include "ScenePlay.h"

//プレイシーン初期化
void ScenePlay::Init()
{
	for (int i = 0; i < 4; i++)
	{
		scorefont[i].Init();
		scorefont[i].SetNumberFont(Number_16_32_orange);

		if (i % 2 == 1)
			scorefont[i].Set_posX(SCREEN_SIZE_X - 100);
		else
			scorefont[i].Set_posX(100);

		if(i >= 2)
			scorefont[i].Set_posY(SCREEN_SIZE_Y - 100);
		else
			scorefont[i].Set_posY(100);
	}
	Back.RectInit(LoadGraph(PLAY_BG_PATH), VGet(0.0f, 0.0f, 0.0f), 1280, 720);

	card.Init();

	SceneManager::g_CurrenySceneID = SCENEID::SCENE_ID_LOOP_PLAY;
}

//プレイシーン通常処理
void ScenePlay::Step()
{
	switch (ScoreManager::GetMulti_Flag())
	{
	case true:
		card.Step();
		break;
	case false:
		break;
	}

	if (Input::PressAnyKey())
	{
		SceneManager::g_CurrenySceneID = SCENEID::SCENE_ID_FIN_PLAY;
	}
}

//プレイシーン描画処理
void ScenePlay::Draw()
{
	Back.DrawRect();

	card.Draw();

	switch (ScoreManager::GetMulti_Flag())
	{
	case true:
		for (int i = 0; i < ScoreManager::GetAll_playerNum(); i++)
		{
			scorefont[i].Draw_int(ScoreManager::GetScore(i));
		}
		break;
	case false:
		break;
	}
}

//プレイシーン後処理
//リトライかどうかを返す
void ScenePlay::Fin()
{
	Back.RectFin();

	card.Fin();

	SceneManager::g_CurrenySceneID = SCENEID::SCENE_ID_INIT_RESULT;
}
