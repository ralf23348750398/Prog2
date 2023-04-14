#include "FirstSquares.h"

void FirstSquares::test(ViewPortGL& vp) {
    bool isRunning = true;
    while (isRunning) {
        isRunning = !vp.windowShouldClose();

        vp.prepareTriangle(0, 999, 999, 999, 500, 0, 200, 0, 0, 0, 0, 200, 0, 200, 0);
        vp.sendTriangles();

        vp.swapBuffers();
    }
}

void FirstSquares::e1_2_static_square(ViewPortGL& vp) {

    bool is_running = true;
    while (is_running) {
        is_running = !vp.windowShouldClose();

        //void prepareLine(int x1, int y1, int x2, int y2, int red, int green, int blue);
        vp.prepareLine(299, 299, 299, 699, 255, 255, 255);
        vp.prepareLine(299, 299, 699, 299, 255, 255, 255);
        vp.prepareLine(299, 699, 699, 699, 255, 255, 255);
        vp.prepareLine(699, 299, 699, 699, 255, 255, 255);

        vp.sendLines();
        vp.swapBuffers();
    }
}

void FirstSquares::e1_3_dyn_square(ViewPortGL& vp) {
    int xy = 499, size = 1, i = 0;
    bool is_running = true;

    while (is_running) {
        is_running = !vp.windowShouldClose();
        if (vp.windowShouldClose()) {
            exit(1);
        }

        vp.prepareBlock(xy, xy, size, size, 255, 0, 255);
        if (i < 500) {
            i++;
            xy--;
            size += 2;
        }
        else if (i < 1000) {
            i++;
            xy++;
            size -= 2;
            vp.clearViewPort();
        }
        else if (i == 1000) {
            i = 0;
            vp.clearViewPort();
        }

        vp.sendTriangles();
        vp.swapBuffers();
        this_thread::sleep_for(1ms); 
    }
}
