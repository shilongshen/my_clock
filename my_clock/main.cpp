#include <iostream>
using namespace std;
#include <cstdlib>
#include "Clock.h"
#include "acllib.h"
#include <windows.h>
const int winWidth = 600, winHeight = 600;


int Setup()
{
	initWindow("my first clock",
		DEFAULT, DEFAULT, winWidth, winHeight);
	Clock c;
	c.DrawmyClock(10, 10, winWidth - 20, winHeight - 20);
	return 0;
}



