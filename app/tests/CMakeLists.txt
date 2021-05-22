set(PI_TEST_SOURCE "${politocean_sdk_SOURCE_DIR}/app/tests/pi_test.cc" "${politocean_sdk_SOURCE_DIR}/app/src/pi.cc" "${politocean_sdk_SOURCE_DIR}/app/src/arm.cc")

add_executable(pi_test ${PI_TEST_SOURCE})
target_link_libraries(pi_test PRIVATE
    Catch2::Catch2
    pigpio
    yaml-cpp
    politocean::base
    politocean::pi
    spdlog::spdlog
)
target_include_directories(pi_test PRIVATE "${politocean_sdk_SOURCE_DIR}/include" "${politocean_sdk_SOURCE_DIR}/app/include")
target_compile_features(pi_test PUBLIC cxx_std_17)