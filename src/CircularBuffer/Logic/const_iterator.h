#ifndef CPP_LAB_7_CONST_ITERATOR_H
#define CPP_LAB_7_CONST_ITERATOR_H
#include "../Classes/CircularBuffer.h"

namespace CircularBuffer{
    template <typename T>
    class CircularBuffer<T>::const_iterator {
    public:
        using iterator_category = std::random_access_iterator_tag;
        using value_type = T;
        using difference_type = ptrdiff_t;
        using pointer = const T*;
        using reference = const T&;

        const_iterator() = default;
        const_iterator(const CircularBuffer<T>* buffer, size_t index)
                : buffer_(buffer), index_(index)
        {
        }

        reference operator*() const
        {
            return buffer_->at(index_);
        }

        pointer operator->() const
        {
            return &buffer_->at(index_);
        }

        const_iterator& operator++()
        {
            index_ = (index_ + 1) % buffer_->size();
            return *this;
        }

        const_iterator operator++(int)
        {
            const_iterator tmp = *this;
            ++(*this);
            return tmp;
        }

        const_iterator& operator--()
        {
            index_ = (index_ + buffer_->size() - 1) % buffer_->size();
            return *this;
        }

        const_iterator operator--(int)
        {
            const_iterator tmp = *this;
            --(*this);
            return tmp;
        }

        const_iterator& operator+=(difference_type n)
        {
            index_ = (index_ + n) % buffer_->size();
            return *this;
        }

        const_iterator operator+(difference_type n) const
        {
            const_iterator tmp = *this;
            return tmp += n;
        }

        const_iterator& operator-=(difference_type n)
        {
            index_ = (index_ + buffer_->size() - n) % buffer_->size();
            return *this;
        }

        const_iterator operator-(difference_type n) const
        {
            const_iterator tmp = *this;
            return tmp -= n;
        }

        difference_type operator-(const const_iterator& other) const
        {
            return static_cast<difference_type>(index_) - static_cast<difference_type>(other.index_);
        }

        bool operator==(const const_iterator& other) const
        {
            return buffer_ == other.buffer_ && index_ == other.index_;
        }

        bool operator!=(const const_iterator& other) const
        {
            return !(*this == other);
        }

        bool operator<(const const_iterator& other) const
        {
            return buffer_ == other.buffer_ && index_ < other.index_;
        }

        bool operator>(const const_iterator& other) const
        {
            return buffer_ == other.buffer_ && index_ > other.index_;
        }

        bool operator<=(const const_iterator& other) const
        {
            return buffer_ == other.buffer_ && index_ <= other.index_;
        }

        bool operator>=(const const_iterator& other) const
        {
            return buffer_ == other.buffer_ && index_ >= other.index_;
        }

    private:
        const CircularBuffer<T>* buffer_ = nullptr;
        size_t index_ = 0;
    };

}
#endif
