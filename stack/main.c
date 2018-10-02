#include <stdio.h>
#include <stdlib.h>

#include "stack.h"

int main()
{
    int MAX = 111;
    int arrayT[MAX];
    int *pInt = NULL;

    initStack();
    for(int i = 0; i < MAX; i++)
    {
        arrayT[i] = i;
        push((arrayT + i));
        printf("%x:%d\n", (arrayT+i), arrayT[i]);
    }
    
    printf("push OK................start pop.\n");
    
    for(int j = 0; j < MAX; j++)
    {
        pInt = pop();
        printf("%x:%d\n", pInt, *pInt);
    }
    destroyStack();

    return EXIT_SUCCESS;
}
