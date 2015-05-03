//Example_102.c -- binary tree traverse

// you can input the follow string to test
// -+x##*y##z##/k##m##

#ifndef EXAMPLE_102_H
#define EXAMPLE_102_H

#endif // EXAMPLE_102_H

#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>

typedef struct node
{
    struct node *lchild;
    char data;
    struct node *rchild;
}bitnode,*bitree;

bitree CreateTree()
{
    char a;
    bitree bt;
    scanf("%c",&a);
    if(a == '#')
        return NULL;
    else
    {
        bt = (bitree)malloc(sizeof(bitnode));
        bt->data = a;
        bt->lchild = CreateTree();
        bt->rchild = CreateTree();
    }
    return bt;
}

void preOrderTraverse(bitree bt)
{
    if(bt!= NULL)
    {
        printf("%c",bt->data);
        preOrderTraverse(bt->lchild);
        preOrderTraverse(bt->rchild);
    }
}

void InOrderTraverse(bitree bt)
{
    if(bt != NULL)
    {
        InOrderTraverse(bt->lchild);
         printf("%c",bt->data);
        InOrderTraverse(bt->rchild);

    }
}

void postOrderTraverse(bitree bt)
{
    if(bt != NULL)
    {

        postOrderTraverse(bt->lchild);
        postOrderTraverse(bt->rchild);
        printf("%c",bt->data);
    }
}

void TestExample_102()
{
    bitree root;
    root = CreateTree();
    printf("preOrderTraverse is:\n");
    preOrderTraverse(root);
    printf("\n");
    printf("inOrderTraverse is:\n");
    InOrderTraverse(root);
    printf("\n");
    printf("postOrderTraverse is:\n");
    postOrderTraverse(root);
    printf("\n");
}
