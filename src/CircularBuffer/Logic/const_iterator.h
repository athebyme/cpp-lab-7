#ifndef CPP_LAB_7_CONST_ITERATOR_H
#define CPP_LAB_7_CONST_ITERATOR_H
#include "../Classes/CircularBuffer.h"

namespace CircularBuffer{
    template <typename T>
    class CircularBuffer<T>::const_iterator {
    public:
        using iterator_category = std::random_access_iterator_tag;
        using value_type = T;
        using difference_type = std::ptrdiff_t;
        using pointer = const T*;
        using reference = const T&;

        const_iterator(const CircularBuffer& buffer, size_t index) :
                buffer_(buffer),
                index_(index)
        {}

        const_iterator(const const_iterator& other) = default;
        const_iterator(const iterator& other) :
                buffer_(other.buffer_),
                index_(other.index_)
        {}

        const_iterator& operator=(const const_iterator& other) = default;
        const_iterator& operator=(const iterator& other) {
            buffer_ = other.buffer_;
            index_ = other.index_;
            return *this;
        }

        reference operator*() const { return buffer_[index_]; }
        pointer operator->() const { return &buffer_[index_]; }

        const_iterator& operator++() { ++index_; return *this; }
        const_iterator operator++(int) { const_iterator temp = *this; ++index_; return temp; }
        const_iterator& operator--() { --index_; return *this; }
        const_iterator operator--(int) { const_iterator temp = *this; --index_; return temp; }

        const_iterator& operator+=(difference_type n) { index_ += n; return *this; }
        const_iterator operator+(difference_type n) const { return const_iterator(buffer_, index_ + n); }
        friend const_iterator operator+(difference_type n, const const_iterator& it) { return const_iterator(it.buffer_, n + it.index_); }
        const_iterator& operator-=(difference_type n) { index_ -= n; return *this; }
        const_iterator operator-(difference_type n) const { return const_iterator(buffer_, index_ - n); }
        difference_type operator-(const const_iterator& other) const { return index_ - other.index_; }

        reference operator[](difference_type n) const { return buffer_[index_ + n]; }

        bool operator==(const const_iterator& other) const { return index_ == other.index_; }
        bool operator!=(const const_iterator& other) const { return index_ != other.index_; }
        bool operator<(const const_iterator& other) const { return index_ < other.index_; }
        bool operator<=(const const_iterator& other) const { return index_ <= other.index_; }
        bool operator>(const const_iterator& other) const { return index_ > other.index_; }
        bool operator>=(const const_iterator& other) const { return index_ >= other.index_; }

    private:
        const CircularBuffer& buffer_;
        size_t index_;
    };
}
#endif
