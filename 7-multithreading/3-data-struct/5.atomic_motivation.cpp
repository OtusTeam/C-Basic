#include <chrono>
#include <cstdlib>
#include <iostream>
#include <mutex>
#include <random>
#include <string>
#include <thread>

const int initial_tickets_count = 10;
const double lambda = 10;  // mean tickets sold per second

void useful_work() {
  using namespace std::chrono_literals;
  std::random_device rd;
  std::default_random_engine gen(rd());
  std::exponential_distribution<> dist(lambda);
  std::this_thread::sleep_for(dist(gen) * 1s);
}

void cashier(int &tickets_left, std::mutex &mtx) {
  for (;;) {
    {
      const std::lock_guard lock(mtx);

      if (tickets_left == 0) {
        break;
      }
      useful_work();
      --tickets_left;
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

  int nCashiers = stoi(argv[1]);
  if (nCashiers < 1) {
    cerr << "number of cashiers must be positive integer\n";
    return EXIT_FAILURE;
  }

  int tickets = initial_tickets_count;
  std::mutex mtx;
  std::vector<std::thread> cashiers;
  for (int i = 0; i < nCashiers; ++i) {
    cashiers.emplace_back(cashier, ref(tickets), ref(mtx));
  }

  for (auto &cashier : cashiers) {
    cashier.join();
  }
  cout << "Tickets left: " << tickets << '\n';
}
