set(PI_HEADERS
    "${politocean_sdk_SOURCE_DIR}/include/politocean/pi/pitypes.h"
    "${politocean_sdk_SOURCE_DIR}/include/politocean/pi/dcmotor.h"
    "${politocean_sdk_SOURCE_DIR}/include/politocean/pi/stepper.h"
    "${politocean_sdk_SOURCE_DIR}/include/politocean/pi/exception.h"
)

set(PI_SOURCES
    "dcmotor.cc"
    "stepper.cc"
    "spi.cc"
)

add_library(pi ${PI_SOURCES} ${PI_HEADERS})
add_library(politocean::pi ALIAS pi)

set_target_properties(pi PROPERTIES LINKER_LANGUAGE CXX)

target_include_directories(pi PUBLIC "${politocean_sdk_SOURCE_DIR}/include/politocean/pi")
target_link_libraries(pi
    pigpio
    spdlog::spdlog
    Threads::Threads)
target_compile_features(pi PUBLIC cxx_std_17)