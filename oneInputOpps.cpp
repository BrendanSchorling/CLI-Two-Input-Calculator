#include <iostream>
#include <math.h>
#include <string>
#include "calculator.h"
#include <vector>
#include <limits>
using namespace std;

double oneInputOpps::logBaseTen(double num1)
{
	return log10(num1);
}
double oneInputOpps::natLog(double num1)
{
	return log(num1); 
}
double oneInputOpps::exponential(double num1)
{
	return exp(num1); 
}
double oneInputOpps::square(double num1)
{
	return pow(num1,2);
}
double oneInputOpps::squareRoot(double num1) 
{
	return sqrt(num1);
}
double oneInputOpps::oneInputOperation(string opperand, double num1)
{
	double answer;
	if (opperand == "log10")
	{
		answer = logBaseTen(num1);  
	}
	else if (opperand == "natlog")
	{
		answer = natLog(num1);
	}
	else if (opperand == "exp")
	{
		answer = exponential(num1); 
	}
	else if (opperand == "^2")
	{
		answer = square(num1);
	}
	else if (opperand == "sqrt")
	{
		answer = squareRoot(num1); 
	}
	return answer;
}