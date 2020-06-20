#include "Point.h"

Point::Point(int x, int y)
{
	m_x = x;
	m_y = y;
}

//--//--//--//--//--//--//--//--//--//--//--//--//--//--//--//--//--//--//--

Point& Point::operator+=(const Point& other)
{
	m_x += other.m_x;
	m_y += other.m_y;

	return *this;
}

//--//--//--//--//--//--//--//--//--//--//--//--//--//--//--//--//--//--//--

Point& Point::operator+=(int a)
{
	m_x += a;
	m_y += a;

	return *this;
}

//--//--//--//--//--//--//--//--//--//--//--//--//--//--//--//--//--//--//--

Point& operator-=(Point& p1, const Point& p2)
{
	p1.m_x -= p2.m_x;
	p1.m_y -= p2.m_y;

	return p1;
}

//--//--//--//--//--//--//--//--//--//--//--//--//--//--//--//--//--//--//--

Point& operator-=(Point& p1, int a)
{
	p1.m_x -= a;
	p1.m_y -= a;

	return p1;
}

//--//--//--//--//--//--//--//--//--//--//--//--//--//--//--//--//--//--//--

Point Point::operator+(const Point& other) const
{
	int tmpX = m_x + other.m_x;
	int tmpY = m_y + other.m_y; 

	return Point(tmpX, tmpY);
}

//--//--//--//--//--//--//--//--//--//--//--//--//--//--//--//--//--//--//--

Point Point::operator+(int a) const
{
	int tmpX = m_x + a;
	int tmpY = m_y + a;

	return Point(tmpX, tmpY);
}

//--//--//--//--//--//--//--//--//--//--//--//--//--//--//--//--//--//--//--

Point operator+(int a, const Point& other)
{
	int tmpX = a + other.GetX();
	int tmpY = a + other.GetY();

	return Point(tmpX, tmpY);
}

//--//--//--//--//--//--//--//--//--//--//--//--//--//--//--//--//--//--//--

Point Point::operator-(const Point& other) const
{
	int tmpX = m_x - other.m_x;
	int tmpY = m_y - other.m_y;

	return Point(tmpX, tmpY);
}

//--//--//--//--//--//--//--//--//--//--//--//--//--//--//--//--//--//--//--

Point Point::operator-(int a) const
{
	int tmpX = m_x - a;
	int tmpY = m_y - a;

	return Point(tmpX, tmpY);
}

//--//--//--//--//--//--//--//--//--//--//--//--//--//--//--//--//--//--//--

Point Point::operator+() const
{
	return *this;
}

//--//--//--//--//--//--//--//--//--//--//--//--//--//--//--//--//--//--//--

Point Point::operator-() const
{
	int x = -m_x;
	int y = -m_y;

	return Point(x, y);
}