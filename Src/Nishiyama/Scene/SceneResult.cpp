#include <math.h>
#include "DxLib.h"
#include "../../Common.h"
#include "../Input/Input.h"
#include "../Shapes/Shapes.h"
#include "Scene.h"
#include "SceneResult.h"
#include "../NumberFont/NumberFont.h"

//クリア初期化
void SceneResult::Init()
{
	Result_BG_Hndl = LoadGraph(RESULT_BG_PATH);
	TextHndl = LoadGraph(TEXT_PATH);

	SceneManager::g_CurrenySceneID = SCENEID::SCENE_ID_LOOP_RESULT;
}

//クリア通常処理
void SceneResult::Step()
{
	if (Input::PressAnyKey())
	{
		SceneManager::g_CurrenySceneID = SCENEID::SCENE_ID_FIN_RESULT;
	}

}

//クリア描画処理
void SceneResult::Draw()
{
	DrawGraph(0, 0, Result_BG_Hndl, true);
	DrawGraph(500, 500, TextHndl, true);

	//デバッグ
	DrawFormatString(100, 100, GetColor(255, 255, 255), "リザルトシーンです", true);
}

//クリア後処理
void SceneResult::Fin()
{
	DeleteGraph(Result_BG_Hndl);
	DeleteGraph(TextHndl);

	SceneManager::g_CurrenySceneID = SCENEID::SCENE_ID_INIT_TITLE;
}
