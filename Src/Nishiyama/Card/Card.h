#pragma once
#include "../Shapes/Shapes.h"

enum class Mark
{
	Spade,
	Clover,
	Heart,
	Dia,

	MarkNum
};

class CardManager
{
private:
	Rect_Data Card[(int)Mark::MarkNum][13];
	Rect_Data Card_Back[(int)Mark::MarkNum][13];
	bool isOpen_now[(int)Mark::MarkNum][13];

	bool isOpened[(int)Mark::MarkNum][13];

	int currentOpenNum;

};