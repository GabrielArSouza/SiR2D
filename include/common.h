#ifndef _COMMON_H_
#define _COMMON_H_


#define MAX_COLOR_VALUE 255
#define MIN_COLOR_VALUE 0
#define VALUES_PER_PIXEL 3
#define OUTPUT_EXTENSION ".ppm"
#define OUTPUT_INDEX "P3"

typedef struct POINT {
    
    int x,y;

    bool operator== (POINT &rhs)
    {
        if ((x == rhs.x) && (y == rhs.y))
            return true;
        return false;
    }
    POINT & operator= (const POINT &rhs)
    { x = rhs.x; y = rhs.y; return *this;}


} POINT;

#endif