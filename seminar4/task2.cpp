#include <iostream>
#include <vector>

void lastDigits(std::vector<int>& st) {
    for (auto& i: st) {
        i = i % 10;
    }
}


int main() {
    std::vector<int> a {1, 2, 3, 4, 5, 6, 10, 12, 13, 14, 15};
    lastDigits(a);

    for (auto i: a) {
        std::cout << i << " ";
    }
}
