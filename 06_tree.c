#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int value;
    struct Node *left;
    struct Node *right;
} Node;

void initialize(Node* tree){
    tree -> value = 2;
    tree -> left = NULL;
    tree -> right = NULL;
}

void addOnLeft(Node* tree){
    Node* new = malloc(sizeof(Node));

    initialize(new);

    tree -> left = new;
}

void addOnRight(Node* tree){
    Node* new = malloc(sizeof(Node));

    initialize(new);

    tree -> right = new;
}


int main(){
    Node *root = malloc(sizeof(Node));

    initialize(root);

    addOnLeft(root);

    addOnRight(root);
}


