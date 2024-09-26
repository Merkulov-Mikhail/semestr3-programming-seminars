#include "cmath"
#include "circle.h"


Circle::Circle () {
    center.setX(0);
    center.setY(0);
    radius = 1;
}

Circle::Circle (const Point& acenter, float aradius) {
    center = acenter;
    radius = aradius;
}

Circle::Circle (const Circle& circle) {
    center = circle.center;
    radius = circle.radius;
}

float Circle::getRadius() const {
    return radius;
}

void Circle::setRadius(float rad) {
    radius = 0;
    if (rad > 0)
        radius = rad;
}

Point Circle::getCenter() const {
    return center;
}

void Circle::setCenter(const Point pnt) {
    center = pnt;
}

float Circle::getArea() const {
    return M_PI * radius * radius;
}

float Circle::getDistance(const Point& p) const {
    float dist = center.distance(p);
    if (dist < radius) {
        return 0;
    }
    return dist - radius;
}

bool Circle::isColliding(const Circle& p) const {
    float dist = center.distance(p.center);

    if (dist <= p.radius + radius)
        return true;

    return false;
}

void Circle::move(const Point& p) {
    center = center + p;
}
