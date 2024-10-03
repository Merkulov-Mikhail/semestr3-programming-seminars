#include <iostream>
#include <string>


void truncateToDot(std::string& str) {
    if (str.find(".") + 1 == 0)
        str.resize(0);
    else
        str.resize(str.find("."));
    str.shrink_to_fit();
}

int main () {
    std::string s{"1234.5"};
    truncateToDot(s);
    std::cout << s;
}

