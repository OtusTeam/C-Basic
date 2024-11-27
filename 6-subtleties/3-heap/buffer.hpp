#pragma once

#include <algorithm>
#include <functional>

class buffer {
  public:

    using value_type = char;

    buffer() = default;

    explicit buffer(size_t size)
        : size_{size}
        , data_{new value_type[size]} {
    }

    ~buffer() {
        clear();
    }

    buffer(const buffer &other)
        : size_{other.size_}
        , data_{new value_type[other.size_]} {
        std::copy_n(other.data_, other.size_, data_);
    }

    buffer &operator=(const buffer &other) {
        if (this == &other) {
            return *this;
        }
        buffer tmp{other};
        swap(tmp);
        return *this;
    }

    buffer(buffer &&other) noexcept
        : size_{other.size_}
        , data_{other.data_} {
        other.size_ = 0;
        other.data_ = nullptr;
    }

    buffer &operator=(buffer &&other) noexcept {
        buffer tmp{std::move(other)};
        swap(tmp);
        return *this;
    }

    void swap(buffer &other) noexcept {
        std::swap(size_, other.size_);
        std::swap(data_, other.data_);
    }

    void clear() noexcept {
        delete[] data_;
        size_ = 0;
        data_ = 0;
    }

    bool empty() const noexcept {
        return size_ == 0;
    }

    size_t size() const noexcept {
        return size_;
    }

    const value_type *data() const noexcept {
        return data_;
    }

    value_type *data() noexcept {
        return data_;
    }

    const value_type &operator[](size_t idx) const noexcept {
        return data_[idx];
    }

    value_type &operator[](size_t idx) noexcept {
        return data_[idx];
    }

  private:
    size_t size_ = 0;
    value_type *data_ = nullptr;
};
