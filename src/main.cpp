#include "aegis/logging/logging.hpp"

int main() {
  aegis_logger.initLogging("aegis.log", 1024 * 1024 * 5, 3);
  aegis_logger.info("Welcome to Aegis");
  return 0;
}
