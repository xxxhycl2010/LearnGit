// Example_094.c  -- Use the stack and recursive calculation polynomials

#ifndef EXAMPLE_094_H
#define EXAMPLE_094_H

#endif // EXAMPLE_094_H

#include <stdio.h>
#include <malloc.h>

double f1(int n,int x)
{
    if(n ==0)
    {
        return 1;
    }
    else if(n==1)
        return 2*x;
    else
        return 2*x*f1(n-1,x)-2*(n-1)*f1(n-2,x);

}

double f2(int n,int x)
{
    struct STACK
    {
        int num;
        double data;
    }stack[100];

    int i,top=0;
    double sum1 = 1,sum2;
    sum2 = 2*x;
    for(i=n;i>=2;i--)
    {
        top++;
        stack[top].num = i;
    }

    while(top > 0)
    {
        stack[top].data = 2*x * sum2 - 2*(stack[top].num -1)*sum1;
        sum1 = sum2;
        sum2 = stack[top].data;
        top--;
    }
    return sum2;
}

void TestExample_094()
{
    int x,n;
    double sum1,sum2;
    printf("please input n:");
    scanf("%d",&n);
    printf("please input the x:");
    scanf("%d",&x);
    sum1 = f1(n,x);
    sum2 = f2(n,x);
    printf("the result of recursion is %f\n",sum1);
    printf("the result of stack is %f\n",sum2);
}

