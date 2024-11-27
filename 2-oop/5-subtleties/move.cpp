#include <cstring>
#include <iostream>

class DynamicString {
public:
  DynamicString() : m_data{nullptr}, m_size{0} {}

  explicit DynamicString(const char *str) : DynamicString{} {
    if (str == nullptr)
      return;
    // First need to check the length of the [str]
    size_t length = std::strlen(str);
    if (!length)
      return;
    // Now we need to allocate memory for the [length] symbols
    m_data = new char[length + 1]; // one more symbol for the zero-termination
    // And now we can copy all symbols from the [str] to the our memory;
    for (size_t i = 0; i < length; ++i) {
      m_data[i] = str[i];
    }
    // Add one more symbol for the zero-termination
    m_data[length] = '\0';
    // Set a correct [m_size] value
    m_size = length;
  }

  // Copy ctor
  DynamicString(const DynamicString &other) : DynamicString{other.data()} {
    std::cout << "DynamicString(const DynamicString&)" << std::endl;
  }

  // Move ctor
  DynamicString(DynamicString &&other) { // r-value reference
    m_data = other.m_data;
    other.m_data = nullptr;
    m_size = other.m_size;
    other.m_size = 0;
  }

  ~DynamicString() {
    delete[] m_data;
    std::cout << "~DynamicString" << std::endl;
  }

  size_t size() const { return m_size; }
  char *data() const { return m_data; }

  // Copy assignment operator
  DynamicString &operator=(const DynamicString &rhs) {
    std::cout << "DynamicString::operator=" << std::endl;
    DynamicString temp{rhs};

    char *ptr = m_data;
    m_data = temp.m_data;
    temp.m_data = ptr;

    size_t size = m_size;
    m_size = temp.m_size;
    temp.m_size = size;

    return *this;
  }

  // Move assignment operator
  DynamicString &operator=(DynamicString &&rhs) {
    DynamicString tmp{std::move(rhs)};
    return *this = tmp;
  }

  DynamicString &operator+=(const char *str) {
    if (str == nullptr)
      return *this;
    // First check the length of the [str]
    size_t length = std::strlen(str);
    if (!length)
      return *this;

    // Allocate new memory region with size = [length] + [m_size]
    char *new_memory = new char[length + m_size + 1];

    // Copy first old symbols - from the old memory
    for (size_t i = 0; i < m_size; ++i) {
      new_memory[i] = m_data[i];
    }
    // Copy next all symbols from the [str]
    for (size_t i = 0; i < length; ++i) {
      new_memory[m_size + i] = str[i];
    }
    // Add one more symbol for zero termination
    new_memory[m_size + length] = '\0';

    // delete old memory region
    delete[] m_data;

    // Assign new memory region and size
    m_data = new_memory;
    m_size = m_size + length;

    return *this;
  }

  DynamicString &operator+=(const DynamicString &str) {
    return *this += str.data();
  }

private:
  char *m_data;
  size_t m_size;
};

DynamicString get_str(const char *ptr) {
  DynamicString str{ptr}; // DynamicString::DynamicString(const char *)
  return str;             // DynamicString::DynamicString(const DynamicString&)
} // DynamicString::~DynamicString()

void example() {

  DynamicString str = get_str("Hello");
  DynamicString str1{"Hello"};
  DynamicString str2{str1}; // copy construct

  str2 = str1;                                // copy assignment
  str2 = static_cast<DynamicString &&>(str1); // move assignment
  str2 = std::move(str1);

  DynamicString str3{get_str("Hello")}; // move constructor
  // DynamicString str4{ str1 + str2 }; // move constructor

  const size_t count = 3;
  DynamicString array[3];

  for (size_t i = 0; i < count; ++i) {
    DynamicString full_name;
    // enter you first name, please
    full_name += "First ";
    // enter you middle name, please
    full_name += "Middle ";
    // enter you last name, please
    full_name += "Third";
    array[i] = full_name;
  }

  std::cout << "We have next employees:" << std::endl;
  for (const auto &i : array) {
    std::cout << i.data() << std::endl;
  }
}

void func(int &&a) { std::cout << "int&&" << std::endl; }

void func(int &a) { std::cout << "int&" << std::endl; }

int main() {
  example();
  return 0;
}