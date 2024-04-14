#include "Card.h"
#include "../Input/Input.h"
#include "../Score/ScoreManager/ScoreManager.h"

void CardManager::Init()
{
	wait_count = 0;
	CPU_count = 0;
	Now_Player = 0;

	canOpen = true;
	currentOpenNum = 0;

	for (int MarkIndex = 0; MarkIndex < (int)Mark::MarkNum; MarkIndex++)
	{
		for (int NumberIndex = 0; NumberIndex < 13; NumberIndex++)
		{
			Card[MarkIndex][NumberIndex].RectInit(LoadGraph(CARD_PATH[MarkIndex][NumberIndex]), VGet(Card_FirstPosX + ((float)Card_sizeX + Card_spaceX) * NumberIndex, Card_FirstPosY + ((float)Card_sizeY + Card_spaceY) * MarkIndex, 0.0f), Card_sizeX, Card_sizeY);
			Card_Back[MarkIndex][NumberIndex].RectInit(LoadGraph(CARD_BACK_PATH), VGet(Card_FirstPosX + ((float)Card_sizeX + Card_spaceX) * NumberIndex, Card_FirstPosY + ((float)Card_sizeY + Card_spaceY) * MarkIndex, 0.0f), Card_sizeX, Card_sizeY);
			isDead[MarkIndex][NumberIndex] = false;
			isOpen_now[MarkIndex][NumberIndex] = false;

			isOpened[MarkIndex][NumberIndex] = false;
		}
	}
}

void CardManager::Step()
{
	//CPU処理
	if (ScoreManager::GetMulti_Flag() == false && Now_Player == 1)
	{
		if (CPU_count >= WAIT_FRAME || wait_count > 0)
		{
			if (wait_count > 0 && wait_count < WAIT_FRAME)
			{
				wait_count++;
				CPU_count--;
			}
			else if (wait_count >= WAIT_FRAME)
			{
				for (int MarkIndex = 0; MarkIndex < (int)Mark::MarkNum; MarkIndex++)
				{
					for (int NumberIndex = 0; NumberIndex < 13; NumberIndex++)
					{
						if (isDead[MarkIndex][NumberIndex])
							continue;
						if (isOpen_now[MarkIndex][NumberIndex])
							isOpen_now[MarkIndex][NumberIndex] = false;
					}
				}
				currentOpenNum = 0;

				Now_Player++;
				if (Now_Player > ScoreManager::GetAll_playerNum() - 1)
				{
					Now_Player = 0;
				}
				canOpen = true;

				wait_count = 0;
				CPU_count = 0;
			}
			else
			{
				CardOpen_CPU();

				if (Judge())
				{
					canOpen = true;
					ScoreManager::AddScore(Now_Player, 2);
				}
			}
		}

		CPU_count++;
	}
	//通常のプレイヤー処理
	else
	{
		if (wait_count > 0 && wait_count < WAIT_FRAME)
		{
			wait_count++;
		}
		else if (wait_count >= WAIT_FRAME)
		{
			for (int MarkIndex = 0; MarkIndex < (int)Mark::MarkNum; MarkIndex++)
			{
				for (int NumberIndex = 0; NumberIndex < 13; NumberIndex++)
				{
					if (isDead[MarkIndex][NumberIndex])
						continue;
					if (isOpen_now[MarkIndex][NumberIndex])
						isOpen_now[MarkIndex][NumberIndex] = false;
				}
			}
			currentOpenNum = 0;

			Now_Player++;
			if (Now_Player > ScoreManager::GetAll_playerNum() - 1)
			{
				Now_Player = 0;
			}
			canOpen = true;

			wait_count = 0;
		}
		else
		{
			CardOpen();

			if (Judge())
			{
				canOpen = true;
				ScoreManager::AddScore(Now_Player, 2);
			}
		}
	}
}

void CardManager::Draw()
{
	for (int MarkIndex = 0; MarkIndex < (int)Mark::MarkNum; MarkIndex++)
	{
		for (int NumberIndex = 0; NumberIndex < 13; NumberIndex++)
		{
			if (isDead[MarkIndex][NumberIndex])
				continue;
			if (isOpen_now[MarkIndex][NumberIndex])
			{
				Card[MarkIndex][NumberIndex].DrawRect();
			}
			else
			{
				Card_Back[MarkIndex][NumberIndex].DrawRect();
			}
		}
	}
}

void CardManager::Fin()
{
	for (int MarkIndex = 0; MarkIndex < (int)Mark::MarkNum; MarkIndex++)
	{
		for (int NumberIndex = 0; NumberIndex < 13; NumberIndex++)
		{
			Card[MarkIndex][NumberIndex].RectFin();
			Card_Back[MarkIndex][NumberIndex].RectFin();
		}
	}
}

void CardManager::CardOpen()
{
	if (currentOpenNum < 2)
	{
		if (canOpen)
		{
			for (int MarkIndex = 0; MarkIndex < (int)Mark::MarkNum; MarkIndex++)
			{
				for (int NumberIndex = 0; NumberIndex < 13; NumberIndex++)
				{
					if (isDead[MarkIndex][NumberIndex])
						continue;
					if (isOpen_now[MarkIndex][NumberIndex])
						continue;
					if (Input::ClickRect(Card[MarkIndex][NumberIndex]))
					{
						isOpen_now[MarkIndex][NumberIndex] = true;
						currentOpenNum++;

						if (isOpened[MarkIndex][NumberIndex] == false)
						{
							isOpened[MarkIndex][NumberIndex] = true;
						}

						if (currentOpenNum == 2)
							canOpen = false;
					}
				}
			}
		}
	}
}

void CardManager::CardOpen_CPU()
{
	if (currentOpenNum < 2)
	{
		if (canOpen)
		{
			//揃えられる組があるか
			int Card1[2] = { -1, -1 };
			int Card2[2] = { -1, -1 };
			
			for (int NumberIndex = 0; NumberIndex < 13; NumberIndex++)
			{
				Card1[0] = -1;	Card1[1] = -1;
				Card2[0] = -1;	Card2[1] = -1;
				for (int MarkIndex = 0; MarkIndex < (int)Mark::MarkNum; MarkIndex++)
				{
					if (isDead[MarkIndex][NumberIndex])
						continue;
					if (isOpened[MarkIndex][NumberIndex])
					{
						if (Card1[0] == -1)
						{
							Card1[0] = MarkIndex;
							Card1[1] = NumberIndex;
						}
						else
						{
							Card2[0] = MarkIndex;
							Card2[1] = NumberIndex;
							break;
						}
					}
				}

				if (Card1[0] != -1 && Card2[0] != -1)
					break;
			}

			if (Card2[0] == -1)
			{
				Card1[0] = -1;
				Card1[1] = -1;
			}

			//揃えられる組があれば
			if (Card1[0] != -1 && Card2[0] != -1)
			{
				if(isOpen_now[Card1[0]][Card1[1]] != true)
				{
					isOpen_now[Card1[0]][Card1[1]] = true;
					currentOpenNum++;

					CPU_count = 0;
				}
				else
				{
					isOpen_now[Card2[0]][Card2[1]] = true;
					currentOpenNum++;

					CPU_count = 0;
				}

				if (currentOpenNum == 2)
					canOpen = false;
			}
			//揃えられる組がなければ
			else
			{
				while (Card1[0] == -1 || Card1[1] == -1)
				{
					int Buf_Mark = GetRand((int)Mark::MarkNum - 1);
					int Buf_Number = GetRand(13 - 1);

					if (isDead[Buf_Mark][Buf_Number])
						continue;
					if (isOpened[Buf_Mark][Buf_Number])
						continue;
					if (isOpen_now[Buf_Mark][Buf_Number])
						continue;
					Card1[0] = Buf_Mark;
					Card1[1] = Buf_Number;
				}

			isOpen_now[Card1[0]][Card1[1]] = true;
			currentOpenNum++;

			if (isOpened[Card1[0]][Card1[1]] == false)
			{
				isOpened[Card1[0]][Card1[1]] = true;
			}

			CPU_count = 0;

			if (currentOpenNum == 2)
				canOpen = false;
			}
		}
	}
}

bool CardManager::Judge()
{
	if (currentOpenNum >= 2)
	{
		int MarkIndex_1 = 0;
		int MarkIndex_2 = 0;
		int NumberIndex = 0;

		for (MarkIndex_1 = 0; MarkIndex_1 < (int)Mark::MarkNum; MarkIndex_1++)
		{
			for (NumberIndex = 0; NumberIndex < 13; NumberIndex++)
			{
				if (isDead[MarkIndex_1][NumberIndex])
					continue;
				if(isOpen_now[MarkIndex_1][NumberIndex])
					break;
				
			}
			if (isOpen_now[MarkIndex_1][NumberIndex])
				break;
		}
		for (MarkIndex_2 = MarkIndex_1 + 1; MarkIndex_2 < (int)Mark::MarkNum; MarkIndex_2++)
		{
			if (isOpen_now[MarkIndex_2][NumberIndex])
			{
				isOpen_now[MarkIndex_1][NumberIndex] = false;
				isOpen_now[MarkIndex_2][NumberIndex] = false;
				isDead[MarkIndex_1][NumberIndex] = true;
				isDead[MarkIndex_2][NumberIndex] = true;

				currentOpenNum = 0;
				return true;
			}
		}

		//はずれ
		wait_count++;
		return false;
	}
	return false;
}

bool CardManager::AllCard_isDead()
{
	int CardIndex = 0;

	for (int MarkIndex = 0; MarkIndex < (int)Mark::MarkNum; MarkIndex++)
	{
		for (int NumberIndex = 0; NumberIndex < 13; NumberIndex++)
		{
			if (isDead[MarkIndex][NumberIndex])
				CardIndex++;
		}
	}

	if (CardIndex >= (int)Mark::MarkNum * 13)
		return true;
	else
		return false;
}
