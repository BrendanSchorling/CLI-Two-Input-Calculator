#include <iostream>
#include <math.h>
#include <string>
#include "calculator.h"
#include <vector>
using namespace std;

double Operator::addition(double num1, double num2)
{
	return num1 + num2;
}
double Operator::subtraction(double num1, double num2)
{
	return num1 - num2;
}
double Operator::multiplication(double num1, double num2)
{
	return num1 * num2;
}
double Operator::division(double num1, double num2)
{
	return num1 / num2;
}
double Operator::modulo(double num1, double num2)
{
	return fmod(num1, num2);
}
double Operator::xPowy(double num1, double num2)
{
	return pow(num1, num2);
}
double Operator::xRooty(double num1, double num2)
{
	return pow(num1, 1 / num2);
}

double Operator::operation(string opperand, double num1, double num2, double result)
{
	double answer;
	if (opperand == "+")
	{
		answer = addition(num1, num2);
	}
	else if (opperand == "-")
	{
		answer = subtraction(num1, num2);
	}
	else if (opperand == "*")
	{
		answer = multiplication(num1, num2);
	}
	else if (opperand == "/")
	{
		answer = division(num1, num2);
	}
	else if (opperand == "%")
	{
		answer = modulo(num1, num2);
	}
	else if (opperand == "^")
	{
		answer = xPowy(num1, num2);
	}
	else if (opperand == "root")
	{
		answer = xRooty(num1, num2);
	}
	return answer;
}