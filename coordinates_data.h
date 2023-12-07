//
// Created by aliye on 4/17/2023.
//

#ifndef LABWORK_10_SCANERIST__COORDINATES_DATA_H_
#define LABWORK_10_SCANERIST__COORDINATES_DATA_H_

#include <string>
#include<cpr/cpr.h>
#include<nlohmann/json.hpp>
class coordinates_data {
 public:
  void city_coordinates(std::string city);
  std::string get_latitude();
  std::string get_longitude();
 private:
  std::string latitude;
  std::string longitude;

};

#endif //LABWORK_10_SCANERIST__COORDINATES_DATA_H_
