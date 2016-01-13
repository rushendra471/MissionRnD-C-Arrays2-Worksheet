/*
OVERVIEW: You are given a bank statement where transactions are ordered by date. Write a function that finds the number of transactions in that statement after a given date.
-- find the count of numbers greater than a given number in a sorted array.
E.g.: Input: A[3] = { { 10, "09-10-2003", "First" }, { 20, "19-10-2004", "Second" }, { 30, "03-03-2005", "Third" } };
date = "19-10-2004"
Output: 1 (as there is only one transaction { 30, "03-03-2005", "Third" })

INPUTS: One bank statement (array of transactions) and date.

OUTPUT: Return the number of transactions in that statement after a given date.

ERROR CASES: Return NULL for invalid inputs.

NOTES:
*/
#include<stdio.h>

struct transaction {
	int amount;
	char date[11];
	char description[20];
};

int checkDate(int d, int m, int y){
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

int isGreater(int d1, int m1, int y1, int d2, int m2, int y2){
	if (y1>y2)
		return 0;
	else if (y2>y1)
		return 1;
	else if (m1>m2)
		return 0;
	else if (m2>m1)
		return 1;
	else if (d1>d2)
		return 0;
	else if (d2>d1)
		return 1;
	else
		return 0;
}

int countGreaterNumbers(struct transaction *Arr, int len, char *date) {
	if (Arr == NULL || len < 1 || date == NULL)
		return NULL;

	int end_day = (date[0] - '0') * 10 + (date[1] - '0');
	int end_mon = (date[3] - '0') * 10 + (date[4] - '0');
	int end_year = (date[6] - '0') * 1000 + (date[7] - '0') * 100 + (date[8] - '0') * 10 + (date[9] - '0');
	if (checkDate(end_day, end_mon, end_year) == 0)		// Validating given date.
		return NULL;

	int cnt = 0;

	for (int i = 0; i < len; i++){
		int cur_day = (Arr[i].date[0] - '0') * 10 + (Arr[i].date[1] - '0');
		int cur_mon = (Arr[i].date[3] - '0') * 10 + (Arr[i].date[4] - '0');
		int cur_year = (Arr[i].date[6] - '0') * 1000 + (Arr[i].date[7] - '0') * 100 + (Arr[i].date[8] - '0') * 10 + (Arr[i].date[9] - '0');

		if (!checkDate(cur_day, cur_mon, cur_year))		// Validating each and every date in a statement.  If we want, we can skip this.
			continue;

		if (cnt > 0 || isGreater(end_day, end_mon, end_year, cur_day, cur_mon, cur_year)){		// cur_date > end_date
			//return (len - i);			//We can write this statement, if we want to skip validating of each and every date in statement.
			cnt++;
		}
	}

	return cnt;
}
