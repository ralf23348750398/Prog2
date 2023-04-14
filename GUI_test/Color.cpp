#include "Color.h"

Color::Color(int r, int g, int b) {
	this->red = r;
	this->green = g;
	this->blue = b;
}

Color::Color() {
	this->red = 0;
	this->green = 0;
	this->blue = 0;
}

int Color::getRed() {
	return this->red;
}

int Color::getGreen() {
	return this->green;
}

int Color::getBlue() {
	return this->blue;
}

void Color::setRed(int r) {
	try {
		if (r < 0 || r > 255) {
			throw logic_error("specified number is not in the rgb range (0-255)");
		}
		this->red = r;
	}
	catch (logic_error& msg) {
		cout << msg.what() << endl;
	}
}

void Color::setGreen(int g) {
	this->green = g;
}

void Color::setBlue(int b) {
	this->blue = b;
}


