/*
 * @Author: Guoquan Wei 1940359148@qq.com 
 * @Date: 2018-01-21 17:16:20 
 * @Last Modified by: Guoquan Wei
 * @Last Modified time: 2018-01-21 18:58:54
 */

#include <stdio.h>

static char daytab[2][13] = {
	{0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
	{0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}};

int day_of_year(int year, int month, int day);
void month_day(int year, int yearday, int *pmonth, int *pday);
char *month_name(int n);

int main()
{
	int month = 1, day = 20;
	int yearday = 45;
	yearday = day_of_year(2018, 3, 1);
	month_day(2018, 50, &month, &day);
	printf("%d\n", yearday);
	printf("today is %s  %d\n", month_name(month), day);
}

int day_of_year(int year, int month, int day)
{
	int i, leap;

	leap = (year % 4 == 0 && year % 100 != 0) || year % 400 == 0;
	for (i = 1; i < month; i++)
	{
		day += daytab[leap][i];
	}
	return day;
}

void month_day(int year, int yearday, int *pmonth, int *pday)
{
	int i, leap;

	leap = (year % 4 == 0 && year % 100 != 0) || year % 400 == 0;
	for (i = 1; yearday > daytab[leap][i]; i++)
	{
		yearday -= daytab[leap][i];
	}
	*pmonth = i;
	*pday = yearday;
}

char *month_name(int n)
{
	static char *monthnamearray[] = {
		"Ilig",//illegal
		"Jan ", "Feb ", "Mar ", "Apr ",
		"May ", "June", "July", "Aug ",
		"Sept", "Oct ", "Nov ", "Dec "};
	return (n < 1 || n > 12) ? monthnamearray[0] : monthnamearray[n];
}