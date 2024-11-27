#include <cstddef>
#include <iostream>
#include <string>

// Наивный класс String из предыдущего вебинара
class String {
  public:
    String(const char* cString) : data{cString} {}

    // Еще раз поговорим о константном методе класса
    std::size_t length() const
    {
        return data.size();
    }

  private:
    std::string data;
};

void foo(const String& s)
{
    std::cout << "string length " << s.length() << '\n';
}

void base()
{
    const String s("Hello!");
    foo(s);
}


// Код примера из презентации
namespace text
{

class Surface {};

class Text {
  public:
    void render(Surface& target) const
    {
        // ...
    }

    void set(const std::string& text)
    {
        this->text = text;
    }

    std::string get() const
    {
        return text;
    }

  private:
    std::string text;
};

// возможная реализация
void show(const Text& text, Surface& s)
{
    if (text.get().empty())
    {
        Text tmp;
        tmp.set("<none>");
        tmp.render(s);
    }
    else
    {
        text.render(s);
    }
}

}  // namespace text

int main()
{
    base();
}
