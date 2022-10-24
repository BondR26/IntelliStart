#pragma once

#include <iostream>
#include <string>
#include <algorithm>

//I kind of like such puzzles ? although you rarely meet them while working(
//(in my case i`ve dealt with them once)
#define SET_BIT(x, p) (x |= (1 << p)) // set (set to 1) proper bit into the "x" byte by "p" position
#define CLR_BIT(x, p) (x &= ~(1 << p)) // clear (set to 0) proper bit into the "x" byte by "p" position
#define TGL_BIT(x, p) (x ^= (1 << p)) // flip/toggle proper bit into the "x" byte by "p" position
#define CHK_BIT(x, p) ((x & (1 << p)) ? (1):(0))// check proper bit into the "x" byte by "p" position

//Allocate memory for dest before
void Int2BitStr(IN int x, OUT char* dest, IN int size)
{
	if (dest != nullptr)
	{
		if (x == 0)
		{
			memcpy(dest, "0", sizeof("0"));
		}
		else
		{
			int copy = abs(x);
			std::string num;

			if (x < 0)//when we deal with negative number we have to be careful about the oldest bit
			{
				copy -= 1;
			}

			while (copy > 0)
			{
				if (copy % 2 == 0)
					num += "0";
				else
					num += "1";

				copy /= 2;
			}

			//we have to hange the order from oldest to youngest because we added bit in differen driection
			std::reverse(num.begin(), num.end());

			if (x > 0)
			{
				
				memcpy(dest, num.c_str(), num.size());
			}
			else
			{
				int size = num.size();
				for (int i = 0; i != size; i++)
				{
					if ('1' == num[i])
						num[i] = '0';
					else
						num[i] = '1';
				}

				std::string negative = "1";
				negative += num;
				memcpy(dest, negative.c_str(), negative.size());
			}

		}
	}
	else
	{
		std::cout << "Dest string is empty\n";
	}
}