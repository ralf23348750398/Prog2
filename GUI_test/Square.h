#pragma once

#include "..\src\Shape.h"
//#include <time.h>
//#include <stdlib.h>

//using namespace std;

class Square : public Shape {
private:
	
public:
	Square(int red, int green, int blue);
	void prepare(ViewPortGL& vp, int centerX, int centerY, int size);
};