#include <iostream>
#include <string>

std::string repeat1(const std::string str) {
    std::string res = str + str;
    return res;
}

void repeat2(std::string& str) {
    str += str;
    return;
}

void repeat3(std::string* str) {
    *str += *str;
}

std::string* repeat4(const std::string& str) {
    std::string* a = new std::string{str + str};
    return a;
}

void test1() {
    std::cout << repeat1(std::string{"1234"}) << std::endl;
}

void test2() {
    std::string a{"1234"};
    std::string& r = a;
    repeat2(r);
    std::cout << a << std::endl;
}

void test3() {
    std::string a{"1234"};
    std::string* r = &a;
    repeat3(r);
    std::cout << a << std::endl;
}

void test4() {
    std::string a{"12345"};
    std::string& r = a;
    std::cout << *repeat4(r) << std::endl;
}

int main() {
    test1();
    test2();
    test3();
    test4();
}
