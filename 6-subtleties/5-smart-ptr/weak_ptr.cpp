#include <cassert>
#include <iostream>
#include <memory>
#include <vector>

void weak_ptr_example() {
    std::weak_ptr<int> weak;
    {
        auto shared = std::make_shared<int>(42);

        weak = shared;
        //std::cout << *weak << std::endl;
        std::cout << *shared << std::endl;

        std::shared_ptr<int> x = weak.lock();
        assert(x);
    }
    auto x = weak.lock();
    assert(!x);
}

template <typename T>
class shared_ptr {
    struct ctrl_block {
        std::size_t counter;

        std::size_t weak_counter;
        /* deleter and smth else */
        ctrl_block() : counter{1}, weak_counter{0} {}
    };

    ctrl_block *ctrl;
    T *ptr;

  public:
    shared_ptr(T *ptr_) : ctrl{new ctrl_block}, ptr{ptr_} {}

    shared_ptr(const shared_ptr &other) : ctrl{other.ctrl}, ptr{other.ptr} {
        ++ctrl->counter;
    }

    ~shared_ptr() {
        if (--ctrl->counter == 0) {
            delete (ptr);

            if (ctrl->weak_counter == 0)
                delete (ctrl);
        }
    }
};

struct Observable;
struct Observer {
  public:
    explicit Observer(int value, std::shared_ptr<Observable> observable) 
    : m_value(value)
    , m_observable(observable) 
    {}

    void notify() { std::cout << "notify: " << m_value << std::endl; }

  private:
    int m_value;
    std::shared_ptr<Observable> m_observable;
};

struct Observable {
    void registerObserver(const std::shared_ptr<Observer> &observer) {
        m_observers.emplace_back(observer);
    }

    void notify() {
        for (auto &obs : m_observers) {
            auto ptr = obs.lock();
            if (ptr)
                ptr->notify();
        }
    }

  private:
    std::vector<std::weak_ptr<Observer>> m_observers;
};

void observer_test() {

    auto observable = std::make_shared<Observable>();

    auto obs1 = std::make_shared<Observer>(1, observable);
    observable->registerObserver(obs1);

    auto obs2 = std::make_shared<Observer>(2, observable);
    observable->registerObserver(obs2);

    auto obs3 = std::make_shared<Observer>(3, observable);
    observable->registerObserver(obs3);

    {
        auto obs4 = std::make_shared<Observer>(4, observable);
        observable->registerObserver(obs4);
    }

    observable->notify();
}

int main()
{
    weak_ptr_example();
    observer_test();

    return 0;
}
