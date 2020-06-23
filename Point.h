#pragma once
class Point
{
		int m_x;
		int m_y;

	public:
		Point(int x = 0, int y = 0);

		int GetX() const { return m_x; }
		int GetY() const { return m_y; }

		Point& operator+=(const Point& other);
		Point& operator+=(int a);

		friend Point& operator-=(Point& p1, const Point& p2);
		friend Point& operator-=(Point& p1, int a);

		Point operator+(const Point& other) const;
		Point operator+(int a) const;

		Point operator-(const Point& other) const;
		Point operator-(int a) const;

		const Point& operator+() const;
		Point operator-() const;
};

Point operator+(int a, const Point& other);