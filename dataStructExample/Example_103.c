//Example_103.c -- Clues to the creation of a binary tree
//you can input the follow string to test
//_+a##*b##c##/d##e##

#ifndef EXAMPLE_103_H
#define EXAMPLE_103_H

#endif // EXAMPLE_103_H

#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    char data;
    struct node *lchild,*rchild;
    int ltag,rtag;
}bithrnode,*bithrtree;

bithrtree CreateTree()
{
    char a;
    bithrtree bt;
    scanf("%c",&a);
    if(a == '#')
        return NULL;
    else
    {
        bt = (bithrtree)malloc(sizeof(bithrnode));
        bt->data = a;
        bt->ltag = 0;
        bt->rtag = 0;
        bt->lchild = CreateTree();
        bt->rchild = CreateTree();
    }
    return bt;

}

void inthread(bithrtree p,bithrtree pre)
{
    if(p)
    {
        inthread(p->lchild,pre);
        if(p->lchild == NULL)
        {
            p->ltag = 1;
            p->lchild = pre;
        }
        if(pre->rchild == NULL)
        {
            pre->rchild = p;
            pre->rtag = 1;
        }
        pre = p;
        inthread(p->rchild,pre);
    }
}

bithrtree inorder_thread(bithrtree bt)
{
    bithrtree thrt;
    bithrtree pre,p;
    thrt = (bithrtree)malloc(sizeof(bithrnode));
    thrt->ltag = 0;
    thrt->rtag = 1;
    thrt->rchild = thrt;
    if(bt == NULL)
    {
        thrt->lchild = thrt;
    }
    else
    {
        p = thrt->lchild = bt;
        thrt->ltag = 0;
        pre = thrt;
        inthread(p,pre);
        pre->rchild = thrt;
        pre->rtag= 1;
        thrt->rchild = pre;
        thrt->rtag = 1;
    }
    return thrt;
}

void InOrderTraverse(bithrtree bt)
{
    if(bt!=NULL)
    {
        if(bt->ltag==0)
        {
            InOrderTraverse(bt->lchild);
        }
        printf("%c",bt->data);
        if(bt->rtag==0)
            InOrderTraverse(bt->rchild);
    }
}

void TestExample_103()
{
    bithrtree root;
    root = CreateTree();
    printf("inorder treaverse is:\n");
    InOrderTraverse(root);
}
