set(DCMOTOR_TEST_SOURCE "${politocean_sdk_SOURCE_DIR}/tests/pi/dcmotor_test.cc")

add_executable(dcmotor_test ${DCMOTOR_TEST_SOURCE})
target_link_libraries(dcmotor_test PRIVATE
    Catch2::Catch2
    politocean::dcmotor
)
target_include_directories(dcmotor_test PRIVATE "${politocean_sdk_SOURCE_DIR}/include")
target_compile_features(dcmotor_test PUBLIC cxx_std_17)

set(STEPPER_TEST_SOURCE "${politocean_sdk_SOURCE_DIR}/tests/pi/stepper_test.cc")

add_executable(stepper_test ${STEPPER_TEST_SOURCE})
target_link_libraries(stepper_test PRIVATE
    Catch2::Catch2
    politocean::stepper
)
target_include_directories(stepper_test PRIVATE "${politocean_sdk_SOURCE_DIR}/include")
target_compile_features(stepper_test PUBLIC cxx_std_17)