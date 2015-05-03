//Example_109.c --- Prim algorithm for minimum spanning tree

#ifndef EXAMPLE_109_H
#define EXAMPLE_109_H

#endif // EXAMPLE_109_H

#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

#define MAXVEX 30
#define MAXCOST 1000

void prim(int c[MAXVEX][MAXVEX],int n)
{
    int i,j,k,min,lowcost[MAXVEX],closest[MAXVEX];
    for(i=2;i<=n;i++)
    {
        lowcost[i] = c[1][i];
        closest[i] = 1;
    }
    closest[1] = 0;
    for(i=2;i<=n;i++)
    {
        min = MAXCOST;
        j= 1;
        k = i;
        while (j<=n) {
            if(lowcost[j]<min && closest[j]!=0)
            {
                min = lowcost[j];
                k = j;
            }
            j++;

        }
        printf("(%d,%d) ",closest[k],k);
        closest[k] = 0;
        for(j=2;j<=n;j++)
        {
            if(closest[j]!= 0 && c[k][j] < lowcost[j])
            {
                lowcost[j] = c[k][j];
                closest[j] = k;
            }
        }
    }
}

void TestExample_109()
{
    int n=7,i,j,mx[MAXVEX][MAXVEX];
    for(i=0;i<=n;i++)
    {
        for(j=0;j<=n;j++)
        {
            mx[i][j] = MAXCOST;
        }
    }

    mx[1][2]= 50;
    mx[1][3]= 60;
    mx[2][4]= 65;
    mx[2][5]= 40;
    mx[3][4]= 52;
    mx[3][7]= 45;
    mx[4][5]= 50;
    mx[5][6]= 70;
    mx[4][6]= 30;
    mx[4][7]= 42;

    printf("minimal spanning tree is:\n");
    prim(mx,n);


}
