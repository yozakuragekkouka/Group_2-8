#pragma once
#include "Scene.h"

//�v���C�V�[���w�i
constexpr char PLAY_BG_PATH[128] = "Data/Image/ScenePlay/PlaySceneBackImage.png";

class ScenePlay : public SceneBase
{
private:

public:
	void Init();
	void Step();
	void Draw();
	void Fin();
};
