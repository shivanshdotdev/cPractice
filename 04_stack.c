#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define SIZE 100

typedef struct {
    int array[SIZE];
    int top;
} Stack;

void initialize(Stack *stack){
    stack -> top = -1;
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

    stack -> top++;
    stack -> array[stack -> top] = value;

    printf("Pushed %d\n", value);
}

int pop(Stack *stack){
    if (isEmpty(stack)){
        printf("There is nothing in stack\n");
        return -1;
    }

    int num = stack -> array[stack -> top--];

    printf("Popped %d\n", num);
    return num;
    // returns the current top and then reduce it by one for future pop

}

void printStack(Stack *stack){
    int limit = stack -> top;
    for (int i = 0; i <= limit; i++){
        printf("%d\t", stack -> array[i]);
    }
    printf("\n");
    return;
}


int main(){
    Stack *stack = malloc(sizeof(Stack));

    initialize(stack);

    push(stack, 10);
    push(stack, 20);
    push(stack, 30);
    push(stack, 40);
    push(stack, 50);
    push(stack, 60);

    printStack(stack);

    pop(stack);
    pop(stack);
    pop(stack);

    printStack(stack);

    push(stack, 70);
    push(stack, 80);
    push(stack, 90);

    printStack(stack);

    pop(stack);

    printStack(stack);
}
