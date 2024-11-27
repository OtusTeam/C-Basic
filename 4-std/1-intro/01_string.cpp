#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

#include <cassert>

void char_pointers()
{
	std::cout << "*** char_pointers ***\n";

	// this is not a std::string, it is а null-terminated string (C-style string): https://en.cppreference.com/w/cpp/string/byte
	// About string literals: https://en.cppreference.com/w/cpp/language/string_literal
	// String literal is a lvalue: https://en.cppreference.com/w/cpp/language/value_category
	const char *str1 = "Hello"; // plus a terminating null character
	const char *str2 = ",";
	const char *str3 = " World";
	auto str4 = "!";

	// Yes, we can output it and it seams like a concatennation
	std::cout << str1 << str2 << str3 << str4 << '\n';

	// But we can't do a concatennation, because there is no addition operation for pointers
	// Compile error here:
	// const char *str = str1 + str2 + str3 + str4;

	// We can't even compare with good result:
	const char *a = "Hello!";
	const char *b = "Hello!";
	// Warninig! The result will be difference with different compilers
	std::cout << "a == b: " << (a == b) << '\n';
	// We must usr this: https://en.cppreference.com/w/cpp/string/byte/strcmp
	// or better this: https://en.cppreference.com/w/cpp/string/byte/strncmp

	std::cout << '\n';
}

void string()
{
	std::cout << "*** string ***\n";

	char array[] = {'H', 'e', 'l', 'l', 'o', '!'};
	// std::string is am alias for std::basic_string<char>: https://en.cppreference.com/w/cpp/string/basic_string
	std::string str{array};

	std::cout << "str = " << str << '\n';
	array[0] = 'T';
	// std::string makes a copy of data. After changing the array[0] value
	// the str is not changed.
	std::cout << "after change str = " << str << '\n';

	// But we can change data in the std::string:
	str[0] = 'T';
	std::cout << "after the second change str = " << str << '\n';
}

void compare() {
	std::string s1{"qwerty"};
	std::string s2{"qwerity"};

	assert(s1 > s2);
	assert(!(s1 < s1) && !(s1 > s1));


	std::vector<std::string> qwerty = {
		"mystring",
		"qwerty",
		"alphabet",
		"row",
		"column",
		"rowboat",
		"QWerty"};

	// sort() usually implemented using only Quicksort: https://en.cppreference.com/w/cpp/algorithm/sort
	std::sort(qwerty.begin(), qwerty.end()); // std::string::operator<

	std::cout << "Sorted by < operator: \n";
	for (auto str_item : qwerty) {
		std::cout << str_item << '\n';
	}
}

void iterators() {
	std::string str{"Some string"};

	// https://en.cppreference.com/w/cpp/string/basic_string/begin
	std::string::const_iterator citer = str.cbegin();
	std::cout << *citer << '\n';
	// const_iterator means that we can change the iterator itself:
	++citer;
	// but we can't change the value:
	// *citer = 'W'; // Compile-time error

	std::string::iterator iter = str.begin();
	std::cout << *iter << '\n';
	// With iterator we can change the iterator itself:
	++iter;
	// and the value:
	*iter = 'W'; // Ok

	// Iterate through the data with iterators
	for (std::string::const_iterator citer = str.cbegin(); citer != str.cend(); ++citer) {
		std::cout << *citer << '\n';
	}
	// Simpler with auto:
	for (auto citer = str.cbegin(); citer != str.cend(); ++citer) {
		std::cout << *citer << '\n';
	}
}

void find() {
	// 1
	std::cout << '\n'
			  << "Simple find begin\n";

	std::string first{"thxyfirst string inn find method"};

	decltype(first.cbegin()) str_iter;
	std::size_t position = 0;

	// Algorithms library: https://en.cppreference.com/w/cpp/algorithm
	// std::find: https://en.cppreference.com/w/cpp/algorithm/find
	// Find the first occurrence of a value in a sequence.
	str_iter = std::find(first.cbegin(), first.cend(), 'n');
	// Returns the number of hops from first to last.
	position = std::distance(first.cbegin(), str_iter);

	std::size_t position2 = first.find('n');

	std::cout << "First 'n' position is: "<< position << "\n";
	assert(position == first.find('n'));

	std::cout << "Simple find end\n\n";

	// 2
	std::cout << "Find_if begin\n";

	struct SymbolComparator {
		SymbolComparator(const char inputChar) : ch_(inputChar) {}
		bool operator()(char ch) {
			return ch <= ch_;
		}

	private:
		char ch_;
	};

	const char ch1('f');
	// Find the first element in a sequence for which a predicate is true.
	str_iter = std::find_if(first.cbegin(), first.cend(), SymbolComparator(ch1));

	std::cout << "--> " << *str_iter << '\n';
	auto pos = std::distance(first.cbegin(), str_iter);
	std::cout << "First greater or equal than " << ch1 << " symbol's position is: " << pos << '\n';

	const char ch2('f');
	// Find the first element in a sequence for which a predicate is false.
	str_iter = std::find_if_not(first.cbegin(), first.cend(), SymbolComparator(ch2));
	pos = std::distance(first.cbegin(), str_iter);
	std::cout << "First lesser to " << ch2 << " symbol's position is: " << pos << '\n';

	std::cout << "Find-if end\n";

	// 3.
	std::cout << " Adjacent find begin\n";
	// Find two adjacent values in a sequence that are equal.
	str_iter = std::adjacent_find(first.cbegin(), first.cend());
	pos = std::distance(first.cbegin(), str_iter);
	std::cout << "Position of the first symbol in an adjacent pair is: " << pos << "\n";
	std::cout << first.at(pos) << " " << first.at(pos + 1) << '\n';
	std::cout << " Adjacent find begin\n";

	// 4.
	std::cout << " Find substring\n";
	std::string eve{"ing"};
	// Search a sequence for a matching sub-sequence.
	str_iter = std::search(first.cbegin(), first.cend(), eve.cbegin(), eve.cend());
	pos = std::distance(first.cbegin(), str_iter);
	std::cout << R"(Position of the "ing" substring is: )" << pos << '\n';

	// 5.
	std::string second{"ABBA BABBAB"};
	std::string bb{"BB"};
	// Find last matching subsequence in a sequence.
	str_iter = std::find_end(second.cbegin(), second.cend(), bb.cbegin(), bb.cend());
	pos = std::distance(second.cbegin(), str_iter);
	std::cout << R"(Position of the last "BB" substring is: )" << pos << "\n";

	// 6.
	std::cout << " Find first symbol from a given set\n";

	std::string origin{"Yet another sEquence of letters"};
	std::string symbols{"l E"};
	// Find element from a set in a sequence.
	str_iter = std::find_first_of(origin.cbegin(), origin.cend(), symbols.cbegin(), symbols.cend());
	pos = std::distance(origin.cbegin(), str_iter);
	std::cout << R"(Position of the first symbol from "l E" set is: )" << pos << '\n';
	// Find first absence of characters
	pos = origin.find_first_not_of("Yex a");
	std::cout << R"(Position of the first symbol different from "Yex a" is: )" << pos << '\n';

	// 7.
	std::cout << " Find sequence of repeated symbols with certain length\n";
	// Search a sequence for a number of consecutive values.
	str_iter = std::search_n(origin.cbegin(), origin.cend(), 2, 't');
	pos = std::distance(origin.cbegin(), str_iter);
	std::cout << "Position of the first symbol in sequence of 2 't' is: " << pos << '\n';

	// 8.
	std::cout << "Strings mismatch\n";
	std::string s1{"The early bird eats the worm"};
	std::string s2{"The early bird catches the worm"};
	// Finds the places in ranges which don't match.
	auto ret = std::mismatch(s1.begin(), s1.end(), s2.begin());
	size_t pos1 = std::distance(s1.begin(), ret.first);
	size_t pos2 = std::distance(s2.begin(), ret.second);

	std::cout << "Position of the first  symbol in mismatch is: " << pos1 << '\n';
	std::cout << "Position of the second symbol in mismatch is: " << pos2 << '\n';
}

int main()
{
	char_pointers();
	string();
	compare();
	find();
}
