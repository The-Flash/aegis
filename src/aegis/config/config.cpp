#include "config.hpp"
#include "aegis/logging/logging.hpp"
#include "yaml-cpp/exceptions.h"
#include "yaml-cpp/node/node.h"
#include "yaml-cpp/node/parse.h"
#include "yaml-cpp/yaml.h"
#include <cstdlib>
#include <stdexcept>
#include <string>
#include <vector>

namespace YAML {
bool convert<Service>::decode(const Node &node, Service &rhs) {
  if (!node.IsMap()) {
    return false;
  }
  if (!node["executablePath"]) {
    aegis_logger.error("'executablePath' is required");
    return false;
  }
  std::string executable_path = node["executablePath"].as<std::string>();
  rhs.set_executable_path(executable_path);
  if (!node["restartPolicy"]) {
    aegis_logger.error("'restartPolicy' is required");
    return false;
  }
  std::string restart_policy = node["restartPolicy"].as<std::string>();
  try {
    rhs.set_restart_policy(restart_policy);
  } catch (const std::invalid_argument &e) {
    aegis_logger.error(e.what());
    return false;
  }

  if (node["args"]) {
    std::vector<std::string> args = node["args"].as<std::vector<std::string>>();
    rhs.set_args(args);
  }
  return true;
}
} // namespace YAML

void Service::set_executable_path(const std::string &ep) {
  executable_path = ep;
}

void Service::set_restart_policy(const std::string &rp) {
  if (rp == "always") {
    restart_policy = RestartPolicy::Always;
  } else if (rp == "on-failure") {
    restart_policy = RestartPolicy::OnFailure;
  } else if (rp == "never") {
    restart_policy = RestartPolicy::Never;
  } else {
    throw std::invalid_argument(
        "Invalid restart policy. Valid values are - always, "
        "on-failure and never");
  }
}

void Service::set_args(const std::vector<std::string> &a) { args = a; }

std::string Service::get_executable_path() const { return executable_path; }
RestartPolicy Service::get_restart_policy() const { return restart_policy; }
std::optional<std::vector<std::string>> Service::get_args() const {
  return args;
}

std::ostream &operator<<(std::ostream &os, const Service &service) {
  os << "executable_name: " << service.executable_path;
  return os;
}

void Config::load(const std::string &config_path) {
  YAML::Node config = YAML::LoadFile(config_path);
  auto services = config["services"];
  for (auto it = services.begin(); it != services.end(); it++) {
    std::string service_name = it->first.as<std::string>();
    try {
      Service s = services[service_name].as<Service>();
      add_service(s);
    } catch (const YAML::InvalidNode &e) {
      aegis_logger.error(e.what());
      std::exit(1);
    }
  }
}

void Config::add_service(const Service &service) {
  services.push_back(service);
}

const std::vector<Service> &Config::get_services() { return services; }
