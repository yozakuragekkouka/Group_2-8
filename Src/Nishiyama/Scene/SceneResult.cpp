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

	TextPosX = 400;
	TextPosY = 470;
	MousePosX = MousePosY = 0;

	SceneManager::g_CurrenySceneID = SCENEID::SCENE_ID_LOOP_RESULT;
}

//クリア通常処理
void SceneResult::Step()
{
	//マウスの座標を取得する
	GetMousePoint(&MousePosX, &MousePosY);

	//マウスを押したときにマウス座標が画像の範囲内にあればシーンを終わる
	if (GetMouseInput() & MOUSE_INPUT_LEFT)
	{
		if (MousePosX > TextPosX && MousePosX < TextPosX + TEXT_WIDHT
			&& MousePosY > TextPosY && MousePosY < TextPosY + TEXT_HEIGHT)
		{
			SceneManager::g_CurrenySceneID = SCENEID::SCENE_ID_FIN_RESULT;
		}
	}
}

//クリア描画処理
void SceneResult::Draw()
{
	DrawGraph(0, 0, Result_BG_Hndl, true);				//背景画像描画
	DrawGraph(TextPosX, TextPosY, TextHndl, true);		//テキスト画像描画
	DrawMousePointa();

	DrawFormatString(0, 0, GetColor(255, 255, 255), "マウスのX座標：%d", MousePosX);
	DrawFormatString(0, 15, GetColor(255, 255, 255), "マウスのY座標：%d", MousePosY);

}

//クリア後処理
void SceneResult::Fin()
{
	DeleteGraph(Result_BG_Hndl);
	DeleteGraph(TextHndl);

	SceneManager::g_CurrenySceneID = SCENEID::SCENE_ID_INIT_TITLE;
}

//マウスポインタ描画処理
void SceneResult::DrawMousePointa()
{
	int mousepoint = 0;

	mousepoint = LoadGraph(MOUSE_POINTA_PATH);

	//マウス位置取得
	DrawRotaGraph(Input::GetMousePos().x, Input::GetMousePos().y, 0.65f, 0.0f, mousepoint, true);

}