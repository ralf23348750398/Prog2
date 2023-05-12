<<<<<<< HEAD
#pragma once

#include "InOrderIntRelation.h"

bool InOrderIntRelation::inRelation(int a, int b) {
	return a <= b;
}

InOrderIntRelation& InOrderIntRelation::GetInstance() {
	return s_Instance;
}
=======
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
>>>>>>> 36785836995875468be5c4698916f5b8be7a1793
