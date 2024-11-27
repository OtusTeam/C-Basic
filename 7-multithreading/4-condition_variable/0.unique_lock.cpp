#include <mutex>

// https://en.cppreference.com/w/cpp/thread/unique_lock

int main() {

	std::mutex mutex;
	{
		std::lock_guard lck{mutex}; // mutex locked here
	} // muted unlocked here

	{
		std::unique_lock lck{mutex}; // mutex locked here
		// work with shared data
		lck.unlock(); // mutex unlocked here

		// work with local data - no sync required

		lck.lock(); // mutex locked here

		// work with shared data again

	} // mutex unlocked here

	return 0;
}