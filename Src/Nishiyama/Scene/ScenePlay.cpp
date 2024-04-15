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
	for (int i = 0; i < 5; i++)
	{
		Player[i].RectInit(LoadGraph(PLAYER_IMAGE_PATH[i]), VGet(0.0f, 0.0f, 0.0f), 400, 400);

		if (i % 2 == 1)
			Player[i].Set_posX(SCREEN_SIZE_X - 50);
		else
			Player[i].Set_posX(50);

		if(i >= 2)
			Player[i].Set_posY(SCREEN_SIZE_Y - 50);
		else
			Player[i].Set_posY(50);

		if (i == 4)
		{
			Player[i].Set_posX(SCREEN_SIZE_X - 50);
			Player[i].Set_posY(50);
		}
	}
	Back.RectInit(LoadGraph(PLAY_BG_PATH), VGet(0.0f, 0.0f, 0.0f), 1280, 720);

	PlayBGM.SetVol(100);
	PlayBGM.BGMInit(BGM_KIND::BGM_PLAY);

	//���j���[�w�i
	m_MenuHadnle[0] = LoadGraph(PLAY_MENU_BG_PATH);
	//�^�C�g���{�^��
	m_MenuHadnle[1] = LoadGraph(MENU_BOTTAN_TITLE_PATH);
	//���g���C�{�^��
	m_MenuHadnle[2] = LoadGraph(MENU_BOTTAN_RETRY_PATH);
	m_MenuFlame = 0;
	//�{�^�����W
	m_TitleBottan_x = 300;
	m_RetryBottan_x = 800;
	m_TitleBottan_y = m_RetryBottan_y = 350;

	card.Init();

	SceneManager::g_CurrenySceneID = SCENEID::SCENE_ID_LOOP_PLAY;
}

//�v���C�V�[���ʏ폈��
void ScenePlay::Step()
{
	m_MenuFlame++;
	//���j���[�J���ĂȂ�������
	if (m_MenuFlag == 0)
	{
		card.Step();
	}

	if (card.AllCard_isDead())
	{
		SceneManager::g_CurrenySceneID = SCENEID::SCENE_ID_FIN_PLAY;
	}

	//0.5�b��������
	if (m_MenuFlame >= 30)
	{
		//�^�u�L�[��������
		if (CheckHitKey(KEY_INPUT_TAB) == 1)
		{
			//�v���C���烁�j���[
			if (m_MenuFlag == 0)
			{
				m_MenuFlag = 1;
				m_MenuFlame = 0;
				
			}
			//���j���[����v���C
			else if (m_MenuFlag == 1)
			{
				m_MenuFlag = 0;
				m_MenuFlame = 0;
			}
		}
	}

	
}

//�v���C�V�[���`�揈��
void ScenePlay::Draw()
{
	Back.DrawRect();

	card.Draw();

	for (int i = 0; i < ScoreManager::GetAll_playerNum(); i++)
	{
		if (i == card.GetNow_Player())
		{
			SetDrawBlendMode(DX_BLENDMODE_ALPHA, 255);
		}
		else
		{
			SetDrawBlendMode(DX_BLENDMODE_ALPHA, 100);
		}

		if (ScoreManager::GetMulti_Flag() == false && i == 1)
			Player[4].DrawRect_Rota_Center(PLAYER_EXTEND_RATE);
		else
			Player[i].DrawRect_Rota_Center(PLAYER_EXTEND_RATE);

		SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
	}

	for (int i = 0; i < ScoreManager::GetAll_playerNum(); i++)
	{
		scorefont[i].Draw_int(ScoreManager::GetScore(i));
	}

	//���j���[�J���Ă�����
	if (m_MenuFlag == 1)
	{
		//�w�i
		SetDrawBlendMode(DX_BLENDMODE_ALPHA, 150);
		DrawRotaGraph(100, 100, 2.0f, 0.0f, m_MenuHadnle[0], true);
		SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
		//�^�C�g���{�^��
		DrawRotaGraph(m_TitleBottan_x, m_TitleBottan_y, 0.4f, 0.0f, m_MenuHadnle[1], true);
		//���g���C�{�^��
		DrawRotaGraph(m_RetryBottan_x, m_RetryBottan_y, 0.4f, 0.0f, m_MenuHadnle[2], true);
	}

}

//�v���C�V�[���㏈��
//���g���C���ǂ�����Ԃ�
void ScenePlay::Fin()
{
	PlayBGM.FinBGM();

	Back.RectFin();

	card.Fin();

	SceneManager::g_CurrenySceneID = SCENEID::SCENE_ID_INIT_RESULT;
}