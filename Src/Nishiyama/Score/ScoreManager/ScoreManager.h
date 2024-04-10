#pragma once
#include "../Score/Score.h"

class ScoreManager
{
private:
	static bool Multi_Flag;
	static int All_playerNum;
	static Score score[4];

public:
	static void Init() { Multi_Flag = false; All_playerNum = 0; for (int i = 0; i < 4; i++) { score[i].Init(); } }
	static void AddScore(int playerNum, int Add_int) { score[playerNum].AddScore(Add_int); }
	static int GetScore(int playerNum) { return score[playerNum].GetScore(); }

	static void SetMulti_Flag(bool new_Multi_Flag = false) { Multi_Flag = new_Multi_Flag; }
	static bool GetMulti_Flag() { return Multi_Flag; }
	static void SetAll_playerNum(int new_All_playerNum = 1) { All_playerNum = new_All_playerNum; }
	static int GetAll_playerNum() { return All_playerNum; }
};