#include "Clock.h"
#include "acllib.h"
#include <iostream>
using namespace std;
#include <time.h>
#include <math.h>
#define  RAD(x) ((x)/360.0*2*3.1415936)



Clock::Clock(void)
{
	time_t t;
	struct tm *tmm;
	t = time(NULL);
	tmm = localtime(&t);
	h = tmm->tm_hour;
	m = tmm->tm_min;
	s = tmm->tm_sec;
}

Clock::Clock(int h = 0, int m = 0, int s = 0)
{
	this->h = h;
	this->m = m;
	this->s = s;
}

void Clock::DrawmyClock(int x, int y, int width, int height)
{
	int ox = (x + width) / 2;
	int oy = (y + height) / 2;
	int min = width < height ? width : height;
	int hl = min / 4 - min / 7;
	int ml = min / 3 - min / 6;
	int sl = min / 2 - min / 5;
	int i;

	beginPaint();
	clearDevice();

	setPenWidth(2);
	setPenColor(BLACK);
	setBrushColor(WHITE);
	ellipse(x, y, width, height);

	setPenWidth(1);
	setPenColor(BLACK);
	int len1 = min / 2 - min / 8;
	int len2 = len1 + 10;
	for (int i = 0; i < 12; i++)
	{
		moveTo(ox + len1 * sin(RAD(180 - i * 30)), oy + len1 * cos(RAD(180 - i * 30)));
		lineTo(ox + len2 * sin(RAD(180 - i * 30)), oy + len2 * cos(RAD(180 - i * 30)));
	}

	setPenWidth(8);
	setPenColor(BLACK);
	moveTo(ox, oy);
	lineTo(ox + hl * sin(RAD(180 - i * 30)), oy + hl * cos(RAD(180 - i * 30)));

	setPenWidth(4);
	setPenColor(GREEN);
	moveTo(ox, oy);
	lineTo(ox + ml * sin(RAD(180 - i * 30)), oy + ml * cos(RAD(180 - i * 30)));

	setPenWidth(2);
	setPenColor(RED);
	moveTo(ox, oy);
	lineTo(ox + sl * sin(RAD(180 - i * 30)), oy + sl * cos(RAD(180 - i * 30)));

	endPaint();
}

void Clock::Addone()
{
	s++;
	if (s >= 60)
	{
		m++;
		s = 0;
		if (m >= 60)
		{
			h++;
			m = 0;
			if (h >= 12)
			{
				h = 0;
			}
		}
	}
}
