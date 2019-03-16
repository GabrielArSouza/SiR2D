#ifndef _CIRCLE_H_
#define _CIRCLE_H_

#include "shape.h"

/**
 * @brief A class for circle, extends Shape
 * 
 */
class Circle : public Shape{

private:

    //<! the radius of circle
    int radius;

    //<! the mid point of circle
    POINT center;

    //<! the color fill of circle
    Color fill;

    //<! points for floodfill algorithm
    std::vector<POINT> p_floodfill;

public:

    /**
     * @brief Construct a new Circle object
     * 
     * @param center   The center point
     * @param radius   the radius of circle
     * @param floodfill  if use floodfill
     * @param p the vector points for flood fill
     */
    Circle(POINT center = POINT{0,0}, int radius = 0, 
           bool floodfill = true, std::vector<POINT> p = {POINT{0,0}});

    /**
     * @brief Construct a new Circle object
     * 
     * @param center   The center point
     * @param radius   the radius of circle
     * @param color    the color of border
     * @param floodfill  if use floodfill
     * @param p the vector points for flood fill 
     */
    Circle(POINT center, int radius, const Color &color, 
           bool floodfill = true, std::vector<POINT> p = {POINT{0,0}});


   /**
     * @brief Construct a new Circle object
     * 
     * @param center   The center point
     * @param radius   the radius of circle
     * @param color    the color of border
     * @param fill     the color fill 
     * @param floodfill  if use floodfill
     * @param p the vector points for flood fill 
     */
    Circle(POINT center, int radius, const Color &color, const Color &fill, 
           bool floodfill = true, std::vector<POINT> p = {POINT{0,0}});

    /**
     * @brief Destroy the Circle object
     * 
     */
    ~Circle();

    /**
     * @brief overload assignment operator 
     * 
     * @param rhs   the other Circle
     * @return Circle&  the reference of new circle
     */
    Circle & operator= (const Circle &rhs);

    /**
     * @brief define the pixels from generate a circle
     */
    void draw();

    /**
     * @brief plot a octantes circle from a point of a octante
     * 
     * @param partide_point the point of a octante
     */
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

    /**
     * @brief Set the fill object
     * 
     * @param fill the new fill color
     */
    void set_fill (const Color & fill);

    /**
     * @brief the descriptions of class
     * 
     * @return std::string the string of description
     */
    std::string to_string();

    /**
     * @brief Get the points floodfill object
     * 
     * @return std::vector<POINT> the points of flood fill 
     */
    std::vector<POINT> get_pfloodfill();

    /**
     * @brief Get the fill object
     * 
     * @return Color& the fill color
     */
    Color& get_fill();
};

#endif