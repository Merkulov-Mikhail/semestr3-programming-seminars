#include <iostream>
#include <vector>

std::vector<std::pair<int, int>> factorization(int n) {
    std::vector<std::pair<int, int>> st;
    int a = 2;
    int cnt = 0;
    while (n != 1) {
        cnt = 0;
        while (n % a == 0){
            cnt++;
            n /= a;
        }

        if (cnt) {
            st.push_back(std::pair<int, int>{a, cnt});
        }
        a++;
    }
    return st;
}


int main() {
    std::vector<std::pair<int, int>> a = factorization(626215995);
    for (auto i: a) {
        std::cout << i.first << " " << i.second << "\n";
    }
}
