#pragma once
#define  RAD(x) ((x)/360.0*2*3.1415936)
class Clock
{
private:
	int h, m, s;
public:
	Clock(void);                //���ݵ���ʱ���ʼ��ʱ��
	Clock(int h, int m, int s); //����ָ��ʱ���ʼ��ʱ��
	Clock(Clock &rc)            //�����Ѵ��ڵ�ʱ�ӳ�ʼ��ʱ��
	{
		h = rc.h;
		m = rc.m;
		s = rc.s;
	}
	//void SetTime(int h, int m, int s);                     //����ʱ��
	void Addone();                                         //ʱ����1
	void DrawmyClock(int x, int y, int width, int height); //����Բ��ʱ��
};

