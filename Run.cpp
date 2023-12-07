//
// Created by aliye on 4/24/2023.
//

#include "Run.h"


void Run::run(std::string config) {
    std::ifstream config_stream(config);
    nlohmann::json config_read = nlohmann::json::parse(config_stream);
    std::vector<std::string> cities = config_read.at("cities");
    int forecast_days = config_read.at("forecast_days");
    weather_controller config_run;
    config_run.get_weather_data(cities, forecast_days);
}
