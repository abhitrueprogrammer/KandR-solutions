// Exercise 5-8. There is no error checking in day_of_year or month_day.
// Remedy this defect. □
#include <stdio.h>
static char year_month_days[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
static char leap_year_month_days[] = {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};


static char *daytab[] = {year_month_days, leap_year_month_days};
int day_of_year(int year, int month, int day);
int month_day(int year, int yearday, int *pmonth, int *pday);

int main(void)
{
    int month, day;
    int day_year;
    if ((day_year =  day_of_year(2024,2, 15))>=0)
    {
        printf("%i\n",day_year);
    }
    else
        printf("input error!\n");
    if(month_day(2024, 46, &month, &day) >=0)
    {
            printf("%i, %i\n", month, day);
    }
    else
        printf("input error!");
}
/* day_of_year: set day of year from month & day */
int day_of_year(int year, int month, int day)
{
    int i, leap;
    if (month > 12 || month < 0)
        return -1;
    leap = year % 4 == 0 && year % 100 != 0 || year % 400 == 0;
    for (i = 1; i < month; i++)
        day += *(daytab[leap] +i);
    return day;
}
/* month_day: set month, day from day of year */
int month_day(int year, int yearday, int *pmonth, int *pday)
{
    int i, leap;
    if(yearday > 366)
    {
        return -1;
    }
    leap = year % 4 == 0 && year % 100 != 0 || year % 400 == 0;
    for (i = 1; yearday > *(daytab[leap]+i); i++)
        yearday -= *(daytab[leap]+i);
    *pmonth = i;
    *pday = yearday;
    return 0;
}
