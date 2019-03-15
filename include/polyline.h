#ifndef _POLYLINE_H_
#define _POLYLINE_H_

#include <vector>
#include <list>

#include "shape.h"
#include "line.h"
#include "edge.h"



class Polyline : public Shape{

private:
    std::vector<Line*> lines;
    Color fill_color;
    std::vector<POINT> p_floodfill;

public:
    Polyline( std::vector<Line*> lines,bool is_polygon = false, 
        bool floodfill = false, std::vector<POINT> p = {POINT{0,0}}, 
        const Color &color = Color::BLACK);

    Polyline( std::vector<POINT> points, bool is_polygon = false, 
        bool floodfill = false, std::vector<POINT> p = {POINT{0,0}}, 
        const Color &color = Color::BLACK);

    ~Polyline();

    void draw();

    std::string to_string();

    std::vector<POINT> get_pfloodfill();
  
    Color& get_fill();

    void set_fill (const Color & color);

    std::vector<Shape*> get_lines();

    std::vector<POINT> scanline(int heght);

};

#endif