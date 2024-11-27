#include <iostream>
#include <vector>

class Primitive
{
  public:
	virtual ~Primitive() = default;

	// Место для потенциальной доработки
	// https://www.equestionanswers.com/cpp/vptr-and-vtable.php
	virtual void draw() const
	{
		std::cout << "Fake implementation!" << std::endl;
	}
};

class Point : public Primitive
{
  public:
	Point() : m_x{0}, m_y{0} {}

	Point(int x, int y) : m_x{x}, m_y{y} {}

	// virtual можно не использовать,
	//  а использование override поможет избежать ошибок
	/* virtual */ void draw() const override
	{
		std::cout << "Point: ";
		std::cout << "x = " << m_x << " y = " << m_y;
	}

  private:
	int m_x;
	int m_y;
};

class Line : public Primitive
{
  public:
	Line() {}
	Line(Point p1, Point p2) : m_p1{p1}, m_p2{p2} {}

	void draw() const override
	{
		std::cout << "Line: Point1: ";
		m_p1.draw();
		std::cout << " Point2: ";
		m_p2.draw();
	}

  private:
	Point m_p1;
	Point m_p2;
};

void draw(const Primitive &primitive)
{
	std::cout << "draw(const Primitive& primitive)" << std::endl;
	primitive.draw();
	std::cout << std::endl;
}

void draw(Primitive **array, size_t count)
{
	std::cout << "draw(Primitive** array, size_t count)" << std::endl;
	for (size_t i = 0; i < count; ++i) {
		array[i]->draw();
		std::cout << std::endl;
	}
}

void bad_draw(Primitive primitive)
{
	std::cout << "bad_draw(Primitive primitive)" << std::endl;
	primitive.draw();
	std::cout << std::endl;
}


int main()
{
	Primitive primitive;
	draw(primitive);

	Point p{10, 20};
	draw(p);

	Line line{Point{10, 20}, Point{100, 200}};
	draw(line);

	Primitive *array[2] = {&p, &line};
	draw(array, 2);

	{
		Primitive* p = new Point{1, 2};
		delete p;
	}

	std::vector<Primitive*> primitives;
	primitives.push_back(new Point{1, 2});
	primitives.push_back(new Point{3, 4});
	primitives.push_back(new Line{Point{5, 6}, Point{7, 8}});
	primitives.push_back(new Line{Point{9, 10}, Point{11, 12}});

	// for (size_t i = 0; i < primitives.size(); ++i)
	// {
	// 	const Primitive* p = primitives[i];
	// 	primitives[i]->draw();
	// 	std::cout << std::endl;
	// }

	for (const Primitive *p : primitives)
	{
		p->draw();
		std::cout << std::endl;
	}

	bad_draw(line);

	// And delete allocated memory
	for (const Primitive *p : primitives)
	{
		delete p;
	}
}
