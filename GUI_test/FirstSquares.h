#pragma once

#include "ViewPortGL.h"
#include <chrono>
#include <thread>

using namespace std::chrono_literals;  //used for: this_thread::sleep_for(1ms);

class FirstSquares {
private:
	
public:
	//default testing method provided by our prof
	void test(ViewPortGL& vp);

	//sheet 1, exercise 2
	void e1_2_static_square(ViewPortGL& vp);

	//sheet 1, exercise 3
	void e1_3_dyn_square(ViewPortGL& vp);
};
