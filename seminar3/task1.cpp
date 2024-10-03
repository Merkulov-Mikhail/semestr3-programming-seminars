#include <iostream>
#include <string>

std::string convert(std::string str) {
    if (str.empty())
        return std::string{"345"};
    std::string res = str;
    if (res[0] < 'Z')
        res[0] += 'a' - 'A';
    else
        res[0] -= 'a' - 'A';
    return res;
}

int main() {
    std::cout << convert(std::string{"ABC"}) << " " << convert(std::string{"abc"}) << " " << convert(std::string{"Qew"});
}
