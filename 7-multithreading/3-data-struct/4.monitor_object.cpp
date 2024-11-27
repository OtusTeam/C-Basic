#include <cassert>
#include <exception>
#include <iostream>
#include <mutex>
#include <thread>
#include <utility>
#include <vector>

namespace monitor {

// Monitor
// Monitor object
template <class T>
class monitor {
 public:
  template <typename... Args>
  monitor(Args &&...args) : m_data{std::forward<Args>(args)...} {}

  struct helper {
    helper(monitor *mon) : m_parent{mon}, m_lock{mon->m_mutex} {
      std::cout << "helper created, LOCKED!\n";
    }
    ~helper() { std::cout << "helper destroyed, UNLOCKED!\n"; }

    T *operator->() {
      std::cout << "helper returning address of data\n";
      return &m_parent->m_data;
    }

   private:
    monitor *m_parent;
    std::lock_guard<std::mutex> m_lock;
  };

  helper operator->() { return helper(this); }

 private:
  T m_data;
  std::mutex m_mutex;
};

void example1() {
  std::cout << "Example 2\n";

  monitor<std::vector<int>> thread_safe_vector{1, 2, 3, 4, 5};

  std::cout << "First vector size: " << thread_safe_vector->size() << '\n';
}

void example2() {
  std::cout << "Example 2\n";

  monitor<std::vector<int>> thread_safe_vector{1, 2, 3, 4, 5};

  const auto lambda = [](monitor<std::vector<int>> &vec) {
    for (int i = 0; i < 10; ++i) {
      vec->push_back(i);
    }
  };

  std::thread thr1{lambda, std::ref(thread_safe_vector)};
  std::thread thr2{lambda, std::ref(thread_safe_vector)};

  thr1.join();
  thr2.join();

  for (size_t i = 0; i < thread_safe_vector->size(); ++i) {
    std::cout << ' ';
    std::cout << thread_safe_vector->data()[i];
  }
  auto size [[maybe_unused]] = thread_safe_vector->size();
  auto iter [[maybe_unused]] = thread_safe_vector->cbegin();
}
}  // namespace monitor

int main() {
  monitor::example1();
  std::cout << "\n ========================================\n";
  monitor::example2();
}