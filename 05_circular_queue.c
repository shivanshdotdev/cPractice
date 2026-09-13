#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define MAX_SIZE 100

typedef struct {
    int entry;
    int exit;
    int data[MAX_SIZE];
} Queue;

void initialize(Queue *queue){
    queue -> entry = -1;
    queue -> exit = -1;
}

bool isEmpty(Queue *queue);

bool isFull(Queue *queue);

void enqueue(Queue *queue, int value){
    queue -> entry++;
    int slot = queue -> entry % MAX_SIZE;

    if (slot == queue -> exit){
        printf("The list is full\n");
        return;
    }

    queue -> data[slot] = value;
    queue -> entry = slot;
    
}

int dequeue(Queue *queue){
    queue -> exit++;
    int return_value = queue -> data[queue -> exit];

    printf("Dequeued %d\n", return_value);

    return return_value;
}

void printQueue(Queue *queue){
    int limit = queue -> entry;
    for (int i = queue -> exit; i <= limit; i++){
        printf("%d\t", queue -> data[i]);
    }
    printf("\n");
}

int main(){

    Queue *queue = malloc(sizeof(Queue));

    initialize(queue);

    enqueue(queue, 10);
    enqueue(queue, 20);
    enqueue(queue, 30);
    enqueue(queue, 40);

    printQueue(queue);
    
    dequeue(queue);
    dequeue(queue);


    printQueue(queue);
}
