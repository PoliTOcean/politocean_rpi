FetchContent_Declare(
  Catch2
  GIT_REPOSITORY https://github.com/catchorg/Catch2.git
  GIT_TAG        v2.13.3)
FetchContent_MakeAvailable(Catch2)

set(SENSOR_TEST_SOURCE "${politocean_sdk_SOURCE_DIR}/tests/sensor_test.cc")
set(COMPONENT_TEST_SOURCE "${politocean_sdk_SOURCE_DIR}/tests/component_test.cc")

add_executable(sensor_test ${SENSOR_TEST_SOURCE})
target_link_libraries(sensor_test PRIVATE
    Catch2::Catch2
    politocean::sensor
)
target_include_directories(sensor_test PRIVATE "${politocean_sdk_SOURCE_DIR}/include")
target_compile_features(sensor_test PUBLIC cxx_std_17)

add_executable(component_test ${COMPONENT_TEST_SOURCE})
target_link_libraries(component_test PRIVATE
    Catch2::Catch2
    politocean::sensor
)
target_include_directories(component_test PRIVATE "${politocean_sdk_SOURCE_DIR}/include")
target_compile_features(component_test PUBLIC cxx_std_17)