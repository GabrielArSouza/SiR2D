#include "edge.h"

Edge::Edge( Line *line )
{

    POINT a = line->get_p1();
    POINT b = line->get_p2();

    int deltaY = 0;
    int deltaX = 0;

    // find the yMin, yMax and deltaY
    if (a.y <= b.y){ 
        this->yMin = a.y;
        this->yMax = b.y;
        this->xMin = a.x;

        deltaX = b.x - a.x;
        deltaY = b.y - a.y;
    }else {
        this->yMin = b.y;
        this->yMax = a.y;
        this->xMin = b.x;

        deltaX = a.x - b.x;
        deltaY = a.y - b.y;
    }

    this->x_remains = 0;

    if (deltaX != 0 && deltaY != 0){
        int gcd = std::__gcd(deltaX, deltaY);
        m_denominator = abs(deltaY / gcd);
        m_whole = deltaX/deltaY;
        m_remains = (deltaX % deltaY)/gcd;
    } else {
        m_denominator = 0;
        m_whole = 0;
        m_remains = 0;
    }
}

Edge::~Edge(){}

void Edge::increment()
{
    if (m_whole == 0 && m_remains == 0) return;

    xMin += m_whole;
    x_remains += m_remains;
    if (abs(x_remains) >= m_denominator){
        if (x_remains > 0){
            x_remains -= m_denominator;
            xMin++;
        }else {
            x_remains += m_denominator;
            xMin--;
        }
    }
}

std::string  Edge::to_string ()
{
    std::string str = "Edge [xMin, yMin]:";
    str += "[" + std::to_string(xMin); 
    str += "," + std::to_string(yMin);
    str += "]\n";
    str += "yMax = " + std::to_string(yMax) + "\n";

    return str; 
}