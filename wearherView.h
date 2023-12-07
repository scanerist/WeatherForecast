//
// Created by aliye on 4/24/2023.
//

#ifndef LABWORK_10_SCANERIST__WEARHERVIEW_H_
#define LABWORK_10_SCANERIST__WEARHERVIEW_H_

#include "nlohmann/json.hpp"
#include <ftxui/dom/elements.hpp>
#include <ftxui/screen/screen.hpp>
#include <ftxui/screen/string.hpp>
#include <ftxui/screen/terminal.hpp>
#include <ftxui/screen/color.hpp>
#include <ftxui/screen/box.hpp>
#include <iostream>
#include <string>
#include <vector>
#include <ftxui/dom/elements.hpp>
#include "weatherdata.h"

class wearherView {
 public:
  void WeatherInterface(std::string city, int forecast_days);
  void DO_YOU_HAVE_THE_BEST_WEATHER(std::string city);
};

#endif //LABWORK_10_SCANERIST__WEARHERVIEW_H_
