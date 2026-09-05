#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define MAX_SIZE 10

typedef struct {
    int front;
    int rear;
    int data[MAX_SIZE];
} Queue;

void initialize(Queue *queue){
    queue -> front = 0;
    queue -> rear = 0;
}

bool isEmpty(Queue *queue);
bool isFull(Queue *queue);
void enqueue(Queue *queue, int value){
    queue -> data[queue -> rear] = value;
    if 
    queue -> rear++;
}
int dequeue(Queue *queue){
    int return_value = queue -> data[queue -> front];
}

int main(){

}
