#include <iostream>

class Complex
{
  public:
	Complex() : m_rel{0}, m_im{0} {}
	Complex(float rel, float im) : m_rel{rel}, m_im{im} {}

	float rel() const { return m_rel; }
	float im() const { return m_im; }

	void setReal(float real)
	{
		m_rel = real;
	}

	void setImage(float image)
	{
		m_im = image;
	}

	// Not a friend because does not need private member usage
	// friend std::ostream &operator<<(std::ostream &os, Complex complex);
	// friend std::istream &operator>>(std::istream &os, Complex &complex);

  private:
	float m_rel;
	float m_im;
};

std::ostream &operator<<(std::ostream &os, Complex complex) {
	os << complex.rel() << " + " << complex.im() << "i";
	return os;
}

std::istream &operator>>(std::istream &os, Complex &complex) {
	float real = 0.0f;
	float image = 0.0f;
	os >> real >> image;
	complex.setReal(real);
	complex.setImage(image);
	return os;
}

Complex operator+(Complex first, Complex second)
{
	Complex result{first.rel() + second.rel(), first.im() + second.im()};
	return result;
}

int main()
{
	Complex first;
	std::cout << "Enter the first complex number in the format: [real part] [image part]\n";
	std::cin >> first;

	Complex second;
	std::cout << "Enter the second complex number in the format: [real part] [image part]\n";
	std::cin >> second;

	Complex result = first + second;
	std::cout << "The result: " << result << '\n';
}
