#ifndef CPP_LAB_7_CIRCULARBUFFER_H
#define CPP_LAB_7_CIRCULARBUFFER_H
#include <vector>
#include <exception>
#include <stdexcept>

using namespace std;
namespace CircularBuffer{
    template <typename T>
    class CircularBuffer {
    public:
        explicit CircularBuffer(size_t capacity) :
                data_(capacity),
                capacity_(capacity),
                size_(0),
                head_(0),
                tail_(0)
        {}

        [[nodiscard]] size_t size() const { return size_; }
        [[nodiscard]] size_t capacity() const { return capacity_; }
        [[nodiscard]] bool empty() const { return size_ == 0; }
        [[nodiscard]] bool full() const { return size_ == capacity_; }

        T& operator[](size_t index) { return data_[(head_ + index) % capacity_]; }
        const T& operator[](size_t index) const { return data_[(head_ + index) % capacity_]; }
        T& at(size_t index);
        const T& at(size_t index) const;
        T& front() { return data_[head_]; }
        const T& front() const { return data_[head_]; }
        T& back() { return data_[(tail_ == 0) ? (capacity_ - 1) : (tail_ - 1)]; }
        const T& back() const { return data_[(tail_ == 0) ? (capacity_ - 1) : (tail_ - 1)]; }

        void push(const T& value);
        void pop();
        void clear() { size_ = 0; head_ = 0; tail_ = 0; }

        class iterator;
        class const_iterator;

        iterator begin();
        const_iterator begin() const;
        iterator end();
        const_iterator end() const;
        const_iterator cbegin() const;
        const_iterator cend() const;

    private:
        std::vector<T> data_;
        size_t capacity_;
        size_t size_;
        size_t head_;
        size_t tail_;
    };


}

#endif