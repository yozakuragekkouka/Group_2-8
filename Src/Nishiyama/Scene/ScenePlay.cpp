#include <math.h>

#include "DxLib.h"
#include "../../Common.h"
#include "../Input/Input.h"
#include "../Score/ScoreManager/ScoreManager.h"
#include "ScenePlay.h"

//�v���C�V�[��������
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

//�v���C�V�[���ʏ폈��
void ScenePlay::Step()
{
	card.Step();

	if (card.AllCard_isDead())
	{
		SceneManager::g_CurrenySceneID = SCENEID::SCENE_ID_FIN_PLAY;
	}
}

//�v���C�V�[���`�揈��
void ScenePlay::Draw()
{
	Back.DrawRect();

	card.Draw();

	//�}�E�X�|�C���^�`�揈��
	DrawMousePointa();

	for (int i = 0; i < ScoreManager::GetAll_playerNum(); i++)
	{
		scorefont[i].Draw_int(ScoreManager::GetScore(i));
	}
}

//�v���C�V�[���㏈��
//���g���C���ǂ�����Ԃ�
void ScenePlay::Fin()
{
	Back.RectFin();

	card.Fin();

	SceneManager::g_CurrenySceneID = SCENEID::SCENE_ID_INIT_RESULT;
}

//�}�E�X�|�C���^�`�揈��
void ScenePlay::DrawMousePointa()
{
	int mousepoint = 0;

	mousepoint = LoadGraph(MOUSE_POINTA_PATH);

	//�}�E�X�ʒu�擾
	DrawRotaGraph(Input::GetMousePos().x, Input::GetMousePos().y, 0.65f, 0.0f, mousepoint, true);

}