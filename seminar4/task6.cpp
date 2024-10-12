#include <iostream>
#include <vector>
#include <array>
#include <string>
#include <utility>
using std::cout, std::endl;

template <typename T, typename U>
std::ostream& operator<<(std::ostream& out, const std::pair<T, U>& p)
{
    out << "(" << p.first << ", " << p.second << ")";
    return out;
}

template <typename T>
std::ostream& operator<<(std::ostream& out, const std::vector<T>& v)
{
    out << "[";
    for (size_t i = 0; i < v.size() - 1; ++i)
        out << v[i] << ", ";

    if (!v.empty())
    {
        out << v.back();
    }
    out << "]";
    return out;
}

template <typename T>
std::vector<std::pair<typename T::value_type, typename T::value_type>> pairing(const T& smth) {
    std::vector<std::pair<typename T::value_type, typename T::value_type>> ans;

    for (auto i = smth.begin(); i != smth.end(); i++) {
        std::cout << "pairing" << i - smth.begin() << "\n";
        std::pair<typename T::value_type, typename T::value_type> currPair;
        currPair.first = *i++;
        if (i != smth.end()) {
            currPair.second = *i;
        }
        ans.push_back(currPair);
    }

    return ans;
}


int main()
{
    std::vector v {10, 20, 30, 40, 50, 60};
    cout << pairing(v) << endl;


    std::array<std::string, 7> a {"cat", "dog", "mouse", "elephant", "tiget", "axolotl", "wolf"};
    cout << pairing(a) << endl;


    std::string s {"Cats and dogs!"};
    cout << pairing(s) << endl;
}


/*
    Программа должна напечатать:

    [(10, 20), (30, 40), (50, 60)]
    [(cat, dog), (mouse, elephant), (tiget, axolotl), (wolf, )]
    [(C, a), (t, s), ( , a), (n, d), ( , d), (o, g), (s, !)]
*/
