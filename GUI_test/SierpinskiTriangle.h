#pragma once

#include "..\src\Shape.h"

class SierpinskiTriangle {
public:
	void e_2_3_sierpinski_triangle(ViewPortGL& vp1);
private:
	void recursion_problem(ViewPortGL& vp1, int x1, int y1, int x2, int y2, int x3, int y3, int depth);
};