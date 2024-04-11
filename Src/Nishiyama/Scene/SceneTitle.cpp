#include "DxLib.h"
#include "../../Common.h"
#include "SceneTitle.h"
#include "Scene.h"
#include "../Input/Input.h"
#include "../Score/ScoreManager/ScoreManager.h"
#include "../Input/Input.cpp"

//タイトル初期化
void SceneTitle::Init()
{
	multiNum = 0;

	ScoreManager::Init();

	TitleImage.RectInit(LoadGraph(TITLE_BG_PATH), VGet(0.0f, 0.0f, 0.0f), 1280, 720);

	TitleSoloText.RectInit(LoadGraph(TITLE_SOLO_TEXT_PATH), VGet((float)(SCREEN_SIZE_X / 2), (float)(SCREEN_SIZE_Y / 2) + 120.0f, 0.0f), 350, 66);
	TitleMultiText.RectInit(LoadGraph(TITLE_MULTI_TEXT_PATH), VGet((float)(SCREEN_SIZE_X / 2), (float)(SCREEN_SIZE_Y / 2) + 250.0f, 0.0f), 350, 66);
	
	for (int i = 0; i < 4; i++)
	{
		Card[i].RectInit(LoadGraph(TITLE_MULTI_CARD_PATH[i]), VGet((float)(SCREEN_SIZE_X / 2) + 250.0f, (float)(SCREEN_SIZE_Y / 2) + 200.0f, 0.0f), 91, 129);
	}

	m_Imagehandle[0] = LoadGraph(TITLE_BOTTAN_SELECT_PATH);		//ボタンセレクト
	m_SelectBottan_x = 420;			//セレクトボタンｘ座標
	m_SelectBottan_y = 480;			//セレクトボタンy座標

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

	

}

//タイトル描画処理
void SceneTitle::Draw()
{
	TitleImage.DrawRect();
	TitleSoloText.DrawRect_Rota_Center();
	TitleMultiText.DrawRect_Rota_Center();

	DrawRotaGraph(m_SelectBottan_x, m_SelectBottan_y, 1.0f, 0.0f, m_Imagehandle[0], true);		//ボタンセレクト矢印描画
	
	Card[multiNum].DrawRect_Rota_Center();
}

//タイトル後処理
void SceneTitle::Fin()
{
	TitleImage.RectFin();

	TitleSoloText.RectFin();
	TitleMultiText.RectFin();

	//タイトル画像の枚数だけ消去
	for (int i = 0; i < TITLE_IMAGE_NUM; i++)
	{
		DeleteGraph(m_Imagehandle[i]);
	}

	for (int i = 0; i < 4; i++)
	{
		Card[i].RectFin();
	}

	TitleBGM.FinBGM();

	SceneManager::g_CurrenySceneID = SCENEID::SCENE_ID_INIT_PLAY;
}

int SceneTitle::BottanAnimation()
{

}