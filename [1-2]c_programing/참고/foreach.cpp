#include <iostream>

int main()
{
	std::string names[] = {"Alex", "Betty", "Caroline", "Dave", "Emily", "Fred", "Greg", "Holly"};
	char input[20];

	std::cout << "Enter a name : ";
	std::cin >> input;

	int i = 0;

	for (auto &name : names)
	{
		if (name == input)
		{
			i = 1;
			break;
		}
	}

	if (i == 1)
	{
		std::cout << input << " was found. \n";
	}
	else
	{
		std::cout << input << " was not found. \n";
	}
	return 0;
}