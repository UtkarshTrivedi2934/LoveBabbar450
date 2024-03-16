//{ Driver Code Starts
//Initial Template for C


// C program for array implementation of stack
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
 
// A structure to represent a stack
struct Stack {
    int top;
    unsigned capacity;
    int* array;
};
struct Stack* createStack(unsigned capacity)
{
    struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));
    stack->capacity = capacity;
    stack->top = -1;
    stack->array = (int*)malloc(stack->capacity * sizeof(int));
    return stack;
}
// Stack is full when top is equal to the last index
int isFull(struct Stack* stack)
{
    return stack->top == stack->capacity - 1;
}
 
// Stack is empty when top is equal to -1
int isEmpty(struct Stack* stack)
{
    return stack->top == -1;
}
// Function to return the top from stack without removing it
int peek(struct Stack* stack)
{
    if (isEmpty(stack))
        return INT_MIN;
    return stack->array[stack->top];
}


int main()
{

    int T;
    scanf("%d",&T);
    while(T--)
    {

        int Q;
        scanf("%d",&Q);
        struct Stack* stack = createStack(1000);
        while(Q--){
        int QueryType=0;
        scanf("%d", &QueryType);
        if(QueryType==1)
        {
            int a;
            scanf("%d",&a);
            push(stack, a);
        }else if(QueryType==2){
            printf("%d ",pop(stack));
        }
        }
        printf("\n");
    }
}

// } Driver Code Ends


//User function Template for C

/*
// A structure to represent a stack
struct Stack {
    int top;
    unsigned capacity;
    int* array;
};
struct Stack* createStack(unsigned capacity)
{
    struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));
    stack->capacity = capacity;
    stack->top = -1;
    stack->array = (int*)malloc(stack->capacity * sizeof(int));
    return stack;
}
*/

//Function to push an integer into the stack.
void push(struct Stack* stack, int item)
{
    //code here
    stack->array[++stack->top] = item;
}


//Function to remove an item from top of the stack.
int pop(struct Stack* stack)
{
    //code here
    if(stack->top == -1)
    return -1;
    return stack->array[stack->top--];
}