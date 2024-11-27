#pragma once

#include <algorithm>
#include <functional>
#include <memory>

class buffer {
  public:
    using value_type = char;

    buffer() = default;

    explicit buffer(size_t size)
        : size_{size}
        , data_{std::make_unique<value_type[]>(size)} {
    }

    buffer(const buffer &other)
        : size_{other.size_}
        , data_{std::make_unique<value_type[]>(other.size_)} {
        std::copy_n(other.data_.get(), other.size_, data_.get());
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
        , data_{std::move(other.data_)} {
        other.size_ = 0;
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
        data_.reset();
        size_ = 0;
    }

    bool empty() const noexcept {
        return size_ == 0;
    }

    size_t size() const noexcept {
        return size_;
    }

    const value_type *data() const noexcept {
        return data_.get();
    }

    value_type *data() noexcept {
        return data_.get();
    }

    const value_type &operator[](size_t idx) const noexcept {
        return data_[idx];
    }

    value_type &operator[](size_t idx) noexcept {
        return data_[idx];
    }

  private:
    size_t size_ = 0;
    std::unique_ptr<value_type[]> data_;
};
