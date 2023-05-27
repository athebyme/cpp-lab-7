
#include "../Classes/CircularBuffer.h"

namespace CircularBuffer {
    template <typename T>
    T& CircularBuffer<T>::at(size_t index) {
        if (index >= size_) {
            throw std::out_of_range("CircularBuffer<T>::at() - index out of range");
        }
        return data_[(head_ + index) % capacity_];
    }

    template <typename T>
    void CircularBuffer<T>::push(const T& value) {
        if (size_ < capacity_) {
            ++size_;
        } else {
            head_ = (head_ + 1) % capacity_;
        }
        data_[tail_] = value;
        tail_ = (tail_ + 1) % capacity_;
    }

    template <typename T>
    void CircularBuffer<T>::pop() {
        if (size_ > 0) {
            --size_;
            head_ = (head_ + 1) % capacity_;
        }
    }

    template <typename T>
    typename CircularBuffer<T>::iterator CircularBuffer<T>::begin() {
        return iterator(data_.begin(), data_.end(), capacity_, head_, tail_, size_);
    }

    template <typename T>
    typename CircularBuffer<T>::const_iterator CircularBuffer<T>::begin() const {
        return const_iterator(data_.begin(), data_.end(), capacity_, head_, tail_, size_);
    }

    template <typename T>
    typename CircularBuffer<T>::iterator CircularBuffer<T>::end() {
        return iterator(data_.begin(), data_.end(), capacity_, head_, tail_, size_) + size_;
    }

    template <typename T>
    typename CircularBuffer<T>::const_iterator CircularBuffer<T>::end() const {
        return const_iterator(data_.begin(), data_.end(), capacity_, head_, tail_, size_) + size_;
    }

    template <typename T>
    typename CircularBuffer<T>::const_iterator CircularBuffer<T>::cbegin() const {
        return const_iterator(data_.begin(), data_.end(), capacity_, head_, tail_, size_);
    }

    template <typename T>
    typename CircularBuffer<T>::const_iterator CircularBuffer<T>::cend() const {
        return const_iterator(data_.begin(), data_.end(), capacity_, head_, tail_, size_) + size_;
    }

    template<typename T>
    const T &CircularBuffer<T>::at(size_t index) const {
        if (index >= size_) {
            throw std::out_of_range("CircularBuffer<T>::at() - index out of range");
        }
        return data_[(head_ + index) % capacity_];
    }
}