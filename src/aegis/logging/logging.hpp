#pragma once

#include "spdlog/logger.h"
#include <string>

class AegisLogger {
private:
  std::shared_ptr<spdlog::logger> _logger;

public:
  void initLogging(const std::string &filename, size_t max_file_size,
                   size_t max_files);
  void debug(const std::string &msg);
  void info(const std::string &msg);
  void error(const std::string &msg);
  void warn(const std::string &msg);
  void critical(const std::string &msg);
};

extern AegisLogger aegis_logger;
