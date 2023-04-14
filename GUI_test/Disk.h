#pragma once

#include <cmath> //used for sqrt() - calculation of the square root

#include "..\src\Shape.h"

class Disk : public Shape {
private:

public:
	Disk(int red = 0, int green = 0, int blue = 0) : Shape(red, green, blue) {}
	void prepare(ViewPortGL& vp, int centerX, int centerY, int radius);

};