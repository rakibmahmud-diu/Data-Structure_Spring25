#include <stdio.h>

int crr1[50][50], n;
void addition(int arr1[][50],int arr2[][50]);



int main() {
    int arr1[50][50], brr1[50][50], i, j;


    printf("\n\nAddition of two Matrices :\n");
    printf("------------------------------\n");
    printf("Input the size of the square matrix: ");
    scanf("%d", &n);


    printf("Input elements in the first matrix :\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &arr1[i][j]);
        }
    }


    printf("Input elements in the second matrix :\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &brr1[i][j]);
        }
    }

    addition(arr1,brr1);

//    for (i = 0; i < n; i++)
//        for (j = 0; j < n; j++)
//            crr1[i][j] = arr1[i][j] + brr1[i][j];


    printf("\nThe Addition of two matrix is : \n");
    for (i = 0; i < n; i++) {
        printf("\n");
        for (j = 0; j < n; j++)
            printf("%d\t", crr1[i][j]);
    }
    return 0;
}


void addition(int arr1[][50],int arr2[][50])
{
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            crr1[i][j] = arr1[i][j] + arr2[i][j];
}












