cmake_minimum_required(VERSION 3.14...3.18)
project(
    "politocean_rpi"
    VERSION 1.0
    DESCRIPTION "PoliTOcean Raspberry Pi ROV based"
    LANGUAGES CXX
)

add_subdirectory(libs)

add_subdirectory(app)

add_subdirectory(src)

find_package(Doxygen)
if(Doxygen_FOUND)
    add_subdirectory(docs)
else()
    message(STATUS "Doxygen not found, not building docs")
endif()