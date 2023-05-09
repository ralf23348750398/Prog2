#pragma once

#include "Color.h"
#include "BinaryRelation.h"

class ColorRelationBrightness :public BinaryRelation<Color, Color> {
public:
	ColorRelationBrightness(ColorRelationBrightness&) = delete;
	static ColorRelationBrightness& get_Instance();
	bool inRelation(Color a, Color b);
private:
	ColorRelationBrightness();
	static ColorRelationBrightness s_instance;
};
