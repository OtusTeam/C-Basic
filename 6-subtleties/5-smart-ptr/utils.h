#include <algorithm>
#include <iostream>
#include <iterator>

#include <vector>
#include <list>

namespace {

class tracer {

    int val;
    int& counter;

public:

    tracer(int v, int& cnt) : val(v), counter(cnt) { }

    // std::sort requirenments (MoveAssignable and MoveConstructible)
    tracer(tracer&&) = default;
    tracer& operator=(tracer&& other) { val = other.val; return *this; };
    bool operator < (const tracer& other) { // Compare
        counter++;
        std::cout << "operator< : (" << val << ") < (" << other.val << ")\n";
        return val < other.val;
    }
    bool operator == (const tracer& other) {
        std::cout << "operator==: (" << val << ") < (" << other.val << ")\n";
        return val == other.val;
    }

    friend std::ostream& operator<<(std::ostream& os, const tracer& tr) {
        os << tr.val;
        return os;
    }

    // std::copy requirenments
    tracer(const tracer&) = default; 

};

template<typename T>
std::ostream& operator<<(std::ostream& os, std::vector<T> vec) {
    std::copy(vec.begin(), vec.end(), std::ostream_iterator<T>(os, " "));
    return os;
}

template<typename T>
std::ostream& operator<<(std::ostream& os, std::list<T> vec) {
    std::copy(vec.begin(), vec.end(), std::ostream_iterator<T>(os, " "));
    return os;
}

}

#define PRETTY_COUT(...) pretty_cout_impl(#__VA_ARGS__, '\n', __VA_ARGS__)
#define PRETTY_COUT_TAB(...) pretty_cout_impl(#__VA_ARGS__, '\t', __VA_ARGS__)

template<typename... Args>
void pretty_cout_impl(const char* str, const char del, Args... args) {
    size_t max_name_len = 0;
    size_t pos = 0;
    const std::string names(str);
    std::vector<std::string> vs(sizeof...(Args));
    std::for_each(vs.begin(), vs.end(), [&](auto& str) {
            auto tmp = names.find(',', pos);
            tmp = tmp > names.size() ? names.size() : tmp;
            str = names.substr(pos, tmp - pos);
            max_name_len = std::max(tmp - pos, max_name_len);
            pos = tmp + 2;
        });
    if (del == '\n')
        std::for_each(vs.begin(), vs.end(), [max_name_len](auto& str) { 
                str += std::string(max_name_len - str.size(), ' ');
            });
    size_t k = 0;
    ( void(std::cout << vs[k++] << ": " << args << del), ... );
    
    if (del != '\n')
        std::cout << std::endl;
}