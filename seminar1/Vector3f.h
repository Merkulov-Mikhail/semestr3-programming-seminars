#ifndef _VECTOR3F
#define _VECTOR3F

#include <iostream>
#include <cmath>

struct Vector3f {
    float x, y, z;
};


Vector3f operator+( Vector3f a,  Vector3f b) {
    Vector3f tmp = {a.x + b.x , a.y + b.y, a.z + b.z};
    return tmp;
}

Vector3f operator-( Vector3f a,  Vector3f b) {
    Vector3f tmp = {a.x - b.x , a.y - b.y, a.z - b.z};
    return tmp;
}

Vector3f operator*( Vector3f a, int b) {
    Vector3f tmp = {a.x * b , a.y * b, a.z * b};
    return tmp;
}

Vector3f operator*(int b,  Vector3f a) {
    return a * b;
}

int operator*( Vector3f a,  Vector3f b) {
    return a.x * b.x + a.y * b.y + a.z * b.z;
}

Vector3f operator-(Vector3f a) {
    Vector3f tmp = {-a.x , -a.y, -a.z};
    return tmp;
}

Vector3f operator+(Vector3f a) {
    return a;
}

bool operator==( Vector3f a,  Vector3f b) {
    if (a.x == b.x && a.y == b.y && a.z == b.z)
        return true;
    return false;
}

bool operator!=( Vector3f a,  Vector3f b) {
    return !(a == b);
}

Vector3f operator+=(Vector3f& a,  Vector3f b) {
    a.x += b.x;
    a.y += b.y;
    a.z += b.z;
    return a;
}

Vector3f operator-=(Vector3f& a,  Vector3f b) {
    Vector3f tmp = -b;
    a += tmp;
    return a;
}

Vector3f operator*=(Vector3f& a, float x) {
    a.x *= x;
    a.y *= x;
    a.z *= x;
    return a;
}

Vector3f operator/=(Vector3f& a, float x) {
    if (x == 0) {
        a.x = 0;
        a.y = 0;
        a.z = 0;
        return a;
    }

    a.x /= x;
    a.y /= x;
    a.z /= x;
    return a;
}

std::istream& operator>>(std::istream& c, Vector3f a) {
    std::cin >> a.x >> a.y >> a.z;
    return c;
}

std::ostream& operator<<(std::ostream& c, Vector3f a) {
    std::cout << "(" << a.x << ", " << a.y << ", " << a.z << ")";
    return c;
}

float squaredNorm(const Vector3f a) {
    return a.x * a.x + a.y * a.y + a.z * a.z;
}

float norm(const Vector3f a) {
    return std::sqrt(squaredNorm(a));
}

void normalize(Vector3f& a) {
    a /= norm(a);
}

#endif // _VECTOR3F

