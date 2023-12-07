
#ifndef LABWORK_10_SCANERIST__RUN_H_
#define LABWORK_10_SCANERIST__RUN_H_

#include <nlohmann/json.hpp>
#include <fstream>
#include"weather_controller.h"
class Run {
 public:
  void run(std::string config);

};

#endif //LABWORK_10_SCANERIST__RUN_H_
