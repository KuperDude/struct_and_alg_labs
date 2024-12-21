#define CATCH_CONFIG_MAIN

#include "../catch2/catch.hpp"
#include "../laba3/main.cpp"  

TEST_CASE() {
    OneList<int> list;
    REQUIRE(list.empty() == true);
    REQUIRE(list.size() == 0);
}

TEST_CASE() {
    OneList<int> list;
    list.push_front(10);
    REQUIRE(list.size() == 1);
    REQUIRE(list.front() == 10);
    REQUIRE(list.back() == 10);
}

TEST_CASE() {
    OneList<int> list;
    list.push_back(10);
    REQUIRE(list.size() == 1);
    REQUIRE(list.front() == 10);
    REQUIRE(list.back() == 10);
}

TEST_CASE() {
    OneList<int> list;
    list.push_back(10);
    list.push_front(20);
    REQUIRE(list.size() == 2);
    REQUIRE(list.front() == 20);
    REQUIRE(list.back() == 10);
}

TEST_CASE() {
    OneList<int> list;
    list.push_front(10);
    list.push_back(20);
    REQUIRE(list.size() == 2);
    REQUIRE(list.front() == 10);
    REQUIRE(list.back() == 20);
}

TEST_CASE() {
    OneList<int> list;
    list.push_back(10);
    list.insert(0, 5);
    REQUIRE(list.size() == 2);
    REQUIRE(list.front() == 5);
    REQUIRE(list.back() == 10);
}

TEST_CASE() {
    OneList<int> list;
    list.push_back(10);
    list.push_back(20);
    list.insert(2, 25);
    REQUIRE(list.size() == 3);
    REQUIRE(list.back() == 25);
}

TEST_CASE() {
    OneList<int> list;
    list.push_back(10);
    list.push_back(20);
    list.pop_front();
    REQUIRE(list.size() == 1);
    REQUIRE(list.front() == 20);
}

TEST_CASE() {
    OneList<int> list;
    list.push_back(10);
    list.push_back(20);
    list.pop_back();
    REQUIRE(list.size() == 1);
    REQUIRE(list.back() == 10);
}

TEST_CASE() {
    OneList<int> list;
    list.push_back(10);
    list.push_back(20);
    list.push_back(10);
    list.remove(10);
    REQUIRE(list.size() == 1);
    REQUIRE(list.front() == 20);
}

TEST_CASE() {
    OneList<int> list;
    bool exceptionThrown = false;
    try {
        list.front();
    } catch (const std::underflow_error&) {
        exceptionThrown = true;
    }
    REQUIRE(exceptionThrown);
}

TEST_CASE() {
    OneList<int> list;
    bool exceptionThrown = false;
    try {
        list.back();
    } catch (const std::underflow_error&) {
        exceptionThrown = true;
    }
    REQUIRE(exceptionThrown);
}

TEST_CASE() {
    OneList<int> list;
    list.push_back(10);
    list.push_back(20);
    list.clear();
    REQUIRE(list.empty() == true);
}

TEST_CASE() {
    DoubleList<int> list;
    REQUIRE(list.empty() == true);
    REQUIRE(list.size() == 0);
}

TEST_CASE() {
    DoubleList<int> list;
    list.push_front(10);
    REQUIRE(list.size() == 1);
    REQUIRE(list.front() == 10);
    REQUIRE(list.back() == 10);
}

TEST_CASE() {
    DoubleList<int> list;
    list.push_back(10);
    REQUIRE(list.size() == 1);
    REQUIRE(list.front() == 10);
    REQUIRE(list.back() == 10);
}

TEST_CASE() {
    DoubleList<int> list;
    list.push_back(10);
    list.push_front(20);
    REQUIRE(list.size() == 2);
    REQUIRE(list.front() == 20);
    REQUIRE(list.back() == 10);
}

TEST_CASE() {
    DoubleList<int> list;
    list.push_front(10);
    list.push_back(20);
    REQUIRE(list.size() == 2);
    REQUIRE(list.front() == 10);
    REQUIRE(list.back() == 20);
}

TEST_CASE() {
    DoubleList<int> list;
    list.push_back(10);
    list.insert(0, 5);
    REQUIRE(list.size() == 2);
    REQUIRE(list.front() == 5);
    REQUIRE(list.back() == 10);
}

TEST_CASE() {
    DoubleList<int> list;
    list.push_back(10);
    list.push_back(20);
    list.insert(2, 25);
    REQUIRE(list.size() == 3);
    REQUIRE(list.back() ==25);
}

TEST_CASE() {
    DoubleList<int> list;
    list.push_back(10);
    list.push_back(20);
    list.pop_front();
    REQUIRE(list.size() == 1);
    REQUIRE(list.front() == 20);
}

TEST_CASE() {
    DoubleList<int> list;
    list.push_back(10);
    list.push_back(20);
    list.pop_back();
    REQUIRE(list.size() == 1);
    REQUIRE(list.back() == 10);
}

TEST_CASE() {
    DoubleList<int> list;
    list.push_back(10);
    list.push_back(20);
    list.push_back(10);
    list.remove(10);
    REQUIRE(list.size() == 1);
    REQUIRE(list.front() == 20);
}

TEST_CASE() {
    DoubleList<int> list;
    bool exceptionThrown = false;
    try {
        list.front();
    } catch (const std::underflow_error&) {
        exceptionThrown = true;
    }
    REQUIRE(exceptionThrown);
}

TEST_CASE() {
    DoubleList<int> list;
    bool exceptionThrown = false;
    try {
        list.back();
    } catch (const std::underflow_error&) {
        exceptionThrown = true;
    }
    REQUIRE(exceptionThrown);
}

TEST_CASE() {
    DoubleList<int> list;
    list.push_back(10);
    list.push_back(20);
    list.clear();
    REQUIRE(list.empty());
}

TEST_CASE() {
    OneList<int> list;
    for (int i = 0; i < 100; ++i) {
        list.push_back(i);
    }
    REQUIRE(list.size() == 100);
}

TEST_CASE() {
    OneList<int> list;
    for (int i = 0; i < 100; ++i) {
        list.push_back(i);
    }
    for (int i = 0; i < 100; ++i) {
        list.pop_back();
    }
    REQUIRE(list.empty());
}

TEST_CASE() {
    OneList<int> list;
    bool exceptionThrown = false;
    try {
        list.pop_front();
    } catch (const std::underflow_error&) {
        exceptionThrown = true;
    }
    REQUIRE(exceptionThrown);
}

TEST_CASE() {
    OneList<int> list;
    bool exceptionThrown = false;
    try {
        list.pop_back();
    } catch (const std::underflow_error&) {
        exceptionThrown = true;
    }
    REQUIRE(exceptionThrown);
}

TEST_CASE() {
    OneList<int> list;
    bool exceptionThrown = false;
    try {
        list.remove(10);
    } catch (const std::out_of_range&) {
        exceptionThrown = true;
    }
    REQUIRE(exceptionThrown == false);
}

TEST_CASE() {
    OneList<int> list;
    bool exceptionThrown = false;
    try {
        list.insert(1, 10);
    } catch (const std::out_of_range&) {
        exceptionThrown = true;
    }
    REQUIRE(exceptionThrown);
}

TEST_CASE() {
    OneList<int>* list = new OneList<int>();
    list->push_back(10);
    list->push_back(20);
    delete list;
    REQUIRE(true);  
}
