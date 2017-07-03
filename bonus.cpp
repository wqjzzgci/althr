#include <stdio.h>
#include <math.h>
void getBonus();
void caldigit();
void calDays();
int main(int argc, char **argv)
{
    //getBonus();
    //caldigit();
    calDays();
    return 0;
}
/*程序2
1.低于等于10万时，奖金提成10%
2.高于10万小于20万时，低于10万的按10%提成，高于10万的部分按7.5%提成
3.20万到40万时，高于20万的部分提成5%
4.40万到60万时高于40万的部分提成3%
5.60万到100万时，高于60万的部分提成1.5%
6.高于100万时，超过100万的部分按1%提成
*/
void getBonus()
{
    long int i;
    int bonus1, bonus2, bonus4, bonus6, bonus10, bonus;
    scanf("%ld", &i);
    bonus1 = 100000 * 0.1;
    bonus2 = bonus1 + 100000 * 0.075;
    bonus4 = bonus2 + 200000 * 0.05;
    bonus6 = bonus4 + 200000 * 0.03;
    bonus10 = bonus6 + 400000 * 0.015;

    if (i <= 100000)
        bonus = i * 0.1;
    else if (i <= 200000)
    {
        bonus = bonus1 + (i - 100000) * 0.075;
    }
    else if (i <= 400000)
    {
        bonus = bonus2 + (i - 200000) * 0.05;
    }
    else if (i <= 600000)
    {
        bonus = bonus4 + (i - 400000) * 0.03;
    }
    else if (i <= 1000000)
    {
        bonus = bonus6 + (i - 600000) * 0.015;
    }
    else
    {
        bonus = bonus10 + (i - 1000000) * 0.01;
    }
    printf("bonus=%d", bonus);
    getchar();
}
/*
一个整数，加上100后是一个完全平方数，再加上168后又是一个完全平方数，请问该数是多少？
*/
void caldigit()
{
    long int i, x, y, z;
    for (i = 1; i < 100000; i++)
    {
        x = sqrt(i + 100);
        y = sqrt(i + 268);
        if (x * x == i + 100 && y * y == i + 268)
        {
            printf("\n%d\n", i);
        }
    }
    getchar();
}
/*
输入某年某月某日，判断这一天是这一年的第几天？
*/
void calDays()
{
    int day, month, year, sum, leap;
    printf("\nplease input year,month,day\n");
    scanf("%d,%d,%d", &year, &month, &day);
    switch (month) /* 先计算某月以前月份的总天数 */
    {
    case 1:
        sum = 0;
        break;
    case 2:
        sum = 31;
        break;
    case 3:
        sum = 59;
        break;
    case 4:
        sum = 90;
        break;
    case 5:
        sum = 120;
        break;
    case 6:
        sum = 151;
        break;
    case 7:
        sum = 181;
        break;
    case 8:
        sum = 212;
        break;
    case 9:
        sum = 243;
        break;
    case 10:
        sum = 273;
        break;
    case 11:
        sum = 304;
        break;
    case 12:
        sum = 334;
        break;
    default:
        printf("data error");
        break;
    }
    sum = sum + day;                                           /* 再加上某天的天数 */
    if (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0)) /* 判断是不是闰年 */
        leap = 1;
    else
        leap = 0;
    if (leap == 1 && month > 2) /* 如果是闰年且月份大于 2,总天数应该加一天 */
        sum++;
    printf("It is the %dth day.", sum);
}
