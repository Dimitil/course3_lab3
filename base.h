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
		Base& operator=(const Base& bd); //����������������!!! 
		Base(Base&& bd);
		Base& operator=(Base&& bd);
		MyData& operator[](const char* key);
		void print(const char* key) const; //����� ����������
		int deletePair(const char* key);	//���������� ���������� ����� ����������, ��� 0 ���� ������ �� �������
		friend std::ostream& operator<<(std::ostream& os, const Base& bd);
	};