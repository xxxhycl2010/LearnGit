#ifndef STACK_H
#define STACK_H

#endif // STACK_H

#include <iostream>
#include <malloc.h>
using namespace std;

typedef struct Node
{
    int num;
    struct Node *next;

}Node ,*pNode;

typedef Node Elemtype;

#define STACK_INIT_SIZE 100
#define STACKINCREMENT 10

typedef struct Stack
{
    pNode base;
    pNode top;
    int stacksize;
}Stack, *pStack;

void Init(pStack ps)
{
    ps->top = (pNode)malloc(sizeof(Node));
    if(ps->top == NULL)
    {
        cout << "malloc memory is fail\n";
        exit(-1);
    }
    else
    {
        ps->base = ps->top;
        ps->top->next = NULL;
        ps->stacksize = STACK_INIT_SIZE;
    }
}

bool IsFull(pStack ps)
{
    if(ps->top - ps->base == ps->stacksize-1)
        return true;
    else
        return false;
}

void Push(pStack ps,int value)
{
    if(IsFull(ps))
    {
        cout << "stack is full\n";
        exit(-1);
    }

    pNode pnew = (pNode)malloc(sizeof(Node));
    pnew->num = value;
    pnew->next = ps->top;
    ps->top = pnew;
}

bool IsEmpty(pStack ps)
{
    if(ps->base == ps->top)
    {
        return true;
    }
    else
        return false;
}

bool Pop(pStack ps,int *val)
{
    if(IsEmpty(ps))
    {
         return false;
    }
    pNode r = ps->top;
    *val = r->num;
    ps->top = r->next;
    free(r);
    r = NULL;
    return true;
}

void Clear(pStack ps)
{
    if(IsEmpty(ps))
        return;
    else
    {
        pNode p = ps->top;
        pNode q = NULL;
        while (p != ps->base)
        {
            q = p->next;
            free(p);
            p = q;

        }
        ps->top = ps->base;
    }
}

bool DestoryStack(pStack ps)
{
    if(!ps->base)
        return false;

    free(ps->base);
    ps->top = ps->base = NULL;
    ps->stacksize = 0;
    return true;
}

bool GetTop(pStack ps,Node &node)
{
    if(ps->top == ps->base)
        return false;
    node = *(ps->top-1);
    return true;
}

void Traverse(pStack ps)
{
    pNode p = ps->top;

    while(p != ps->base)
    {
        cout << "data=" << p->num << endl;
        p = p->next;
    }
}

void TestStack()
{
    Stack s;
    cout << "create stack is :\n";
    Init(&s);
    for(int i=0;i<5;i++)
    {
        Push(&s,i);
    }

    cout << "traverse stack is :\n";
    Traverse(&s);

    cout << "the top elem is :";
    int value;
    if(Pop(&s,&value))
    {
        cout <<"delete is successful ,the value=" << value <<endl;

    }
    else
    {
        cout << "delete is fail\n";
    }
    cout << "use the pos after:\n";
    Traverse(&s);

    cout << "get top elem is:\n";

    Node _top;
    if(GetTop(&s,_top))
    {
        cout << "the value is "<< _top.num << endl;
    }
    else
        cout << "get top elem is fail\n";

//    cout << "use clear stack is:\n";
//    Clear(&s);
//    Traverse(&s);


}
