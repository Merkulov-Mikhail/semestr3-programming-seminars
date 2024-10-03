#include <iostream>
#include <string>

int pos = 1;

int p(std::string& str) {
    int ans = 0;
    while ('0' <= str[pos] && str[pos] <= '9') {
        ans *= 10;
        ans += str[pos] - '0';
        pos++;
    }
    return ans;
}

int sm(std::string& str) {

    if (str.size() < 2)
        throw std::invalid_argument(str);

    if (str[0] != '[' || str[str.size() - 1] != ']')
        throw std::invalid_argument(str);

    int ans = 0;
    int curr = 0;
    while (pos < str.size() - 1) {
        curr = p(str);
        if (str[pos] != ',' && str[pos + 1] != ' ' && pos < str.size() - 1) {
            throw std::invalid_argument("lol, you died");
        }
        ans += curr;
        pos += 2;
    }
    return ans;
}


int main() {
    std::string b{"[123, 345, , , 123]"};
    std::string& r = b;
    std::cout << sm(r);
}
