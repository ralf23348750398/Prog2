#pragma once

#include "InOrderIntRelation.h"

bool InOrderIntRelation::inRelation(int a, int b) {
	return a <= b;
}

InOrderIntRelation& InOrderIntRelation::GetInstance() {
	return s_Instance;
}
