#include <iostream>

struct Complex
{
  public:
	Complex() : m_rel{0}, m_im{0} {}
	Complex(float rel, float im) : m_rel{rel}, m_im{im} {}

	float rel() const { return m_rel; }
	float im() const { return m_im; }

	Complex sum(Complex rhs) const
	{
		Complex result{m_rel + rhs.m_rel, m_im + rhs.m_im};
		return result;
	}

	friend std::ostream &operator<<(std::ostream &os, Complex complex);
	friend std::istream &operator>>(std::istream &os, Complex &complex);

  private:
	float m_rel;
	float m_im;
};

/*friend*/ std::ostream &operator<<(std::ostream &os, Complex complex) {
	os << complex.m_rel << " + " << complex.m_im << "i"; // Место для возможного улучшения
	return os;
}

/*friend*/ std::istream &operator>>(std::istream &os, Complex &complex) {
	os >> complex.m_rel >> complex.m_im; // Место для возможного улучшения
	return os;
}

int main()
{
	Complex first;
	std::cout << "Enter the first complex number in the format: [real part] [image part]\n";
	std::cin >> first;

	Complex second;
	std::cout << "Enter the second complex number in the format: [real part] [image part]\n";
	std::cin >> second;

	Complex result = first.sum(second);
	std::cout << "The result: " << result << '\n';
}