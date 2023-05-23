#pragma once

#include "BinaryRelation.h"

class InOrderIntRelation : public BinaryRelation<unsigned int, unsigned int> {
public:
	bool inRelation(unsigned int a, unsigned int b);
	
	//deleting the copy constructor (Is called when there is an operation with an object on the right side of an assignment operator)
	//e.g. s_instance2=s_instance + 12;
	InOrderIntRelation(const InOrderIntRelation&) = delete;

	//deleting the assignment operator (Necessary to prevent sth like s_instance2=instance. Here, the copy constructor isn't called)
	InOrderIntRelation& operator=(const InOrderIntRelation&) = delete;

	//return a reference of the static instance
	static InOrderIntRelation& get_Instance();
private:
	InOrderIntRelation();
	static InOrderIntRelation s_instance;
};
