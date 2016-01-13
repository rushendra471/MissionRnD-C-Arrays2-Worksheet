/*
OVERVIEW: You are given 2 bank statements that are ordered by date. Write a function that returns dates common to both statements
(ie both statements have transactions in these dates).
E.g.: Input: A[3] = { { 10, "09-10-2003", "First" }, { 20, "19-10-2004", "Second" }, { 30, "03-03-2005", "Third" } };
B[3] = { { 10, "09-10-2003", "First" }, { 220, "18-01-2010", "Sixth" }, { 320, "27-08-2015", "Seventh" } };
Output: { { 10, "09-10-2003", "First" } }

INPUTS: Two bank statements (array of transactions).

OUTPUT: Transactions having same dates.

ERROR CASES: Return NULL for invalid inputs.

NOTES:
*/

#include <iostream>

struct transaction {
	int amount;
	char date[11];
	char description[20];
};

int checkDate2(int d, int m, int y){	// Same implementation as in first problem
	if (m>0 && m<13){
		if (m == 2){
			if ((((y % 4 == 0 && y % 100 != 0) || (y % 400 == 0)) && (d>0 && d<30)) || ((y % 4 != 0) && d>0 && d<29))	//checking for leap year and non-leap year including days
				return 1;
			else
				return 0;
		}
		else if (m>7)
			m++;

		if ((m % 2 == 1) && (d>0 && d<32))
			return 1;
		if ((m % 2 == 0) && (d>0 && d<31))
			return 1;
	}

	return 0;
}

int compareDates(char *dob1, char *dob2) {
	int d1, m1, y1, d2, m2, y2;
	if ((dob1[2] != '-'&&dob1[5] != '-') && (dob2[2] != '-'&&dob2[5] != '-'))
		return -1;
	d1 = ((dob1[0] - 48) * 10) + (dob1[1] - 48);
	m1 = ((dob1[3] - 48) * 10) + (dob1[4] - 48);
	y1 = ((dob1[6] - 48) * 1000) + ((dob1[7] - 48) * 100) + ((dob1[8] - 48) * 10) + (dob1[9] - 48);
	d2 = ((dob2[0] - 48) * 10) + (dob2[1] - 48);
	m2 = ((dob2[3] - 48) * 10) + (dob2[4] - 48);
	y2 = ((dob2[6] - 48) * 1000) + ((dob2[7] - 48) * 100) + ((dob2[8] - 48) * 10) + (dob2[9] - 48);
	if (checkDate2(d1, m1, y1) == 0)
		return -1;
	if (checkDate2(d2, m2, y2) == 0)
		return -2;
	else{
		if (y1>y2)
			return 2;
		else if (y2>y1)
			return 1;
		else if (m1>m2)
			return 2;
		else if (m2>m1)
			return 1;
		else if (d1>d2)
			return 2;
		else if (d2>d1)
			return 1;
		else
			return 0;
	}
}

struct transaction * sortedArraysCommonElements(struct transaction *A, int ALen, struct transaction *B, int BLen) {
	if (A == NULL || ALen < 1 || B == NULL || BLen < 1)
		return NULL;

	int AInd = 0, BInd = 0, resInd = 0;
	struct transaction *res = (struct transaction *) malloc(sizeof(struct transaction) * ((ALen < BLen) ? ALen : BLen));

	while (AInd < ALen && BInd < BLen) {
		int temp = compareDates(A[AInd].date, B[BInd].date);
		if (temp == -1 || temp == 1)
			AInd++;
		else if (temp == -2 || temp == 2)
			BInd++;
		else {
			res[resInd++] = A[AInd++];
			BInd++;
		}
	}
	if (resInd == 0)
		return NULL;

	realloc(res, resInd);
	return res;
}
