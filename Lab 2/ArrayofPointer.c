#include <stdio.h>

int main() {
    int n;
    scanf("%d",&n);
    int val[n];
    int *ptr2[n];

    printf("Enter %d numbers:\n",n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &val[i]);
    }

    for (int i = 0; i < n; i++) {
        ptr2[i] = &val[i];
    }


    printf("The values are:\n");
    for (int i = 0; i < n; i++) {
        printf("%d\n", *ptr2[i]);
    }

    return 0;
}
