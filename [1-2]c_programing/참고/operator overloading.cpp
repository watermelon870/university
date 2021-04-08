#include <iostream>

class Average {
private :
	int32_t track = 0;
	int8_t numbers = 0;
public :
	Average()
	{
	}

	friend std::ostream& operator<< (std::ostream &out, const Average &average);
	
	Average& operator+=(int num)
	{
		track += num;
		++numbers;

		return *this;                           //this를 활용하면 둘 다 한번에 return 가능
	}
};


std::ostream& operator<< (std::ostream &out, const Average &average)
{
	out << static_cast<double>(average.track) / average.numbers;    //static_cast?

	return out;
}

int main()
{
	Average avg;

	avg += 4;
	std::cout << avg << '\n'; // 4 / 1 = 4

	avg += 8;
	std::cout << avg << '\n'; // (4 + 8) / 2 = 6

	avg += 24;
	std::cout << avg << '\n'; // (4 + 8 + 24) / 3 = 12

	avg += -10;
	std::cout << avg << '\n'; // (4 + 8 + 24 - 10) / 4 = 6.5

	(avg += 6) += 10; // 2 calls chained together
	std::cout << avg << '\n'; // (4 + 8 + 24 - 10 + 6 + 10) / 6 = 7

	Average copy = avg;
	std::cout << copy << '\n';

	return 0;
}