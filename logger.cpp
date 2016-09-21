#include "logger.h"

// use the logger by including the header, then to log something use the command:
// log("caller", "message");
log::log(std::string module, std::string message) {
  if (log::verbose) {
    std::cout << module << " - " << message << std::endl;
  }
}

bool log::verbose;
