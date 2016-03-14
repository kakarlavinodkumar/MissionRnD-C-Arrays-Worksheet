/*
OVERVIEW:  You are given scores for students of a class in alphabetical order. Write a function that sorts these scores in descending order.
Input is array of structures of type student (each student has name and score).
E.g.: If input is [ { "stud1", 20 }, { "stud2", 30 }, { "stud3", 40 } ] (three students with marks 20, 30 , 40).
Output for this will be [ { "stud3", 40 }, { "stud2", 30 }, { "stud1", 20 } ]

INPUTS: Array of structures of type student, length of array.

OUTPUT: Sort the array in descending order of scores.

ERROR CASES: Return NULL for invalid Inputs.

NOTES:
*/

#include <stdio.h>

struct student {
	char name[10];
	int score;
};


void swapstr(struct student *students, int index, int minindex)
{
	int index1;
	char *str;
	str = (char *)malloc(sizeof(char)* 15);
	for (index1 = 0; students[index].name[index1] != NULL; index1++)
		str[index1] = students[index].name[index1];
	str[index1] = '\0';
	for (index1 = 0; students[minindex].name[index1] != '\0'; index1++)
		students[index].name[index1] = students[minindex].name[index1];
	students[index].name[index1] = '\0';
	for (index1 = 0; str[index1] != '\0'; index1++)
		students[minindex].name[index1] = str[index1];
	students[minindex].name[index1] = '\0';
}
void swap_score(struct student *students, int index_low, int index_high)
{
	students[index_low].score = students[index_low].score + students[index_high].score;
	students[index_high].score = students[index_low].score - students[index_high].score;
	students[index_low].score = students[index_low].score - students[index_high].score;
}
void quick_sort(struct student *students, int low, int high)
{
	int index_low, index_high;
	if (low < high)
	{
		for (index_low = low, index_high = high; index_low <= index_high;)
		{
			if (students[index_low].score >= students[low].score)
				index_low++;
			else if (students[index_high].score < students[low].score)
				index_high--;

			else
			{
				swapstr(students, index_low, index_high);
				swap_score(students, index_low, index_high);
			}
		}
		if (students[index_high].score > students[low].score)
		{
			swapstr(students, index_high, low);
			swap_score(students, index_high, low);
		}
		quick_sort(students, low, index_high - 1);
		quick_sort(students, index_high + 1, high);
	}
}
void * scoresDescendingSort(struct student *students, int len) {
	int index1, index2, index;
	if (students == NULL || len<0)
		return NULL;
	quick_sort(students, 0, len - 1);
}
