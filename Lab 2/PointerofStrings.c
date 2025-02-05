#include <stdio.h>
#include <stdlib.h>

int main() {
    int n,N;
    scanf("%d", &n);
    char *names[n];

    for (int i = 0; i < n; i++) {
        scanf("%d",&N);
        names[i] = (char *)malloc(N * sizeof(char));
        if (names[i] == NULL) {
            printf("Memory allocation failed\n");
            return 1;
        }
        scanf("%s", names[i]);
    }

    for (int i = 0; i < n; i++) {
        printf("%s\n", names[i]);
    }


    for (int i = 0; i < n; i++) {
        free(names[i]);
    }

    return 0;
}
