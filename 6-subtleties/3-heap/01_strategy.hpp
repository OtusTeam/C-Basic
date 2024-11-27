#pragma once

class Unit {
  public:
    Unit(int x, int y) : x_{x}, y_{y} {}
    void move(int x, int y) {
        x_ = x;
        y_ = y;
    }
    void attack() {}

    int health() const { return health_; }

  private:
    int x_;
    int y_;
    int health_ = 100;
};

class Selection {
  public:
    void set(Unit* unit) {
      if (unit == nullptr)
        return;
      current_ = unit;
      }

    void unset() {
      current_ = nullptr; }

    void click(int x, int y) {
        if (current_) {
            current_->move(x, y);
        }
    }

  private:
    Unit *current_ = nullptr;
};
