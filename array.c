#include <stdio.h>

void even_and_odd_elements(int array[], int size);
void sum_of_even_odd(int array[], int size);
void reverse_array(int array[], int size);
void search_in_array(int array[], int size, int key);
void avg_of_positive_and_negetive(int array[], int size);
void second_largest(int array[], int size);
void print_lines();

int main(){
    
    int array[] = {123,12,432,5,2,3254,5,42,123,123};
    int pos_neg_array[] = {74, 23, -85, -65, 74, -96, 49, 25, 45, -25};
    
    even_and_odd_elements(array, 10);
    print_lines();

    sum_of_even_odd(array, 10);
    print_lines();

    reverse_array(array, 10);
    print_lines();

    search_in_array(array, 10, 2);
    print_lines();

    avg_of_positive_and_negetive(pos_neg_array, 10);
    print_lines();

    second_largest(array, 10);
    return 0;
}

void even_and_odd_elements(int array[], int size){
    int even_count = 0, odd_count = 0;

    for (int i = 0; i < size; i++){
        int num = array[i];

        if (num % 2 == 0){
            even_count++;
        }
        else {
            odd_count++;
        }
    }

    printf("Even Count: %d\n", even_count);
    printf("Odd Count: %d\n", odd_count);
}

void sum_of_even_odd(int array[], int size){
    int even_sum = 0, odd_sum = 0;

    for (int i = 0; i < size; i++){
        int num = array[i];

        if (num % 2 == 0){
            even_sum += num;
        }
        else {
            odd_sum += num;
        }
    }

    printf("Even Sum: %d\n", even_sum);
    printf("Odd Sum: %d\n", odd_sum);
}

void reverse_array(int array[], int size){
    for (int i = (size - 1); i >= 0; i--){
        printf("%d, ", array[i]);
    }
    printf("\n");
}

void print_lines(){
    for (int i = 0; i < 60; i++){
        printf("=");
    }
    printf("\n");
}

void search_in_array(int array[], int size, int key){
    for (int i = 0; i < size; i++){
        if (array[i] == key){
            printf("The item %d is at position %d\n", key, i);
            return;
        }
    }
    printf("The item is not found\n");

}
void avg_of_positive_and_negetive(int array[], int size){
    int positive_count = 0;
    int negative_count = 0;
    int positive_sum = 0;
    int negative_sum = 0;

    for (int i = 0; i < size; i++){
        int num = array[i];

        if (num < 0){
            negative_count++;
            negative_sum += num;
        }
        else {
            positive_count++;
            positive_sum += num;
        }
    }

    printf("Average of positives: %.2f\n", (positive_sum/(positive_count * 1.0)));
    printf("Average of negatives: %.2f\n", (negative_sum/(negative_count * 1.0)));
}
void second_largest(int array[], int size){
    int largest, second_largest;

    if (array[0] > array[1]){
        largest = array[0];
        second_largest = array[1];
    }
    else {
        largest = array[1];
        second_largest = array[0];
    }

    for (int i = 2; i < size; i++){
        int num = array[i];

        if (num > largest){
            second_largest = largest;
            largest = num;
        }
        else if (num > second_largest && num < largest){
            second_largest = num;
        }
    }

    printf("Second Largest: %d\n", second_largest);
}
