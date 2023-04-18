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
			throw invalid_argument("specified number is not in the rgb range (0-255)");
		}
		this->red = r;
	}
	catch (invalid_argument& msg) {
		cout << msg.what() << endl;
	}
}

void Color::setGreen(int g) {
	try {
		if (g < 0 || g > 255) {
			throw invalid_argument("specified number is not in the rgb range (0-255)");
		}
		this->green = g;
	}
	catch (invalid_argument& msg) {
		cout << msg.what() << endl;
	}
}

void Color::setBlue(int b) {
	try {
		if (b < 0 || b > 255) {
			throw invalid_argument("specified number is not in the rgb range (0-255)");
		}
		this->blue = b;
	}
	catch (invalid_argument& msg) {
		cout << msg.what() << endl;
	}
}

Color Color::darken(int amount) {
	if (this->red - amount >= 0) {
		this->red -= amount;
	}
	else {
		this->red = 0;
	}
	if (this->green - amount >= 0) {
		this->green -= amount;
	}
	else {
		this->green = 0;
	}
	if (this->blue - amount >= 0) {
		this->blue -= amount;
	}
	else {
		this->blue = 0;
	}
	return Color(this->red, this->green, this->blue);
}

Color Color::lighten(int amount) {
	if (this->red + amount <= 255) {
		this->red += amount;
	}
	else {
		this->red = 255;
	}
	if (this->green + amount <= 255) {
		this->green += amount;
	}
	else {
		this->green = 255;
	}
	if (this->blue + amount <= 255) {
		this->blue += amount;
	}
	else {
		this->blue = 255;
	}
	return Color(this->red, this->green, this->blue);
}