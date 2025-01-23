#include <stdio.h>

int findMin(int arr[], int size) {
    if (size == 1) {
        return arr[0];
    }
    int restMin = findMin(arr, size - 1);
    return (arr[size - 1] < restMin) ? arr[size - 1] : restMin;
}

int main() {
    int n;
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("The minimum element in the array is: %d\n", findMin(arr, n));
    return 0;
}
