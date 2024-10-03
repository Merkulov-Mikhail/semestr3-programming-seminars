#include <iostream>
#include <string>

std::string operator*(std::string str, int n) {
    std::string res{};
    for (;n;n--) {
        res += str;
    }
    return res;
}

int main() {
    std::cout << std::string{"123"} * 5;
}
