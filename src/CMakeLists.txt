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

find_package(pigpio)
if(pigpio_FOUND)
    add_subdirectory(pi)
else()
    message(STATUS "pigpio not found, not building for raspberry pi")
endif()