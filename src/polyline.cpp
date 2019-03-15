#include "polyline.h"

Polyline::Polyline( std::vector<Line*> lines,bool is_polygon, 
    bool floodfill , std::vector<POINT> p, const Color &color)
    : Shape(color, floodfill, is_polygon)
{ 
    this->lines = lines; 
    this->p_floodfill = p;
}

Polyline::Polyline( std::vector<POINT> points, bool is_polygon,
     bool floodfill , std::vector<POINT> p,  const Color &color)
    : Shape(color, floodfill, is_polygon)
{ 
    POINT aux;
    if ( !points.empty() )
        aux = points[0];

    for (std::vector<POINT>::iterator it = points.begin()+1;
         it != points.end();
         it++)
    {   
        lines.push_back(new Line(aux, *it, color));
        aux = *it;
    }

    this->p_floodfill = p;
}

Polyline::~Polyline()
{}

void Polyline::draw()
{
    std::vector<POINT> aux;
    for (unsigned int i=0; i < lines.size(); i++)
    {
        this->lines[i]->draw();
        aux = lines[i]->get_pixels();
        for(std::vector<POINT>::iterator it = aux.begin(); it != aux.end(); ++it)
            this->pixels.push_back(*it);
    }

}

std::string Polyline::to_string()
{  return "I'm a polyline and my color is " + color.to_string() + "\n"; }

std::vector<POINT> Polyline::get_pfloodfill(){
    return p_floodfill;
}
// void Polyline::set_pfloodfill(POINT p){
//     this->p_floodfill = p;
// }

Color& Polyline::get_fill()
{ return this->fill_color;}

void Polyline::set_fill (const Color & color)
{ this->fill_color = color; }

#include <iostream>
std::vector<POINT> Polyline::scanline(int height)
{
    std::vector<POINT> points;
    std::vector<std::list<Edge>> et;
    for (auto i =0; i <= height+1 ; i++)
        et.push_back({});
    
    // initial y - init with a great value
    int y = 90000;
    
    // build et
    int etCount = 0;
    for (Line *l : this->lines){
        
        Edge *edg = new Edge(l);
        int pos = edg->yMin;
        
        // update initial y
        if (pos < y) y = pos;
        
        std::list<Edge>::iterator it = et[pos].begin();
        while (it != et[pos].end() && (it->xMin < edg->xMin) ) ++it;
        
        et[pos].insert(it, *edg);
        etCount++;
    }

    // Initialize AET to empty
    std::list<Edge> aet;
    while ( !aet.empty() || etCount != 0 ){
       
        // add current et's edges to aet 
        std::list<Edge>::iterator it = aet.begin();
        for (Edge e : et[y] ){
            // std::cout << e.to_string();
            while (it != aet.end() && it->xMin <= e.xMin) it++;
            aet.insert(it, e);
            etCount--;
        }

        // std::cout << "ordem dos x das arestas no aet\n";
        // for ( auto i = aet.begin(); i != aet.end(); i++ )
        // {   std::cout << "[" << i->xMin << "] ";
        // }
        std::cout << std::endl;
        // draw
        for ( auto i = aet.begin(); i != aet.end(); i++ )
        {
            Edge &e1 = *i;
            i++;
            Edge &e2 = *i;
            //std::cout << "vou pintar do [" << e1.xMin+1 << "," << y << "]"
            //<< " até [" << e2.xMin+1 << "," << y << "]\n";
            for (int i=e1.xMin+1; i<e2.xMin; i++)
                points.push_back(POINT{i, y});
            
        }

        // update y and remove used edges
        y++;
        it = aet.begin();
        while (it != aet.end()){
            if (it->yMax <= y)
                it = aet.erase(it);
            else it++;
        }

        // update x values 
        for (Edge &e : aet) e.increment();
    }

    return points;
}