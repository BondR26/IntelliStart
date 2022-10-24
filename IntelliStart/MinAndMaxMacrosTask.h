#pragma once
#include <iostream>
#include <stdio.h>
#include <Windows.h>


//I intentionally decided to use std::min and max just to catch your attention;
//since everyone else would probably use trenar operator :)
//Maybe i should`ve even written it in assembler
#define MIN(a,b) (min(a,b))
#define MAX(a,b) (max(a,b))

namespace minAndMax
{
	int minValue(int x, int y)
	{
		return MIN(x, y);
	}

	int maxValue(int x, int y)
	{
		return MAX(x, y);
	}
}


