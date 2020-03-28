#pragma once
class tan_function
{
public:
	tan_function(double i);
	~tan_function(void);
	double input;
	double output;
	double caculate(void);
};


int input_parse(double x);

