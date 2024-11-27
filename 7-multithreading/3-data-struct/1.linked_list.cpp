#include <cassert>
#include <exception>
#include <iostream>
#include <memory>
#include <utility>

namespace basic {

template <typename T>
struct List {
  void push_back(const T &value) {
    // 1. Create new element
    std::unique_ptr<Node> newNode = std::make_unique<Node>();
    newNode->data = value;

    // 2. Insert
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

    // 3. New size
    ++m_size;
  }
  T &back() {
    if (empty()) {
      throw std::logic_error{"Containter is empty!"};
    }
    return m_last->data;
  }
  void pop_back() {
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
    if (empty()) {
      throw std::logic_error{"Container is empty!"};
    }
    return m_first->data;
  }
  void pop_front() {
    if (empty()) {
      throw std::logic_error{"Container is empty!"};
    }
    if (size() == 1) {
      m_first.reset();
      m_last = nullptr;
      m_size = 0;
    } else {
      m_first = std::move(m_first->next);
      m_first->prev = nullptr;
      --m_size;
    }
  }

  bool empty() { return m_size == 0; }
  size_t size() const { return m_size; }

 private:
  struct Node {
    T data;
    std::unique_ptr<Node> next;
    Node *prev = nullptr;  // prev pointer is not owner
  };

  std::unique_ptr<Node> m_first = nullptr;
  Node *m_last = nullptr;
  size_t m_size = 0;
};

void example() {
  List<int> list;

  if (!list.empty()) {  // this thread list.empty == false |
    list.pop_back();    // thread 2. pop_back() list.empty() == true;
  }

  const int count = 10;
  for (int i = 0; i < count * 2; ++i) {
    if (i % 2) {
      list.push_back(i);
    } else {
      list.push_front(i);
    }
  }

  for (int i = 0; i < count; ++i) {
    int value = list.front();
    if (i) {
      std::cout << ' ';
    }
    std::cout << value;
    list.pop_front();
  }
  std::cout << std::endl;

  for (int i = 0; i < count; ++i) {
    int value = list.back();
    if (i) std::cout << ' ';
    std::cout << value;
    list.pop_back();
  }
  std::cout << std::endl;
}

}  // namespace basic

int main() { basic::example(); }