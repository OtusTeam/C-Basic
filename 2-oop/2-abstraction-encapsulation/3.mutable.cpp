#include <cstddef>
#include <cstring>

class String {
  public:
    std::size_t length() const
    {
      if (!cacheIsActual) {
        cachedLength = strlen(cStyleStr);
        cacheIsActual = true;
      }
      return cachedLength;
    }

    void set(const char* cStyleStr)
    {
      this->cStyleStr = cStyleStr;
      cacheIsActual = false;
    }

  private:
    const char* cStyleStr = nullptr;
    mutable std::size_t cachedLength = 0;
    mutable bool cacheIsActual = false;
};

int main()
{
    // ....
}
