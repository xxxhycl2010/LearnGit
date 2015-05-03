//Example_106.c -- Figure of adjacency table storage

#ifndef EXAMPLE_106_H
#define EXAMPLE_106_H

#endif // EXAMPLE_106_H

#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>

struct node
{
    int vertex;
    struct node *next;
};
typedef struct node *graph;
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

void TestExample_106()
{
    graph p;
    int node[100],i,sn,vn;
    printf("please input the number of sides:\n");
    scanf("%d",&sn);
    printf("please input the number of vertexes:\n");
    scanf("%d",&vn);
    printf("please input hte vertexes which connected by the sides:\n");
    for(i=0;i<4*sn;i++)
    {
        scanf("%d",&node[i]);
    }
    for(i=1;i<=vn;i++)
    {
        vertex_node[i].vertex = i;
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
}
