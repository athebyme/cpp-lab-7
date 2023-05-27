#ifndef CPP_LAB_7_ITERATOR_H
#define CPP_LAB_7_ITERATOR_H
#include "../Classes/CircularBuffer.h"


namespace CircularBuffer {
    template <typename T>
    class CircularBuffer<T>::iterator {
    public:
        using iterator_category = std::random_access_iterator_tag;
        using value_type = T;
        using difference_type = std::ptrdiff_t;
        using pointer = T*;
        using reference = T&;

        iterator(CircularBuffer& buffer, size_t index) :
                buffer_(buffer),
                index_(index)
        {}

        iterator(const iterator& other) = default;
        iterator& operator=(const iterator& other) = default;

        reference operator*() const { return buffer_[index_]; }
        pointer operator->() const { return &buffer_[index_]; }

        iterator& operator++() { ++index_; return *this; }
        iterator operator++(int) { iterator temp = *this; ++index_; return temp; }
        iterator& operator--() { --index_; return *this; }
        iterator operator--(int) { iterator temp = *this; --index_; return temp; }

        iterator& operator+=(difference_type n) { index_ += n; return *this; }
        iterator operator+(difference_type n) const { return iterator(buffer_, index_ + n); }
        friend iterator operator+(difference_type n, const iterator& it) { return iterator(it.buffer_, n + it.index_); }
        iterator& operator-=(difference_type n) { index_ -= n; return *this; }
        iterator operator-(difference_type n) const { return iterator(buffer_, index_ - n); }
        difference_type operator-(const iterator& other) const { return index_ - other.index_; }

        reference operator[](difference_type n) const { return buffer_[index_ + n]; }

        bool operator==(const iterator& other) const { return index_ == other.index_; }
        bool operator!=(const iterator& other) const { return index_ != other.index_; }
        bool operator<(const iterator& other) const { return index_ < other.index_; }
        bool operator<=(const iterator& other) const { return index_ <= other.index_; }
        bool operator>(const iterator& other) const { return index_ > other.index_; }
        bool operator>=(const iterator& other) const { return index_ >= other.index_; }

    private:
        CircularBuffer& buffer_;
        size_t index_;
    };
}

#endif //CPP_LAB_7_ITERATOR_H
