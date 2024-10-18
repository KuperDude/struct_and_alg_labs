//13. Найти самое длинное слово в строке и 
//удалить его, если оно содержит 
//более 5 символов и не начинается с гласной буквы.

#include <iostream>
#include <string.h>
#include <cctype>
#include <functional>

using namespace std;

bool isConsonant(char ch) {
    ch = tolower(ch);

    return (ch != 'a' && ch != 'e' && ch != 'i' && ch != 'o' && ch != 'u' && ch != 'y');
}

template<typename T>
void findMaxWord(T arr, int len, const function<void(int, int)>& closure) {
    int maxStartIndex = 0;
    int maxWordLen = 0;
    int wordLen = 0;
    for (int i = 0; i<len; i++) {
        if (arr[i] != ' ') {
            wordLen++;
        } else {
            if (maxWordLen < wordLen) {
                maxStartIndex = i - wordLen;
                maxWordLen = wordLen;
            }
            wordLen = 0;
        }
    }
    if (maxWordLen < wordLen) {
        maxStartIndex = len - wordLen;
        maxWordLen = wordLen;
    }
    if (maxWordLen >= 5 && isConsonant(arr[maxStartIndex])) {
        closure(maxStartIndex, maxWordLen);
    }
}

void task1() {
    char arr[100];
    cin.getline(arr, 100);

    findMaxWord(arr, strlen(arr), [&arr](int maxStartIndex, int maxWordLen) {
        for (int i = maxStartIndex; i < maxStartIndex+maxWordLen; i++) {
            arr[i] = arr[i+maxWordLen+1];
        }
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
    char arr[100] = {};

	FILE* file = fopen("someString.txt", "r");
	
	if (file) {
		fgets(arr, 100, file);
	} else {
        return;
    }

    fclose(file);

    findMaxWord(arr, strlen(arr), [&arr](int maxStartIndex, int maxWordLen) {
        for (int i = maxStartIndex; i < maxStartIndex+maxWordLen; i++) {
            arr[i] = arr[i+maxWordLen+1];
        }
    });

    FILE* file2 = fopen("result.txt", "w");

	fputs(arr, file2);
	fclose(file2);
}


int main() {
    task1();

    return 0;
}