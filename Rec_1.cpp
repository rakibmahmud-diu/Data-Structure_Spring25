#include <stdio.h>

int sumToN(int n) {
    if (n == 0) {
        return 0;
    }
    return n + sumToN(n - 1);
}

int main() {
    int n;
    printf("Enter a number: ");
    scanf("%d", &n);
    printf("The sum of numbers from 0 to %d is: %d\n", n, sumToN(n));
    return 0;
}
