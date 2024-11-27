#include <iostream>

class Complex
{
  public:
	Complex() = default;

	Complex(float rel, float im) : m_rel{rel}, m_im{im} {}

	float rel() const
	{
		return m_rel;
	}

	float im() const { return m_im; }

	Complex sum(Complex rhs) const
	{
		Complex result{m_rel + rhs.m_rel, m_im + rhs.m_im};
		return result;
	}

  private:
	float m_rel = 0.0f;
	float m_im = 0.0f;
};

int main()
{
	float rel, im;
	std::cout << "Enter the first complex number in the format: [real part] [image part]\n";
	std::cin >> rel >> im; // Место для возможного улучшения
	Complex first{rel, im};

	std::cout << "Enter the second complex number in the format: [real part] [image part]\n";
	std::cin >> rel >> im;
	Complex second{rel, im};

	Complex result = first.sum(second); // Место для возможного улучшения
	std::cout << "The result: " << result.rel() << " + " << result.im() << "i\n";
}
