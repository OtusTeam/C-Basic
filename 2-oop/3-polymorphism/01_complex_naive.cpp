#include <iostream>

void complex_sum(
		float real1, float im1,		   // The first complex number
		float real2, float im2,		   // The second complex number
		float &real_res, float &im_res // The result
	)
{
	real_res = real1 + real2;
	im_res = im1 + im2;
}

int main()
{

	float real1, im1; // first complex
	float real2, im2; // second complex

	std::cout << "Enter the first complex number in the format: [real part] [image part]\n";
	std::cin >> real1 >> im1;

	std::cout << "Enter the second complex number in the format: [real part] [image part]\n";
	std::cin >> real2 >> im2;

	float res_real = 0;
	float res_im = 0;
	complex_sum(real1, im1, real2, im2, res_real, res_im);

	std::cout << "The result: " << res_real << " + " << res_im << "i\n";

}
