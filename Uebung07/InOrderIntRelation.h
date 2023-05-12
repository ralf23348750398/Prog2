#pragma once

#include "BinaryRelation.h"

class InOrderIntRelation : public BinaryRelation<int, int> {
public:
	static InOrderIntRelation& GetInstance();
	bool inRelation(int a, int b);
	
	InOrderIntRelation(const InOrderIntRelation& obj) = delete;

private:
	InOrderIntRelation();
	
	static InOrderIntRelation s_Instance;
};
