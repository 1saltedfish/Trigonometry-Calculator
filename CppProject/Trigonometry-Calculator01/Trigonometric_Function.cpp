#include "pch.h"
#include "Trigonometric_Function.h"
#include "math.h"

const int ORDER_NUM = 10;  //麦克劳林展开的阶数
const double pi = 3.14159265358979323846;

/*求n的阶乘*/
LONG64 factorial(int n)    //7！就会超出int所能表示的范围，故要用long64
{
	LONG64 y = 1;
	for (int i = 1; i <= n; i++)
		y = y * i;
	return y;
}

/*sin函数，输入的是角度*/
double f_sin(double x)
{
	if (x >= 360)  //将输入规范至-360—360°之间
		x -= floor(x / 360) * 360;
	if (x <= -360)
		x += floor(-x / 360) * 360;

	x = pi / 180 * x;  //将角度转化为弧度

	double y = 0;      //初始化输出为零
	for (int i = 1; i <= ORDER_NUM; i++)
		y += pow(-1, i - 1) * pow(x, 2 * i - 1) / factorial(2 * i - 1);

	return y;
}