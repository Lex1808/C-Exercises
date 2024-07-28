#include <stdio.h>

typedef struct Date {
    int month;
    int day;
    int year;
} date;

int day_of_year(date d) {
    int day = 0;
    const int days_in_month[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (d.month > 1 && ((d.year % 4 == 0 && d.year % 100 != 0) || d.year % 400 == 0)) {
        day++;
    }

    for (int i = 0; i < d.month; i++) {
        day += days_in_month[i];
    }
    return day + d.day; 
}
int compare_dates(date d1, date d2) {
    int day1 = day_of_year(d1);
    int day2 = day_of_year(d2);
    if (day1 < day2) {
        if (d1.year < d2.year) {
            return -1;
        }
        else if(d1.year > d2.year) {
            return 1;
        } else {
            goto label1;
        }  
    }
    label1:
    if (day1 > day2) {
        if(d1.year > d2.year) {
            return 1;
        }
        else if (d1.year < d2.year) {
            return -1;
        } else {
            goto label2;
        }        
    }
    label2:
    if (day1 == day2 || d1.year == d2.year) {
        return 0;
    }
}

int main(void) {
    date day1 = {10, 20, 2024};
    date day2 = {10, 20, 2024};

    printf("Days day1: %d\n", day_of_year(day1));
    printf("Days day2: %d\n", day_of_year(day2));

    if(compare_dates(day1, day2) == -1) {
        printf("This date is earlier: %d.%d.%d\n", day1.day, day1.month, day1.year);
    }
    else if(compare_dates(day1, day2) == 1) {
        printf("This date is earlier: %d.%d.%d\n", day2.day, day2.month, day2.year);
    } else {
        printf("day1 and day2 are equel\n");
    }
    
    return 0;
}
