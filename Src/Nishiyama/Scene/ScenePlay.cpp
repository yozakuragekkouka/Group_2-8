#include <math.h>

#include "DxLib.h"
#include "../../Common.h"
#include "../Input/Input.h"
#include "../Score/ScoreManager/ScoreManager.h"
#include "ScenePlay.h"

//プレイシーン初期化
void ScenePlay::Init()
{
	Back.RectInit(LoadGraph(PLAY_BG_PATH), VGet(0.0f, 0.0f, 0.0f), 1280, 720);

	SceneManager::g_CurrenySceneID = SCENEID::SCENE_ID_LOOP_PLAY;
}

//プレイシーン通常処理
void ScenePlay::Step()
{
	switch (ScoreManager::GetMulti_Flag())
	{
	case true:
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

	//デバッグ
	DrawFormatString(100, 100, GetColor(255, 255, 255), "プレイシーンです", true);

	switch (ScoreManager::GetMulti_Flag())
	{
	case true:
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

	SceneManager::g_CurrenySceneID = SCENEID::SCENE_ID_INIT_RESULT;
}
