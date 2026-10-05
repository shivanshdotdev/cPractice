#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int value;
    struct Node *left;
    struct Node *right;
} Node;

Node* queue[100];
int front = 0, back = 0;

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

int addUsingDFS(Node* node, int value){
    
    /*
     * -1 = NULL Object 
     *  0 = added on left 
     *  1 = added on right
     */


    if (node == NULL){
        printf("Cannot add in NULL object\n");
        return -1;
    }

    if (node -> left == NULL){
        addOnLeft(node, value);
        return 0;
    }

    else if (node -> right == NULL){
        addOnRight(node, value);
        return 1;
    }

    if (node -> left != NULL){
        addUsingDFS(node -> left, value);
    }
    else if (node -> right != NULL){
        addUsingDFS(node -> right, value);
    }

}

void traversalBFS(Node* node){

    front = back = 0;
    queue[back++] = node;

    while (front <= back){
        Node* currentNode = queue[front++];
        printf("%d\n", currentNode -> value);

        if (currentNode -> left != NULL){
            queue[back++] = currentNode -> left;
        }

        if (currentNode -> right != NULL){
            queue[back++] = currentNode -> right;
        }
    }

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

    // printf("PreOrder => Root -> Left -> Right\n");
    // traversalPreOrder(root);
    //
    // printf("InOrder => Left -> Root -> Right\n");
    // traversalInOrder(root);

    printf("PostOrder => Left -> Right -> Root\n");
    traversalPostOrder(root);

    printf("BFS\n");
    traversalBFS(root);
    return 0;

    addUsingDFS(root, 8);
    addUsingDFS(root, 9);
    addUsingDFS(root, 10);
    addUsingDFS(root, 11);

    printf("PostOrder => Left -> Right -> Root\n");
    traversalPostOrder(root);
}


