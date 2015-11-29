/*
OVERVIEW: 	Given date of births of two persons as inputs, return 1 if person one is elder,
2 if person two is elder, 0 if both are of same age.
Example: isOlder("24-07-2000", "25-07-2000") should return 1 as person one
is elder than person two.

INPUTS: 	DOBs of two persons as parameters in the format "DD-MM-YYYY".

OUTPUT: 	1 if person one is elder, 2 if person two is elder, 0 if both are of same age.

ERROR CASES: Return -1 if any DOB is invalid.

NOTES: 		Don't use any built-in C functions for comparisions. You are free to write any helper functions.
*/

int is_date_valid(int date, int month, int year);
int string_length(char* x);
int is_data_valid(char* dob);

int isOlder(char *dob1, char *dob2) 
{
	int ans = -1, d1, m1, y1, d2, m2, y2;
	if (is_data_valid(dob1) == 1 && is_data_valid(dob2))
	{
		d1 = (dob1[0] - '0') * 10 + (dob1[1] - '0');
		m1 = (dob1[3] - '0') * 10 + (dob1[4] - '0');
		y1 = (dob1[6] - '0') * 1000 + (dob1[7] - '0') * 100 + (dob1[8] - '0') * 10 + (dob1[9] - '0');

		d2 = (dob2[0] - '0') * 10 + (dob2[1] - '0');
		m2 = (dob2[3] - '0') * 10 + (dob2[4] - '0');
		y2 = (dob2[6] - '0') * 1000 + (dob2[7] - '0') * 100 + (dob2[8] - '0') * 10 + (dob2[9] - '0');

		if (is_date_valid(d1, m1, y1) == 1 && is_date_valid(d2, m2, y2) == 1)
		{
			if (y1 > y2)
				ans = 2;
			else if (y1 < y2)
				ans = 1;
			else
			{
				if (m1 > m2)
					ans = 2;
				else if (m1 < m2)
					ans = 1;
				else
				{
					if (d1 > d2)
						ans = 2;
					else if (d1 < d2)
						ans = 1;
					else
						ans = 0;
				}
			}
		}

	}

	return ans;
}

int is_date_valid(int date, int month, int year)
{
	int valid = 1;

	if (year <= 1800 || year > 2100)
		valid = 0;
	else if (month < 1 || month >12)
		valid = 0;
	else if (month == 2)
	{
		if (date > 28)
			valid = 0;
		if (date == 29 && year % 4 == 0)
			valid = 1;
	}
	else if (month == 4 || month == 6 || month == 9 || month == 11)
	{
		if (date > 30 || date < 1)
			valid = 0;
	}
	else if (date > 31 || date < 1)
		valid = 0;

	return valid;
}

int is_data_valid(char* dob)
{
	int i, flag = 1;
	if (string_length(dob) != 10)
		flag = 0;
	else
	{
		for (i = 0; i < 10; i++)
		{
			if (dob[i] < '0' || dob[i] >'9')
			{
				flag = 0;
				if (i == 2 || i == 5)
					flag = 1;
				else
					break;
			}			
		}
		
		if (dob[2] != '-' && dob[5] != '-')
			flag = 0;
	}
	return flag;
}

int string_length(char* x)				// string length calculator 
{
	int i;
	for (i = 0; x[i] != '\0'; i++);
	return i;
}