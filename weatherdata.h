#include<cpr/cpr.h>
#include<nlohmann/json.hpp>
#include<vector>
#include "coordinates_data.h"




#ifndef LABWORK_10_SCANERIST__WETAHERDATA_H_
#define LABWORK_10_SCANERIST__WETAHERDATA_H_

class weatherdata {
 public:
  void get_weather_data_information(std::string city, int forecats_days);
  std::vector<std::string> get_weather_time();
  std::vector<std::string> get_temp_2m();
  std::vector<std::string> get_relative_humidity();
  std::vector<std::string> get_wind_speed();
  std::vector<std::string> get_wind_direction();
  std::vector<std::string> get_weather_code();
  std::vector<std::string> get_temperature_2m_max();
  std::string get_weather_time(int i);
 private:
  std::vector<std::string> weather_time_;
  std::vector<std::string> temp_2m_;
  std::vector<std::string> relative_humidity_;
  std::vector<std::string> wind_speed_;
  std::vector<std::string> wind_direction_;
  std::vector<std::string> weather_code_;
  std::vector<std::string> temperature_2m_max_;

};



#endif //LABWORK_10_SCANERIST__WETAHERDATA_H_
