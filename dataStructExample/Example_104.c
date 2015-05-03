//Example_104.c  -- binary sort tree

// you can input the flllow string to test
//5 4 2 1 0 0 3 0 0 0 7 6 0 0 9 8 0 0 10 0 0
#ifndef EXAMPLE_104_H
#define EXAMPLE_104_H

#endif // EXAMPLE_104_H

#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

typedef struct node
{
    struct node *lchild;
    int data;
    struct node *rchild;
}bitnode,*bitree;

bitree CreateTree()
{
    int a;
    bitree bt;
    scanf("%d",&a);
    if(a == 0)
        return NULL;
    else
    {
        bt = (bitree)malloc(sizeof(bitnode));
        bt->data = a;
        bt->rchild = CreateTree();
        bt->lchild = CreateTree();
    }
    return bt;

}

void Search(bitree p,int key)
{
    int n=0;
    while(p!=NULL)
    {
        n++;
        if(p->data == key)
        {
            printf("successful ,search %d times",n);
            break;
        }
        else if(p->data > key)
        {
            p = p->lchild;
        }
        else
            p = p->rchild;
    }
    if(p == NULL)
    {
        printf("not find");
    }
}


void TestExample_104()
{
    bitree root;
    int key;
    root = CreateTree();
    printf("please input the number which do you want to search:");
    scanf("%d",&key);
    Search(root,key);
}



