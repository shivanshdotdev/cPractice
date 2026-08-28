#include <stdio.h>
#include <stdlib.h>

void add_new_node_via_traversal(int new_data);
void add_new_node_in_single_step(int new_data);
void traverse();

struct Node{
    int data;
    struct Node *next;
};

struct Node *head = NULL;
struct Node *tail = NULL;

int main(){
    add_new_node_in_single_step(10);
    add_new_node_in_single_step(20);
    add_new_node_in_single_step(30);
    add_new_node_in_single_step(40);
    add_new_node_in_single_step(40);
    add_new_node_in_single_step(40);
    add_new_node_in_single_step(40);
    add_new_node_in_single_step(40);
    add_new_node_in_single_step(40);
    add_new_node_in_single_step(40);
    add_new_node_in_single_step(40);
    traverse();
}

void add_new_node_via_traversal(int new_data){
    // naya node banao jisme data store hoga
    struct Node *new_node = malloc(sizeof(struct Node));
    new_node -> data = new_data;
    new_node -> next = NULL;

    // agar ye upar wala pahela node hai to first node ko head kahete hai and done
    if (head == NULL){
        head = new_node;
        return;
    }

    // in case pahele se nodes the, to head se start karke, end tak pahuncho and last node mein add kar do 
    struct Node *current_node = head;

    // last node wahi hoga jo NULL ko point kar raha ho, to tabtak jate rahe jabtak current node ka next NULL ko na point kar raha ho
    while(current_node -> next != NULL){
        current_node = current_node -> next;
    }

    // jab last mil jaye, to usme add kardo naya wala node
    current_node -> next = new_node;
    return;
}

void add_new_node_in_single_step(int new_data){
    struct Node *new_node = malloc(sizeof(struct Node));
    new_node -> data = new_data;
    new_node -> next = NULL;

    // agar tail null hai means abhi ye pahele hi node hai to head and tail dono hi honge, cuz head to first hai, and add hum end mein kar rahe hai to tail mein hi end hoga
    if (tail == NULL){
        head = new_node;
        tail = new_node;
        return;
    }

    // agar tail means last node hai to chuppe se last node mein add kardo
    tail -> next = new_node;
    tail = new_node;

}

void traverse(){
    if (head == NULL){
        printf("Nothing to traverse my dear ‍❤️‍\n");
        return;
    }
    
    struct Node *start = head;

    while (start -> next != NULL){
        printf("%d\t", start -> data);
        start = start -> next;
    }
    printf("%d\n", start -> data);
}

