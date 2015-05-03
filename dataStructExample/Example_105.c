//Example_105.c -- Huffman encoding

#ifndef EXAMPLE_105_H
#define EXAMPLE_105_H

#endif // EXAMPLE_105_H

#include <stdio.h>
#include <malloc.h>
#include <string.h>

#define MAXSIZE 50

typedef struct
{
    char data;
    int weight;
    int parent;
    int left;
    int right;
    int flag;
}huffnode;

typedef struct
{
    char code[MAXSIZE];
    int start;
}huffcode;

huffnode htree[2*MAXSIZE];
huffcode hcode[MAXSIZE];

int select(int i)
{
    int k = 32767;
    int j,q;
    for(j=0;j<=i;j++)
    {
        if(htree[j].weight < k && htree[j].flag == -1)
        {
            k = htree[j].weight;
            q = j;
        }
    }
    htree[q].flag = 1;
    return q;
}

void CreateHuffTree(int n)
{
    int i,l,r;
    for(i=0;i<2*n;i++)
    {
        htree[i].parent = htree[i].left = htree[i].right = htree[i].flag = -1;
    }

    for(i=n;i<2*n;i++)
    {
        l = select(i-1);
        r = select(i-1);
        htree[l].parent = i;
        htree[r].parent = i;
        htree[i].weight = htree[l].weight + htree[r].weight;
        htree[i].left = 1;
        htree[i].right = r;

    }
}

void CreateHuffCode(int n)
{
    int i,f,c;
    huffcode d;
    for(i=0;i<n;i++)
    {
        d.start = n+1;
        c = i;
        f= htree[i].parent;
        while (f != -1)
        {
            if(htree[f].left == c)
            {
                d.code[--d.start] = '0';
            }
            else
            {
                d.code[--d.start] = '1';
            }
            c =f;
            f = htree[f].parent;
        }
        hcode[i] = d;
    }
}

void display_huffcode(int n)
{
    int i,k;
    printf("huffman is :\n");
    for(i=0;i<n;i++)
    {
        printf("%c:",htree[i].data);
        for(k = hcode[i].start;k<=n;k++)
        {
            printf("%c",hcode[i].code[k]);
        }
        printf("\n");
    }
}

void TestExample_105()
{
    int n=6;
    htree[0].data = 'a';
    htree[0].weight = 18;
    htree[1].data = 'b';
    htree[1].weight = 20;
    htree[2].data = 'c';
    htree[2].weight = 4;
    htree[3].data = 'd';
    htree[3].weight = 13;
    htree[4].data = 'e';
    htree[4].weight = 16;
    htree[5].data = 'f';
    htree[5].weight = 38;

    CreateHuffTree(n);
    CreateHuffCode(n);
    display_huffcode(n);
}
