#include <iostream>

typedef double(*arithmeicFcn)(double, double);

typedef struct {
	char op;
	arithmeicFcn fcn;
}arithmeticStruct;

double add(double a, double b)
{
	return a + b;
}
double substract(double a, double b)
{
	return a - b;
}
double multiply(double a, double b)
{
	return a * b;
}
double divide(double a, double b)
{
	return a / b;
}

arithmeticStruct arithmeticArray[] ={
	{'+', add},
	{'-', substract},
	{'*', multiply},
	{'/', divide}
};


int getDouble()
{
	std::cout << "Input a number : ";
	int x;
	std::cin >> x;
	return x;
}

char getOperation()
{
	char operation;
	while (1)
	{
		std::cout << "Input operater : ";
		std::cin >> operation;

		if (operation == '+')
		{
			return operation;
			break;
		}
		else if (operation == '-')
		{
			return operation;
			break;
		}
		else if (operation == '*')
		{
			return operation;
			break;
		}
		else if (operation == '/')
		{
			return operation;
			break;
		}
		else
		{
			std::cout << "Input valid operation \n";
		}
	}
}


arithmeicFcn getArithemeticFcn(char op)
{
	for (const auto &arith : arithmeticArray)
	{
		if (arith.op == op)
		{
			return arith.fcn;
		}
	}

}


int main()
{
	
	double a = getDouble();
	char op = getOperation();
	double b = getDouble();

	arithmeicFcn fcn = getArithemeticFcn(op);

	std::cout << a << " " << op << " " << b << " = " << fcn(a, b) << std::endl;


	

	return 0;
}