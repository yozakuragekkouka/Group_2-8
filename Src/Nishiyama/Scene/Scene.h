#pragma once

constexpr char MOUSE_POINTA_PATH[128] = "Data/Image/SceneTitle/MousePointa.png";

enum class SCENEID
{
//�I����ID
SCENE_ID_END = -1,	//�G���h�V�[����ID

//�^�C�g���V�[����ID
SCENE_ID_INIT_TITLE	= 100,	//�������V�[����ID
SCENE_ID_LOOP_TITLE,		//�J��Ԃ��V�[����ID
SCENE_ID_FIN_TITLE,			//�㏈���V�[����ID

//�v���C�V�[����ID
SCENE_ID_INIT_PLAY = 200,	//�������V�[����ID
SCENE_ID_LOOP_PLAY,			//�J��Ԃ��V�[����ID
SCENE_ID_FIN_PLAY,			//�㏈���V�[����ID

//���U���g�V�[����ID
SCENE_ID_INIT_RESULT = 300,		//�������V�[����ID
SCENE_ID_LOOP_RESULT,			//�J��Ԃ��V�[����ID
SCENE_ID_FIN_RESULT,			//�㏈���V�[����ID
};

//�V�[�����N���X
class SceneBase
{
public:
	virtual void Init() { return; }
	virtual void Step() { return; }
	virtual void Draw() { return; }
	virtual void Fin() { return; }
};

class SceneManager
{
private:
	SceneBase* scene;

public:
	static SCENEID g_CurrenySceneID;	//���݂̃V�[��ID

	SceneManager();
	~SceneManager();

	void SceneInit();

	bool SceneLoop();

	void SceneFin();

};
