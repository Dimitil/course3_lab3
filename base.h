#pragma once
#include <iostream>
#include "Pair.h"


	class Base 
	{
		Pair* m_pBase;
		size_t m_count;
		size_t m_capacity;

	public: 

		Base(size_t count=0); 
		~Base();
		Base(const Base& bd); 
		Base& operator=(const Base& bd); //оптимизированный!!! 
		Base(Base&& bd);
		Base& operator=(Base&& bd);
		MyData& operator[](const char* key);
		void print(const char* key) const; //вывод сотрудника
		int deletePair(const char* key);	//возвращает порядковый номер удаленного, или 0 если никого не удалили
		friend std::ostream& operator<<(std::ostream& os, const Base& bd);
	};