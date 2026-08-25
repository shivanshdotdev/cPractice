#include <stdio.h>

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

    printLines("Sum of the Matrix");

    int sum[2][2];

    for (int i = 0; i < 2; i++){
        for (int j = 0; j < 2; j++){
            sum[i][j] = matrix1[i][j] + matrix2[i][j];
        }
    }

    printMatrix(sum);

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
