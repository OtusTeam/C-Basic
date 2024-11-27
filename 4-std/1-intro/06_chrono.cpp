// https://en.cppreference.com/w/cpp/chrono
#include <chrono>

#include <iostream>

using namespace std::literals::chrono_literals;

// https://en.cppreference.com/w/cpp/language/user_literal
constexpr long double operator"" _deg_to_rad(long double deg) {
	constexpr long double pi = 3.14159265358979323846;
	return deg * pi / 180;
}

int main() {
	// 1.
	double x_rad = 90.0_deg_to_rad;
	std::cout << x_rad << '\n';

	// 2.
	std::chrono::seconds sec(5);
	auto secs = 5s;

	std::chrono::seconds time1 = 5min + 17s;
	std::chrono::minutes time2 = 2h - 15min;
	std::cout << time2.count() << " min\n";

	std::chrono::seconds s = 15s;
	std::cout << s.count() << " s\n";

	// Monotonic clock that will never be adjusted
	auto start = std::chrono::steady_clock::now();
	std::cout << "Timeout string printed to measure time\n";
	auto end = std::chrono::steady_clock::now();
	auto elapsed = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
	std::cout << elapsed.count() << " ms\n";
}
