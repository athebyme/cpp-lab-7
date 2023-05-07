#include "src/App.h"
#include "src/Service/ConsoleDisplayService.h"
int main() {
    return App::create(
            new Service::ConsoleDisplayService()
            )->start();
}
