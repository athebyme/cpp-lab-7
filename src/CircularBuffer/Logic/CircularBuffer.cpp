
#include "../Classes/CircularBuffer.h"

namespace CircularBuffer {
    template <typename T>
    T& CircularBuffer<T>::at(size_t index) {
        if (index >= size_)
            throw std::out_of_range("CircularBuffer::at() index out of range");
        return (*this)[index];
    }

    template <typename T>
    const T& CircularBuffer<T>::at(size_t index) const {
        if (index >= size_)
            throw std::out_of_range("CircularBuffer::at() index out of range");
        return (*this)[index];
    }

    template <typename T>
    void CircularBuffer<T>::push(const T& value) {
        if (full())
            pop();
        data_[tail_] = value;
        tail_ = (tail_ + 1) % capacity_;
        ++size_;
    }

    template <typename T>
    void CircularBuffer<T>::pop() {
        if (empty())
            return;
        head_ = (head_ + 1) % capacity_;
        --size_;
    }
}