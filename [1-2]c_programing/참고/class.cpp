#include <iostream>

class Point2d {         //typedef로 선언하면 안 된다 nested에서 안 되는 것과 같은 듯?
public:
	double m_x = 0;
	double m_y = 0;
	double parameter = 0;

public:                  //constructor 로 초기화
	Point2d(double x = 0.0, double y = 0.0)
		: m_x(x), m_y(y)
	{
	}

	void print() const
	{
		std::cout << "Point2d(" << m_x << ", " << m_y << ")\n";
	}
	/*
	double distanceTo(Point2d & other)                //하나만 받아도 된다
	{
		return sqrt((m_x - other.m_x)*(m_x - other.m_x) + (m_y - other.m_y)*(m_y - other.m_y));
	}
	*/
};

double distanceTo(Point2d first, Point2d second)
{
	return sqrt((first.m_x - second.m_x)*(first.m_x - second.m_x) + (first.m_y - second.m_y) * (first.m_y - second.m_y));
}

int main()
{
	Point2d first;
	Point2d second = { 3, 4 };               //second(3,4)와 같다
	first.print();
	second.print();

	std::cout << "Distance between two points : " << distanceTo(first, second) << "\n";

	return 0;
}