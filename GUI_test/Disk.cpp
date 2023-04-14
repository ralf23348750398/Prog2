#include "Disk.h"



void Disk::prepare(ViewPortGL& vp1, int centerX, int centerY, int radius) {
    int half_line = 0, height = radius;
    int x1 = 0, y1 = 0, x2 = 0, y2 = 0, i = 0;

    do {
        //radius^2 = heigth^2 * half_line^2
        //half_line = sqrt(radius^2 / height^2)
        half_line = int(sqrt((radius * radius) - (height * height)));
        x1 = centerX - half_line;
        y1 = centerY - (radius - i);
        x2 = centerX + half_line;
        y2 = centerY - (radius - i);

        if (i < radius) {
            height--;
        }
        else {
            height++;
        }

        //void prepareLine(int x1, int y1, int x2, int y2, int red, int green, int blue)
        vp1.prepareLine(x1, y1, x2, y2, red, green, blue);

        i++;
    } while (i < radius * 2);
}