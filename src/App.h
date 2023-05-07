#ifndef CPP_LAB_5_APP_H
#define CPP_LAB_5_APP_H
#include "Service/DisplayServiceInterface.h"

class App {
private:
    Service::DisplayServiceInterface* displayService;
public:
    explicit App(
            Service::DisplayServiceInterface* displayService
    );
    int start();
    static App* create(Service::DisplayServiceInterface* displayService);
};

#endif
