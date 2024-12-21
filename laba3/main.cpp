#include <iostream>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include "../laba1/convert_string.h"

template <typename T>
class Element {
public:
    T data;
    Element* next;
    Element* prev;

    Element(const T& value) : data(value), next(nullptr), prev(nullptr) {}
};

template <typename T>
class OneList {
private:
    Element<T>* head;
    Element<T>* tail;
    size_t list_size;

public:
    OneList() : head(nullptr), tail(nullptr), list_size(0) {}

    ~OneList() {
        while (!empty()) {
            pop_front();
        }
    }

    void push_front(const T& value) {
        Element<T>* new_element = new Element<T>(value);
        new_element->next = head;
        head = new_element;
        if (!tail) {
            tail = head;
        }
        ++list_size;
    }

    void push_back(const T& value) {
        Element<T>* new_element = new Element<T>(value);
        if (tail) {
            tail->next = new_element;
            tail = new_element;
        }
        else {
            head = tail = new_element;
        }
        ++list_size;
    }

    void insert(int position, const T& value) {
        if (position < 0 || position > static_cast<int>(list_size)) {
            throw std::out_of_range("Position out of range");
        }
        if (position == 0) {
            push_front(value);
            return;
        }
        if (position == static_cast<int>(list_size)) {
            push_back(value);
            return;
        }
        Element<T>* current = head;
        for (int i = 1; i < position; ++i) {
            current = current->next;
        }
        Element<T>* new_element = new Element<T>(value);
        new_element->next = current->next;
        current->next = new_element;
        ++list_size;
    }

    void pop_front() {
        if (empty()) {
            throw std::underflow_error("List is empty");
        }
        Element<T>* temp = head;
        head = head->next;
        delete temp;
        if (!head) {
            tail = nullptr;
        }
        --list_size;
    }

    void pop_back() {
        if (empty()) {
            throw std::underflow_error("List is empty");
        }
        if (head == tail) {
            delete head;
            head = tail = nullptr;
        }
        else {
            Element<T>* current = head;
            while (current->next != tail) {
                current = current->next;
            }
            delete tail;
            tail = current;
            tail->next = nullptr;
        }
        --list_size;
    }

    T& operator[](size_t index) {
        if (index >= list_size) {
            throw std::out_of_range("Index out of range");
        }
        Element<T>* current = head;
        for (size_t i = 0; i < index; ++i) {
            current = current->next;
        }
        return current->data;
    }

    void clear() {
        while (!empty()) {
            pop_front();
        }
    }

    void remove(const T& value) {
        while (head && head->data == value) {
            pop_front();
        }
        if (!head) return;

        Element<T>* current = head;
        while (current->next) {
            if (current->next->data == value) {
                Element<T>* temp = current->next;
                current->next = temp->next;
                if (temp == tail) {
                    tail = current;
                }
                delete temp;
                --list_size;
            }
            else {
                current = current->next;
            }
        }
    }

    size_t size() const { return list_size; }

    T& front() {
        if (empty()) {
            throw std::underflow_error("List is empty");
        }
        return head->data;
    }

    T& back() {
        if (empty()) {
            throw std::underflow_error("List is empty");
        }
        return tail->data;
    }

    bool empty() const { return head == nullptr; }

    class Iterator {
    private:
        Element<T>* current;

    public:
        Iterator(Element<T>* start) : current(start) {}

        T& operator*() { return current->data; }

        Iterator& operator++() {
            current = current->next;
            return *this;
        }

        bool operator!=(const Iterator& other) const { return current != other.current; }
    };

    Iterator begin() { return Iterator(head); }
    Iterator end() { return Iterator(nullptr); }
};


template <typename T>
class DoubleList {
private:
    Element<T>* head;
    Element<T>* tail;
    size_t list_size;

public:
    DoubleList() : head(nullptr), tail(nullptr), list_size(0) {}

    ~DoubleList() {
        while (!empty()) {
            pop_front();
        }
    }

    void clear() {
        while (!empty()) {
            pop_front();
        }
    }

    T& operator[](size_t index) {
        if (index >= list_size) {
            throw std::out_of_range("Index out of range");
        }
        Element<T>* current = head;
        for (size_t i = 0; i < index; ++i) {
            current = current->next;
        }
        return current->data;
    }

    void push_front(const T& value) {
        Element<T>* new_element = new Element<T>(value);
        new_element->next = head;
        if (head) {
            head->prev = new_element;
        }
        head = new_element;
        if (!tail) {
            tail = head;
        }
        ++list_size;
    }

    void push_back(const T& value) {
        Element<T>* new_element = new Element<T>(value);
        new_element->prev = tail;
        if (tail) {
            tail->next = new_element;
        }
        tail = new_element;
        if (!head) {
            head = tail;
        }
        ++list_size;
    }

    void insert(int position, const T& value) {
        if (position < 0 || position > static_cast<int>(list_size)) {
            throw std::out_of_range("Position out of range");
        }
        if (position == 0) {
            push_front(value);
            return;
        }
        if (position == static_cast<int>(list_size)) {
            push_back(value);
            return;
        }
        Element<T>* current = head;
        for (int i = 0; i < position; ++i) {
            current = current->next;
        }
        Element<T>* new_element = new Element<T>(value);
        new_element->next = current;
        new_element->prev = current->prev;
        current->prev->next = new_element;
        current->prev = new_element;
        ++list_size;
    }

    void pop_front() {
        if (empty()) {
            throw std::underflow_error("List is empty");
        }
        Element<T>* temp = head;
        head = head->next;
        if (head) {
            head->prev = nullptr;
        }
        else {
            tail = nullptr;
        }
        delete temp;
        --list_size;
    }

    void pop_back() {
        if (empty()) {
            throw std::underflow_error("List is empty");
        }
        Element<T>* temp = tail;
        tail = tail->prev;
        if (tail) {
            tail->next = nullptr;
        }
        else {
            head = nullptr;
        }
        delete temp;
        --list_size;
    }

    void remove(const T& value) {
        Element<T>* current = head;
        while (current) {
            if (current->data == value) {
                Element<T>* temp = current;
                if (current->prev) {
                    current->prev->next = current->next;
                }
                else {
                    head = current->next;
                }
                if (current->next) {
                    current->next->prev = current->prev;
                }
                else {
                    tail = current->prev;
                }
                current = current->next;
                delete temp;
                --list_size;
            }
            else {
                current = current->next;
            }
        }
    }

    size_t size() const { return list_size; }

    T& front() {
        if (empty()) {
            throw std::underflow_error("List is empty");
        }
        return head->data;
    }

    T& back() {
        if (empty()) {
            throw std::underflow_error("List is empty");
        }
        return tail->data;
    }

    bool empty() const { return head == nullptr; }

    class Iterator {
    private:
        Element<T>* current;

    public:
        Iterator(Element<T>* start) : current(start) {}

        T& operator*() { return current->data; }

        Iterator& operator++() {
            current = current->next;
            return *this;
        }

        Iterator& operator--() {
            current = current->prev;
            return *this;
        }

        bool operator!=(const Iterator& other) const { return current != other.current; }
    };

    Iterator begin() { return Iterator(head); }
    Iterator end() { return Iterator(nullptr); }
};

// int main() {

//     OneList<std::string> one_list;
//     DoubleList<std::string> double_list;

//     char* ptr;

//     FILE* file = fopen("someString.txt", "r");
//     int n = 5; 
//     int countChar = 0;
//     ptr = (char*)calloc(n, sizeof(char));

//     char ch;
//     while ((ch = fgetc(file)) != EOF) {
//         countChar++;

//         if (countChar+1 > n) {
//             n+=5;
//             ptr = (char*)realloc(ptr, n);
//         }
//         ptr[countChar-1] = ch;
//     }
//     ptr[countChar] = '\0';

//     fclose(file);

//     findMaxWord(ptr, countChar, [ptr, countChar](int maxStartIndex, int maxWordLen) {
//         memmove(&ptr[maxStartIndex], &ptr[maxStartIndex+maxWordLen], countChar - maxStartIndex - maxWordLen + 1);
//     });

//     for (int i = 0; i < countChar; ++i) {
//         if (ptr[i] == '\0') {
//             break;
//         }
//         one_list.push_back(std::string(1, ptr[i]));
//         double_list.push_back(std::string(1, ptr[i]));
//     }

//     std::cout << "Processed string: " << ptr << "\n";

//     std::cout << "OneList contents: ";
//     for (auto it = one_list.begin(); it != one_list.end(); ++it) {
//         std::cout << *it;
//     }
//     std::cout << "\n";

//     std::cout << "DoubleList contents: ";
//     for (auto it = double_list.begin(); it != double_list.end(); ++it) {
//         std::cout << *it;
//     }
//     std::cout << "\n";

//     return 0;
// }