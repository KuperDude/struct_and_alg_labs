//13. Найти самое длинное слово в строке и 
//удалить его, если оно содержит 
//более 5 символов и не начинается с гласной буквы.

#include <iostream>
#include <string.h>
#include <cctype>
#include <functional>
#include "convert_string.h"

using namespace std;

void task1() {
    char arr[100];
    cin.getline(arr, 100);

    findMaxWord(arr, strlen(arr), [&arr](int maxStartIndex, int maxWordLen) {
        memmove(&arr[maxStartIndex], &arr[maxStartIndex+maxWordLen], strlen(arr) - maxStartIndex - maxWordLen + 1);
    });

    cout << arr << endl;
}

void task2() {
    string arr;
    getline(cin, arr);

    findMaxWord(arr, arr.length(), [&arr](int maxStartIndex, int maxWordLen) {
        arr.erase(maxStartIndex, maxWordLen);
    });

    cout << arr << endl;
}

void task3() {
    char arr[100];

	FILE* file = fopen("someString.txt", "r");
	
	if (file) {
		fgets(arr, 100, file);
	} else {
        return;
    }

    fclose(file);

    findMaxWord(arr, strlen(arr), [&arr](int maxStartIndex, int maxWordLen) {
        memmove(&arr[maxStartIndex], &arr[maxStartIndex+maxWordLen], strlen(arr) - maxStartIndex - maxWordLen + 1);
    });

    FILE* file2 = fopen("result.txt", "w");

	fputs(arr, file2);
	fclose(file2);
}


// int main() {
//     task1();

//     return 0;
// }