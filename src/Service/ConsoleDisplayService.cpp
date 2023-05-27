#include "ConsoleDisplayService.h"
#include <iostream>
#include <cstdarg>

namespace Service {
    void ConsoleDisplayService::displayError(std::exception const &e) {
        std::cerr << "error >" << e.what() << std::endl;
    }
    void ConsoleDisplayService::displayInformation(const char* format, ...) {
        va_list args;
        va_start(args, format);
        vfprintf(stdout, format, args);
        va_end(args);
    }

}
