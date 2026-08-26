#include <stdio.h>

void matrix_sum(int matrix1[][2], int matrix2[][2]);
void matrix_difference(int matrix1[][2], int matrix2[][2]);
void matrix_product(int matrix1[][2], int matrix2[][2]);
void matrix_transpose(int matrix[][2]);
void matrix_all_element_sum(int matrix[][2]);
void matrix_sum_of_diagonals(int matrix[][2]);
void matrix_smallest_largest(int matrix[][2]);
void printLines(char *string);
void printMatrix(int matrix[2][2]);

int main(){
    int matrix1[2][2] = {
        {13, 7},
        {9, 11}
    };

    int matrix2[2][2] = {
        {6, 8},
        {5, 12}
    };

    printLines("Original Matrix");

    printMatrix(matrix1);
    printMatrix(matrix2);

    matrix_sum(matrix1, matrix2);
    matrix_difference(matrix1, matrix2);
    matrix_product(matrix1, matrix2);
    matrix_transpose(matrix1);
    matrix_all_element_sum(matrix1);
    matrix_sum_of_diagonals(matrix1);
    matrix_smallest_largest(matrix1);
    
}

void matrix_sum(int matrix1[][2], int matrix2[][2]){
    printLines("Sum of the Matrix");

    int sum[2][2];

    for (int i = 0; i < 2; i++){
        for (int j = 0; j < 2; j++){
            sum[i][j] = matrix1[i][j] + matrix2[i][j];
        }
    }

    printMatrix(sum);
}

void matrix_difference(int matrix1[][2], int matrix2[][2]){
    printLines("Difference of the matrix");

    int sum[2][2];

    for (int i = 0; i < 2; i++){
        for (int j = 0; j < 2; j++){
            sum[i][j] = matrix1[i][j] - matrix2[i][j];
        }
    }
    printMatrix(sum);
}

void matrix_product(int matrix1[][2], int matrix2[][2]){

    printLines("Product of Matrix");
    
    int product[2][2] = {0};

    for (int i = 0; i < 2; i++){
        for (int j = 0; j < 2; j++){
            for (int k = 0; k < 2; k++){
                product[i][j] += matrix1[i][k] * matrix2[k][j];
            }
        }
    }

    printMatrix(product);
}

void matrix_transpose(int matrix[][2]){
    
    printLines("Transposed Matrix");

    int transposed[2][2];

    for (int i = 0; i < 2; i++){
        for (int j = 0; j < 2; j++){
            if (i != j){
                transposed[i][j] = matrix[j][i];
            }
            else{
                transposed[i][j] = matrix[i][j];
            }
            
        }
    }

    printMatrix(transposed);

}

void matrix_all_element_sum(int matrix[][2]){
    printLines("Sum of all elements ");
    int sum = 0;

    for (int i = 0; i < 2; i++){
        for (int j = 0; j < 2; j++){
            sum += matrix[i][j];
        }
    }

    printf("%d\n", sum);

}


void matrix_sum_of_diagonals(int matrix[][2]){
    printLines("Sum of Diagonals");

    int sum_of_diagonals = 0;

    for (int i = 0; i < 2; i++){
        for (int j = 0; j < 2; j++){
            if (i == j){
                sum_of_diagonals += matrix[i][j];
            }
        }
    }

    printf("%d\n", sum_of_diagonals);
}


void matrix_smallest_largest(int matrix[][2]){
    printLines("Largest and Smallest");

    int smallest = matrix[0][0];
    int largest = matrix[0][0];

    for (int i = 0; i < 2; i++){
        for (int j = 0; j < 2; j++){
            int num = matrix[i][j];
            if (num > largest) largest = num;
            if (num < smallest) smallest = num;
        }
    }

    printf("Largest Number : %d\n", largest);
    printf("Smallest Number : %d\n", smallest);

}

void printLines(char *string){
    for (int i = 0; i < 20; i++){
        printf("=");
    }

    printf(" %s ", string);

    for (int i = 0; i < 20; i++){
        printf("=");
    }
    printf("\n");
}

void printMatrix(int matrix[2][2]){
    for (int i = 0; i < 2; i++){
        for (int j = 0; j < 2; j++){
            printf("%d   ", matrix[i][j]);
        }

        printf("\n");
    }
    printf("\n");
}
