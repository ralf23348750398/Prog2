#pragma once
#include "ViewPortGL.h"
#include "Color.h"

class GridViewer : public ViewPortGL {
public:
	GridViewer(string titleP, int size, int cellSizeP);
	~GridViewer();
	unsigned int getCell(int x, int y);
	void setCell(int x, int y, unsigned int value);
	void draw();
	int getGridSize();

private:
	unsigned int* content;
	const int cellSize;	//Size of a single cell inside the ViewPort
	const int gridSize;	//Amount of cells inside the ViewPort
	void testCoordinates(int x, int y); //used to throw exceptions if x/y is out of scope of the cellSize


protected:
	virtual Color colorFor(unsigned int value);
	virtual void prepareCell(int x, int y);
	virtual void prepareCellBorder(int x, int y);
};

