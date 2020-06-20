#include "MyData.h"

MyData::MyData(Sex s, size_t age, const char* job, float sal)
{
	m_sex = s;
	m_age = age;
	m_job=MyString(job);
	m_salary = sal;
}

//--//--//--//--//--//--//--//--//--//--//--//--//--//--//--//--//--//--//--//--//--//--

std::ostream& operator<<(std::ostream& os, const MyData& d)
{

	/*const char* sex;
	switch (d.m_sex)
	{ 
	case MyData::FEMALE:
		sex = "Female";
		break;
	case MyData::MALE:
		sex = "Male";
		break;
	default:
		sex = "Undef";
	}*/
	

	//os << "\nSex: "     так память течет
		//<< (d.m_sex == MyData::MALE ? "Male" : (d.m_sex == MyData::FEMALE ? "Female" : "Undef")) 
		//<< "\nAge: " << d.m_age	<< "\nJob " << d.m_job << "\nSalary: " << d.m_salary;

	os << "\nSex: "	<< d.m_sex << "\nAge: " << d.m_age		//и так тоже
		<< "\nJob " << d.m_job << "\nSalary: " << d.m_salary;
		
	return os;
}