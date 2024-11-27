#include <iostream>
#include <vector>

class Primitive
{
  public:
	virtual ~Primitive() = default;

	// https://en.cppreference.com/w/cpp/language/abstract_class
	virtual void draw() const = 0;
};

class Point : public Primitive
{
  public:
	Point() : m_x{0}, m_y{0}
	{}

	~Point() override
	{
		std::cout << "Point::~Point()\n";
		delete m_heap;
	}

	Point(int x, int y) : m_x{x}, m_y{y}
	{
		std::cout << "Point::Point()\n";
		m_heap = new int(1);
	}

	// virtual можно не использовать,
	//  а использование override поможет избежать ошибок
	/* virtual */ void draw() const override
	{
		std::cout << "Point: ";
		std::cout << "x = " << m_x << " y = " << m_y;
	}

  private:
	int* m_heap = nullptr;
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


int main()
{

	{
		Primitive *p = new Point{10, 20};
		delete p;
	}

	// Primitive primitive;

	// Point p{10, 20};
	// draw(p);

	// Line line{Point{10, 20}, Point{100, 200}};
	// draw(line);

	// Primitive *array[2] = {&p, &line};
	// draw(array, 2);

	// std::vector<Primitive *> primitives;
	// primitives.push_back(new Point{1, 2});
	// primitives.push_back(new Point{3, 4});
	// primitives.push_back(new Line{Point{5, 6}, Point{7, 8}});
	// primitives.push_back(new Line{Point{9, 10}, Point{11, 12}});

	// for (const Primitive *p : primitives)
	// {
	// 	p->draw();
	// 	std::cout << std::endl;
	// }

	// // And delete allocated memory
	// for (const Primitive *p : primitives)
	// {
	// 	delete p;
	// }
}
