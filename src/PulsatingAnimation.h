#pragma once

#include <chrono>
#include <thread>

#include "ViewPortGL.h"
#include "Shape.h"

using namespace std::chrono_literals;  //used for: this_thread::sleep_for(1ms);


class PulsatingAnimation {

public:
	PulsatingAnimation(int x, int y, int min, int max);
	void animate(ViewPortGL& vp, Shape& s);

private:
	int posX, posY;
	int minSize, maxSize;
};

