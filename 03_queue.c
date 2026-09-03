#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define MAX_SIZE 100

struct Queue {
    int queue[MAX_SIZE];
    int rear;
};

void initializeQueue(struct Queue *q){
    q -> rear = 0;
}

bool isEmpty(struct Queue *q){
    return (q -> rear == 0);
}

bool isFull(struct Queue *q){
    return (q -> rear >= (MAX_SIZE - 1));
}

void enqueue(struct Queue *q, int value){
    if (isFull(q)){
        printf("Queue is full\n");
        return;
    }

    if (isEmpty(q)) q -> rear = 0;

    q -> queue[(q -> rear)] = value;
    q -> rear++;

    printf("Enqueued %d in queue\n", value);
}

int dequeue(struct Queue *q){
    if (isEmpty(q)) {
        printf("Queue is Empty\n");
        return -1;
    }

    int return_value = q -> queue[0];

    for(int i = 1; i < (q -> rear); i++){
        q -> queue[i-1] = q -> queue[i];
    }
    q -> rear--;
    q -> queue[q -> rear] = 0;

    printf("%d has been dequeued from the queue.\n", return_value);
    return return_value;
}


int main(){
    struct Queue *queue = malloc(sizeof(struct Queue));

    initializeQueue(queue);
    enqueue(queue, 10);
    enqueue(queue, 18);
    enqueue(queue, 14);
    enqueue(queue, 13);
    enqueue(queue, 14);
    dequeue(queue);
    dequeue(queue);
    dequeue(queue);
    dequeue(queue);
    enqueue(queue, 18);
    enqueue(queue, 14);
    enqueue(queue, 13);
    dequeue(queue);
    dequeue(queue);
    dequeue(queue);
    dequeue(queue);
    dequeue(queue);
    dequeue(queue);
    dequeue(queue);
    enqueue(queue, 18);
    enqueue(queue, 14);
    enqueue(queue, 13);
    dequeue(queue);
    dequeue(queue);


    return 0;
}
