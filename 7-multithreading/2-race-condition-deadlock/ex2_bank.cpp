// Emulates bank accounts

#include <chrono>
#include <cstdlib>
#include <vector>
#include <thread>
#include <mutex>
#include <iostream>
#include <random>
#include <string>

const int total_accounts = 10;
const int max_initial_balance = 100;
const double lambda = 100;  // mean transactions per second
const std::chrono::seconds work_time(5);

class sync_account {
public:
    sync_account(int initial_balance)
        : balance_{initial_balance}
    {}

    sync_account(const sync_account &oth) {
        std::lock_guard lock{oth.mutex_};
        balance_ = oth.balance_;
    }

    sync_account(sync_account &&oth) {
        balance_ = oth.balance_;
    }

    sync_account& operator=(const sync_account &oth) {
        sync_account tmp{oth};
        std::lock_guard lock{mutex_};
        std::swap(*this, tmp);
        return *this;
    }

    sync_account& operator=(sync_account &&oth) {
        std::lock_guard lock{mutex_};
        balance_ = oth.balance_;
        return *this;
    }

    bool withdraw(int amount) {
        std::lock_guard lock{mutex_};
        if (amount > balance_)
            return false;
        balance_ -= amount;
        return true;
    }

    bool deposit(int amount) {
        std::lock_guard lock{mutex_};
        balance_ += amount;
        return true;
    }

    friend bool transaction(sync_account &from, sync_account &to, int amount) {
        std::lock_guard lock_from{from.mutex_};
        std::lock_guard lock_to{to.mutex_};
        if (amount > from.balance_) {
            return false;
        }
        from.balance_ -= amount;
        to.balance_ += amount;

        return true;
    }

    int balance() const {
        std::lock_guard lock{mutex_};
        return balance_;
    }

private:
    int balance_;
    mutable std::mutex mutex_;
};

std::vector<sync_account> open_operation_day() {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dist(0, max_initial_balance);
    std::vector<sync_account> accounts;
    for (int i = 0; i < total_accounts; ++i) {
        accounts.emplace_back(dist(gen));
    }
    return accounts;
}

void usefull_work() {
    using namespace std::chrono_literals;
    std::random_device rd;
    std::default_random_engine gen(rd());
    std::exponential_distribution<> dist(lambda);
    std::this_thread::sleep_for(dist(gen) * 1s);
}

void clerk(std::vector<sync_account> &accounts) {
    std::random_device rd;
    std::default_random_engine gen(rd());
    std::uniform_int_distribution<size_t> dist(0, accounts.size() - 1);

    std::chrono::time_point begin = std::chrono::steady_clock::now();

    for (;;) {
        size_t from = dist(gen);
        size_t to = dist(gen);
        if (from == to) {
            continue;
        }
        int amount = 10;
        usefull_work();
        transaction(accounts.at(from), accounts.at(to), amount);
        std::chrono::time_point end = std::chrono::steady_clock::now();
        std::chrono::duration<double> elapsed = end - begin;
        if (elapsed > work_time) {
            break;
        }
    }
}

int main(int argc, char *argv[]) {
    using namespace std;
    if (argc < 2) {
        cout << "Usage: " << argv[0] << " [number of clerks]\n";
        return EXIT_FAILURE;
    }

    int nclerks = stoi(argv[1]);
    if (nclerks < 1) {
        cerr << "Number of clerks must be positive number\n";
        return EXIT_FAILURE;
    }

    vector<sync_account> accounts = open_operation_day();
    vector<thread> clerks;
    for (int i = 0; i < nclerks; ++i) {
        thread clerk_thread{clerk, ref(accounts)};
        cout << "Clerk " << clerk_thread.get_id() << " starts working\n";
        clerks.emplace_back(move(clerk_thread));
    }

    for (auto &clerk_thread: clerks) {
        thread::id clerk_id = clerk_thread.get_id();
        clerk_thread.join();
        cout << "Clerk " << clerk_id << " ends work\n";
    }
}
