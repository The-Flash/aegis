#include "logging.hpp"
#include "spdlog/common.h"
#include "spdlog/logger.h"
#include "spdlog/sinks/rotating_file_sink.h"
#include "spdlog/sinks/stdout_color_sinks.h"
#include <memory>

void AegisLogger::initLogging(const std::string &filename, size_t max_file_size,
                              size_t max_files) {
  auto file_sink = std::make_shared<spdlog::sinks::rotating_file_sink_mt>(
      filename, max_file_size, max_files);
  auto console_sink = std::make_shared<spdlog::sinks::stdout_color_sink_mt>();

  _logger = std::make_shared<spdlog::logger>(
      "aegis_logger", spdlog::sinks_init_list({file_sink, console_sink}));
};

void AegisLogger::debug(const std::string &msg) { _logger->debug(msg); }
void AegisLogger::info(const std::string &msg) { _logger->info(msg); }
void AegisLogger::warn(const std::string &msg) { _logger->warn(msg); }
void AegisLogger::error(const std::string &msg) { _logger->error(msg); }
void AegisLogger::critical(const std::string &msg) { _logger->critical(msg); }

AegisLogger aegis_logger = AegisLogger();
