#pragma once
using namespace std;
#include <string>
#include <vector>

class calculate {
	public:
		void operationList();
		void performOperation();
		string buildHistory(string opperand, double num1, double num2, double answer);
		void printHistory(vector<string> oppHistory);
		bool oneInputCheck(string opperand);
		bool twoInputCheck(string opperand);
};

class Operator {
	public:
		double addition(double num1, double num2);
		double subtraction(double num1, double num2);
		double multiplication(double num1, double num2);
		double division(double num1, double num2);
		double modulo(double num1, double num2);
		double xPowy(double num1, double num2);
		double xRooty(double num1, double num2);
		double operation(string opperand, double num1, double num2, double result);
};

class oneInputOpps {
	public:
		double logBaseTen(double num1);
		double natLog(double num1);
		double exponential(double num1);
		double square(double num1);
		double squareRoot(double num1); 
		double oneInputOperation(string opperand, double num1);
};