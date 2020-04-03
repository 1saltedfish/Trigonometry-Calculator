// ConsoleApplication1.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//
#include <iostream>
//#include "mclmcr.h"
//#include "matrix.h"
//#include "mclcppclass.h"

#include "mclmcrrt.h"
#include "mclcppclass.h"
#include "tmwtypes.h"
#include "mat.h"

#include "tanm.h"
using namespace std;
int main()
{
    if (!tanmInitialize())  
    {
        cout << "Could not initialize" << endl;
        exit(0);
    }

    mwArray input(1,1, mxDOUBLE_CLASS, mxREAL);
    mwArray output(1,1, mxDOUBLE_CLASS, mxREAL);

    double i[1] = { 45.0 };
  //  i = 45.0;

    input.SetData(i,1);
    tanm(1,output,input);

    cout << output.Get(1, 1);
    return 0;
}