#include <fstream>
#include <iostream>
#include <string>

// Обратите внимание, что объект нужно передавать по ссылке
// По копии передавать нельзя!
bool write_to_file_example(std::ofstream& file) {
	std::cout << "write_to_file_example:\n";

	if (!file.is_open()) {
		std::cout << "Error! File was not opened!\n";
		return false;
	}

	// Записываваем в файл
	// целочисленнуэ константу
	file << 42;
	// константу с плавающей точкой
	file << 3.1415f;
	// строковую константу
	file << "hello!";

	int someVariable = 56;
	// переменную
	file << someVariable;

	// Результат находится по адресу ./build/testFile.txt:
	// 423.1415hello!56

	return true;
}

bool read_from_file(std::ifstream& file) {
	std::cout << "read_from_file:\n";

	if (!file.is_open()) {
		std::cout << "Error! File was not opened!\n";
		return false;
	}

	// Объявляем переменные, в которые будем считывать данные из файла
	float f_value = 0;
	std::string str_value;
	int i_value = 0;

	// Файл содеожит данные:
	// 423.1415hello!56
	// Считываем данные из файла:
	file >> f_value; // 423.1415
	file >> str_value; // hello!56
	file >> i_value; // 0

	std::cout << "f_value = " << f_value << '\n';
	std::cout << "str_value = " << str_value << '\n';
	std::cout << "i_value = " << i_value << '\n';

	return true;
}

bool read_write_file_example(std::fstream& file) {
	std::cout << "read_write_file_example:'\n'";

	if (!file.is_open()) {
		std::cout << "Error! File was not opened!'\n'";
		return false;
	}

	// Записываемые данные в файл
	// Записываем первую строку
	file << 42 << ' ';
	file << "hello!" << ' ';
	file << 3.1415 << '\n';
	// Записываем вторую строку
	file << "some other string" << '\n';

	// Не обязательная операция
	// file.flush();
	// Обязательная операция, если собираемся читать файл с начала
	// Перемещаем каретку в начало файла
	// Можно проверить, что произойдет без этой команды:)
	file.seekg(0);

	// Считываем данные из файла
	// Cчитываем данные из первой строки
	int i_value = 0;
	file >> i_value; // 42
	std::string s_value;
	file >> s_value; // hello!
	float f_value = 0.f;
	file >> f_value; // 3.1415
	//// int pos = file.tellg();
	// Cчитываем данные из второй строки
	std::string other_s_value;
	// Результат отличается от ожидаемого
	file >> other_s_value; // some

	//// Выставляем каретку в заданную позицию
	//// file.seekg(pos);

	// https://en.cppreference.com/w/cpp/io/basic_istream/ignore
	file.ignore();
	std::getline(file, other_s_value);

	std::cout << "i_value = " << i_value << '\n';
	std::cout << "s_value = " << s_value << '\n';
	std::cout << "f_value = " << f_value << '\n';
	std::cout << "other_s_value = " << other_s_value << '\n';

	return true;
}

int main() {

	const std::string filename = "testFile.txt";

	// Открываем файл для записи
	// Файл будет создан рядом с исполняемым модулем
	std::ofstream o_file{ filename };
	bool success = write_to_file_example(o_file);
	if (success) {
		std::cout << "Write to file succeeded!" << '\n';
	}
	else {
		std::cout << "Write to file failed!" << '\n';
		return EXIT_FAILURE;
	}
	// Закрываем файл и сбрасываем (flush) буфер на диск
	o_file.close();

	// Открываем файл для чтения
	std::ifstream i_file{filename};
	success = read_from_file(i_file);
	if (success) {
		std::cout << "Read from file succeeded!" << '\n';
	}
	else {
		std::cout << "Read from file failed!" << '\n';
		return EXIT_FAILURE;
	}

	// Открываем файл и для чтения, и для записи
	const std::string filename2 = "testFile2.txt";
	std::fstream io_file{filename2, std::ios_base::in | std::ios_base::out | std::fstream::app};
	read_write_file_example(io_file);

	return EXIT_SUCCESS;
}
