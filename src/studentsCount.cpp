
/*
OVERVIEW:  Write a function that takes ascending sorted student's score array and tells how many number of students got more marks and how many students got less marks than the given student.
E.g.: Input array: [10, 20, 30, 40, 50], score: 30, lessCount value is 2 (10, 20 are less than 30), moreCount value is 2 (40, 50 are greater than 30).

INPUTS: Ascending sorted student marks array, length of the array, one student score, lessCount and moreCount are to be
used to store final results.

OUTPUT: Update lessCount and moreCount with number of students less than and more than given score.

ERROR CASES: Return NULL for invalid inputs.

NOTES:
*/

#include <stdio.h>

int less_count_binary_search(int *arr, int size, int num)
{
	int low, mid, high;
	for (low = 0, high = size - 1; low <= high;)
	{
		mid = (low + high) / 2;
		if (arr[mid] >= num&&arr[mid - 1] < num)
			return mid;
		if (num < arr[mid])
			high = mid - 1;
		else
			low = mid + 1;
	}
	return 0; //no lesser elemnts than num
}
int more_count_binary_search(int *arr, int size, int left_bound,int num)
{
	int low, mid, high;
	for (low = left_bound, high = size - 1; low <= high;)
	{
		mid = (low + high) / 2;
		if (arr[mid] > num&&arr[mid - 1] <= num)
			return size - mid;
		if (arr[mid] < num)
			low = mid + 1;
		else
			high = mid - 1;
	}
	return 0;   //no greater elements than num
}
void * studentsCount(int *Arr, int len, int score, int *lessCount, int *moreCount) {
	if (len<0||Arr==NULL)
	return NULL;
	if (Arr[0]>score)
	{
		moreCount[0] = len;  //all elements are grearter than given score
		lessCount[0] = 0;
	}
	else if (Arr[len - 1] < score)     
	{
		lessCount[0] = len;  //all elements are lesser than given score
		moreCount[0] = 0;
	}
	else
	{
		lessCount[0] = less_count_binary_search(Arr, len, score);
		moreCount[0] = more_count_binary_search(Arr, len, lessCount[0], score);
	}
}
