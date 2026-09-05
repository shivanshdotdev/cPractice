#include <stdio.h>
#include <stdbool.h>

#define SIZE 100

typedef struct {
    int array[SIZE];
    int top;
} Stack;

void initialize(Stack *stack){
    stack -> top = 0;
}

bool isEmpty(Stack *stack){
    return (stack -> top == 0);
}

bool isFull(Stack *stack){
    return (stack -> top >= SIZE);
}

void push(Stack *stack, int value){
    if (isFull(stack)){
        printf("Stack is already full\n");
        return;
    }

    stack -> array[stack -> top] = value;
    stack -> top++;
}

int pop(Stack *stack){
    int return_value = 
}


int main(){

}
