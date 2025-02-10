#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

void reverseString(char *str) {
    int len = strlen(str);
    char *start = str;
    char *end = str + len - 1;
    while (start < end) {
        char temp = *start;
        *start = *end;
        *end = temp;
        start++;
        end--;
    }
}

int countWords(char *str) {
    int count = 0;
    while (*str != '\0') {
        if (*str == ' ') {
            count++;
        }
        str++;
    }
    return count+1;
}

int main() {
    int n;
    printf("Enter the number of strings: ");
    scanf("%d", &n);

    char *strings[n];
    char t[100];

    printf("Enter %d strings:\n", n);
    for (int i = 0; i < n; i++) {
        scanf(" %[^\n]s", t);
        strings[i] = (char *)malloc(sizeof(t));
        strcpy(strings[i],t);
    }

    for (int i = 0; i < n; i++) {
        reverseString(strings[i]);
    }

    for (int i = 0, j = n - 1; i < j; i++, j--) {
        char *temp = strings[i];
        strings[i] = strings[j];
        strings[j] = temp;
    }

    int maxWords = 0;
    char *mostWordsString = NULL;
    for (int i = 0; i < n; i++) {
        int words = countWords(strings[i]);
        if (words > maxWords) {
            maxWords = words;
            mostWordsString = strings[i];
        }
    }

    printf("\nReversed strings:\n");
    for (int i = 0; i < n; i++) {
        printf("%s\n", strings[i]);
    }

    printf("\nString with the most words: \"%s\" (Words: %d)\n", mostWordsString, maxWords);
    for (int i = 0; i < n; i++) {
        free(strings[i]);
    }

    return 0;
}
