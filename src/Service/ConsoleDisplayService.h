#ifndef CPP_LAB_2_CONSOLEDISPLAYSERVICE_H
#define CPP_LAB_2_CONSOLEDISPLAYSERVICE_H

#include <exception>
#include "DisplayServiceInterface.h"

namespace Service {
    class ConsoleDisplayService: public Service::DisplayServiceInterface {
        void displayError(std::exception const &e) override;
        void displayInformation(const char* message, ...) override;
    };
}
#endif
