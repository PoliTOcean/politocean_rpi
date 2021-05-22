
include(FetchContent)

FetchContent_Declare(
    yaml-cpp
    GIT_REPOSITORY https://github.com/jbeder/yaml-cpp
    GIT_TAG yaml-cpp-0.6.3)

FetchContent_MakeAvailable(yaml-cpp)

set(APP_SOURCES "main.cc" "pi.cc" "arm.cc")

add_executable(app ${APP_SOURCES})
target_include_directories(app PUBLIC "${CMAKE_SOURCE_DIR}/include" "../include")
target_compile_features(app PRIVATE cxx_std_17)
target_link_libraries(app PRIVATE
    pigpio
    yaml-cpp
    politocean::dcmotor
    politocean::stepper
    politocean::axis
    politocean::command)