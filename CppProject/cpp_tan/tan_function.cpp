// tan_function.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include "tan_function.h"
using namespace std;
#define _USE_MATH_DEFINES
const double PI  =3.141592653589793238463;

int _tmain(int argc, _TCHAR* argv[])
{
	double x,y;
	cout << "�������ĽǶ�ֵ";
	cin >> x;

	y = x/180 * PI;

	tan_function a(y);
	cout << "����ֵΪ��" << a.caculate() ;
	cout << "���Ϊ��" << tan(y)-a.caculate();
	system("pause");
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
	//ʹ���������չ������tan������Ĭ�Ͻ���Ϊ10
	double o;
	o = input +  (double(1.0/3.0)) * pow(input,3) +  double(2.0/15.0) * pow(input,5) +  double(17.0/315.0) * pow(input,7)  +  double(62.0/2835.0) * pow(input,9) ;
	return o;
}
