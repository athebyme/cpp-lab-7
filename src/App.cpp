#include <iostream>
#include "App.h"
#include "Service/ExceptionService.h"
#include "../src/CircularBuffer/Classes/CircularBuffer.h"
#include <algorithm>
using namespace std;
int App::start() {
    CircularBuffer::CircularBuffer<int> buffer(5);
    buffer.push(1);
    buffer.push(2);
    buffer.push(3);

    std::cout << "Size: " << buffer.size() << std::endl;
    std::cout << "Front: " << buffer.front() << std::endl;
    std::cout << "Back: " << buffer.back() << std::endl;

    std::sort(buffer.begin(), buffer.end());


    try{
        buffer.pop();
    }catch (exception &e){
        displayService->displayError(e);
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