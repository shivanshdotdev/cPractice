#include <stdio.h>
#include <stdlib.h>

// first and last element deletion logic
// check index of 0 and last in insert at index

void append_via_traversal(int new_data);
void append_in_single_step(int new_data);
void prepend(int new_data);
int length();
int search(int value);
void display();
void delete_at(int index);
void delete(int value);
void insert_at_index(int index, int new_data);

void reverse();

struct Node{
    int data;
    struct Node *next;
};

struct Node *head = NULL;
struct Node *tail = NULL;

int main(){
    append_in_single_step(10);
    append_in_single_step(20);
    append_in_single_step(30);
    append_in_single_step(40);
    printf("Number of elements is %d\n", length());
    display();
    prepend(1);
    prepend(2);
    display();
    printf("Number of elements is %d\n", length());

    printf("The number 10 is at index %d\n", search(10));

    display();
    delete_at(3);
    display();
    delete(30);
    display();
    insert_at_index(2, 200);
    display();
}

void append_via_traversal(int new_data){
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

void append_in_single_step(int new_data){
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

void display(){
    if (head == NULL){
        printf("Nothing to display my dear ‍❤️‍\n");
        return;
    }
    
    struct Node *start = head;

    while (start -> next != NULL){
        printf("%d\t", start -> data);
        start = start -> next;
    }
    printf("%d\n", start -> data);
}

void prepend(int new_data){
    struct Node *new_node = malloc(sizeof(struct Node));
    new_node -> data = new_data;
    new_node -> next = head;
    head = new_node;
}

int length(){
    int count = 0;
    struct Node *start = head;

    while(start != NULL){
        count++;
        start = start -> next;
    }
    return count;
}

int search(int value){
    int index = 0;

    struct Node *start = head;

    while(start != NULL){
        if (start -> data == value){
            return index;
        }
        index++;
        start = start -> next;
    }

    return -1;
}

void delete_at(int index){
    int pos = 0;

    struct Node *current = head;
    struct Node *prev;
    struct Node *next;

    while (current != NULL){
        if (pos == index){
            next = current -> next;
            prev -> next = next;
        }
        prev = current;
        current = current -> next;
        pos++;
    }
    
}

void delete(int value){
    struct Node *current = head;
    struct Node *prev;
    struct Node *next;

    while (current != NULL){
        if (current -> data == value){
            next = current -> next;
            prev -> next = next;
        }
        prev = current;
        current = current -> next;
    }
    
}

void insert_at_index(int index, int new_data){
    struct Node *new_node = malloc(sizeof(struct Node));
    new_node -> data = new_data;
    new_node -> next = NULL;

    struct Node *current = head;
    struct Node *prev;
    struct Node *next;

    int pos = 0;

    while (current != NULL){
        if (pos == index){
            new_node -> next = current;
            prev -> next = new_node;
            return;
        }
        prev = current;
        current = current -> next;
        pos++;
    }

}


void reverse(){
    struct Node *current = tail;
    struct Node *prev;
    struct Node *next;

}
