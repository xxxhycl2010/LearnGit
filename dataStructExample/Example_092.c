//Example_092.cpp -- use stack to edit row process

#ifndef EXAMPLE_092_H
#define EXAMPLE_092_H

#endif // EXAMPLE_092_H

#include <stdio.h>
#include <malloc.h>
#include <iostream>

#define STACK_SIZE 100
typedef char DataType;


typedef struct
{
    DataType *base;
    DataType *top;
    int stacksize;
}SeqStack;

void Initial(SeqStack *s)
{
    s->base = (DataType*)malloc(STACK_SIZE*sizeof(DataType));
    if(!s->base)
        exit(-1);
    s->top = s->base;
    s->stacksize = STACK_SIZE;
}

int IsEmpty(SeqStack *s)
{
    return s->top == s->base;

}

int IsFull(SeqStack *s)
{
    return s->top - s->base == STACK_SIZE -1;
}

void Push(SeqStack *s,DataType x)
{
    if(IsFull(s))
    {
        printf("overflow\n");
        exit(1);
    }
    else
        *s->top++ = x;
}

void Pop(SeqStack *s)
{
    if(!IsEmpty(s))
    {
        printf("stack is empty\n");
        exit(1);
    }
    else
        --s->top;
}

DataType Top(SeqStack *s)
{
    if(IsEmpty(s))
    {
        printf("stack is empty\n");
        exit(1);
    }
    return *(s->top-1);
}

void clearstack(SeqStack *s)
{
    s->top = s->base;
}

void LineEdit(SeqStack *s)
{
    int i=0,a[100],n;
    char ch;
    ch = getchar();
    while (ch != '\n') {
        i++;
        switch (ch) {

        case '#':
            Pop(s);
            i-=2;
            break;
        case '@':
            clearstack(s);
            i=0;
            break;
        default:
            Push(s,ch);
            break;
        }
        ch = getchar();
    }
    for(n=1;n<=i;n++)
    {
        a[n] = Top(s);
        Pop(s);
    }
    for(n=i;n>=1;n--)
    {
        printf("%c",a[n]);
    }

}

void TestExample_092(SeqStack *s)
{

    printf("please intput:");
    Initial(s);
    LineEdit(s);

}


