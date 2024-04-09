#include <math.h>

#include "DxLib.h"
#include "../../Common.h"
#include "../FrameRate/FrameRate.h"
#include "../Input/Input.h"
#include "Scene.h"
#include "SceneTitle.h"
#include "ScenePlay.h"
#include "SceneResult.h"

//�v���C�V�[���摜�p�X
const char* PLAY_IMAGE_PATH[SCENE_PLAY_IMAGE_NUM] =
{
	SCENE_PLAY_BACK_PATH,		//�v���C�V�[���w�i�p�X


};

//�v���C�V�[��������
void ScenePlay::Init()
{

	SceneManager::g_CurrenySceneID = SCENEID::SCENE_ID_LOOP_PLAY;
}

//�v���C�V�[���ʏ폈��
void ScenePlay::Step()
{
	if (Input::PressAnyKey())
	{
		SceneManager::g_CurrenySceneID = SCENEID::SCENE_ID_FIN_PLAY;
	}
}

//�v���C�V�[���`�揈��
void ScenePlay::Draw()
{

}

//�v���C�V�[���㏈��
//���g���C���ǂ�����Ԃ�
void ScenePlay::Fin()
{
	SceneManager::g_CurrenySceneID = SCENEID::SCENE_ID_INIT_RESULT;
}
