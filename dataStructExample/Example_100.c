//Example_100.c --- Generalized table copy

#ifndef EXAMPLE_100_H
#define EXAMPLE_100_H

#endif // EXAMPLE_100_H

#include <stdio.h>
#include <stdlib.h>

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


GLNode *GLCopy(GLNode *gl)
{
    GLNode *q;
    if(gl == NULL)
    {
        return NULL;
    }
    q = (GLNode*)malloc(sizeof(GLNode));
    q->tag = gl->tag;
    if(gl->tag == 1)
    {
        q->val.sublist = GLCopy(gl->val.sublist);
    }
    else
        q->val.data = gl->val.data;
    q->next = GLCopy(gl->next);
    return q;
}

GLNode *head(GLNode *gl)
{
    GLNode *p = gl->val.sublist;
    GLNode *q,*t;
    if(gl == NULL)
    {
        printf("null\n");
        return NULL;
    }
    if(gl->tag == 0)
    {
        printf("atom is not head:\n");
        return NULL;
    }
    if(p->tag == 0)
    {
        q = (GLNode*)malloc(sizeof(GLNode));
        q->tag = 0;
        q->val.data = p->val.data;
        t->next = NULL;
        q = GLCopy(t);
        free(t);
    }
    return q;
}

GLNode *tail(GLNode *gl)
{
    GLNode *p = gl->val.sublist;
    GLNode *q,*t;
    if(gl == NULL)
    {
        printf("null\n");
        return NULL;
    }
    if(gl->tag ==0)
    {
        printf("atom is not tail\n");
        return NULL;
    }
    p = p->next;
    t = (GLNode*)malloc(sizeof(GLNode));
    t->tag = 1;
    t->val.sublist = p;
    t->next = NULL;
    q = GLCopy(t);
    free(t);
    return q;
}

void TestExample_100()
{
    struct lnode *g,*v;
    struct lnode *h;
    createGList(&h);
    printf("\n");
    v = head(h);
    if(v != NULL)
    {
        printf("head is :");
        printGList(v);
        printf("\n");
    }
    g = tail(h);
    if(g!= NULL)
    {
        printf("tail is :");
        printGList(g);
        printf("\n");
    }
    if(h!= NULL)
    {
        printf("glist is:");
        printGList(h);
        printf("\n");
    }
    else
        printf("glist is null\n");
}
