#include "DxLib.h"
#include "../../Common.h"
#include "SceneTitle.h"
#include "Scene.h"
#include "../Input/Input.h"
#include "../Score/ScoreManager/ScoreManager.h"

//タイトル初期化
void SceneTitle::Init()
{
	multiNum = 0;

	ScoreManager::Init();

	TitleImage.RectInit(LoadGraph(TITLE_BG_PATH), VGet(0.0f, 0.0f, 0.0f), 1280, 720);

	TitleSoloText.RectInit(LoadGraph(TITLE_SOLO_TEXT_PATH), VGet((float)(SCREEN_SIZE_X / 2), (float)(SCREEN_SIZE_Y / 2) + 120.0f, 0.0f), 371, 89);
	TitleMultiText.RectInit(LoadGraph(TITLE_MULTI_TEXT_PATH), VGet((float)(SCREEN_SIZE_X / 2), (float)(SCREEN_SIZE_Y / 2) + 250.0f, 0.0f), 371, 93);
	
	for (int i = 0; i < 4; i++)
	{
		Card[i].RectInit(LoadGraph(TITLE_MULTI_CARD_PATH[i]), VGet((float)(SCREEN_SIZE_X / 2) + 250.0f, (float)(SCREEN_SIZE_Y / 2) + 250.0f, 0.0f), 91, 129);
	}

	SceneManager::g_CurrenySceneID = SCENEID::SCENE_ID_LOOP_TITLE;
}

//タイトル通常処理
void SceneTitle::Step()
{
	if (Input::ClickRect_Center(Card[multiNum]))
	{
		multiNum++;
		if (multiNum >= 4)
		{
			multiNum = 0;
		}
	}
	
	if (Input::PressAnyKey())
	{
		SceneManager::g_CurrenySceneID = SCENEID::SCENE_ID_FIN_TITLE;
	}

	if (Input::ClickRect_Center(TitleSoloText))
	{
		ScoreManager::SetMulti_Flag(false);
		ScoreManager::SetAll_playerNum(2);

		SceneManager::g_CurrenySceneID = SCENEID::SCENE_ID_FIN_TITLE;
	}
	if (Input::ClickRect_Center(TitleMultiText))
	{
		ScoreManager::SetMulti_Flag(true);
		ScoreManager::SetAll_playerNum(multiNum + 1);


		SceneManager::g_CurrenySceneID = SCENEID::SCENE_ID_FIN_TITLE;
	}

}

//タイトル描画処理
void SceneTitle::Draw()
{
	TitleImage.DrawRect();
	TitleSoloText.DrawRect_Rota_Center();
	TitleMultiText.DrawRect_Rota_Center();

	Card[multiNum].DrawRect_Rota_Center();
}

//タイトル後処理
void SceneTitle::Fin()
{
	TitleImage.RectFin();

	TitleSoloText.RectFin();
	TitleMultiText.RectFin();

	for (int i = 0; i < 4; i++)
	{
		Card[i].RectFin();
	}

	TitleBGM.FinBGM();

	SceneManager::g_CurrenySceneID = SCENEID::SCENE_ID_INIT_PLAY;
}
