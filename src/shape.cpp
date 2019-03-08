#include "shape.h"

Shape::Shape (const Color &color)
{ this->color = color; }

Shape::~Shape (){}

#include <iostream>
void Shape::draw(){
    std::cout << "chamou o draw do pai\n";
}

Color * Shape::get_color ()
{ return &color; }

void Shape::set_color (const Color &color)
{ this->color = color; }

std::vector<POINT> Shape::get_pixels ()
{ return this->pixels;}

std::string Shape::to_string(){return "I'm a shape\n";}