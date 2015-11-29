/*
OVERVIEW: In a given ascending sorted array, two numbers are changed their position, please fix those two numbers.
E.g.: In [10, 40, 30, 20, 50] 20 and 40 are swapped, so final output will be [10, 20, 30, 40, 50]

INPUTS: Ascending sorted array with two positions swapped, length of the array.

OUTPUT: Update sorted array by fixing swapped numbers.

ERROR CASES: Return NULL for invalid Inputs.

NOTES:
*/

#include <stdio.h>

void * sortedArrayPositionsChange(int *Arr, int len)
{
	int max, index1 = 0, index2 = 0, index;
	if (Arr == NULL || len<0)
		return NULL;
	for (max = Arr[0], index = 0; index < len; index++)
	{
		if (max <= Arr[index])
			max = Arr[index];
		else
			index1 = index;
	}
	for (max = Arr[len - 1], index = len - 1; index >= 0; index--)
	{
		if (max >= Arr[index])
			max = Arr[index];
		else
			index2 = index;
	}
	Arr[index1] = Arr[index1] + Arr[index2];
	Arr[index2] = Arr[index1] - Arr[index2];
	Arr[index1] = Arr[index1] - Arr[index2];
}