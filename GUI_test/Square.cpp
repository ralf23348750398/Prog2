#include "Square.h"

//srand(time(NULL));

Square::Square(int red, int green, int blue) : Shape(red, green, blue) {}

void Square::prepare(ViewPortGL& vp1, int centerX, int centerY, int size) {
    int length = 2 * size;
    int x = centerX - size;
    int y = centerY - size;

    vp1.prepareBlock(x, y, length, length, red, green, blue);
}

