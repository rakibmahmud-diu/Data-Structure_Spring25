#include <stdio.h>


int fibonacci(int n) {
    if (n <= 0) return 0;
    if (n == 1) return 1;
    return fibonacci(n - 1) + fibonacci(n - 2);
}


int sumOfFibonacci(int n) {
    if (n <= 0) return 0;
    return fibonacci(n) + sumOfFibonacci(n - 1);
}

int main() {
    int n;


    printf("Enter the value of N: ");
    scanf("%d", &n);


    int result = sumOfFibonacci(n - 1);
    printf("The sum of the first %d Fibonacci numbers is: %d\n", n, result);

    return 0;
}
