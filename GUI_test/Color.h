#pragma once

#include <iostream>

using namespace std;

class Color {
public:
	Color(int r, int g, int b);
	Color();

	int getRed();
	int getGreen();
	int getBlue();
	void setRed(int r);
	void setGreen(int g);
	void setBlue(int b);

	Color darken(int amount);
	Color lighten(int amount);
private:
	int red, green, blue;
};