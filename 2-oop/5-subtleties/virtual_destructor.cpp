#include <cstring>
#include <iostream>

class String {
public:
  virtual const char *data() const = 0;
  virtual size_t size() const = 0;
};

class StringRef : public String {
public:
  StringRef() : m_data{nullptr}, m_size{0} {
    std::cout << "String()" << std::endl;
  }
  StringRef(const char *str) : StringRef{} {
    std::cout << "String(const char*)" << std::endl;

    if (!str)
      return;

    m_size = std::strlen(str);
    if (!m_size)
      return;

    m_data = str;
  }
  ~StringRef() { std::cout << "~String()" << std::endl; }

  const char *data() const override {
    std::cout << "String::data()" << std::endl;
    return m_data;
  }
  size_t size() const override {
    std::cout << "String::size()" << std::endl;
    return m_size;
  }

private:
  const char *m_data;
  size_t m_size;
};

class DynamicString : public String {
public:
  DynamicString() : m_data{nullptr}, m_size{0} {
    std::cout << "DynamicString()" << std::endl;
  }

  explicit DynamicString(const char *str) : DynamicString{} {
    std::cout << "DynamicString(const char *)" << std::endl;
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

  ~DynamicString() {
    std::cout << "~DynamicString()" << std::endl;
    delete[] m_data;
  }

  size_t size() const override {
    std::cout << "DynamicString::size()" << std::endl;
    return m_size;
  }
  const char *data() const override {
    std::cout << "DynamicString::size()" << std::endl;
    return m_data;
  }

private:
  char *m_data;
  size_t m_size;
};

void example() {

  const size_t count = 4;
  String *array[count] = {
      new StringRef{"Just a string"}, new DynamicString{"Dynamic string"},
      new StringRef{"Just a string2"}, new DynamicString{"Dynamic string2"}};

  for (size_t i = 0; i < count; ++i) {
    std::cout << array[i]->data() << std::endl;
  }

  for (size_t i = 0; i < count; ++i) {
    delete array[i];
  }
}

int main() {
  example();

  return 0;
}