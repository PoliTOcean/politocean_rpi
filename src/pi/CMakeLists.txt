set(DCMOTOR_HEADERS
    "${politocean_sdk_SOURCE_DIR}/include/politocean/pi/pi.h"
    "${politocean_sdk_SOURCE_DIR}/include/politocean/pi/dcmotor.h")

set(DCMOTOR_SOURCES "sensor.cc")

add_library(dcmotor ${DCMOTOR_SOURCES} ${DCMOTOR_HEADERS})
add_library(politocean::pi::dcmotor ALIAS dcmotor)

set_target_properties(dcmotor PROPERTIES LINKER_LANGUAGE CXX)

target_include_directories(dcmotor PUBLIC "${politocean_sdk_SOURCE_DIR}/include/politocean/pi")
target_compile_features(dcmotor PUBLIC cxx_std_17)