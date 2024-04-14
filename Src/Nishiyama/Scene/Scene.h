#pragma once

constexpr char MOUSE_POINTA_PATH[128] = "Data/Image/SceneTitle/MousePointa.png";

enum class SCENEID
{
//終了のID
SCENE_ID_END = -1,	//エンドシーンのID

//タイトルシーンのID
SCENE_ID_INIT_TITLE	= 100,	//初期化シーンのID
SCENE_ID_LOOP_TITLE,		//繰り返しシーンのID
SCENE_ID_FIN_TITLE,			//後処理シーンのID

//プレイシーンのID
SCENE_ID_INIT_PLAY = 200,	//初期化シーンのID
SCENE_ID_LOOP_PLAY,			//繰り返しシーンのID
SCENE_ID_FIN_PLAY,			//後処理シーンのID

//リザルトシーンのID
SCENE_ID_INIT_RESULT = 300,		//初期化シーンのID
SCENE_ID_LOOP_RESULT,			//繰り返しシーンのID
SCENE_ID_FIN_RESULT,			//後処理シーンのID
};

//シーン基底クラス
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
	static SCENEID g_CurrenySceneID;	//現在のシーンID

	SceneManager();
	~SceneManager();

	void SceneInit();

	bool SceneLoop();

	void SceneFin();

};
