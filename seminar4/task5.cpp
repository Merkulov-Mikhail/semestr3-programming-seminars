#include <vector>
#include <iostream>
#include <string>

template <typename T>
T maximum(std::vector<T> st) {
    // i guess that st.size > 0
    T mx = st[0];

    for (auto a: st) {
        if (a > mx) {
            mx = a;
        }
    }
    return mx;
}


int main() {
    std::vector<int> a {1,2 , 3 ,4, 5, 6, 7, 11, 9};
    std::cout << maximum(a) << "\n";

    std::vector<float> b{1.2, 1.3, 1.4, 1.1, 5.1};
    std::cout << maximum(b) << "\n";

    std::vector<std::string> c{"15", "16", "17", "19"};
    std::cout << maximum(c) << "\n";

    std::vector<std::pair<int, int>> d{{13, 14}, {14, 15}, {15, 16}, {15, 17}};
    std::pair<int, int> mx = maximum(d);
    std::cout << mx.first << " " << mx.second << "\n";
}
