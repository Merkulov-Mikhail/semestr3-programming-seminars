#include <iostream>
#include <assert.h>

struct Book {
    char title[100];
    int pages;
    float prices;
};


void addPrice(Book& tmp, float x) {
    tmp.prices += x;
}

bool isExpensive(const Book& tmp) {
    return tmp.prices > 1000;
}

namespace myspace {

    void printNTimes(const char* str, int n = 10) {

        assert(str);

        for ( ; n > 0; n-- )
            std::cout << str;
    }

}

long long int cubeV(int n) {
    return n * n * n;
}

void cubeR(int& n) {
    n *= n * n;
}

int main() {
    myspace::printNTimes("1", 10);
    std::cout << std::endl;
    std::cout << cubeV(5) << std::endl;
    int someInt = 2;
    cubeR(someInt);
    std::cout << someInt << std::endl;

    Book someBook = {"asd", 10, 1000};
    std::cout << isExpensive(someBook) << "\n";

    addPrice(someBook, 1);
    std::cout << isExpensive(someBook) << "\n";
}
