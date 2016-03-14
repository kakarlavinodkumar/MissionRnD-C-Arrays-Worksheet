/*
OVERVIEW: Given a sorted array, insert a given number into the array at appropriate position.
			E.g.: Arr = [2, 4, 6], num = 5 final Arr = [2, 4, 5, 6]. 5 is inserted at 2nd index.

INPUTS: Integer	Array pointer, length of the array, number to be inserted.

OUTPUT: Array pointer after inserting number.

ERROR CASES: Return NULL for invalid inputs.

NOTES: Use realloc to allocate memory.
*/

#include <stdio.h>
#include <malloc.h>

void shift_right(int *Arr, int len, int k)
{
	for (; len >= k; len--)
		Arr[len] = Arr[len - 1];
}

int binary_search(int *arr, int size, int num)
{
	int low, mid, high;
	for (low = 0, high = size - 1; low <= high;)
	{
		mid = (low + high) / 2;
		if (arr[mid] >= num&&arr[mid - 1] < num)
			return mid;
		if (arr[mid] < num)
			low = mid + 1;
		else
			high = mid - 1;
	}
}
int * sortedArrayInsertNumber(int *arr, int size, int num)
{
	int position;
	if (arr == NULL || size <= 0)
		return NULL;
	arr = (int *)realloc(arr,sizeof(int)*(size + 1));
	if (arr[size - 1] <= num)
		arr[size] = num;
	else if (arr[0] >= num)
	{
		shift_right(arr, size, 0);
		arr[0] = num;
	}
	else
	{
		position = binary_search(arr, size, num);
		shift_right(arr, size, position);
		arr[position] = num;
	}
	return arr;
}
