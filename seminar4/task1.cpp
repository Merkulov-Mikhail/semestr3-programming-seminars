#include <vector>
#include <iostream>


int sumEven(const std::vector<int>& st) {
    int ans = 0;
    for (auto i: st)
        if (i % 2 == 0)
            ans += i;
    return ans;
}



int main() {
    std::cout << sumEven(std::vector{1, 2, 3, 4, 5, 6, 7, 8, 9});
}
