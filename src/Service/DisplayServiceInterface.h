#ifndef CPP_LAB_2_DISPLAYSERVICEINTERFACE_H
#define CPP_LAB_2_DISPLAYSERVICEINTERFACE_H
#include <exception>

namespace Service {
    class DisplayServiceInterface {
    public:
        virtual void displayError(std::exception const &e) = 0;
        virtual void displayInformation(const char* message, ...) = 0;
    };
}
#endif
