#include <iostream>

#include "..\src\ViewPortGL.h"
#include "..\src\PulsatingAnimation.h"
#include "..\GUI_test\FirstSquares.h"
#include "..\GUI_test\Square.h"
#include "..\GUI_test\Disk.h"
#include "..\GUI_test\EquilateralTriangle.h"
#include "..\GUI_test\SierpinskiTriangle.h"
#include "..\GUI_test\BinaryVisuals.h"

using namespace std;

void e_2_1_squares(ViewPortGL& vp1, Square& sq1, Square& sq2, Square& sq3, Square& sq4) {
    bool is_running = true;

    while (is_running) {
        is_running = !vp1.windowShouldClose();

        sq1.prepare(vp1, 25, 25, 4);
        sq2.prepare(vp1, 400, 600, 200);
        sq3.prepare(vp1, 900, 333, 34);
        sq4.prepare(vp1, 100, 900, 50);

        vp1.sendTriangles();
        vp1.swapBuffers();
    }
}

void e_2_1_disks(ViewPortGL& vp1, Disk& d1, Disk& d2, Disk& d3, Disk& d4) {
    bool is_running = true;
    //int centerX = 0, centerY = 0, size = 0;

    while (is_running) {
        is_running = !vp1.windowShouldClose();

        d1.prepare(vp1, 400, 400, 200);
        d2.prepare(vp1, 700, 800, 50);
        d3.prepare(vp1, 100, 700, 35);
        d4.prepare(vp1, 10, 20, 10);

        vp1.sendLines();
        vp1.swapBuffers();
    }
}

void e3_1_uchar(ViewPortGL& vp1) {
    bool is_running = true;

    while (is_running) {
        is_running = !vp1.windowShouldClose();

        BinaryVisuals::prepareRepresentation(vp1, unsigned char(63), 830, 200, 100, 150);

        vp1.sendLines();
        vp1.sendTriangles();
        vp1.swapBuffers();
    }
}

void e3_1_uint(ViewPortGL& vp1) {
    bool is_running = true;

    while (is_running) {
        is_running = !vp1.windowShouldClose();

        BinaryVisuals::prepareRepresentation(vp1, unsigned int(65535), 970, 200, 20, 40);

        vp1.sendLines();
        vp1.sendTriangles();
        vp1.swapBuffers();
    }
}

void e3_2_exchangeHalves(ViewPortGL& vp1, BinaryVisuals& b1, unsigned int original_value) {
    bool is_running = true;
    unsigned int res = 0;

    while (is_running) {
        is_running = !vp1.windowShouldClose();

        BinaryVisuals::prepareRepresentation(vp1, unsigned int(original_value), 970, 200, 20, 40);
        res = b1.exchangeHalves(original_value, 7, 12);
        BinaryVisuals::prepareRepresentation(vp1, unsigned int(res), 970, 300, 20, 40);

        vp1.sendLines();
        vp1.sendTriangles();
        vp1.swapBuffers();
    }
}

void e3_3_reverse(ViewPortGL& vp1, BinaryVisuals& b1, unsigned int original_value) {
    bool is_running = true;
    unsigned int res = 0;

    while (is_running) {
        is_running = !vp1.windowShouldClose();

        BinaryVisuals::prepareRepresentation(vp1, unsigned int(original_value), 970, 200, 20, 40);
        res = b1.reverse(original_value);
        BinaryVisuals::prepareRepresentation(vp1, unsigned int(res), 970, 300, 20, 40);

        vp1.sendLines();
        vp1.sendTriangles();
        vp1.swapBuffers();
    }
}

int main() { 
    int selector;

    cout << "Select the exercise you would like to execute." << endl << "Select" << endl << "0 for the test," << endl << "1 for sheet 1, exercise 2," << endl
        << "2 for sheet 1, exercise 3," << endl << "3 for sheet 2, exercise 1a," << endl << "4 for sheet 2, exercise 1b," << endl << "5 for sheet 2, exercise 1c," << endl
        << "6 for sheet 2, exercise 2," << endl << "7 for sheet 2, exercise 3," << endl << "8 for sheet 3, exercise 1b," << endl << "9 for sheet 3, exercise 1c," 
        << endl << "10 for sheet 3, exercise 2," << endl << "11 for sheet 3, exercise 3," << endl << "q to quit:" << endl;
    cin >> selector;

    //object creation
    ViewPortGL vp1("OpenGL default window vp1", 1000, 1000);

    FirstSquares fs1;

    Square sq1(255, 0, 0);
    Square sq2(255, 255, 0);
    Square sq3(0, 255, 0);
    Square sq4(0, 0, 255);

    Disk d1(0, 0, 255);
    Disk d2(0, 255, 255);
    Disk d3(0, 255, 0);
    Disk d4(255, 0, 0);

    EquilateralTriangle et1(0, 255, 0);
    SierpinskiTriangle st1;
    PulsatingAnimation pa1(500, 500, 10, 300);
    BinaryVisuals b1;

    switch (selector) {
    case 0:
        fs1.test(vp1);
        break;
    case 1:
        fs1.e1_2_static_square(vp1);
        break;
    case 2:
        fs1.e1_3_dyn_square(vp1);
        break;
    case 3:
        e_2_1_squares(vp1, sq1, sq2, sq3, sq4);
        break;
    case 4:
        e_2_1_disks(vp1, d1, d2, d3, d4);
        break;
    case 5:
        et1.e_2_1_equilateral_triangles(vp1);
        break;
    case 6:
        pa1.animate(vp1, et1);
        break;
    case 7:
        st1.e_2_3_sierpinski_triangle(vp1);
        break;
    case 8:
        e3_1_uchar(vp1);
        break;
    case 9:
        e3_1_uint(vp1);
        break;
    case 10:
        e3_2_exchangeHalves(vp1, b1, 2383392409);
        break;
    case 11:
        e3_3_reverse(vp1, b1, 2383392409);
        break;
    default:
        break;
    }
    
    return 0;
}


