#pragma once
#include "Scene.h"

//�v���C�V�[���摜����
const int SCENE_PLAY_IMAGE_NUM = 1;

//�v���C�V�[���w�i
#define SCENE_PLAY_BACK_PATH	"Data/Image/ScenePlay/PlaySceneBackImage.png"

class ScenePlay : public SceneBase
{
private:

public:
	void Init();
	void Step();
	void Draw();
	void Fin();
};