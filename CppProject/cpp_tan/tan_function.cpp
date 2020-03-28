// tan_function.cpp : �������̨Ӧ�ó������ڵ㡣
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
	cout << "�������ĽǶ�ֵ";
	cin >> x;

	//������
	sta = input_parse(x);
	if(sta == ERROR_INPUT)
	{
		cout << "��������";
		system("pause");
		return 0;
	}

	//���м���
	tan_function a(x);
	cout << "����ֵΪ��" << a.caculate() ;

	////�������
	//y = x/180 * PI;	//���Ƕ�����ת��Ϊ��������
	//cout << "���Ϊ��" << tan(y)-a.caculate();

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
	//ʹ���������չ������tan������Ĭ�Ͻ���Ϊ10
	double o;
	double x,y;

	//��������д���ʹ��������-90��+90��Χ��

	x = fmod(input,180);//�������ϵĵ�ȫ��ӳ�䵽-180��180��,��ʱx��ȡֵ��ΧΪ-180��180,��Ҫ�ٽ���ѹ��Ϊ-90��90
	if(x>90)
	{
		x = x-180;//��90-180�ϵĵ�ӳ��Ϊ-90-0
	}	
	else if (x<-90)
	{
		x = x+180;//��-180--90�ĵ�ӳ��Ϊ0-90
	}

	//��������ֵ
	if(x==45)
		return 1;
	if(x==-45)
		return -1;

	y = x/180 * PI;	//���Ƕ�����ת��Ϊ��������
	o = y +  (double(1.0/3.0)) * pow(y,3) +  double(2.0/15.0) * pow(y,5) +  double(17.0/315.0) * pow(y,7)  +  double(62.0/2835.0) * pow(y,9) ;
	return o;
}
