#include <algorithm>
#include <iostream>
#include <vector>

/* ТЗ:
	1. Получить вектор целых чисел из stdin
	2. Отсортировать полученный вектор
	3. Вывести результат в консоль
	4. Отфильтровать четные числа
	5. Вывести результат в консоль
*/

int main() {

	// Получаем вектор из stdin
	std::vector<int> values;
	int v = 0;
	while (std::cin >> v) { // Linux: для выхода из цикла используем ctrl+D
		values.push_back(v);
	}

	// Сортируем полученный вектор
	std::sort(values.begin(), values.end());

	// Печатаем отсортированный результат
	for (size_t i = 0; i < values.size(); ++i) {
		if (i != 0) std::cout << ' ';
		std::cout << values[i];
	}
	std::cout << '\n';

	// Извлекаем из вектора четные числа
	std::vector<int> evens;
	for (size_t i = 0; i < values.size(); ++i) {
		if (values[i] % 2 == 0) {
			evens.push_back(values[i]);
		}
	}

	// Печатаем четные числа
	for (size_t i = 0; i < evens.size(); ++i) {
		if (i != 0) std::cout << ' ';
		std::cout << evens[i];
	}
	std::cout << '\n';

	return 0;
}

/*
	Проанализируем приведенную реализацию.
	Какие у неё достоинства? Недостатки?
	Можно ли написать юнит-тесты для данной реализации?
*/
