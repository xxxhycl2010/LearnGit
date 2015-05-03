//Example_108.c -- The figure of the breadth-first search

#ifndef EXAMPLE_108_H
#define EXAMPLE_108_H

#endif // EXAMPLE_108_H

#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>

typedef struct node
{
    int vertex;
    struct node *next;
}*graph;
struct node vertex_node[10];

#define MAXQUEUE 100
int queue[MAXQUEUE];
int front = -1;
int rear = -1;
int visited[10];


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

int enqueue(int value)
{
    if(rear>=MAXQUEUE)
        return -1;
    rear++;
    queue[rear] = value;
}

int dequeue()
{
    if(front == rear)
        return -1;
    front++;
    return queue[front];
}

void BreadthFirstSearch(int k)
{
    graph p;
    enqueue(k);
    visited[k] = 1;
    printf("vertex[%d] ",k);
    while(front != rear)
    {
        k = dequeue();
        p = vertex_node[k].next;
        while (p!=NULL)
        {
            if(visited[p->vertex] == 0)
            {
                enqueue(p->vertex);
                visited[p->vertex] = 1;
                printf("vertex[%d] ",p->vertex);
            }
            p = p->next;

        }
    }
}

void TestExample_108()
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

    printf("the result of breadth-first search is :\n");
    BreadthFirstSearch(1);
    printf("\n");
}
