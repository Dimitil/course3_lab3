#pragma once

#include "myString.h"
#include <iostream>

	class MyData {
		public: 
			enum Sex { UNDEF, MALE, FEMALE }; 
		private: 
			Sex m_sex; 
			size_t m_age; 
			MyString m_job; 
			float  m_salary; 
		public: 
			MyData(Sex s=UNDEF, size_t age=0, const char* job="???",  float sal=0.0);
			//~MyData();							
			//MyData(const MyData& d);				
			//MyData& operator=(const MyData& d); 
			//MyData(MyData&& d); 
			//MyData& operator=(MyData&& d);
			friend std::ostream& operator<<(std::ostream& os, const MyData& d);
	};