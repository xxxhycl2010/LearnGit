//Example_093.c -- this is test include operate matching

#ifndef EXAMPLE_093_H
#define EXAMPLE_093_H

#endif // EXAMPLE_093_H

#include <stdio.h>
#include <malloc.h>

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
    return s->top - s->base == STACK_SIZE-1;
}

void Push(SeqStack *s, DataType x)
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
    if(IsEmpty(s))
    {
        printf("stack is empty\n");
        exit(1);
    }
    else
        --s->top;
}

DataType GetTop(SeqStack *s)
{
    if(IsEmpty(s))
    {
        printf("empty\n");
        exit(1);
    }
    return *(s->top-1);
}

int match(SeqStack *s,char *str)
{
    char x;
    int i,flag =1;
    for(i=0;str[i]!='\0';i++)
    {
        switch (str[i]) {
        case '(':
            Push(s,'(');
            break;
        case '[':
            Push(s,'[');
            break;
        case '{':
           Push(s,'{');
           break;
        case ')':
            x= GetTop(s);
            Pop(s);
            if(x !='(')
                flag = 0;

            break;
        case ']':
            x = GetTop(s);
            Pop(s);
            if(x!='[')
                flag = 0;
            break;
        case '}':
            x = GetTop(s);
            Pop(s);
            if(x!='{')
                flag = 0;

            break;

        default:
            break;
        }
        if(!flag)
            break;
    }

    if(IsEmpty(s) == 1 && flag)
        return 1;
    else
        return 0;

}

void TestExample_093(SeqStack *s)
{
//    SeqStack *s;
    char str[100];
    Initial(s);
    gets(str);
    if(match(s,str))
        printf("matching \n");
    else
        printf("not matching\n");
}
