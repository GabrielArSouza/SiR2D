#ifndef _EDGE_H_
#define _EDGE_H_

#include "line.h"
#include <cstdlib>
#include <algorithm> 
#include <string>

/**
 * @brief A class for edge
 * 
 */
class Edge {

public:
    
    int yMin;
    int yMax;
    int xMin;

    int x_remains;

	int m_whole;
	int m_denominator;
	int m_remains;
    
    /**
     * @brief Construct a new Edge object
     * 
     * @param line the polyline's line
     */
    Edge( Line *line );

    /**
     * @brief Destroy the Edge object
     * 
     */
    ~Edge();

    /**
     * @brief increment x
     * 
     */
    void increment();

    /**
     * @brief description of class
     * 
     * @return std::string a description string
     */
    std::string to_string ();
};

#endif