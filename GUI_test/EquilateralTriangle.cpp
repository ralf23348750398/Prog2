#include "EquilateralTriangle.h"

void EquilateralTriangle::prepare(ViewPortGL& vp1, int centerX, int centerY, int size) {
    int x1, y1, x2, y2, x3, y3;
    double pi = 2 * acos(0.0);

    x1 = int(centerX + (size * cos(pi / 6)));
    y1 = int(centerY + (size * sin(pi / 6)));
    x2 = centerX;
    y2 = centerY - size;
    x3 = int(centerX - (size * cos(pi / 6)));
    y3 = int(centerY + (size * sin(pi / 6)));

    //void prepareTriangle(int x1, int y1, int x2, int y2, int x3, int y3, int red, int green, int blue);
    vp1.prepareTriangle(x1, y1, x2, y2, x3, y3, red, green, blue);
}

void EquilateralTriangle::e_2_1_equilateral_triangles(ViewPortGL& vp1) {
    bool is_running = true;
    //int centerX = 0, centerY = 0, size = 0;

    while (is_running) {
        is_running = !vp1.windowShouldClose();

        prepare(vp1, 400, 400, 200);
        prepare(vp1, 700, 800, 50);
        prepare(vp1, 100, 700, 35);
        prepare(vp1, 10, 20, 10);

        vp1.sendTriangles();
        vp1.swapBuffers();
    }
}