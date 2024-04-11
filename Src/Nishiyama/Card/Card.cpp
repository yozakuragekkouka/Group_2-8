#include "Card.h"
#include "../Input/Input.h"
#include "../Score/ScoreManager/ScoreManager.h"

void CardManager::Init()
{
	Now_Player = 0;

	canOpen = false;
	currentOpenNum = 0;

	for (int MarkIndex = 0; MarkIndex < (int)Mark::MarkNum; MarkIndex++)
	{
		for (int NumberIndex = 0; NumberIndex < 13; NumberIndex++)
		{
			Card[MarkIndex][NumberIndex].RectInit(LoadGraph(CARD_PATH[MarkIndex][NumberIndex]), VGet(100.0f + (Card_sizeX + Card_spaceX) * NumberIndex, 100.0f + (Card_sizeY + Card_spaceY) * MarkIndex, 0.0f), Card_sizeX, Card_sizeY);
			Card_Back[MarkIndex][NumberIndex].RectInit(LoadGraph(CARD_BACK_PATH), VGet(100.0f + (Card_sizeX + Card_spaceX) * NumberIndex, 100.0f + (Card_sizeY + Card_spaceY) * MarkIndex, 0.0f), Card_sizeX, Card_sizeY);
			isAlive[MarkIndex][NumberIndex] = false;
			isOpen_now[MarkIndex][NumberIndex] = false;

			isOpened[MarkIndex][NumberIndex] = false;
		}
	}
}

void CardManager::Step()
{
	if (wait_count > 0 && wait_count < WAIT_FRAME)
	{
		wait_count++;
	}
	else if (wait_count == WAIT_FRAME)
	{
		for (int MarkIndex = 0; MarkIndex < (int)Mark::MarkNum; MarkIndex++)
		{
			for (int NumberIndex = 0; NumberIndex < 13; NumberIndex++)
			{
				if (isOpen_now[MarkIndex][NumberIndex])
					isOpen_now[MarkIndex][NumberIndex] = false;
			}
		}

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

void CardManager::Draw()
{
	for (int MarkIndex = 0; MarkIndex < (int)Mark::MarkNum; MarkIndex++)
	{
		for (int NumberIndex = 0; NumberIndex < 13; NumberIndex++)
		{
			if (isOpen_now[MarkIndex][NumberIndex])
			{
				Card[MarkIndex][NumberIndex].DrawRect_Rota_Center();
			}
			else
			{
				Card_Back[MarkIndex][NumberIndex].DrawRect_Rota_Center();
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
					if (Input::ClickRect_Center(Card[MarkIndex][NumberIndex]))
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

				return true;
			}
		}

		//‚Í‚¸‚ê
		wait_count++;
		return false;
	}
}
