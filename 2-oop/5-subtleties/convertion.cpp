#include <iostream>
#include <string>

////////////////////////////////////////////////////////////////////////////////

namespace error {
enum class ErrorCode { Ok, Failed, NotFound, OutOfMemory, NotImplemented };

class Error {
public:
  Error() : m_code{ErrorCode::Ok} {}

  explicit Error(const ErrorCode code) : m_code{code} {}

  bool isError() const { return m_code != ErrorCode::Ok; }

  ErrorCode getError() const { return m_code; }

  /*explicit*/
  operator bool() const { return isError(); }

  bool toBool() const { return isError(); }

private:
  const ErrorCode m_code;
};

//! The function which does something, but could return an error on failure.
Error doSomeImportantTask() {
  const Error result{ErrorCode::NotImplemented};
  // ...
  return result;
}

void example() {
  const Error error = doSomeImportantTask();

  // Calling the method to see - is it error? Understandable...
  if (error.isError()) {
    std::cout << "We have error!" << std::endl;
  } else {
    std::cout << "Everything is good!" << std::endl;
  }

  // Call the Error::operator bool here - Nice and understandable.
  if (error) {
    std::cout << "We have error!" << std::endl;
  } else {
    std::cout << "Everything is good!" << std::endl;
  }

  // Very understandable.
  if (error.toBool()) {
    std::cout << "We have error!" << std::endl;
  } else {
    std::cout << "Everything is good!" << std::endl;
  }

  const bool b = error;
  const float f = error;
  const int i = error;
}
} // namespace error

////////////////////////////////////////////////////////////////////////////////

int main() {

  error::example();

  return 0;
}

/*

Describes a method of creating another type from this type - like "convert".

Good for general cases, such as checking for success, but in specific cases,
it could confuse readers.

Could be explicitly to don't allow implicit conversations.

 */