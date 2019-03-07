#ifndef _CIRCLE_H_
#define _CIRCLE_H_

#include "shape.h"

class Circle : public Shape{

private:

    //<! the radius of circle
    int radius;

    //<! the mid point of circle
    POINT center;

    Color fill;

public:

    /**
     * @brief Construct a new Circle object
     * 
     * @param radius the radius
     */
    Circle(POINT center = POINT{0,0}, int radius = 0);

    /**
     * @brief Construct a new Circle object
     * 
     * @param radius the radius
     * @param color the color border and backgroud
     */
    Circle(POINT center, int radius, const Color &color);

    Circle(POINT center, int radius, const Color &color, const Color &fill);

    /**
     * @brief Destroy the Circle object
     * 
     */
    ~Circle();

    Circle & operator= (const Circle &rhs);

    /**
     * @brief define the pixels from generate a circle
     */
    void draw();

    void plot_octante_circle (POINT partide_point);

    /**
     * @brief Get the radius object
     * 
     * @return int the radius of circle
     */
    int get_radius ();

    /**
     * @brief Set the radius object
     * 
     * @param radius the new radius of circle
     */
    void set_radius (int radius);

    void set_fill (const Color & fill);

    std::string to_string();
};

#endif