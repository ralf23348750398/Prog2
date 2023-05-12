#include "InOrderIntRelation.h"

//instanciate the variable s_instance as object of class InOrderIntRelation
InOrderIntRelation InOrderIntRelation::s_instance;

InOrderIntRelation& InOrderIntRelation::get_Instance() {
	return s_instance;
}

InOrderIntRelation::InOrderIntRelation() {}

bool InOrderIntRelation::inRelation(unsigned int a, unsigned int b) {
	return a <= b;
}