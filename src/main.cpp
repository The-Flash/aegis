#include "aegis/config/config.hpp"
#include "aegis/logging/logging.hpp"
#include <iostream>

int main() {
  aegis_logger.initLogging("aegis.log", 1024 * 1024 * 5, 3);
  aegis_logger.info("Welcome to Aegis");
  Config config = Config();
  config.load("aegis.yaml");
  for (auto service : config.get_services()) {
    std::cout << service << std::endl;
  }
  return 0;
}
