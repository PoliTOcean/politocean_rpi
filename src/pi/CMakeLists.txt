set(DCMOTOR_HEADERS
    "${politocean_sdk_SOURCE_DIR}/include/politocean/pi/pitypes.h"
    "${politocean_sdk_SOURCE_DIR}/include/politocean/pi/dcmotor.h")

set(DCMOTOR_SOURCES "dcmotor.cc")

add_library(dcmotor ${DCMOTOR_SOURCES} ${DCMOTOR_HEADERS})
add_library(politocean::dcmotor ALIAS dcmotor)

set_target_properties(dcmotor PROPERTIES LINKER_LANGUAGE CXX)

target_include_directories(dcmotor PUBLIC "${politocean_sdk_SOURCE_DIR}/include/politocean/pi")
target_link_libraries(dcmotor
    pigpio)
target_compile_features(dcmotor PUBLIC cxx_std_17)

set(STEPPER_HEADERS
    "${politocean_sdk_SOURCE_DIR}/include/politocean/pi/pitypes.h"
    "${politocean_sdk_SOURCE_DIR}/include/politocean/pi/stepper.h")

set(STEPPER_SOURCES "stepper.cc")

add_library(stepper ${STEPPER_SOURCES} ${STEPPER_HEADERS})
add_library(politocean::stepper ALIAS stepper)

set_target_properties(stepper PROPERTIES LINKER_LANGUAGE CXX)

target_include_directories(stepper PUBLIC "${politocean_sdk_SOURCE_DIR}/include/politocean/pi")
target_link_libraries(stepper
    pigpio
    Threads::Threads)
target_compile_features(stepper PUBLIC cxx_std_17)