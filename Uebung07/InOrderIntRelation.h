#pragma once

#include "BinaryRelation.h"

<<<<<<< HEAD
class InOrderIntRelation : public BinaryRelation<int, int> {
public:
	static InOrderIntRelation& GetInstance();
	bool inRelation(int a, int b);
	
	InOrderIntRelation(const InOrderIntRelation& obj) = delete;

private:
	InOrderIntRelation();
	
	static InOrderIntRelation s_Instance;
=======
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
>>>>>>> 36785836995875468be5c4698916f5b8be7a1793
};
