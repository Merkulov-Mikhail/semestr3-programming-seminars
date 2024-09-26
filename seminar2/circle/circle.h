#include "point.hpp"


class Circle {
    private:
        Point center;
        float radius;

    public:
        Circle ();
        Circle (const Point& acenter, float aradius);

        Circle (const Circle& circle);

        float getRadius() const;
        void setRadius(float rad);

        Point getCenter() const;
        void setCenter(const Point pnt);

        float getArea() const;
        float getDistance(const Point& p) const;

        bool isColliding(const Circle& p) const;

        void move(const Point& p);

};
