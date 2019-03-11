#ifndef _POLYLINE_H_
#define _POLYLINE_H_

#include <vector>

#include "shape.h"
#include "line.h"

class Polyline : public Shape{

private:
    std::vector<Shape*> lines;
    Color fill_color;
    std::vector<POINT> p_floodfill;

public:
    Polyline( std::vector<Shape*> lines,bool is_polygon = false, 
        bool floodfill = false, std::vector<POINT> p = {POINT{0,0}}, 
        const Color &color = Color::BLACK);

    Polyline( std::vector<POINT> points, bool is_polygon = false, 
        bool floodfill = false, std::vector<POINT> p = {POINT{0,0}}, 
        const Color &color = Color::BLACK);

    ~Polyline();

    void draw();

    std::string to_string();

    std::vector<POINT> get_pfloodfill();
    // void set_pfloodfill(POINT p);

    Color& get_fill();

    void set_fill (const Color & color);

};

#endif