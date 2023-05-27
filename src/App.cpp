#include "App.h"
#include "Service/ExceptionService.h"
using namespace std;
int App::start() {
    try {

    }catch (std::exception const &e) {
        this->displayService->displayError(e);
        return -1;
    }
    return 0;
}

App::App(
        Service::DisplayServiceInterface* displayService
) {
    this->displayService = displayService;
}

App *App::create(Service::DisplayServiceInterface* displayService) {
    return new App(displayService);
}