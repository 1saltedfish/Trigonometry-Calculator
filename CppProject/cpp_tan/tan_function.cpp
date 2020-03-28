// tan_function.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "tan_function.h"
using namespace std;
#define _USE_MATH_DEFINES
const double PI  =3.141592653589793238463;

#define ERROR_INPUT 1

int _tmain(int argc, _TCHAR* argv[])
{
	double x,y;
	int sta;
	cout << "输入待求的角度值";
	cin >> x;

	//输入检测
	sta = input_parse(x);
	if(sta == ERROR_INPUT)
	{
		cout << "错误输入";
		system("pause");
		return 0;
	}

	//进行计算
	tan_function a(x);
	cout << "正切值为：" << a.caculate() ;

	////计算误差
	//y = x/180 * PI;	//将角度输入转化为弧度输入
	//cout << "误差为：" << tan(y)-a.caculate();

	system("pause");
	return 0;
}

int input_parse(double x)
{

	if(fmod(x,180)==90 )
		return ERROR_INPUT;

	return 0;
}

tan_function::tan_function(double i)
{
	input = i;
	output = 0.0;
}


tan_function::~tan_function(void)
{
}


double tan_function::caculate()
{
	//使用麦克劳林展开近似tan函数，默认阶数为10
	double o;
	double x,y;

	//对输入进行处理：使得输入在-90到+90范围内

	x = fmod(input,180);//将数轴上的点全部映射到-180到180上,此时x的取值范围为-180到180,需要再将其压缩为-90到90
	if(x>90)
	{
		x = x-180;//将90-180上的点映射为-90-0
	}	
	else if (x<-90)
	{
		x = x+180;//将-180--90的点映射为0-90
	}

	//常用特殊值
	if(x==45)
		return 1;
	if(x==-45)
		return -1;

	y = x/180 * PI;	//将角度输入转化为弧度输入
	o = y +  (double(1.0/3.0)) * pow(y,3) +  double(2.0/15.0) * pow(y,5) +  double(17.0/315.0) * pow(y,7)  +  double(62.0/2835.0) * pow(y,9) ;
	return o;
}
