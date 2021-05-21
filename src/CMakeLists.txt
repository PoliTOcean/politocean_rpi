set(SENSOR_HEADERS
    "${politocean_sdk_SOURCE_DIR}/include/politocean/codable.h"
    "${politocean_sdk_SOURCE_DIR}/include/politocean/sensor.h")

set(SENSOR_SOURCES "sensor.cc")

add_library(sensor ${SENSOR_SOURCES} ${SENSOR_HEADERS})
add_library(politocean::sensor ALIAS sensor)

set_target_properties(sensor PROPERTIES LINKER_LANGUAGE CXX)

target_include_directories(sensor PUBLIC "${politocean_sdk_SOURCE_DIR}/include/politocean")
target_link_libraries(sensor PRIVATE 
    nlohmann_json::nlohmann_json)
target_compile_features(sensor PUBLIC cxx_std_17)

set(COMMAND_HEADERS
    "${politocean_sdk_SOURCE_DIR}/include/politocean/codable.h"
    "${politocean_sdk_SOURCE_DIR}/include/politocean/command.h")

set(COMMAND_SOURCE "command.cc")

add_library(command ${COMMAND_SOURCES} ${COMMAND_HEADERS})
add_library(politocean::command ALIAS command)

set_target_properties(command PROPERTIES LINKER_LANGUAGE CXX)

target_include_directories(command PUBLIC "${politocean_sdk_SOURCE_DIR}/include/politocean")
target_link_libraries(command PRIVATE 
    nlohmann_json::nlohmann_json)
target_compile_features(command PUBLIC cxx_std_17)

set(AXIS_HEADERS
    "${politocean_sdk_SOURCE_DIR}/include/politocean/codable.h"
    "${politocean_sdk_SOURCE_DIR}/include/politocean/identifiable.h"
    "${politocean_sdk_SOURCE_DIR}/include/politocean/axis.h")
set(AXIS_SOURCE "axis.cc")

add_library(axis ${AXIS_SOURCE} ${AXIS_HEADERS})
add_library(politocean::axis ALIAS axis)

set_target_properties(axis PROPERTIES LINKER_LANGUAGE CXX)

target_include_directories(axis PUBLIC "${politocean_sdk_SOURCE_DIR}/include/politocean")
target_link_libraries(axis PRIVATE 
    nlohmann_json::nlohmann_json)
target_compile_features(axis PUBLIC cxx_std_17)

set(MQTT_HEADERS
    "${politocean_sdk_SOURCE_DIR}/include/politocean/mqtt.h")
set(MQTT_SOURCE "mqtt.cc")

add_library(mqtt ${MQTT_SOURCE} ${MQTT_HEADERS})
add_library(politocean::mqtt ALIAS mqtt)

set_target_properties(mqtt PROPERTIES LINKER_LANGUAGE CXX)

target_include_directories(mqtt PUBLIC "${politocean_sdk_SOURCE_DIR}/include/politocean")
target_link_libraries(mqtt PRIVATE 
    PahoMqttCpp::paho-mqttpp3
    spdlog::spdlog)
target_compile_features(mqtt PUBLIC cxx_std_17)

find_package(pigpio)
if(pigpio_FOUND)
    add_subdirectory(pi)
else()
    message(STATUS "pigpio not found, not building for raspberry pi")
endif()