#include <iostream>

template <typename T, int b>
class Modular {
private:
    T   value;
    int mod = b;
public:
    Modular(T val): value(val % b + b * (val < 0)) {}

    template <int c>
    Modular& operator=(const Modular<T, c>& tmp) {
        value = tmp.get();
        mod = c;

        if (value < 0)
            value += mod;

        return *this;
    }

    Modular operator+(T tmp) const {
        Modular<T, b> t = *this;
        t.value += tmp;
        t.value %= t.mod;

        if (t.value < 0)
            t.value += t.mod;

        return t;
    }

    Modular operator-(T tmp) const {
        Modular<T, b> t = *this;
        t.value -= tmp;
        t.value %= t.mod;

        if (t.value < 0)
            t.value += t.mod;

        return t;
    }

    Modular operator*(T tmp) const {
        Modular<T, b> t = *this;
        t.value *= tmp;
        t.value %= t.mod;

        if (t.value < 0)
            t.value += t.mod;

        return t;
    }

    Modular operator+(const Modular<T, b>& tmp) const {
        return *this + tmp.value;
    }

    Modular operator-(const Modular<T, b>& tmp) const {
        return *this - tmp.value;
    }

    Modular operator*(const Modular<T, b>& tmp) const {
        return *this * tmp.value;
    }

    Modular operator-() const {
        Modular<T, b> tmp{0};
        return tmp - *this;
    }

    T get() const {
        return value;
    }

};

template <typename T, int b>
std::ostream& operator<<(std::ostream& out, const Modular<T, b> m) {
    out << m.get();
    return out;
}

int main() {
    Modular<int, 7> a(10);
    std::cout << a << std::endl;
    a = a + 8;
    a = a * 4;
    std::cout << a << std::endl;
    Modular<int, 7> b(a);
    b = b + 2;
    a = a - b;
    std::cout << a << std::endl;

    std::cout << -2 % 7;
    // Modular<short, 3> c(a);
    // std::cout << c << std::endl;
}
