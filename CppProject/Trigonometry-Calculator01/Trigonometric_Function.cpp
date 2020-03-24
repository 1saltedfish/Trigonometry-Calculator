#include "pch.h"
#include "Trigonometric_Function.h"
#include "math.h"

const int ORDER_NUM = 10;  //�������չ���Ľ���
const double pi = 3.14159265358979323846;

/*��n�Ľ׳�*/
LONG64 factorial(int n)    //7���ͻᳬ��int���ܱ�ʾ�ķ�Χ����Ҫ��long64
{
	LONG64 y = 1;
	for (int i = 1; i <= n; i++)
		y = y * i;
	return y;
}

/*sin������������ǽǶ�*/
double f_sin(double x)
{
	if (x >= 360)  //������淶��-360��360��֮��
		x -= floor(x / 360) * 360;
	if (x <= -360)
		x += floor(-x / 360) * 360;

	x = pi / 180 * x;  //���Ƕ�ת��Ϊ����

	double y = 0;      //��ʼ�����Ϊ��
	for (int i = 1; i <= ORDER_NUM; i++)
		y += pow(-1, i - 1) * pow(x, 2 * i - 1) / factorial(2 * i - 1);

	return y;
}