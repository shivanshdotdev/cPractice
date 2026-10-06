#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int value;
    struct Node *left;
    struct Node *right;
} Node;

Node* queue[100];
int front = 0, back = 0;

void initialize(Node* node, int value){
    node -> value = value;
    node -> left = NULL;
    node -> right = NULL;
}

void addOnLeft(Node* node, int value){
    Node* new = malloc(sizeof(Node));

    initialize(new, value);

    node -> left = new;
}

void addOnRight(Node* node, int value){
    Node* new = malloc(sizeof(Node));

    initialize(new, value);

    node -> right = new;
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

void addUsingBFS(Node* node, int value){
    if (node == NULL){
        return;
    }

    front = back = 0;
    queue[back++] = node;

    while (front <= back){
        Node* currentNode = queue[front++];

        if (currentNode -> left == NULL){
            addOnLeft(currentNode, value);
            break;
        }
        else {
            queue[back++] = currentNode -> left;
        }

        if (currentNode -> right == NULL){
            addOnRight(currentNode, value);
            break;
        }
        else {
            queue[back++] = currentNode -> right;
        }
    }
    
}

Node* searchBFS(Node* node, int value){
    int steps = 0;

    front = back = 0;
    queue[back++] = node;

    while (front <= back){
        Node* currentNode = queue[front++];
        steps++;

        if (currentNode -> value == value){
            printf("Found %d in %d steps.\n", value, steps);
            return currentNode;
        }

        if (currentNode -> left != NULL){
            queue[back++] = currentNode -> left;
        }

        if (currentNode -> right != NULL){
            queue[back++] = currentNode -> right;
        }
    }

}

Node* searchDFS(Node* node, int value, int step){
    
    int steps = step;
    steps++;

    if (node -> value == value){
        printf("Found %d in %d steps.\n", value, steps);
        return node;
    }
    if (node -> left != NULL){
        searchDFS(node -> left, value, steps);
    }

    if (node -> right != NULL){
        searchDFS(node -> right, value, steps);
    }
}

void delete(Node* parentNode, Node* nodeToDelete){

}


int main(){
    Node *root = malloc(sizeof(Node));

    initialize(root, 1);

    // addOnLeft(root, 2);
    // addOnRight(root, 3);
    //
    // addOnLeft(root -> left, 4);
    // addOnRight(root -> left, 5);
    //
    // addOnLeft(root -> right, 6);
    // addOnRight(root -> right, 7);

    // printf("PreOrder => Root -> Left -> Right\n");
    // traversalPreOrder(root);
    //
    // printf("InOrder => Left -> Root -> Right\n");
    // traversalInOrder(root);
    
    addUsingBFS(root, 2);
    addUsingBFS(root, 3);
    addUsingBFS(root, 4);
    addUsingBFS(root, 5);
    addUsingBFS(root, 6);
    addUsingBFS(root, 7);
    addUsingBFS(root, 8);
    addUsingBFS(root, 9);
    addUsingBFS(root, 10);
    addUsingBFS(root, 11);
    addUsingBFS(root, 12);
    addUsingBFS(root, 13);
    addUsingBFS(root, 14);
    addUsingBFS(root, 15);

    // addUsingDFS(root, 2);
    // addUsingDFS(root, 3);
    // addUsingDFS(root, 4);
    // addUsingDFS(root, 5);
    // addUsingDFS(root, 6);
    // addUsingDFS(root, 7);
    // addUsingDFS(root, 8);
    // addUsingDFS(root, 9);
    // addUsingDFS(root, 10);
    // addUsingDFS(root, 11);
    // addUsingDFS(root, 12);
    // addUsingDFS(root, 13);
    // addUsingDFS(root, 14);
    // addUsingDFS(root, 15);

    searchDFS(root, 8, 0);

    return 0;
}


