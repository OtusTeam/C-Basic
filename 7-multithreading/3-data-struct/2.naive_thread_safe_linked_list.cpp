#include <exception>
#include <iostream>
#include <memory>
#include <utility>

// added
#include <cassert>
#include <mutex>
#include <thread>

namespace naive {

template <typename T>
struct List {
  void push_back(const T &value) {
    // added
    std::unique_ptr<Node> newNode = std::make_unique<Node>();
    const std::lock_guard lck{m_mutex};
    newNode->data = value;

    // the first element case
    if (empty()) {
      assert(m_first.get() == nullptr);
      assert(m_last == nullptr);

      m_first = std::move(newNode);
      m_last = m_first.get();
    } else {
      Node *oldLast = m_last;
      oldLast->next = std::move(newNode);
      oldLast->next->prev = oldLast;
      m_last = oldLast->next.get();
    }
    ++m_size;
  }
  T &back() {
    // added
    const std::lock_guard lck{m_mutex};
    if (empty()) {
      throw std::logic_error{"Containter is empty!"};
    }
    return m_last->data;
  }
  void pop_back() {
    // added
    const std::lock_guard lck{m_mutex};
    if (empty()) {
      throw std::logic_error{"Containter is empty!"};
    }
    if (size() == 1) {
      m_first.reset();
      m_last = nullptr;
      m_size = 0;
      return;
    }

    Node *old_last = m_last;
    m_last = old_last->prev;
    old_last->prev->next.reset();
    --m_size;
  }

  void push_front(const T &value) {
    // added
    const std::lock_guard lck{m_mutex};
    std::unique_ptr<Node> newNode = std::make_unique<Node>();
    newNode->data = value;

    // the first element case
    if (empty()) {
      assert(m_first.get() == nullptr);
      assert(m_last == nullptr);

      m_first = std::move(newNode);
      m_last = m_first.get();
    } else {
      newNode->next = std::move(m_first);
      newNode->next->prev = newNode.get();
      m_first = std::move(newNode);
    }
    ++m_size;
  }
  T &front() {
    // added
    const std::lock_guard lck{m_mutex};
    if (empty()) {
      throw std::logic_error{"Containter is empty!"};
    }
    return m_first->data;
  }

  void pop_front() {
    // added
    const std::lock_guard lck{m_mutex};
    if (empty()) {
      throw std::logic_error{"Containter is empty!"};
    }
    if (size() == 1) {
      m_first.reset();
      m_last = nullptr;
      m_size = 0;
      return;
    }
    m_first = std::move(m_first->next);
    m_first->prev = nullptr;
    --m_size;
  }

  bool empty() const {
    // added
    const std::lock_guard lck{m_mutex};
    return m_size == 0;
  }
  size_t size() const {
    // added
    const std::lock_guard lck{m_mutex};
    return m_size;
  }

 private:
  struct Node {
    T data;
    std::unique_ptr<Node> next;
    Node *prev = nullptr;  // prev pointer is not owner
  };

  // added
  mutable std::recursive_mutex m_mutex;

  std::unique_ptr<Node> m_first = nullptr;
  Node *m_last = nullptr;
  size_t m_size = 0;
};

void example() {
  List<int> list;

  auto lambda = [](List<int> &list) {
    for (int i = 0; i < 10; ++i) {
      if (i % 2) {
        list.push_back(i);
      } else {
        list.push_front(i);
      }
    }
  };

  std::thread thr1{lambda, std::ref(list)};
  std::thread thr2{lambda, std::ref(list)};

  thr1.join();
  thr2.join();

  for (size_t i = 0; i < list.size(); ++i) {
    int value = list.back();
    if (i) std::cout << ' ';
    std::cout << value;
    list.pop_back();
  }
}

}  // namespace naive

int main() { naive::example(); }