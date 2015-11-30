/*
OVERVIEW:  given an array that has duplicate values remove all duplicate values.
E.g.: input: [1, 1, 2, 2, 3, 3], output [1, 2, 3]

INPUTS: Integer array and length of the array.

OUTPUT: Update input array by removing duplicate values.

ERROR CASES: Return NULL for invalid inputs.

NOTES: Don't create new array, try to change the input array.
*/

#include <stdio.h>

void * removeArrayDuplicates(int *Arr, int len)
{
	int index1, index2, count;
	if (Arr==NULL||len<0)
	return NULL;
	for (index1 = count = 0; index1 < len - 1; index1++)
	{
		for (index2 = index1 + 1; index2 < len; index2++)
		{
			if (Arr[index1] == Arr[index2])
				break;
		}
		if (index2 == len)
			Arr[count++] = Arr[index1];
	}
	Arr[count] = Arr[index1];
}