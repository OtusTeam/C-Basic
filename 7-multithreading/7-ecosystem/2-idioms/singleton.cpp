#include <iostream>
#include <fstream>


namespace motivation {

	struct Logger {
	public:
		Logger(const char *filename)
			: m_file{ filename } {
			if (!m_file.is_open()) {
				throw std::runtime_error(std::string{"Could not open file: "} + filename);
			}
		}

		void debug(const std::string& msg) {
			m_file << "[DEBUG] " << msg << std::endl;
		}
		void info(const std::string& msg) {
			m_file << "[INFO] " << msg << std::endl;
		}
		void error(const std::string& msg) {
			m_file << "[ERROR] " << msg << std::endl;
		}
	private:
		std::ofstream m_file;
	};

	struct Some_class {
	public:
		Some_class(Logger& logger)
			: m_logger{logger} {}

		void do_work() {
			m_logger.debug("Some_class - do_work");
		}
	private:
		Logger& m_logger;
	};

	void some_function(Logger& logger) {
		logger.error("some_function - call");
	}

	void example() {
		std::cout << "motivation::example()" << std::endl;
		
		// Initialize logger
		Logger logger{"out.txt"};

		// and put it everywhere...
		Some_class some{logger};
		some.do_work();
		some_function(logger);

		std::cout << std::endl << std::endl;
	}
} // namespace motivation


static int s_value = 42;

namespace singleton {

	struct Logger {
	public:
		// 2. 
		static Logger& get_instance(const char *path = nullptr) {
			static Logger logger{path}; // 
			return logger;
		}
		void initialize(const char *ptr) {
			m_file.open(ptr);
			if (!m_file.is_open()) {
				throw std::runtime_error(std::string{"Could not open file: "} + ptr);
			}
		}
		void debug(const std::string& msg) {
			m_file << "[DEBUG] " << msg << std::endl;
		}
		void info(const std::string& msg) {
			m_file << "[INFO] " << msg << std::endl;
		}
		void error(const std::string& msg) {
			m_file << "[ERROR] " << msg << std::endl;
		}

		// 1.
		Logger(const Logger&) = delete;
		Logger(Logger&&) = delete;
		Logger& operator=(const Logger&) = delete;
		Logger& operator=(Logger&&) = delete;
	private:
		explicit Logger(const char *path) 
			: m_file{ path } {
			if (!m_file.is_open()) {
				throw std::runtime_error(std::string{"Could not open file: "} + path);
			}
		}
		std::ofstream m_file;
	};

	struct Some_class {
	public:
		Some_class() = default;

		void do_work() {
			auto& logger = Logger::get_instance();
			logger.debug("Some_class - do_work");
		}
	private:
	};

	void some_function() {
		auto& logger = Logger::get_instance();
		logger.error("some_function - call");
	}


	void example() {
		std::cout << "singleton::example()" << std::endl;

		// Initialize logger
		auto& logger = Logger::get_instance();

		// and use it everywhere
		Some_class some{};
		some.do_work();
		some_function();

		std::cout << std::endl << std::endl;
	}

} // namespace singleton

int main() {

	motivation::example();
	singleton::example();

	return 0;
}