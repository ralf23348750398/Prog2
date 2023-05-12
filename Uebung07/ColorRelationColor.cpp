#include "ColorRelationColor.h"

ColorRelationColor::ColorRelationColor(){};

ColorRelationColor ColorRelationColor::s_instance;

ColorRelationColor& ColorRelationColor::get_Instance() {
	return s_instance;
}

bool ColorRelationColor::inRelation(Color a, Color b) {
	if (a.getRed() < b.getRed()) {
		return 1;
	}
	else if (a.getRed() > b.getRed()) {
		return 0;
	}
	else {
		if (a.getGreen() < b.getGreen()) {
			return 1;
		}
		else if (a.getGreen() > b.getGreen()) {
			return 0;
		}
		else {
			if (a.getBlue() <= b.getBlue()) {
				return 1;
			}
			else if (a.getBlue() > b.getBlue()) {
				return 0;
			}
		}
	}
}
