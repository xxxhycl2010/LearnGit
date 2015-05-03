//Example_107.c -- Graph depth first search

#ifndef EXAMPLE_107_H
#define EXAMPLE_107_H

#endif // EXAMPLE_107_H

#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

typedef struct node
{
    int vertex;
    int flag;
    struct node *next;
}*graph;
struct node vertex_node[10];

void CreateGraph(int *node,int n)
{
    graph newnode,p;
    int start,end,i;
    for(i=0;i<n;i++)
    {
        start = node[i*2];
        end = node[i*2+1];
        newnode = (graph)malloc(sizeof(struct node));
        newnode->vertex = end;
        newnode->next = NULL;
        p = &(vertex_node[start]);
        while(p->next != NULL)
        {
            p = p->next;
        }
        p->next = newnode;
    }
}

void DepthFirstSearch(int k)
{
    graph p;
    vertex_node[k].flag = 1;
    printf("vertex[%d]",k);
    p = vertex_node[k].next;
    while(p != NULL)
    {
        if(vertex_node[p->vertex].flag == 0)
        {
            DepthFirstSearch(p->vertex);
        }
        p = p->next;
    }
}

void TestExample_107()
{
    graph p;
    int node[100],i,sn,vn;
    printf("please input the number of sides:\n");
    scanf("%d",&sn);
    printf("please input the number of vertex:\n");
    scanf("%d",&vn);
    printf("pleaes input the verteses which connectd by sides:\n");
    for(i=0;i<4*sn;i++)
    {
        scanf("%d",&node[i]);
    }
    for(i=1;i<=vn;i++)
    {
        vertex_node[i].vertex = i;
        vertex_node[i].flag = 0;
        vertex_node[i].next = NULL;
    }
    CreateGraph(node,2*sn);
    printf("the result is :\n");
    for(i=1;i<=vn;i++)
    {
        printf("vertex:%d",vertex_node[i].vertex);
        p = vertex_node[i].next;
        while (p!=NULL)
        {
            printf("->%3d",p->vertex);
            p = p->next;

        }
        printf("\n");
    }

    printf("the result of depth-first search is :\n");
    DepthFirstSearch(1);
    printf("\n");

}


