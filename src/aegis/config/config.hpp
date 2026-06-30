#pragma once

#include "yaml-cpp/node/node.h"
#include <optional>
#include <ostream>
#include <string>
#include <vector>
enum class RestartPolicy { OnFailure, Never, Always };

class Service {
private:
  std::string executable_path;
  RestartPolicy restart_policy;
  std::optional<std::vector<std::string>> args;

public:
  void set_executable_path(const std::string &);
  void set_restart_policy(const std::string &);
  void set_args(const std::vector<std::string> &);

  std::string get_executable_path() const;
  RestartPolicy get_restart_policy() const;
  std::optional<std::vector<std::string>> get_args() const;

  friend std::ostream &operator<<(std::ostream &os, const Service &);
};

namespace YAML {
template <> struct convert<Service> {
  static bool decode(const Node &node, Service &rhs);
};
} // namespace YAML

class Config {
private:
  std::vector<Service> services;

public:
  void load(const std::string &config_path);
  void add_service(const Service &);
  const std::vector<Service> &get_services();
};
