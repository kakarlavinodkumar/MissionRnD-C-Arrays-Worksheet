/*
OVERVIEW:  given an array that has duplicate values remove all duplicate values.
E.g.: input: [1, 1, 2, 2, 3, 3], output [1, 2, 3]

INPUTS: Integer array and length of the array.

OUTPUT: Update input array by removing duplicate values.

ERROR CASES: Return NULL for invalid inputs.

NOTES: Don't create new array, try to change the input array.
*/

#include <stdio.h>
struct binary_search_tree
{
	int data;
	struct binary_search_tree *left, *right;
}*root,*current,*newnode,*temp;
void * removeArrayDuplicates(int *Arr, int len)
{
	int index1, count;
	bool flag;
	if (Arr==NULL||len<0)
	return NULL;
	root = (struct binary_search_tree*)malloc(sizeof(binary_search_tree));
	root->left = root->right = NULL;
	root->data = Arr[0];
	for (index1 = count = 1; index1 < len ; index1++)
	{
		for (current = root,flag=0; current != NULL;)
		{
			if (current->data == Arr[index1])
				break;
			if (current->data < Arr[index1])
			{
				if (current->right == NULL)
				{
					flag = 1;
					break;
				}
				current = current->right;
			}
			else
			{
				if (current->left == NULL)
				{
					flag = 1;
					break;
				}
				current = current->left;
			}
		}
			if (flag==1)
			{
				newnode = (struct binary_search_tree *)(malloc(sizeof(struct binary_search_tree)));
				newnode->data = Arr[index1];
				newnode->left = newnode->right = NULL;
				if (current->data < newnode->data)
					current->right = newnode;
				else
					current->left = newnode;
				Arr[count++] = Arr[index1];
			}
	}
}
