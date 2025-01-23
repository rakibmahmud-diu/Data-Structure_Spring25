#include <stdio.h>

int main() {

    int arr1[50][50], brr1[50][50], i, j, r, c;


    printf("\n\nTranspose of a Matrix :\n");
    printf("---------------------------\n");


    printf("\nInput the rows and columns of the matrix: ");
    scanf("%d %d", &r, &c);


    printf("Input elements in the matrix:\n");
    for (i = 0; i < r; i++) {
        for (j = 0; j < c; j++) {
            scanf("%d", &arr1[i][j]);
        }
    }


    for (i = 0; i < r; i++) {
        for (j = 0; j < c; j++) {
            brr1[j][i] = arr1[i][j];
        }
    }


    printf("\n\nThe transpose of a matrix is : ");
    for (i = 0; i < c; i++) {
        printf("\n");
        for (j = 0; j < r; j++) {
            printf("%d\t", brr1[i][j]);
        }
    }

    return 0;
}
