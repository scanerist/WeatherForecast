//
// Created by aliye on 4/14/2023.
//

#include "weather_controller.h"
void weather_controller::get_weather_data(std::vector<std::string> cities, int days) {

    wearherView *weather_view;
    weather_days = days;

    weather_view->WeatherInterface(cities[city], days);
    while (true) {
        const int key = getch();
        if (key == 27) {
            exit(0);
        }
        if (key == '+') {
            if (weather_days < 16) {
                weather_days++;
                system("cls");
                weather_view->WeatherInterface(cities[city], weather_days);
            }
        }
        if (key == '-') {
            if (weather_days > 1) {
                weather_days--;
                system("cls");
                weather_view->WeatherInterface(cities[city], weather_days);
            }
        }
        if (key == 'n') {
            if (city < cities.size() - 1) {
                city++;
                system("cls");
                weather_view->WeatherInterface(cities[city], weather_days);
            }
        }
        if (key == 'p') {
            if (city > 0) {
                city--;
                system("cls");
                weather_view->WeatherInterface(cities[city], weather_days);
            }
        }
        if (key == 'f') {
            system("cls");
            for (const auto & citie : cities) {
                weather_view->DO_YOU_HAVE_THE_BEST_WEATHER(citie);

            }
        }

    }
}

