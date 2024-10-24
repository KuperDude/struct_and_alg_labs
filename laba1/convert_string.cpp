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
        if (arr[i] != ' ' && arr[i] != '\n' && arr[i] != EOF) {
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