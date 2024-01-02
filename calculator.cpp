#include <iostream>
#include <math.h>
#include <string>
#include "calculator.h"
#include <vector>
#include <limits>
using namespace std;
Operator O;
oneInputOpps One;

void calculate::operationList()
{
	cout << "Operation List: " << endl;
	cout << "1 - 'list' to print operation list" << endl;
	cout << "2 - '+' to perform addition" << endl;
	cout << "3 - '-' to perform subtraction" << endl;
	cout << "4 - '*' to perform multiplication" << endl;
	cout << "5 - '/' to perform division" << endl;
	cout << "6 - '%' to perform modulo division" << endl;
	cout << "7 - 'history' to view operation history" << endl;
	cout << "8 - 'erase' to erase operation history" << endl;
	cout << "9 - '^' to perform x to power of y" << endl;
	cout << "10 - 'root' to perform yth root of x" << endl;
	cout << "11 - 'off' to exit calculator program" << endl;
	cout << "12 - 'clear' to set result to zero" << endl;
	cout << "13 - 'repeat' to repeat and output previous function" << endl;
	cout << "14 - 'log10' to perform log base ten on first number/previous result" << endl;
	cout << "15 - 'natlog' to perform natural log on first number/previous result" << endl;
	cout << "16 - 'exp' to perform exponetial function with first number/previous result" << endl; 
	cout << "17 - '^2' to perform square of first number/previous result" << endl;
	cout << "18 - 'sqrt' to perform square root of first number/previous result" << endl;
	cout << "Input operations exactly as shown" << endl; 
}
void calculate::performOperation()
{
	vector <string> list;
	double answer,prevAnswer = 0;
	double x,y = 0;
	string opp,prevOpp = "";
	//First operation
	while (opp == "") 
	{
		operationList();
		cout << "Enter first number: " << endl;
		cin >> x;
		while (cin.fail()) 
		{
			cin.clear(); 
			cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
			cout << "Improper entry, please enter a number: " << endl; 
			cin >> x; 
		}
		cout << "Enter operation symbol: " << endl;
		cin >> opp;
		if (opp == "list")
		{
			operationList();
			answer = 0;
		}
		else if (opp == "history")
		{
			printHistory(list);
			answer = 0; 
		}
		else if (opp == "erase")
		{
			list.clear();
			cout << "Operation History has been erased" << endl;
		}
		else if (opp == "off")
		{
			cout << "Exiting Calculator Program" << endl;
			exit(0);
		}
		else if (oneInputCheck(opp) == true)
		{
			answer = One.oneInputOperation(opp, x);
			list.push_back(buildHistory(opp, x, y, answer));
		}
		else if (twoInputCheck(opp) == true)
		{
			cout << "Enter second number: " << endl;
			cin >> y;
			while (cin.fail()) 
			{ 
				cin.clear(); 
				cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
				cout << "Improper entry, please enter a number: " << endl; 
				cin >> y; 
			}
			answer = O.operation(opp, x, y, prevAnswer); 
			list.push_back(buildHistory(opp, x, y, answer));
		}
		else
		{
			cout << "Invalid operator input, please use proper syntax in order to perform successful operation" << endl;
			answer = 0;
		}
		cout << "Result: " << answer << endl;
	}
	//All other operations
	while (true)
	{
		cout << "Enter operation symbol to perform on result: " << endl;
		if (opp != "repeat")
		{
			prevOpp = opp;
		}
		cin >> opp;
		prevAnswer = answer;
		if (opp == "list")
		{
			operationList();
		}
		else if (opp == "history")
		{
			printHistory(list);
		}
		else if (opp == "erase")
		{
			list.clear();
			cout << "Operation History has been erased" << endl;
		}
		else if (opp == "off")
		{
			cout << "Exiting Calculator Program" << endl;
			exit(0);
		}
		else if (opp == "clear")
		{
			cout << "Result cleared" << endl;
			answer = 0;
		}
		else if (opp == "repeat")
		{

			if (oneInputCheck(prevOpp) == true) 
			{
				answer = One.oneInputOperation(prevOpp, prevAnswer);
			}
			else
			{ 
				answer = O.operation(prevOpp, prevAnswer, y, prevAnswer); 
			}
			list.push_back(buildHistory(prevOpp, prevAnswer, y, answer)); 
		}
		else if (oneInputCheck(opp) == true)
		{
			answer = One.oneInputOperation(opp, prevAnswer);
			list.push_back(buildHistory(opp, prevAnswer, y, answer)); 
		}
		else if(twoInputCheck(opp) == true) 
		{
			cout << "Enter second number: " << endl;
			cin >> y;
			while (cin.fail()) 
			{ 
				cin.clear(); 
				cin.ignore(numeric_limits<streamsize>::max(), '\n');  
				cout << "Improper entry, please enter a number: " << endl; 
				cin >> y; 
			}
			answer = O.operation(opp, prevAnswer, y, prevAnswer);
			list.push_back(buildHistory(opp, prevAnswer, y, answer));
		}
		else
		{
			cout << "Invalid operator input, please use proper syntax in order to perform successful operation" << endl; 
		}
		cout << "Result: " << answer << endl;
	}
}

string calculate::buildHistory(string opperand, double num1, double num2, double answer)
{
	string tempOperation = to_string(num1) + " " + opperand + " " + to_string(num2) + " = " + to_string(answer);
	if (oneInputCheck(opperand) == true) 
	{
		tempOperation = opperand + " " + to_string(num1) + " = " + to_string(answer); 
	}
	return tempOperation;
}

void calculate::printHistory(vector<string> oppHistory)
{
	for (int i = 0; i < oppHistory.size(); i++)
	{
		cout << "Operation " << i + 1 << ": " << oppHistory[i] << endl;
	}
}

bool calculate::oneInputCheck(string opperand)
{
	bool numVal;
	if (opperand == "log10" || opperand == "natlog" || opperand == "exp" || opperand == "^2" || opperand == "sqrt")
	{
		numVal = true;
	}
	else
	{
		numVal = false;
	}
	return numVal;
}

bool calculate::twoInputCheck(string opperand)
{
	bool numVal;
	if (opperand == "+" || opperand == "-" || opperand == "*" || opperand == "/" || opperand == "%" || opperand == "^" || opperand == "root")
	{
		numVal = true;
	}
	else
	{
		numVal = false;
	}
	return numVal;
}



