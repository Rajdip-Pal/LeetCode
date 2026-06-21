/*  
    Implementing Stack variable to create stack in C. 
    By myself.
*/

// C header Files .
#include <stdio.h>
#include <stdlib.h>

// Defining a data type to create and store basic information of a stack;
typedef struct STACK{
    int top;
    unsigned short int capacity;
    int *Data;
} stack ;

// Defining a Function to create stack an initializing memory to it.
stack *createStack(const unsigned short int stackSize){
    stack *tempStack = (stack *)malloc(sizeof(stack));
    tempStack -> top = -1;
    tempStack -> capacity = stackSize;
    tempStack -> Data = (int *)calloc(sizeof(int),tempStack -> capacity);
    return tempStack;
}

//  Function to check if the stack is empty;
short int isStackEmpty(const stack* tempStack){
    if (tempStack -> top == -1)
        return 1;
    return 0;
}

//  Function to check if the stack is full;
short int isStackFull(const stack* tempStack){
    if (tempStack -> top ==  tempStack -> capacity - 1)
        return 1;
    return 0;
}

// Push Function;
void push(stack* tempStack, const int pushElement){
    if (!(isStackFull(tempStack))){
        tempStack -> top++;
        tempStack -> Data[tempStack -> top] = pushElement;
        return ;
    }
    printf("\nStack Overflow\n");
}

// Pop Function;
int pop(stack* tempStack){
    if (!(isStackEmpty(tempStack))){
        tempStack -> top-- ;
        return tempStack -> Data[tempStack -> top + 1];
    }
    printf("\nStack Underflow\n");
    return -1;
}

// Peek element finding Function;
int top(const stack *tempStack){
    if (isStackEmpty(tempStack)){
        // printf("\nStack is Empty.\n");
        return -1;
    }
    return tempStack -> Data[tempStack -> top];
}

// Print Element Of Stack;
void printStack(const stack *tempStack){
    if (isStackEmpty(tempStack)){
        printf("\nStack is Empty. Nothing to Print.\n");
        return ;
    }

    putchar('\n');
    for (int i = 0; i <= tempStack -> top; i++){
        printf("%d ",*(tempStack -> Data + i));
    }
    // putchar('\n');
    // printf("Finished\n");
}