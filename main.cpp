#include <ftxui/dom/elements.hpp>
#include <ftxui/screen/screen.hpp>
#include <iostream>
#include "weather_controller.h"
#include"Run.h"



int main() {
    std::vector<std::string> cities = {"Moscow", "Baku", "London", "Tokyo"};
    Run start;
    start.run("config.json");
}