#pragma once
#include <iostream>

// simple class to handle log messages
// log::verbose must be set to actually display the log
class log {
public:
  log(std::string module, std::string message);

  static bool verbose;
};
