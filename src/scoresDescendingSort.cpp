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
	char str[15];
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
void * scoresDescendingSort(struct student *students, int len) {
	int index1, index2, index;
	if (students == NULL || len<0)
		return NULL;
	for (index1 = 0; index1 < len; index1++)
	{
		for (index2 = 0; index2 < len - 1; index2++)
		{
			if (students[index2].score < students[index2 + 1].score)
			{
				students[index2].score = students[index2].score + students[index2 + 1].score;
				students[index2 + 1].score = students[index2].score - students[index2 + 1].score;
				students[index2].score = students[index2].score - students[index2 + 1].score;
				swapstr(students, index2, index2 + 1);
			}
		}
	}
}