#pragma once
#define  RAD(x) ((x)/360.0*2*3.1415936)
class Clock
{
private:
	int h, m, s;
public:
	Clock(void);                //根据电脑时间初始化时钟
	Clock(int h, int m, int s); //根据指定时间初始化时钟
	Clock(Clock &rc)            //根据已存在的时钟初始化时钟
	{
		h = rc.h;
		m = rc.m;
		s = rc.s;
	}
	//void SetTime(int h, int m, int s);                     //设置时间
	void Addone();                                         //时间增1
	void DrawmyClock(int x, int y, int width, int height); //绘制圆形时钟
};

