#ifndef _TRIANGLE_H_
#define _TRIANGLE_H_

#include "shape.h"
#include "line.h"

class Triangle : public Shape {

private:

    POINT p1;
    POINT p2;
    POINT p3;

public:

    Triangle(POINT p1, POINT p2, POINT p3);

    Triangle(POINT p1, POINT p2, POINT p3, const Color &color);

    ~Triangle();

    void draw();

    std::vector<POINT> get_points ();
    void set_points (POINT p1, POINT p2, POINT p3);

    std::string to_string();
};

#endif