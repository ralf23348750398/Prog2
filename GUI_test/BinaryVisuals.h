#pragma once

#include <cmath> //used for pow(a, b) = a^b

#include "ViewPortGL.h"
#include "Shape.h"

using namespace std;

class BinaryVisuals {

public:
	static void prepareRepresentation(ViewPortGL& vp1, unsigned char value, int xk, int yk, int width, int height);
	static void prepareRepresentation(ViewPortGL& vp1, unsigned int value, int xk, int yk, int width, int height);
	unsigned int exchangeHalves(unsigned int value, int fromBit, int toBit);
	unsigned int reverse(unsigned int b);

private:
	static void prepareBit(ViewPortGL& vp, int xk, int yk, int width, int height, bool isOne);
	static const int xpadding = 10;
};