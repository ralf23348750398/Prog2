#include "ReverseOrderIntRelation.h"

ReverseOrderIntRelation ReverseOrderIntRelation::s_instance;

ReverseOrderIntRelation::ReverseOrderIntRelation(){}

ReverseOrderIntRelation& ReverseOrderIntRelation::get_Instance() {
	return s_instance;
}

bool ReverseOrderIntRelation::inRelation(unsigned int a, unsigned int b) {
	return a >= b;
}