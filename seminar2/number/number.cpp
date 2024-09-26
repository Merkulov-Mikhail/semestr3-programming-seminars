/*
    Класс Number - класс положительных больших чисел

    Большое число будет храниться в динамическом массиве data.
    Каждый элемент этого массива содержит разряд числа в 100-ричной системе счисления (так как base = 100).
    По сути, каждый элемент data хранит две цифры числа в десятичной записи.

    Значение 100 для системы счисления выбрано для того, чтобы задача была не такой сложной.
    Если выбрать значения базы 256 (максимально эффективное использование памяти для типа char),
    то алгоритм печати на экран усложнится. Наиболее эффективный вариант - использование 64 битных чисел
    (то есть uint64_t вместо char) и базы 2^64, но это бы ещё сильнее усложнило эту задачу.

    data - указатель, на элементы, хранящиеся в куче.
    capacity - размер массива data.
    size - сколько ячеек занимет число в массиве data, size <= capacity.

    Для удобства разряды числа хранятся в обратном порядке (это упрощает многие алгоритмы с такими числами).
    апример, число 12345678 соответствует массиву:

        {78, 56, 34, 12}

*/

#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <string.h>

class Number
{
private:
    static const int sBase = 100;
    std::size_t mSize;
    std::size_t mCapacity;
    unsigned char* mData;

public:

    Number(int a)
    {
        // Находим размер необходимой памяти под это число
        int temp = a;
        mCapacity = 0;
        while (temp != 0)
        {
            temp /= sBase;
            mCapacity += 1;
        }

        // Отдельно обрабатываем случай, когда число равно 0
        if (mCapacity == 0)
            mCapacity = 1;

        // Выделяем память и записывем число a в массив mData
        mData = new unsigned char[mCapacity];

        for (int i = 0; i < mCapacity; ++i)
        {
            mData[i] = a % sBase;
            a /= sBase;
        }

        // В данном случае размер будет равен вместимости
        mSize = mCapacity;
    }

    Number() {

        mCapacity = 1;
        mSize = 1;
        printf("asdasd");
        // mData = new unsigned char[mCapacity];
        std::cout << "asdqweqweqwe" << std::endl;
        // mData[0] = 0;
    }

    Number(const Number& n) {

        mSize = n.mSize;
        mCapacity = n.mCapacity;
        mData = new unsigned char[mCapacity];

        memcpy(mData, n.mData, mCapacity);
    }

    Number(const char* str) {

        int strLen = strlen(str);
        mCapacity = strLen / 2 + strLen % 2;
        mSize = 0;

        mData = new unsigned char[mCapacity];

        for ( int i = strLen - 1; i > -1; i -= 2 ) {
            if (i == 0) {
                mData[mSize++] = str[i] - '0';
            }
            else {
                mData[mSize++] = str[i] - '0' + (str[i - 1] - '0') * 10;
            }
        }
    }

    Number& operator=(const Number& right) {
        delete [] mData;
        mCapacity = right.mCapacity;
        mSize = right.mSize;
        memcpy(mData, right.mData, mCapacity);
        return *this;
    }


    ~Number()
    {
        delete [] mData;
    }

    Number operator+(const Number& n) const {
        Number tmp;
        if (n.mCapacity > mCapacity)
            tmp.mCapacity = n.mCapacity + 1;
        else
            tmp.mCapacity = mCapacity + 1;

        tmp.mSize = 0;
        tmp.mData = new unsigned char[tmp.mCapacity];
        memset(tmp.mData, 0, tmp.mCapacity);

        for ( ; tmp.mSize < tmp.mCapacity; tmp.mSize++ ) {
            if (tmp.mSize != 0)
                std::cout << tmp << std::endl;
            if (tmp.mSize < n.mCapacity)
                tmp.mData[tmp.mSize] += n.mData[tmp.mSize];
            if (tmp.mSize < mCapacity)
                tmp.mData[tmp.mSize] += mData[tmp.mSize];

//            std::cout << "hmmm " << static_cast<int>(tmp.mData[tmp.mSize]) << std::endl;
            if (tmp.mData[tmp.mSize] >= sBase) {
                tmp.mData[tmp.mSize + 1] += tmp.mData[tmp.mSize] / sBase;
                tmp.mData[tmp.mSize]      = tmp.mData[tmp.mSize] % sBase;
            }
        }
        // std::cout << tmp.mSize << " " << tmp.mCapacity << std::endl;
        // printf("%u %d %d %d\n", tmp.mData[0], tmp.mData[1], tmp.mData[2], tmp.mData[3]);
        // std::cout << (tmp.mData[tmp.mSize] == 0) << " " << tmp.mSize << std::endl;
        while (tmp.mData[tmp.mSize - 1] == 0 && tmp.mSize > 1) {
            // std::cout << tmp.mSize << " " << (!tmp.mData[tmp.mSize] && tmp.mSize > 1) << " " << tmp.mData[tmp.mSize] << std::endl;
            tmp.mSize--;
        }

        return tmp;
    }

    Number& operator+=(const Number& n) {
        *this = *this + n;
        return *this;
    }

    friend std::ostream& operator<<(std::ostream& stream, const Number& num);
};

std::ostream& operator<<(std::ostream& stream, const Number& num)
{
    // Печатаем самый большой разряд
    stream << static_cast<int>(num.mData[num.mSize - 1]);

    // Печатаем остальные разряды с заполнением нулями до 2-х цифр
    // setfill и setw используются для того, чтобы замостить ноликом, элемент будет меньше чем 10.
    for (std::size_t i = 0; i < num.mSize - 1; ++i)
        stream << std::setfill('0') << std::setw(2) << static_cast<int>(num.mData[num.mSize - 2 - i]);

    return stream;
}

int main()
{
    Number x = "0";
    Number y = 1;
    Number tmp;
    int n = 1000;
    std::cout << n << "i was herer" << std::endl;
    while (n--) {
        tmp = y;
        std::cout << tmp << std::endl << x << std::endl << y << std::endl;
        y += x;
        std::cout << x << std::endl << y << std::endl;
        x = tmp;
        std::cout << x << std::endl << y << std::endl;
    }
}
