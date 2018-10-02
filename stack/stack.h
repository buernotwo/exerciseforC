/*
    author: Tisawudii->buernotwo
    description: The stack is generic and self-growing
    date: 2018-10-02
*/
#ifndef __STACK_H__
#define __STACK_H__

/*initializes the stack with a capacity of 10 elements*/
void initStack();

/*pushs the argument onto the stack*/
void push(void *object);

/*pops the top element of the stack*/
void *pop();

/*gets the elements' number of the stack*/
int size();

/*returns 1 if stack is empty otherwise 0*/
int isEmpty();

/*returns the top element of the stack without removing it*/
void *top();

/*destroy the stack*/
void destroyStack();

#endif