#include <stdio.h>
#include <stdlib.h>
#include "../laba1/convert_string.h"

void task1() {
    char* ptr;
    int n = 1; 

    ptr = (char*)malloc(n * sizeof(char)); 

    char ch;
    while ((ch = getchar()) != EOF) {
        ptr[n-1] = ch;

        n++;
        char* tmp_ptr = (char*)malloc(n * sizeof(char));
        for (int i = 0; i<n-1; i++) {
            tmp_ptr[i] = ptr[i];
        }
        free(ptr);

        ptr = (char*)malloc(n * sizeof(char));
        ptr = tmp_ptr;
    }
    ptr[n] = '\0';
    
    findMaxWord(ptr, n, [ptr, n](int maxStartIndex, int maxWordLen) {
        memmove(&ptr[maxStartIndex], &ptr[maxStartIndex+maxWordLen], n - maxStartIndex - maxWordLen + 1);
    });

    for (int i = 0; (i < n-1) && ptr[i] != '\0'; i++) {
        printf("%c", ptr[i]);
    }

    free(ptr);
}

void task2() {
    char* ptr;
    int n = 5; 
    int countChar = 0;
    ptr = (char*)calloc(n, sizeof(char)); 

    char ch;
    while ((ch = getchar()) != EOF) {
        countChar++;

        if (countChar+1 > n) {
            n+=5;
            ptr = (char*)realloc(ptr, n);
        }
        ptr[countChar-1] = ch;
    }
    ptr[countChar] = '\0';

    findMaxWord(ptr, countChar, [ptr, countChar](int maxStartIndex, int maxWordLen) {
        memmove(&ptr[maxStartIndex], &ptr[maxStartIndex+maxWordLen], countChar - maxStartIndex - maxWordLen + 1);
    });
    
    for (int i = 0; i < n-1 && ptr[i] != '\0'; i++) {
        printf("%c", ptr[i]);
    }

    free(ptr);
}

void task3() {

    char* ptr;
    int n = 5; 
    int countChar = 0;
    ptr = (char*)calloc(n, sizeof(char)); 

    char ch;

    while ((ch = getchar()) != EOF) {
        countChar++;

        if (countChar+1 > n) {
            n+=5;
            ptr = (char*)realloc(ptr, n);
        }
        ptr[countChar-1] = ch;
    }
    ptr[countChar] = '\0';

    FILE* file0 = fopen("someString.txt", "w");
    fputs(ptr, file0);
    fclose(file0);
    free(ptr);

    FILE* file = fopen("someString.txt", "r");
    n = 5; 
    countChar = 0;
    ptr = (char*)calloc(n, sizeof(char));

    while ((ch = fgetc(file)) != EOF) {
        countChar++;

        if (countChar+1 > n) {
            n+=5;
            ptr = (char*)realloc(ptr, n);
        }
        ptr[countChar-1] = ch;
    }
    ptr[countChar] = '\0';

    fclose(file);

    findMaxWord(ptr, countChar, [ptr, countChar](int maxStartIndex, int maxWordLen) {
        memmove(&ptr[maxStartIndex], &ptr[maxStartIndex+maxWordLen], countChar - maxStartIndex - maxWordLen + 1);
    });

    FILE* file2 = fopen("result.txt", "w");

	fputs(ptr, file2);
    free(ptr);
	fclose(file2);
}

int main() {
    task3();
    return 0;
}