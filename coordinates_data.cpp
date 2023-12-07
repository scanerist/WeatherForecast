//
// Created by aliye on 4/17/2023.
//

#include "coordinates_data.h"
void coordinates_data::city_coordinates(std::string city) {
    cpr::Response city_response = cpr::Get(cpr::Url{"https://api.api-ninjas.com/v1/city"},
                                           cpr::Header{{"X-Api-key", "dkralizek6E7fmvAQLBAag==di2gcnKpiHXWTH84"}},
                                           cpr::Parameters{{"name", city}});
    nlohmann::json city_coordinates_json = nlohmann::json::parse(city_response.text);
    latitude = to_string(city_coordinates_json[0]["latitude"]);
    longitude = to_string(city_coordinates_json[0]["longitude"]);

}
std::string coordinates_data::get_latitude() {
    return latitude;
}
std::string coordinates_data::get_longitude() {
    return longitude;
}
