#ifndef _EDGE_H_
#define _EDGE_H_

#include "line.h"
#include <cstdlib>
#include <algorithm> 
#include <string>

class Edge {

public:
    
    int yMin;
    int yMax;
    int xMin;

    int x_remains;

	int m_whole;
	int m_denominator;
	int m_remains;
    
    Edge( Line *line );

    ~Edge();

    void increment();

    std::string to_string ();
};

#endif