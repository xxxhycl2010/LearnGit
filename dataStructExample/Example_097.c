//Example_097.c -- The string pattern matching

#ifndef EXAMPLE_097_H
#define EXAMPLE_097_H

#endif // EXAMPLE_097_H

#include <string.h>
#include <stdio.h>
#include <malloc.h>

#define MAXSIZE 100

typedef struct
{
    char string[MAXSIZE];
    int len;
}str;

int findstr(str s,str t)
{
    int i=1,j=0,k=0,pos;
    while(i<s.len && j<t.len)
    {
        if(s.string[k] == t.string[j])
        {
            k++;
            j++;
        }
        else
        {
            i++;
            k = i;
            j=0;
        }
    }

    if(j==t.len)
        pos = k-j+1;
    else
        pos = -1;
    return pos;
}

void TestExample_097()
{
    str s,t;
    int p;
    printf("qing shu ru zhu cuan:\n");
    scanf("%s",s.string);

    printf("qing shu ru mo shi cuan:\n");
    scanf("%s",t.string);
      s.len = strlen(s.string);
    t.len = strlen(t.string);
    p  = findstr(s,t);
    if(p == -1)
        printf("no matching\n");
    else
        printf("matching the pos is :%d ",p);
}
