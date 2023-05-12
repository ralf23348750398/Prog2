#pragma once

#include "BinaryRelation.h"
#include "Color.h"

class ColorRelationColor :public BinaryRelation<Color, Color> {
public:
	ColorRelationColor(const ColorRelationColor&) = delete;
	static ColorRelationColor& get_Instance();
	bool inRelation(Color a, Color b);
private:
	ColorRelationColor();
	static ColorRelationColor s_instance;
};
