#include <iostream>

namespace details
{

enum class Oxidizing {
    Oxygen,
    Ozone,
    //...
};

class Engine {
  public:
    Engine(Oxidizing oxidizing) : oxidizingAgent{oxidizing} {}
    bool run() { return pumpFuel() && turbopump() && /*...*/ fire(); }
    void setOxidizingAgent(Oxidizing oxidizing) { oxidizingAgent = oxidizing; }

  private:
    bool pumpFuel() { return true; }
    bool turbopump() { return true; }
    bool fire() { return true; }

  private:
    Oxidizing oxidizingAgent{Oxidizing::Oxygen};
};

struct CrewCapsule {
    //...
};

struct FuelTank {
    //...
};

struct NavigationSystem {
    // ...
};

  //...

}  // namespace details

class Spaceflight {
  public:
    void setEngine(const details::Engine& engine) { this->engine = engine; }
    bool launch() {
      // navSystem.check()
      // crewCapsule.check()
      // ...
      // fuel.pump()

      return engine.run();
    }

  private:
    // maybe better use std::optional or builder pattern
    details::Engine engine{details::Oxidizing::Oxygen};
    details::CrewCapsule crewCapsule;
    details::FuelTank fuel;
    details::NavigationSystem navSystem;
};

struct Location {
    double x;
    double y;
};

class Payload {};
class Fuel {};

Spaceflight runSpaceflight() {
    Spaceflight s;
    if (s.launch()) {
       return s;
    } else {
        // throw ... but we don't know anything about it
        return {};
    }
}

int main()
{
    runSpaceflight();
}
