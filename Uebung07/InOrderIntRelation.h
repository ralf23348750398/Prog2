#pragma once

#include "BinaryRelation.h"

class InOrderIntRelation : public BinaryRelation<unsigned int, unsigned int> {
public:
	bool inRelation(unsigned int a, unsigned int b);
	
	//deleting the copy constructor
	InOrderIntRelation(const InOrderIntRelation&) = delete;

	//return a reference of the static instance
	static InOrderIntRelation& get_Instance();
private:
	InOrderIntRelation();
	static InOrderIntRelation s_instance;
};
