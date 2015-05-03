//Example_101.c -- Binary tree recursive created

#ifndef EXAMPLE_101_H
#define EXAMPLE_101_H

#endif // EXAMPLE_101_H

#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>

typedef struct node
{
    struct node *lchild;
    char data;
    struct node *rchild;
}bitnode, *bitree;

bitree CreateTree()
{
    char a;
    bitree tree;
    scanf("%c",&a);
    if(a== '#')
        return NULL;
    else
    {
        tree = (bitree)malloc(sizeof(bitnode));
        tree->data = a;
        tree->lchild = CreateTree();
        tree->rchild = CreateTree();
    }
    return tree;


}


void print(bitree bt)
{
    if(bt!= NULL)
    {
        print(bt->lchild);
        printf("%c",bt->data);
        print(bt->rchild);
    }
}

int btreeDepth(bitree bt)
{
    int ldepth,rdepth;
    if(bt == NULL)
    {
        return 0;
    }
    else
    {
        ldepth = btreeDepth(bt->lchild);
        rdepth = btreeDepth(bt->rchild);
        return (ldepth>rdepth?ldepth+1:rdepth+1);
    }
}

int ncount(bitree bt)
{
    if(bt == NULL)
    {
        return 0;
    }
    else
        return (ncount(bt->lchild) + ncount(bt->rchild)+1);
}



int lcount(bitree bt)
{
    if(bt == NULL)
    {
        return 0;
    }
    else if(bt->lchild == NULL && bt->rchild == NULL)
    {
        return 1;
    }
    else
        return (lcount(bt->lchild)+lcount(bt->rchild));
}

void TestExample_101()
{
    bitree root;
    root = CreateTree();
    printf("contents of binary tree:\n");
    print(root);
    printf("\n depth of the binary tree:%d\n",btreeDepth(root));
    printf("\n the number of the nodes:%d\n",ncount(root));
    printf("\n the number of the leaf nodes:%d\n",lcount(root));
}
