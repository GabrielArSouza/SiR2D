#ifndef _CIRCLE_H_
#define _CIRCLE_H_

#include "shape.h"

class Circle : public Shape{

private:

    //<! the radius of circle
    int radius;

    //<! the mid point of circle
    POINT center;

public:

    /**
     * @brief Construct a new Circle object
     * 
     * @param radius the radius
     */
    Circle(POINT center, int radius);

    /**
     * @brief Construct a new Circle object
     * 
     * @param radius the radius
     * @param color the color border and backgroud
     */
    Circle(POINT center, int radius, const Color &color);

    /**
     * @brief Destroy the Circle object
     * 
     */
    ~Circle();

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

    std::string to_string();
};

#endif