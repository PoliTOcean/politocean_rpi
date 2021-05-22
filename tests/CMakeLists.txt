set(SENSOR_TEST_SOURCE "${politocean_sdk_SOURCE_DIR}/tests/sensor_test.cc")
set(COMPONENT_TEST_SOURCE "${politocean_sdk_SOURCE_DIR}/tests/component_test.cc")
set(COMMAND_TEST_SOURCE "${politocean_sdk_SOURCE_DIR}/tests/command_test.cc")
set(MQTT_TEST_SOURCE "${politocean_sdk_SOURCE_DIR}/tests/mqtt_test.cc")

add_executable(sensor_test ${SENSOR_TEST_SOURCE})
target_link_libraries(sensor_test PRIVATE
    Catch2::Catch2
    politocean::base
)
target_include_directories(sensor_test PRIVATE "${politocean_sdk_SOURCE_DIR}/include")
target_compile_features(sensor_test PUBLIC cxx_std_17)

add_executable(component_test ${COMPONENT_TEST_SOURCE})
target_link_libraries(component_test PRIVATE
    Catch2::Catch2
)
target_include_directories(component_test PRIVATE "${politocean_sdk_SOURCE_DIR}/include")
target_compile_features(component_test PUBLIC cxx_std_17)

# add_executable(command_test ${COMMAND_TEST_SOURCE})
# target_link_libraries(command_test PRIVATE
#     Catch2::Catch2
#     politocean::command
# )
# target_include_directories(command_test PRIVATE "${politocean_sdk_SOURCE_DIR}/include")
# target_compile_features(command_test PUBLIC cxx_std_17)

add_executable(mqtt_test ${MQTT_TEST_SOURCE})
target_link_libraries(mqtt_test PRIVATE
    Catch2::Catch2
    politocean::base
)
target_include_directories(mqtt_test PRIVATE "${politocean_sdk_SOURCE_DIR}/include")
target_compile_features(mqtt_test PUBLIC cxx_std_17)

find_package(pigpio)
if(pigpio_FOUND)
    add_subdirectory(pi)
else()
    message(STATUS "pigpio not found, not building for raspberry pi")
endif()