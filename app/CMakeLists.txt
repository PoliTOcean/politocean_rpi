set(SOURCES "command_parser.cc")

find_package(PahoMqttCpp REQUIRED)

add_executable(command_parser ${SOURCES})
target_include_directories(command_parser PUBLIC "${CMAKE_SOURCE_DIR}/include" "./include")
target_compile_features(command_parser PRIVATE cxx_std_17)
target_link_libraries(command_parser PRIVATE
    PahoMqttCpp::paho-mqttpp3
    spdlog::spdlog)

# add_executable(controller "controller.cc")
# target_include_directories(controller PUBLIC "${CMAKE_SOURCE_DIR}/include" "../include")
# target_compile_features(controller PRIVATE cxx_std_17)