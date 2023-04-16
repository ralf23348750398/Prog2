#include "GridViewer.h"
#include <stdexcept>


GridViewer::GridViewer(string titleP, int size, int cellSizeP) 
	:ViewPortGL(titleP, size, size), cellSize(cellSizeP), gridSize(size / cellSizeP) {	//calling the constructor of class ViewPortGL, initializing the two const values
																						
	//throwing exceptions if cellSizeP parameter is not a viable value
	if (size < 4) {
		throw logic_error("The specified size (" + to_string(size) + ") is too low. It should be at least 4.");
	}
	else if (size > 1024) {
		throw logic_error("The specified size (" + to_string(size) + ") is too high. It should be no more than 1024.");
	}
	else if ((size & (size - 1)) != 0) {
		throw logic_error("The specified size (" + to_string(size) + ") is no power of 2.");
	}

	//throwing exceptions if cellSizeP parameter is not a viable value
	if (cellSizeP < 4) {
		throw logic_error("The cellSizeP parameter (" + to_string(cellSizeP) + ") is too low. It should be at least 4.");
	}
	else if (cellSizeP > 1024) {
		throw logic_error("The cellSizeP parameter (" + to_string(cellSizeP) + ") is too high. It should be no more than 1024.");
	}
	else if ((cellSizeP & (cellSizeP - 1)) != 0) {
		throw logic_error("The cellSizeP parameter (" + to_string(cellSizeP) + ") is no power of 2.");
	}
	else if (cellSizeP > size) {
		throw logic_error("The cellSizeP value (" + to_string(cellSizeP) + ") is higher than the given size value (" + to_string(size) + ").");
	}

	//allocating memory & initializing the content array 
	content = new unsigned int[gridSize ^ 2];
	for (int i = 0; i < (gridSize ^ 2); i++) {
		content[i] = 0;
	}
}

GridViewer::~GridViewer() {
	delete content;
}

Color GridViewer::colorFor(unsigned int value) {
	int r, g, b;
	unsigned int mask_r, mask_g, mask_b;

	for (int i = 0; i < sizeof(unsigned int) * 8; i++) {
		if (i <= 31 && i >= 24) {
			mask_r = unsigned int(pow(2, i));
		}
		if (i <= 23 && i >= 16) {
			mask_g = unsigned int(pow(2, i));
		}
		if (i <= 15 && i >= 8) {
			mask_b = unsigned int(pow(2, i));
		}
	}

	r = value & mask_r >> 23;
	g = value & mask_g >> 15;
	b = value & mask_b >> 7;
	
	return Color(r, g, b);
}

void GridViewer::prepareCell(int x, int y) {
    // Bitte implementieren!
}

void GridViewer::prepareCellBorder(int x, int y) {
    // Bitte implementieren!
}

void GridViewer::testCoordinates(int x, int y) {
	if (x<0 || x>cellSize) {
		throw logic_error("The x parameter (" + to_string(x) + ") is out of scope of the cellSize (" + to_string(cellSize) + ").");
	}
	if (y<0 || y>cellSize) {
		throw logic_error("The y parameter (" + to_string(y) + ") is out of scope of the cellSize (" + to_string(cellSize) + ").");
	}
}

unsigned int GridViewer::getCell(int x, int y) {
	testCoordinates(x, y);
	return content[y * gridSize + x];
}

void GridViewer::setCell(int x, int y, unsigned int value) {
	testCoordinates(x, y);
	content[y * gridSize + x] = value;
}

void GridViewer::draw() {
	/*int count = 0;
	static const int maxPreparedTriangles = getMaxNumberOfPreparedTriangles();
	static const int maxPreparedLines = getMaxNumberOfPreparedLines();
	for (int x = 0; x < gridSize; x++) {
		for (int y = 0; y < gridSize; y++) {
			prepareCell(x, y);
			prepareCellBorder(x, y);
			count++;
			if (maxPreparedTriangles - 1 <= count*2 || maxPreparedLines - 3 <= count * 4) {
				sendTriangles();
				sendLines();
				sendPixels();
				count = 0;
			}
		}
	}
	if (count > 0) {
		sendTriangles();
		sendLines();
		sendPixels();
	}*/
}

int GridViewer::getGridSize() {
	return gridSize;
}
