#include <iostream>
#include <cmath>
using namespace std;
// #define  PI 3.1415926
#define _USE_MATH_DEFINES
#include <math.h>     // 5��6�б�֤ʹ��pi��д��M_PI
double cottest(double a)
{	
	int quotient=1;
	if (a >= 180 ) 
	{
		quotient = a / 180;
		a = a - quotient * 180;
	}
	else if(a <= -180)
	{
		quotient = a / 180;
		a = a - quotient * 180;
	}
	else if (a == 0)
	{
		printf("��������0����Ϊ0�����к�������û������ģ�����\n\a");
		exit(0);  //������ĽǶ���0ʱ������ʾ��������������������У�
	}
	double newa = a * M_PI / 180.0;
	//����cot������̩�չ�ʽչ����ȡǰ���4�
	double cotx = 1.0 / newa - newa / 3.0 - pow(newa,3)/ 45 - 2 * pow(newa,5)/ 945.0;
	return cotx;
}
int main()
{
	double x;
	cout << "������Ҫ������еĶ���ֵ:";
	cin >> x;
	cout << "�����к�����ֵ�ǣ�" <<cottest(x)<<endl;
	return 0;
}

