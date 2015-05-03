//Exmaple_096.c  -- A ring buffer, this is circlue queue

#ifndef EXAMPLE_096_H
#define EXAMPLE_096_H

#endif // EXAMPLE_096_H

#include <stdio.h>
#include <malloc.h>
#include <conio.h>
#include<dos.h>
#include <stdlib.h>

#define MAXSIZE 30
#define TRUE 1
#define FALSE 0
char queue[MAXSIZE];
int front,rear;

void init()
{
    front = rear = -1;
}

int enqueue(char x)
{
    if(front == -1 && (rear+1) == MAXSIZE)
    {
        printf("overflow\n");
        return 0;
    }
    else if((rear+1)%MAXSIZE == front)
    {
        printf("overflow\n");
        return 0;
    }
    else
    {
        rear = (rear+1)%MAXSIZE;
        queue[rear] = x;
        return 1;
    }
}

void dequeue()
{
    if(front == rear)
    {
        printf("null \n");
    }
    else
        front = (front+1)%MAXSIZE;
}

char gethead()
{
    if(front == rear)
    {
        printf("null\n");
        return ' ';
    }
    else
        return queue[(front+1)%MAXSIZE];
}

//TODO: need to modify
char bdos(int a,int b,int c)
{
    return ' ';
}

void TestExmaple_096()
{
    char ch1,ch2;
    init();
    for(;;)
    {
        for(;;)
        {
            printf("A");
            if(kbhit())
            {
                ch1 = bdos(7,0,0);
                if(!enqueue(ch1))
                {
                    printf("is full \n");
                    break;
                }

            }
            if(ch1 == ';' || ch1 == ',')
                break;
        }
        while(front != rear)
        {
            ch2 = gethead();
            dequeue();
            putchar(ch2);
        }
        if(ch1 == ';')
            break;
        else
            ch1 = ' ';
    }
}

