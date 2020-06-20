#pragma once

#include "myString.h"
#include "MyData.h"
#include <iostream>

class Pair {

		MyString m_key; //ключ - фамилия
		MyData m_Data; //данные о сотруднике

	public: 

		Pair(const char* surname = "???", MyData::Sex s = MyData::UNDEF, 
			size_t age = 0,	const char* job = "???", float sal = 0.0);

		Pair(const char* k, const MyData& d);
	
		//~Pair();
		//Pair(const Pair& other); 
		//Pair& operator=(const Pair& other); 
		//Pair(Pair&& other); 
		//Pair& operator=(Pair&& other);
		//bool operator==(const char* k) const;
		//friend class Base; 
		friend std::ostream& operator<<(std::ostream& os, const Pair& pair);
};