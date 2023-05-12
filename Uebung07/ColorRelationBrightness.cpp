#include "ColorRelationBrightness.h"

ColorRelationBrightness ColorRelationBrightness::s_instance;

ColorRelationBrightness::ColorRelationBrightness() {}

ColorRelationBrightness& ColorRelationBrightness::get_Instance() {
	return s_instance;
}

bool ColorRelationBrightness::inRelation(Color a, Color b) {
	return a.getRed() + a.getGreen() + a.getBlue() <= b.getRed() + b.getGreen() + b.getBlue();
}
