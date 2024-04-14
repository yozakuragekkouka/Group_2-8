#include <math.h>
#include "DxLib.h"
#include "../../Common.h"
#include "../Input/Input.h"
#include "../Shapes/Shapes.h"
#include "Scene.h"
#include "SceneResult.h"
#include "../NumberFont/NumberFont.h"

//�N���A������
void SceneResult::Init()
{
	Result_BG_Hndl = LoadGraph(RESULT_BG_PATH);
	TextHndl = LoadGraph(TEXT_PATH);

	TextPosX = 400;
	TextPosY = 470;
	MousePosX = MousePosY = 0;

	SceneManager::g_CurrenySceneID = SCENEID::SCENE_ID_LOOP_RESULT;
}

//�N���A�ʏ폈��
void SceneResult::Step()
{
	//�}�E�X�̍��W���擾����
	GetMousePoint(&MousePosX, &MousePosY);

	//�}�E�X���������Ƃ��Ƀ}�E�X���W���摜�͈͓̔��ɂ���΃V�[�����I���
	if (GetMouseInput() & MOUSE_INPUT_LEFT)
	{
		if (MousePosX > TextPosX && MousePosX < TextPosX + TEXT_WIDHT
			&& MousePosY > TextPosY && MousePosY < TextPosY + TEXT_HEIGHT)
		{
			SceneManager::g_CurrenySceneID = SCENEID::SCENE_ID_FIN_RESULT;
		}
	}
}

//�N���A�`�揈��
void SceneResult::Draw()
{
	DrawGraph(0, 0, Result_BG_Hndl, true);				//�w�i�摜�`��
	DrawGraph(TextPosX, TextPosY, TextHndl, true);		//�e�L�X�g�摜�`��
	DrawMousePointa();

	DrawFormatString(0, 0, GetColor(255, 255, 255), "�}�E�X��X���W�F%d", MousePosX);
	DrawFormatString(0, 15, GetColor(255, 255, 255), "�}�E�X��Y���W�F%d", MousePosY);

}

//�N���A�㏈��
void SceneResult::Fin()
{
	DeleteGraph(Result_BG_Hndl);
	DeleteGraph(TextHndl);

	SceneManager::g_CurrenySceneID = SCENEID::SCENE_ID_INIT_TITLE;
}

//�}�E�X�|�C���^�`�揈��
void SceneResult::DrawMousePointa()
{
	int mousepoint = 0;

	mousepoint = LoadGraph(MOUSE_POINTA_PATH);

	//�}�E�X�ʒu�擾
	DrawRotaGraph(Input::GetMousePos().x, Input::GetMousePos().y, 0.65f, 0.0f, mousepoint, true);

}