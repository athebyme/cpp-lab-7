#ifndef CPP_LAB_5_EXCEPTIONSERVICE_H
#define CPP_LAB_5_EXCEPTIONSERVICE_H


#include <exception>
namespace CustomExceptions {
    class BufferIsFull : std::exception{
        const char *what() const noexcept override {
            return "ЧЗХ";
    }
};
}

#endif
