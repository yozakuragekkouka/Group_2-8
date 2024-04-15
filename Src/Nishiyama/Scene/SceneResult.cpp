#include <math.h>
#include "DxLib.h"
#include "../../Common.h"
#include "../Input/Input.h"
#include "../Shapes/Shapes.h"
#include "Scene.h"
#include "SceneResult.h"
#include "../NumberFont/NumberFont.h"
#include "../Score/ScoreManager/ScoreManager.h"

//クリア初期化
void SceneResult::Init()
{
	Result_BG_Hndl = LoadGraph(RESULT_BG_PATH);
	TextHndl = LoadGraph(TEXT_PATH);

	ClownHndl = LoadGraph("Data/Image/SceneResult/王冠.png");
	PlayerHndl[0] = LoadGraph("Data/Image/ScenePlay/プレイヤー1.png");
	PlayerHndl[1] = LoadGraph("Data/Image/ScenePlay/プレイヤー2.png");
	PlayerHndl[2] = LoadGraph("Data/Image/ScenePlay/プレイヤー3.png");
	PlayerHndl[3] = LoadGraph("Data/Image/ScenePlay/プレイヤー4.png");
	PlayerHndl[4] = LoadGraph("Data/Image/ScenePlay/CPU_400.png");


	BGM_Hndl = LoadSoundMem(RESULT_BMG_PATH);			//BGM読み込み
	TAPSound_Hndl = LoadSoundMem(RESULT_TAP_PATH);		//決定音読み込み

	TextPosX = 400;
	TextPosY = 470;
	MousePosX = MousePosY = 0;

	PlaySoundMem(BGM_Hndl, DX_PLAYTYPE_LOOP);

	//テスト用
	//ScoreManager::SetWinner(1);

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
			PlaySoundMem(TAPSound_Hndl, DX_PLAYTYPE_NORMAL);
			SceneManager::g_CurrenySceneID = SCENEID::SCENE_ID_FIN_RESULT;
		}
	}

	
}

//クリア描画処理
void SceneResult::Draw()
{

	DrawGraph(0, 0, Result_BG_Hndl, true);				//背景画像描画
	DrawGraph(TextPosX, TextPosY, TextHndl, true);		//テキスト画像描画

	DrawRotaGraph(640, 320, 0.7f, 0.0f, PlayerHndl[ScoreManager::GetWinner()], true, false, false);	//勝者プレイヤーの描画
	DrawRotaGraph(640, 120, 0.7f, 0.0f, ClownHndl, true, false, false);		//王冠画像表示

	/*DrawFormatString(0, 0, GetColor(255, 255, 255), "マウスのX座標：%d", MousePosX);
	DrawFormatString(0, 15, GetColor(255, 255, 255), "マウスのY座標：%d", MousePosY);*/

}

//クリア後処理
void SceneResult::Fin()
{
	DeleteGraph(Result_BG_Hndl);
	DeleteGraph(TextHndl);
	DeleteGraph(ClownHndl);

	for (int i = 0; i < 5; i++)
	{
		DeleteGraph(PlayerHndl[i]);
	}


	DeleteSoundMem(BGM_Hndl);
	DeleteSoundMem(TAPSound_Hndl);

	SceneManager::g_CurrenySceneID = SCENEID::SCENE_ID_INIT_TITLE;
}