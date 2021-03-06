#include "base.h"

Base::Base(size_t count)
{
	m_count		= count;
	m_capacity	= count+3;
	m_pBase		= new Pair[m_capacity];
}

//--//--//--//--//--//--//--//--//--//--//--//--//--//--//--//--//--//--//--//--//--//--//--//--//--//

Base::~Base()
{
	delete[] m_pBase;
	m_pBase		= nullptr;
	m_count		= 0;
	m_capacity	= 0;
}

//--//--//--//--//--//--//--//--//--//--//--//--//--//--//--//--//--//--//--//--//--//--//--//--//--//

Base::Base(const Base& bd)
{
	m_count		= bd.m_count;
	m_capacity  = m_count;
	m_pBase		= new Pair[m_capacity];
	//memcpy(m_pBase, bd.m_pBase, m_count * sizeof(Pair)); Скопировать руками в цикле
}

//--//--//--//--//--//--//--//--//--//--//--//--//--//--//--//--//--//--//--//--//--//--//--//--//--//

Base& Base::operator=(const Base& bd)
{
	if (this != &bd)
	{
		m_count = bd.m_count;
		if (m_capacity < bd.m_count)
		{
			m_capacity = bd.m_count;
			delete[] m_pBase;
			m_pBase = new Pair[m_capacity];
		}
		//memcpy(m_pBase, bd.m_pBase, m_count * sizeof(Pair));  переделать руками!!!!!!!!!!!!!!!!!!!
	}
	return *this;
}

//--//--//--//--//--//--//--//--//--//--//--//--//--//--//--//--//--//--//--//--//--//--//--//--//--//

Base::Base(Base&& bd)
{
	m_count		= bd.m_count;//проверка на самоприсваивание
	m_capacity	= bd.m_capacity;
	m_pBase		= bd.m_pBase;

	bd.m_pBase	= nullptr;
	bd.m_count	= 0;
	bd.m_capacity = 0;
}

//--//--//--//--//--//--//--//--//--//--//--//--//--//--//--//--//--//--//--//--//--//--//--//--//--//

Base& Base::operator=(Base&& bd)
{
	//высвыбодить память , проверка на самоприсваивание
	m_count = bd.m_count;
	m_capacity = bd.m_capacity;
	m_pBase = bd.m_pBase;
	
	bd.m_pBase = nullptr;
	bd.m_count = 0;
	bd.m_capacity = 0;
	return *this;
}

//--//--//--//--//--//--//--//--//--//--//--//--//--//--//--//--//--//--//--//--//--//--//--//--//--//

MyData& Base::operator[](const char* key)
{
	for (size_t i = 0; i < m_count; i++)
	{
		if (m_pBase[i] == key)
		{
		return	m_pBase[i].m_Data;
		}
	}

	if (m_count>=m_capacity)
	{
		int add_to_capacity = 3;
		m_capacity+=add_to_capacity;
		Pair* newm_pBase = new Pair[m_capacity];
		for (size_t i = 0; i < m_capacity - add_to_capacity; i++)
		{
			newm_pBase[i] = std::move(m_pBase[i]);   //интересно
		}
		
		delete[] m_pBase;     
		m_pBase = newm_pBase;
	}

	m_count++;
	m_pBase[m_count-1].m_key.SetNewString(key);
	m_pBase[m_count - 1].m_Data = MyData();//подумать с этим вот явным вызовом дефолтного конструктора.!!!!!!!!!!!!

	return m_pBase[m_count - 1].m_Data;
}	

//--//--//--//--//--//--//--//--//--//--//--//--//--//--//--//--//--//--//--//--//--//--//--//--//--//--//--//--//--

std::ostream& operator<<(std::ostream& os, const Base& bd)
{
	for (size_t i = 0; i < bd.m_count; i++)
	{
		os << std::endl<< i+1 <<'.' << bd.m_pBase[i]<< std::endl;
	}
	return os;
}

//--//--//--//--//--//--//--//--//--//--//--//--//--//--//--//--//--//--//--//--//--//--//--//--//--//

int Base::deletePair(const char* key)
{
	int const not_found = -1;
	int delete_index = not_found;;
	for (size_t i = 0; i < m_count; i++)
	{
		if (m_pBase[i] == key)
		{
			delete_index = i;//èùåì óäàëÿåìîãî ñîòðóäíèêà
			
			break;
		}
	}			//можно в одном цикле
	
	if (delete_index != not_found)//åñëè íàøëè, òî ïåðåñòàâëÿåì íàø ìàññèâ , çàòèðàÿ óäàëÿåìîãî
	{
		for (size_t i = delete_index; i < m_count - 1; i++)
		{
			m_pBase[i] = m_pBase[i+1];
		}
		m_count--;	
	}
	return delete_index + 1;//âîçâðàùàåì ïîðÿäêîâûé íîìåð óäàëåííîãî, èëè 0 åñëè íèêîãî íå óäàëèëè 
}

//--//--//--//--//--//--//--//--//--//--//--//--//--//--//--//--//--//--//--//--//--//--//--//--//--//--

void Base::print(const char* key) const //âûâîä ñîòðóäíèêà
{
	for (size_t i = 0; i < m_count; i++)
	{
		if (m_pBase[i] == key)
		{

			std::cout <<"\nEmployee: "<< m_pBase[i].m_key;
			std::cout << m_pBase[i].m_Data;
			return;
		}
	}
	std::cout << "\nThis employee not found.\n";
}
