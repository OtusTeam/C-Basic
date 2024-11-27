#include <chrono>
#include <cstdlib>
#include <iostream>
#include <random>
#include <string>
#include <thread>

// Added, and no mutex anymore
#include <atomic>

const int initial_tickets_count = 100;
const double lambda = 10;  // mean tickets sold per second

void useful_work() {
  using namespace std::chrono_literals;
  std::random_device rd;
  std::default_random_engine gen(rd());
  std::exponential_distribution<> dist(lambda);
  std::this_thread::sleep_for(dist(gen) * 1s);
}

void cashier(std::atomic<int> &tickets_left) {
  while (tickets_left > 0) {
    auto tickets_actual = tickets_left.load();
    if (tickets_actual == 0) {
      break;
    }

    useful_work();

    while (!tickets_left.compare_exchange_weak(tickets_actual,
                                               tickets_actual - 1)) {
      if (tickets_actual == 0) {
        break;
      }
    }

    useful_work();
  }
}

int main(int argc, char *argv[]) {
  using namespace std;

  if (argc < 2) {
    cout << "Usage: " << argv[0] << " [number of cashiers]\n";
    return EXIT_FAILURE;
  }

  const auto nCashiers = stoi(argv[1]);
  if (nCashiers < 1) {
    cerr << "number of cashiers must be positive integer\n";
    return EXIT_FAILURE;
  }

  std::atomic<int> tickets = initial_tickets_count;
  std::vector<std::thread> cashiers;
  for (int i = 0; i < nCashiers; ++i) {
    cashiers.emplace_back(cashier, ref(tickets));
  }

  for (auto &cashier : cashiers) {
    cashier.join();
  }
  cout << "Tickets left: " << tickets << '\n';
}
