#include<stdio.h>
/*
题目1：有1,2,3,4个数字，能组成多少互不相同且无重复数字的三位数？都是多少？
*/
int main(int argc,char **argv)
{
    int i,j,k;
    printf("\n");
    int num=0;
    for(i=1;i<5;i++)
    {
        for(j=1;j<5;j++)
        {
            for(k=1;k<5;k++)
            {
                if(i!=j&&i!=k&&j!=k)
                {
                    printf("%d,%d,%d",i,j,k);
                    printf("\n");
                    printf("%d",i*100+j*10+k);
                    printf("\n");
                    num++;
                }
            }
        }
    }
    printf("\n");
    printf("%d",num);
    getchar();
    return 0;
}