#pragma once
#include <iostream>
#include "MyData.h"

class Base;

class Pair {

		MyString m_key; //êëþ÷ - ôàìèëèÿ
		MyData m_Data;

	public: 

		Pair(const char* surname = "???", Sex s = UNDEF,
			size_t age = 0, const char* job = "???", float sal = 0.0);

		Pair(const char* k, const MyData &d);
	
		//~Pair();
		//Pair(const Pair& other); 
		//Pair& operator=(const Pair& other); 
		//Pair(Pair&& other); 
		//Pair& operator=(Pair&& other);
		bool operator==(const char* k) const;
		friend class Base;	//÷òîáû ðàáîòàëà èíäåêñàöèÿ âîçâðàùàþùàÿ MyData все методы сделать приватными
		friend std::ostream& operator<<(std::ostream& os, const Pair& pair);
		friend std::ostream& operator<<(std::ostream& os, const Base& bd);
};
