//Example_091.cpp -- function: use stack to set password

#ifndef EXAMPLE_091_H
#define EXAMPLE_091_H

#endif // EXAMPLE_091_H


#include <iostream>
#include <malloc.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

using namespace std;

#define STACK_SIZE 100
char PASSWORD[10] = "13579";
typedef char DataType;

typedef struct
{
    DataType *base;
    DataType *top;
    int stacksize;
    int length;

}SeqStack;

void Initial(SeqStack *s)
{
    s->base = (DataType*)malloc(STACK_SIZE*sizeof(DataType));
    if(!s->base)
        exit(-1);
    s->top = s->base;
    s->stacksize =STACK_SIZE;
    s->length = 0;
}

bool IsEmpty(SeqStack *s)
{
    return s->top == s->base;
}

bool IsFull(SeqStack *s)
{
    return s->top - s->base == STACK_SIZE-1;
}

void Push(SeqStack *s,DataType x)
{
    if(IsFull(s))
    {
        printf("stack is full\n");
        exit(1);


    }
    *(s->top++) = x;
    ++s->length;
}

DataType Pop(SeqStack *s)
{
    if(IsEmpty(s))
    {
        printf("stack is empty\n");
        exit(1);
    }
    --(s->length);
    return *--s->top;
}

DataType GetTop(SeqStack *s,DataType *e)
{
    if(IsEmpty(s))
    {
        printf("statck is empty\n");
        exit(1);
    }
    *e = *(s->top-1);
    s->top--;
}

void change(SeqStack *s,char *a)
{
    int n = s->length-1;
    while (!IsEmpty(s)) {
        GetTop(s,&a[n--]);

    }
}

void clearstack(SeqStack *s)
{
    s->top = s->base;
    s->length = 0;
}

/*
void PwdSet(SeqStack *s)
{
    int i=0,k,j=0;
    DataType ch, *a;
    k =strlen(PASSWORD);
    printf("input the password:");
    for(;;)
    {
        if(i>=3)
        {
            i++;
            break;

        }
        else if(i>0 && i<3)
        {
            for(j=1;j<=s->length;j++)
                printf(" ");
            clearstack(s);
        }
        for(;;)
        {
            ch = getchar();
            if(ch != 13)
            {
                if(ch == 8)
                {
                    Pop(s);
                    gotoxy(4+j,2);
                    printf(" ");
                    gotoxy(4+j,2);
                }
                else
                {
                    printf("*");
                    Push(s,ch);
                }
                j = s->length;
            }
            else
            {
                printf("\n");
                break;
            }
        }
         i++;
         if(k!=j)
             continue;
         else
         {
             a= (DataType*)malloc(s->length*sizeof(DataType));
             change(s,a);

             for(j=1;j<=s->length;)
             {
                 if(*a(a+j-1) == PASSWORD[j-1])
                     j++;
                 else
                 {
                     j = s->length+2;
                     printf("\n password wrong!\n");
                     break;
                 }
             }
             if(j == s->length+2)
                 continue;
             else
                 break;
         }
    }
    if(i==4)
        printf("\n hava no changce,it will quit\n");
    else
        printf("\n password right \n");
    free(a);

}

*/
void TestExample_091
{
    //TODO: need to modify
    /*
    SeqStack *s;
    printf("plesase input\n");
    Initial(s);
    PwdSet(s);
    */
}




