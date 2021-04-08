#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <cassert>

int getArrayValue(int array[], int index)
{
	// we're asserting that index is between 0 and 9
	assert(index >= 0 && index <= 9); // this is line 6 in Test.cpp

	return array[index];
}

int main()
{
	int array[10] = { 1,2,3,4,5,6,7,8,9,10 };
	
	getArrayValue(array, -3);

	return 0;
}