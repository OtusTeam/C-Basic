#include "../include/utils.h"

#include <algorithm>

/* ТЗ:
	1. Получить вектор целых чисел из stdin
	2. Отсортировать полученный вектор
	3. Вывести результат в консоль
	4. Отфильтровать четные числа
	5. Вывести результат в консоль
*/

int main() {

	std::vector<int> sequence = project::read_sequence(std::cin);

	std::sort(sequence.begin(), sequence.end());

	project::print_sequence(sequence, std::cout);

	std::vector<int> evens = project::filter_even(sequence);

	project::print_sequence(evens, std::cout);

	return 0;
}