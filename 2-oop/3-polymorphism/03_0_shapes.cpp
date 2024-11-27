#include <iostream>

class Point
{
  public:
	Point()
		: m_x{0}, m_y{0} {}

	Point(int x, int y)
		: m_x{x}, m_y{y} {}

	void draw() const
	{
		std::cout << "Point: ";
		std::cout << "x = " << m_x << " y = " << m_y;
	}

  private:
	int m_x;
	int m_y;
};

class Line
{
  public:
	Line() {}
	Line(Point p1, Point p2)
		: m_p1{p1}, m_p2{p2} {}

	void draw() const
	{
		std::cout << "Line: ";
		std::cout << "Point1: ";
		m_p1.draw();
		std::cout << " Point2: ";
		m_p2.draw();
	}

  private:
	Point m_p1;
	Point m_p2;
};

void draw(const Point &point)
{
	point.draw();
	std::cout << std::endl;
}

void draw(const Line &line)
{
	line.draw();
	std::cout << std::endl;
}

int main()
{
	Point p{10, 20};
	draw(p);

	Line line{Point{10, 20}, Point{100, 200}};
	draw(line);

	// How should we make a collection?
	// std::vector<...> shapes{
	// 	Line{...},
	// 	Point{...},
	// 	Line{...},
	// 	Point{...}};
}
