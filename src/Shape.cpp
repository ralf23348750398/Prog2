#pragma once

#include "Shape.h"
#include "ViewPortGL.h"

Shape::Shape() : red(255), green(255), blue(255) {}
Shape::Shape(int red, int green, int blue) {
	this->red = red;
	this->green = green;
	this->blue = blue;
}
