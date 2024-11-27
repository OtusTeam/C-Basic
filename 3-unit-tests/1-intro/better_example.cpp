#include <algorithm>
#include <iostream>
#include <vector>

/*
	Проанализируем доработанную версию.
	1. Выделили отдельные этапы алгоритма в изолированные функции.
	2. Избавились от дублирования кода (печать на экран).

	Остались ли еще замечания к коду?
*/

/* Подсказка
	Представим, что заказчик изменил требования,
	 вектор теперь нужно читать/отображать в файл
*/

std::vector<int> read_sequence() {
	std::vector<int> values;
	int v = 0;
	while (std::cin >> v) {
		values.push_back(v);
	}
	return values;
}

void print_sequence(const std::vector<int> &seq) {
	for (size_t i = 0; i < seq.size(); ++i) {
		if (i != 0)
			std::cout << ' ';
		std::cout << seq[i];
	}
	std::cout << '\n';
}

std::vector<int> filter_even(const std::vector<int>& seq) {
	std::vector<int> evens;
	for (size_t i = 0; i < seq.size(); ++i) {
		if (seq[i] % 2 == 0) {
			evens.push_back(seq[i]);
		}
	}
	return evens;
}

/* ТЗ:
	1. Получить вектор целых чисел из stdin
	2. Отсортировать полученный вектор
	3. Вывести результат в консоль
	4. Отфильтровать четные числа
	5. Вывести результат в консоль
*/

int main() {

	std::vector<int> sequence = read_sequence();

	std::sort(sequence.begin(), sequence.end());

	print_sequence(sequence);

	std::vector<int> evens = filter_even(sequence);

	print_sequence(evens);

	return 0;
}
