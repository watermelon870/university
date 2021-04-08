#include <iostream>

class Point2d {         //typedef�� �����ϸ� �� �ȴ� nested���� �� �Ǵ� �Ͱ� ���� ��?
public:
	double m_x = 0;
	double m_y = 0;
	double parameter = 0;

public:                  //constructor �� �ʱ�ȭ
	Point2d(double x = 0.0, double y = 0.0)
		: m_x(x), m_y(y)
	{
	}

	void print() const
	{
		std::cout << "Point2d(" << m_x << ", " << m_y << ")\n";
	}
	/*
	double distanceTo(Point2d & other)                //�ϳ��� �޾Ƶ� �ȴ�
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
	Point2d second = { 3, 4 };               //second(3,4)�� ����
	first.print();
	second.print();

	std::cout << "Distance between two points : " << distanceTo(first, second) << "\n";

	return 0;
}