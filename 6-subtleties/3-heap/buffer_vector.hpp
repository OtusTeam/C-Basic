#pragma once

#include <algorithm>
#include <functional>
#include <memory>

class buffer {
  public:
    using value_type = char;

    buffer() = default;

    explicit buffer(size_t size) {
        data_.resize(size);
    }

    buffer(const buffer &other) = default;

    buffer &operator=(const buffer &other) = default;

    buffer(buffer &&other) = default;

    buffer &operator=(buffer &&other) = default;

    void clear() noexcept {
        data_.clear();
    }

    bool empty() const noexcept {
        return data_.empty();
    }

    size_t size() const noexcept {
        return data_.size();
    }

    const value_type *data() const noexcept {
        return data_.data();
    }

    value_type *data() noexcept {
        return data_.data();
    }

    const value_type &operator[](size_t idx) const noexcept {
        return data_[idx];
    }

    value_type &operator[](size_t idx) noexcept {
        return data_[idx];
    }

  private:
    std::vector<value_type> data_;
};
