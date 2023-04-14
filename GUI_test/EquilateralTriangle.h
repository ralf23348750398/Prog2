#pragma once

#include <cmath> //used for the trigonometric functions (std::sin, std::cos, std::tan)

#include "..\src\Shape.h"

using namespace std;

class EquilateralTriangle : public Shape {
private:
	void prepare(ViewPortGL& vp, int centerX, int centerY, int radius);

public:
	EquilateralTriangle(int red = 0, int green = 0, int blue = 0) : Shape(red, green, blue) {}
	void e_2_1_equilateral_triangles(ViewPortGL& vp1);
};