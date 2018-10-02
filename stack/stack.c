/*
*   the definition of stack
*/

/*include the public header files*/
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

/*include the header file : __STACK_H__*/
#include "stack.h"

/*actual stack data structure*/
void **array;

/*the current capacity of the stack*/
int maxCapacity = 10;

/*counts the elements of the stack*/
int counter = 0;

/*points the top elements of the stack*/
int offset = -1;

/*initializes the stack with a capacity of 10 elements*/
void initStack()
{
    //malloc memory for the pointer array
    array = malloc(sizeof(void *) * maxCapacity);
    //tests whether pointer is assigned to memory
    assert(array);
    printf("initializes the stack.\n");
}

void grow()
{
    maxCapacity += 10;
    void **tmp = malloc(sizeof(void *) * maxCapacity);

    for (int i = 0; i < (maxCapacity-10); i++)
    {
        *(tmp + i) = *(array + i);
    }

    array = tmp;
}

/*pushs the argument onto the stack*/
void push(void *object)
{
    //tests whether pointer isn't null
    assert(object);

    if (counter < maxCapacity)
    {
        //increases the element-pointer
        offset++;
        //pushs the object onto stack
        *(array + offset) = object;
        //increases the inner counter
        counter++;
    }
    else
    {
        //to grow stack, maxCapacity+=10
        grow();
        //recursive call
        push(object);
    }
}

/*pops the top element of the stack*/
void *pop()
{
    //gets the top element of the stack
    void *topElement = top();
    assert(topElement);
    //once the stack is Empty, offset is -1 and counter = 0
    assert(!isEmpty());
    //pointer's offset--
    offset--;
    //counter--
    counter--;
    //for printing the top and poped element of the stack
    return topElement;
}

/*gets the elements' number of the stack*/
int size()
{
    return counter;
}

/*returns 1 if stack is empty otherwise 0*/
int isEmpty()
{
    return (counter == 0);
}

/*returns the top element of the stack without removing it*/
void *top()
{
    return *(array+offset);
}

/*destroy the stack*/
void destroyStack()
{
    assert(array);
    free(array);
    printf("destroy the stack.\n");
}

