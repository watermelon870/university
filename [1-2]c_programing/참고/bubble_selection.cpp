#include <iostream>

void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

void selection(int a[], int len)
{
	for (int i = len - 1; i >= 0; i--)
	{
		for (int j = i - 1; j >= 0; j--)
		{
			if (a[i] < a[j])
			{
				swap(a + i, a + j);
			}
		}
	}
}

void bubble(int a[], int len)
{
	int swaped = 0;					  //early termination을 위해서 선언
	int count = 0;

	for (int i = 0; i < len - 1; i++) //len - 1이 마지막 정리 되었다는걸 보여줌
	{
		for (int j = 1; j < len; j++)
		{
			if (a[j - 1] > a[j])
			{
				swap((a + j - 1), (a + j));
				swaped = 1;
			}
		}
		count++;
		if (swaped == 0)
		{
			break;
		}
		swaped = 0;
	}

	std::cout << "Early termination on iteration " << count << std::endl;

}

int main()
{
	int array[] = { 6,3,2,9,7,1,5,4,8 };
	const int length = sizeof(array) / sizeof(array[0]);

	selection(array, length);  //selection or bubble

	for (int i = 0; i < length; i++)
	{
		std::cout << array[i] << " ";
	}

	std::cout << "\n";

	return 0;
}

