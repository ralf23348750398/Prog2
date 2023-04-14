#include "PulsatingAnimation.h"

PulsatingAnimation::PulsatingAnimation(int x, int y, int min, int max) {
    this->posX = x;
    this->posY = y;
    this->minSize = min;
    this->maxSize = max;
}

//Shape& s is a reference to an object (not a pointer). It is therefore more or less the same object, but with a different name.
//s can be any object of a derived class.
void PulsatingAnimation::animate(ViewPortGL& vp1, Shape& s) {
    int size = this->minSize;

    bool is_running = true;
    while (is_running) {
        is_running = !vp1.windowShouldClose();

        for (int i = minSize; i < maxSize; i++) {
            if (vp1.windowShouldClose()) {
                exit(1);
            }
            //virtual void prepare(ViewPortGL& vp, int centerX, int centerY, int size) = 0;
            s.prepare(vp1, posX, posY, size);
            size++;

            vp1.sendTriangles();
            vp1.sendLines();
            vp1.sendPixels();
            vp1.swapBuffers();

            this_thread::sleep_for(1ms);
        }
        for (int i = minSize; i < maxSize; i++) {
            if (vp1.windowShouldClose()) {
                exit(1);
            }
            vp1.clearViewPort();
            //void prepareBlock(int x, int y, int width, int height, int r, int g, int b);
            s.prepare(vp1, posX, posY, size);
            size--;

            vp1.sendTriangles();
            vp1.sendLines();
            vp1.sendPixels();
            vp1.swapBuffers();

            this_thread::sleep_for(1ms);
        }
    }
}

