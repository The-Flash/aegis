cmake_minimum_required(VERSION 4.0.0)
project(aegis)

include(FetchContent)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)


# yaml-cpp
FetchContent_Declare(
    yaml-cpp
    GIT_REPOSITORY https://github.com/jbeder/yaml-cpp.git        
    GIT_TAG yaml-cpp-0.9.0
)
FetchContent_MakeAvailable(yaml-cpp)

# spdlog
FetchContent_Declare(
    spdlog
    GIT_REPOSITORY https://github.com/gabime/spdlog.git
    GIT_TAG v1.17.0
)
FetchContent_MakeAvailable(spdlog)

# cpp-httplib
FetchContent_Declare(
    cpp-httplib
    GIT_REPOSITORY https://github.com/yhirose/cpp-httplib.git    
    GIT_TAG v0.48.0
)
FetchContent_MakeAvailable(cpp-httplib)

# Catch2
FetchContent_Declare(
    catch2
    GIT_REPOSITORY https://github.com/catchorg/Catch2.git    
    GIT_TAG v3.15.1
)
FetchContent_MakeAvailable(catch2)

add_library(
    aegis_lib 
    STATIC 
    src/aegis/application/application.cpp
    src/aegis/logging/logging.cpp
    src/aegis/config/config.cpp
)
# where to find the header files for aegis_lib
target_include_directories(aegis_lib PUBLIC src)

add_executable(
    aegis 
    src/main.cpp
)

# Link aegis_lib to aegis executable
target_link_libraries(aegis PRIVATE aegis_lib)

# Link yaml-cpp
target_link_libraries(aegis_lib PUBLIC yaml-cpp::yaml-cpp)

# Link spdlog
target_link_libraries(aegis_lib PUBLIC spdlog::spdlog)

# Link cpp-httplib
target_link_libraries(aegis_lib PUBLIC httplib::httplib)

