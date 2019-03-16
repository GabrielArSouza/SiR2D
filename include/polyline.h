#ifndef _POLYLINE_H_
#define _POLYLINE_H_

#include <vector>
#include <list>

#include "shape.h"
#include "line.h"
#include "edge.h"

/**
 * @brief A class for polyline
 * 
 */
class Polyline : public Shape{

private:
    std::vector<Line*> lines; //<! the polyline's lines vector 
    Color fill_color; //<! the fill color of polyline
    std::vector<POINT> p_floodfill; //<! the points for flood fill algorithm

public:

    /**
     * @brief Construct a new Polyline object
     * 
     * @param lines    The lines vector
     * @param is_polygon  if is a polygon
     * @param floodfill   if use a flood fill algorithm
     * @param p           the vector of points for flood fill
     * @param color       the border color of polyline
     */
    Polyline( std::vector<Line*> lines,bool is_polygon = false, 
        bool floodfill = false, std::vector<POINT> p = {POINT{0,0}}, 
        const Color &color = Color::BLACK);

    /**
     * @brief Construct a new Polyline object
     * 
     * @param points   the points vector for polyline
     * @param is_polygon  if is a polygon
     * @param floodfill   if use a flood fill algorithm
     * @param p           the vector of points for flood fill
     * @param color       the border color of polyline
     */
    Polyline( std::vector<POINT> points, bool is_polygon = false, 
        bool floodfill = false, std::vector<POINT> p = {POINT{0,0}}, 
        const Color &color = Color::BLACK);

    /**
     * @brief Destroy the Polyline object
     * 
     */
    ~Polyline();

    /**
     * @brief draw a polyline
     * 
     */
    void draw();

    /**
     * @brief class description
     * 
     * @return std::string the description string
     */
    std::string to_string();

    /**
     * @brief Get the pfloodfill object
     * 
     * @return std::vector<POINT> the point vector
     */
    std::vector<POINT> get_pfloodfill();
  
    /**
     * @brief Get the fill object
     * 
     * @return Color& the color of polyline
     */
    Color& get_fill();

    /**
     * @brief Set the fill object
     * 
     * @param color the new color 
     */
    void set_fill (const Color & color);

    /**
     * @brief Get the lines object
     * 
     * @return std::vector<Shape*> all lines of polyline 
     */
    std::vector<Shape*> get_lines();

    /**
     * @brief scanline algorithm
     * 
     * @param heght the canvas's height 
     * @return std::vector<POINT> 
     */
    std::vector<POINT> scanline(int heght);

};

#endif