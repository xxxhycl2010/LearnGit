//Example_099.c -- Generalized table storage


#ifndef EXAMPLE_099_H
#define EXAMPLE_099_H

#endif // EXAMPLE_099_H

#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

typedef char ElemType;

typedef struct lnode
{
    int tag;
    union
    {
        ElemType data;
        struct lnode *sublist;
    }val;
    struct lnode *next;
}GLNode;

void createGList(struct lnode **gl)
{
    char ch;
    ch = getchar();
    if(ch == '#')
    {
        *gl = NULL;
    }
    else if(ch == '(')
    {
        *gl = (struct lnode *)malloc(sizeof(struct lnode));
        (*gl)->tag = 1;
        createGList(&((*gl)->val.sublist));
    }
    else
    {
        *gl = (struct lnode *)malloc(sizeof(struct lnode));
        (*gl)->tag = 0;
        (*gl)->val.data = ch;
    }

    ch = getchar();
    if(*gl == NULL)
    {
        if(ch == '#')
        {}
        else if(ch == ',')
        {
            createGList(&((*gl)->next));
        }
        else
            (*gl)->next = NULL;
    }

    return;
}

void printGList(struct lnode *gl)
{
    if(gl->tag == 1)
    {
        printf("(");
        if(gl->val.sublist == NULL)
        {
            printf("#");

        }
        else
        {
            printGList(gl->val.sublist);
        }
        printf(")");
    }
    else
    {
        printf("%c",gl->val.data);
    }

    if(gl->next != NULL)
    {
        printf(",");
        printGList(gl->next);
    }
    return ;
}

int GLLenght(GLNode *gl)
{
    int n=0;
    gl = gl->val.sublist;
    while (gl != NULL)
    {
        n++;
        gl = gl->next;

    }
    return n;
}

int GLDepth(GLNode *gl)
{
    int max =0,dep;
    if(gl->tag == 0)
    {
        return 0;
    }
    gl = gl->val.sublist;
    if(gl == NULL)
    {
        return 1;
    }
    while(gl != NULL)
    {
        if(gl->tag == 1)
        {
            dep = GLDepth(gl);
            if(dep > max)
            {
                max = dep;
            }
        }
        gl = gl->next;
    }
    return (max+1);
}

void TestExample_099()
{
    int len =0;
    int dep = 0;
    struct lnode *h;
    createGList(&h);
    len = GLLenght(h);
    dep = GLDepth(h);
    printf("\n");
    printf("the length is:\n");
    printf("%d",len);
    printf("\n");
    printf("the depth is:\n");
    printf("%d",dep);
    printf("\n");
    if(h!= NULL)
    {
        printf("gllist is:\n");
        printGList(h);
        printf("\n");
    }
    else
    {
        printf("gllist is null\n");
    }
}
