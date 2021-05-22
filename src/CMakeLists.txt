set(HEADERS
    "${politocean_sdk_SOURCE_DIR}/include/politocean/codable.h"
    "${politocean_sdk_SOURCE_DIR}/include/politocean/identifiable.h"
    "${politocean_sdk_SOURCE_DIR}/include/politocean/sensor.h"
    "${politocean_sdk_SOURCE_DIR}/include/politocean/axis.h"
    "${politocean_sdk_SOURCE_DIR}/include/politocean/mqtt.h")

set(SOURCES
    "sensor.cc"
    "axis.cc"
    "mqtt.cc")

add_library(politocean ${SOURCES} ${HEADERS})
add_library(politocean::base ALIAS politocean)

set_target_properties(politocean PROPERTIES LINKER_LANGUAGE CXX)

target_include_directories(politocean PUBLIC "${politocean_sdk_SOURCE_DIR}/include/politocean")
target_link_libraries(politocean PRIVATE 
    nlohmann_json::nlohmann_json
    PahoMqttCpp::paho-mqttpp3
    spdlog::spdlog)
target_compile_features(politocean PUBLIC cxx_std_17)

find_package(pigpio)
if(pigpio_FOUND)
    add_subdirectory(pi)
else()
    message(STATUS "pigpio not found, not building for raspberry pi")
endif()