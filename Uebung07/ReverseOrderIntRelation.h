#pragma once

#include "BinaryRelation.h"

class ReverseOrderIntRelation : public BinaryRelation<unsigned int, unsigned int> {
public:
	bool inRelation(unsigned int a, unsigned int b);
	ReverseOrderIntRelation(ReverseOrderIntRelation& a) = delete;
	static ReverseOrderIntRelation& get_Instance();
private:
	ReverseOrderIntRelation();
	static ReverseOrderIntRelation s_instance;
};
