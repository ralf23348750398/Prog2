#include "SierpinskiTriangle.h"

void SierpinskiTriangle::recursion_problem(ViewPortGL& vp1, int ax, int ay, int bx, int by, int cx, int cy, int min_size) {
    int ex, ey, fx, fy, dx, dy;

    //calculation of the coordinates
    //original triangle: Coordinates A (left corner), B (right corner), C (upper corner)
    //new triangles: Coordinates E (between A and C), F (between B and C), D (between A and B)
    //coordinates are represented by their x and y values. Example: A(ax|ay)
    ex = (ax + cx) / 2;
    ey = (ay + cy) / 2;
    fx = (bx + cx) / 2;
    fy = (by + cy) / 2;
    dx = (ax + bx) / 2;
    dy = (ay + by) / 2;

    //upper triangle
    if ((fx - ex) > min_size) {
        recursion_problem(vp1, ex, ey, fx, fy, cx, cy, min_size);
    }
    else {
        vp1.prepareTriangle(ex, ey, fx, fy, cx, cy, 255, 255, 255);
    }

    //left triangle
    if (dx - ax > min_size) {
        recursion_problem(vp1, ax, ay, dx, dy, ex, ey, min_size);
    }
    else {
        vp1.prepareTriangle(ax, ay, dx, dy, ex, ey, 255, 255, 255);
    }

    //right triangle
    if (bx - dx > min_size) {
        recursion_problem(vp1, dx, dy, bx, by, fx, fy, min_size);
    }
    else {
        vp1.prepareTriangle(dx, dy, bx, by, fx, fy, 255, 255, 255);
    }
}

void SierpinskiTriangle::e_2_3_sierpinski_triangle(ViewPortGL& vp1) {
    //starting coordinates of the original, colored triangle
    int ax = 0, ay = 999, bx = 999, by = 999, cx = 500, cy = 0;

    //minimum size for the new triangles (pixels between two corner coordinates)
    int min_size = 10;

    bool isRunning = true;
    while (isRunning) {
        isRunning = !vp1.windowShouldClose();

        vp1.prepareBlock(0, 0, 1000, 1000, 255, 255, 255);
        vp1.prepareTriangle(ax, ay, bx, by, cx, cy, 200, 0, 0, 0, 0, 200, 0, 200, 0);
        recursion_problem(vp1, ax, ay, bx, by, cx, cy, min_size);

        vp1.sendTriangles();
        vp1.swapBuffers();
    }
}

