/*
OVERVIEW: Given an array where every element occurs three times, except one element which occurs only
once. Find the element that occurs once.
E.g.: Input: arr = 12, 1, 12, 3, 12, 1, 1, 2, 3, 3
ouput: 2

INPUTS: Integer array and length of the array.

OUTPUT: Element that occurs only once.

ERROR CASES: Return -1 for invalid inputs.

NOTES:
*/

#include<stdio.h>

int findSingleOccurenceNumber(int *A, int len) {
	if (A == NULL || len < 1 || len % 3 == 0 || len % 3 == 2)
		return -1;
	int ind = 0, element, i, j;
	for (i = 0; i < len; i++) {
		for (j = 0; j < len - 1; j++) 
			if (A[i] == A[j] && i != j)
				break;
		if (j == len - 1)
			element = A[i];
	}
	return element;
}