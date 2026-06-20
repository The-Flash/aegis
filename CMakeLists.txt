cmake_minimum_required(VERSION 4.0.0)
project(aegis)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_library(aegis_lib STATIC src/aegis/application/application.cpp)
# where to find the header files for aegis_lib
target_include_directories(aegis_lib PUBLIC src)

add_executable(aegis src/main.cpp)

# Link aegis_lib to aegis executable
target_link_libraries(aegis PRIVATE aegis_lib)
