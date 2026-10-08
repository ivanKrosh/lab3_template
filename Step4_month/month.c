#include <stdio.h>
#include <stdlib.h>

static int days_in_month(int month, int year)
{
    switch (month) {
    case 1: case 3: case 5: case 7: case 8: case 10: case 12:
        return 31;
    case 4: case 6: case 9: case 11:
        return 30;
    case 2:
        if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0) {
            return 29;
        } else {
            return 28;
        }
    default:
        return 0;
    }
}

int main(int argc, char *argv[])
{
    int month = argc > 1 ? atoi(argv[1]) : 2;
    int year  = argc > 2 ? atoi(argv[2]) : 2024;
    int days  = days_in_month(month, year);
    if (days == 0) {
        fprintf(stderr, "bad month: %d\n", month);
        return 2;
    }
    printf("%02d.%d: %d days\n", month, year, days);
    return 0;
}
