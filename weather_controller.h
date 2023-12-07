//
// Created by aliye on 4/14/2023.
//

#ifndef LABWORK_10_SCANERIST__WEATHER_CONTROLLER_H_
#define LABWORK_10_SCANERIST__WEATHER_CONTROLLER_H_
#include<conio.h>
#include<winsock2.h>
#include<windows.h>
#include<string>
#include "wearherView.h"
class weather_controller {
 private:
  int weather_days;
  int city = 0;
  std::vector<std::string> cities;
 public:
  void get_weather_data(std::vector<std::string> city, int days);

};

#endif //LABWORK_10_SCANERIST__WEATHER_CONTROLLER_H_
