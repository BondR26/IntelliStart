#include <time.h>
#include <random>
#include "MinAndMaxMacrosTask.h"
#include "SetBitsMasksTask2.h"

void logInfoForMinAndMaxTask();

void bitMaskTask();

int main()
{
	
	bitMaskTask();

	logInfoForMinAndMaxTask();

	return EXIT_SUCCESS;
}

void bitMaskTask()
{
	srand(time(0));
	int num = rand() % 100;
	char dest[MAX_PATH] = { 0 };
	Int2BitStr(num, dest, MAX_PATH);
	std::cout << "num " << num << " == in binary " << dest << std::endl;

	int x, y, z, f, starting_point;
	starting_point = x = y = z = f = rand() % 10;
	int xn = 10 + rand() % 10, yn = 10 + rand() % 10, zn = 10 + rand() % 10, fn = 10 + rand() % 10;
	
	std::cout << "setting bit N "<< xn << " in number " << starting_point <<" to 1 equals = " << SET_BIT(x, xn) << std::endl;
	std::cout << "setting bit N "<< yn << " in number " << starting_point <<" to 0 equals = " << CLR_BIT(y, yn) << std::endl;
	std::cout << "setting bit N "<< zn << " in number " << starting_point <<" to opposite, equals = " << TGL_BIT(z, zn) << std::endl;
	std::cout << "bit N "<< fn << " in number " << starting_point <<" is set to " << CHK_BIT(f, fn) << std::endl;
}

void logInfoForMinAndMaxTask()
{
	int x1 = 3, x2 = 3;
	int y1 = 3, y2 = 3;
	char buffer1[MAX_PATH] = "Instead of explaining to you what the increment and decrement does\n ";
	char buffer2[MAX_PATH] = "i would rather say that instead of using printf you would rather use something with _s, casue of buffer overflow issues";
	sprintf_s(buffer1, MAX_PATH, "\n");
	sprintf_s(buffer2, MAX_PATH, "\n");
	printf("MIN(%d, %d) = %d\n", x1, y1, MIN(x1++, y1));
	printf("MIN(%d, %d) = %d\n", x1, y1, MIN(++x1, y1));
	printf("MIN(%d, %d) = %d\n", x2, y2, minAndMax::minValue(++x2, y1));
	printf("MIN(%d, %d) = %d\n", x2, y2, minAndMax::minValue(x2++, y1));
}