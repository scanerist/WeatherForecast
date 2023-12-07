//
// Created by aliye on 4/7/2023.
//

#include <iostream>
#include "weatherdata.h"

void weatherdata::get_weather_data_information(std::string city, int forecast_days) {
    coordinates_data coordinates;
    coordinates.city_coordinates(city);
        cpr::Response weather_response = cpr::Get(cpr::Url{"https://api.open-meteo.com/v1/forecast"},
                                                  cpr::Parameters{{"latitude", coordinates.get_latitude()},
                                                                  {"longitude", coordinates.get_longitude()},
                                                                  {"timezone", "GMT"},
                                                                  {"hourly", "weathercode"},
                                                                  {"hourly", "relativehumidity_2m"},
                                                                  {"hourly", "windspeed_10m"},
                                                                  {"hourly", "winddirection_10m"},
                                                                  {"hourly", "temperature_2m"},
                                                                  {"daily", "temperature_2m_max"},
                                                                  {"forecast_days", std::to_string(forecast_days)}});

        if (weather_response.status_code == 200) {
            nlohmann::json weather_json = nlohmann::json::parse(weather_response.text);
            for (int i = 0; i < weather_json["hourly"]["time"].size(); i++) {
                std::string time = weather_json["hourly"]["time"][i];
                std::string hour = time.substr(11, 5);
                if (hour == "06:00" || hour == "12:00" || hour == "18:00" || hour == "02:00") {
                    weather_time_.push_back(weather_json["hourly"]["time"][i]);
                    temp_2m_.push_back(to_string(weather_json["hourly"]["temperature_2m"][i]));
                    relative_humidity_.push_back(to_string(weather_json["hourly"]["relativehumidity_2m"][i]));
                    wind_speed_.push_back(to_string(weather_json["hourly"]["windspeed_10m"][i]));
                    wind_direction_.push_back(to_string(weather_json["hourly"]["winddirection_10m"][i]));
                    weather_code_.push_back(to_string(weather_json["hourly"]["weathercode"][i]));
                    temperature_2m_max_.push_back(to_string(weather_json["daily"]["temperature_2m_max"][i]));
                }
            }
        }
        else{
            std::cout << "Status code "<< weather_response.status_code << ". Something went wrong";
        }
    }


std::string weatherdata::get_weather_time(int i) {
    return weather_time_[i];
}

std::vector<std::string> weatherdata::get_temp_2m() {
    return temp_2m_;
}

std::vector<std::string> weatherdata::get_relative_humidity() {
    return relative_humidity_;
}

std::vector<std::string> weatherdata::get_wind_speed() {
    return wind_speed_;
}

std::vector<std::string> weatherdata::get_wind_direction() {
    return wind_direction_;
}

std::vector<std::string> weatherdata::get_weather_code() {
    return weather_code_;
}

std::vector<std::string> weatherdata::get_temperature_2m_max() {
    return temperature_2m_max_;
}
std::vector<std::string> weatherdata::get_weather_time() {
    return weather_time_;
}


