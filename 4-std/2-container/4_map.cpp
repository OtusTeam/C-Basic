#include "line_separator.h"

#include <iostream>
#include <map>
#include <string>

void testUnique() {
	LineSeparator::out(" Example 1: testUnique");

	std::map<int, std::string> values;

	// std::pair<std::map<char,int>::iterator,bool> ret;
	auto result = values.insert(std::make_pair(42, "Petia"));

	values[24] = "Who is it?";

	std::cout << result.first->first << " <-> ";
	std::cout << result.first->second << ". inserted: " << result.second << std::endl;

	result = values.insert(std::make_pair(42, "Vasia"));
	std::cout << result.first->first << " <-> ";
	std::cout << result.first->second << ". inserted: " << result.second << std::endl;
}

void testOrder() {
	LineSeparator::out(" Example 2: testOrder");

	std::map<std::string, int> values = {
		{"Vasia", 10},
		{"Petia", 42},
		{"Marina", 17},
		{"Mike", 22},
		{"Alex", 1}};

	for (const auto &v : values) {
		std::cout << v.first << std::endl;
	}
}

void testIterator() {
	LineSeparator::out(" Example 3: testIterator");

	std::map<std::string, int> values = {
		{"Alpha", 1},
		{"Bravo", 2},
		{"Charlie", 3},
		{"Delta", 4},
		{"Echo", 5}};

	auto iter = values.begin();
	std::cout << iter->first << " " << iter->second << std::endl;

	// Bidirectional
	++iter;
	--iter;

	// But not random-access
	// iter += 3;

	std::advance(iter, 2);
	std::cout << iter->first << " " << iter->second << std::endl;
}

void testInsert() {
	LineSeparator::out(" Example 4: testInsert by operator[] (std::size_t)");
	std::map<int, int> values;
	std::cout << values[5] << std::endl;
	std::cout << "values size " << values.size() << std::endl;
}

int main(int, char *[]) {
	testUnique();
	testOrder();
	testIterator();
	testInsert();

	return 0;
}
