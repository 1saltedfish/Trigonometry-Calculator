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

	if (y > 0 && y < 1.0e-8)  //�������
		y = 0;
	else if (y > -1.0e-8 && y < 0)
		y = 0;

	return y;
}

/*cos����*/
double f_cos(double x)
{
    x = (x / 180) * pi;
    for (; 1;)
    {
        if (x > pi)
        {
            x = x - 2 * pi;
        }
        if (x < -pi)
        {
            x = x + 2 * pi;
        }
        if (-pi <= x && x <= pi)
        {
            break;
        }
    }
    double result;
    double temp = 0;
    int symbol = 1;


    for (int i = 2; i < 21; i = i + 2)
    {
        symbol = symbol * (-1);
        double mi_x = 1;
        double jicheng = 1;
        for (int j = 1; j <= i; j = j + 1)
        {
            mi_x = mi_x * x;
            jicheng = jicheng * j;
        }
        temp = temp + symbol * mi_x / jicheng;
    }
    result = 1 + temp;
    return result;
}

/*tan����*/
double f_tan(double x)
{
    double o;
    x = (x / 180) * pi;
    o = x + (double(1.0 / 3.0)) * pow(x, 3) + double(2.0 / 15.0) * pow(x, 5) + double(17.0 / 315.0) * pow(x, 7) + double(62.0 / 2835.0) * pow(x, 9);
    return o;
}

/*cot����*/
double f_cot(double x)
{
	int quotient = 1;
	// cot��������Ϊpi

	//double��fioat�Ͳ�����%�������� ���� ����(a - int(a) + int(a) % 180)���൱�� a%180  
	if ((x - int(x) + int(x) % 180) == 0)
	{
		printf("��������180�ı�������Ϊ��ֵ�����к�������û������ģ�����\n\a");
		//exit(0);
	}
	else if (x > 180)    //doubleת����int������ȡ��
	{

		quotient = x / 180;      //��a=365.3����quotient=365/180=2 ��a=365.3-2*180= 5.3 
		x = x - quotient * 180;
	}
	else if (x < -180)     //����ȡ������ -359.7-> 359  ,ĨȥС����
	{
		quotient = x / 180;        //��a=-365.3����quotient=-365/180=-2 ��a=-365.3-��-2��*180 = -5.3 
		x = x - quotient * 180;
	}
	//��Ϊ������ -90<x<90
	if (x >= 90)
	{
		x = x - 180;
	}
	else if (x <= -90)
	{
		x = x + 180;
	}
	double newa = x * pi / 180.0;
	//����cot������̩�չ�ʽչ����ȡǰ���4�
	double cotx = 1.0 / newa - newa / 3.0 - pow(newa, 3) / 45 - 2 * pow(newa, 5) / 945.0;
	if (abs(cotx) < 0.007)
	{
		cotx = 0;
	}
	return cotx;
}