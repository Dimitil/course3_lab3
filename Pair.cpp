#include "Pair.h"

Pair::Pair(const char* surname, Sex s,
	size_t age, const char* job, float sal)
{
	m_key	= surname;
	m_Data	= MyData(s, age, job, sal);
}

//--//--//--//--//--//--//--//--//--//--//--//--//--//--//--//--//--//--//--//--//--//--//--//--//--//--//--//--

Pair::Pair(const char* k, const MyData& d)
{
	m_key  = k;
	m_Data = MyData(d);
}

//--//--//--//--//--//--//--//--//--//--//--//--//--//--//--//--//--//--//--//--//--//--//--//--//--//--//--//--

std::ostream& operator<<(std::ostream& os, const Pair& pair)
{
	os <<'\n'<< pair.m_key << pair.m_Data;
	return os;
}

//--//--//--//--//--//--//--//--//--//--//--//--//--//--//--//--//--//--//--//--//--//--//--//--//--//--//--//--

bool Pair::operator==(const char* k) const
{
	return (!strcmp(m_key.GetString(), k));
}