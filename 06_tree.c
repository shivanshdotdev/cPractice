#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int value;
    struct Node *left;
    struct Node *right;
} Node;

void initialize(Node* tree, int value){
    tree -> value = value;
    tree -> left = NULL;
    tree -> right = NULL;
}

void addOnLeft(Node* tree, int value){
    Node* new = malloc(sizeof(Node));

    initialize(new, value);

    tree -> left = new;
}

void addOnRight(Node* tree, int value){
    Node* new = malloc(sizeof(Node));

    initialize(new, value);

    tree -> right = new;
}

void traversalPostOrder(Node* node){
    if (node == NULL){
        return;
    }

    if (node -> left != NULL){
        traversalPostOrder(node -> left);
    }

    if (node -> right != NULL){
        traversalPostOrder(node -> right);
    }

    printf("%d\n", node -> value);
}

void traversalInOrder(Node* node){
    if (node == NULL){
        return;
    }

    if (node -> left != NULL){
        traversalInOrder(node -> left);
    }

    printf("%d\n", node -> value);

    if (node -> right != NULL){
        traversalInOrder(node -> right);
    }

}

void traversalPreOrder(Node* node){
    if (node == NULL){
        return;
    }

    printf("%d\n", node -> value);

    if (node -> left != NULL){
        traversalPreOrder(node -> left);
    }

    if (node -> right != NULL){
        traversalPreOrder(node -> right);
    }

}

void traversalBFS(Node* node){

}


int main(){
    Node *root = malloc(sizeof(Node));

    initialize(root, 1);

    addOnLeft(root, 2);
    addOnRight(root, 3);

    addOnLeft(root -> left, 4);
    addOnRight(root -> left, 5);

    addOnLeft(root -> right, 6);
    addOnRight(root -> right, 7);

    printf("PreOrder => Root -> Left -> Right\n");
    traversalPreOrder(root);

    printf("InOrder => Left -> Root -> Right\n");
    traversalInOrder(root);

    printf("PostOrder => Left -> Right -> Root\n");
    traversalPostOrder(root);
}


