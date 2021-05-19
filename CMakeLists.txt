cmake_minimum_required(VERSION 3.14...3.18)
project(
    "politocean_sdk"
    VERSION 1.0
    DESCRIPTION "PoliTOcean Software Development Kit"
    LANGUAGES CXX
)

include(FetchContent)

FetchContent_Declare(
    spdlog
    GIT_REPOSITORY https://github.com/gabime/spdlog.git
    GIT_TAG v1.8.5)
FetchContent_Declare(
    json
    GIT_REPOSITORY https://github.com/nlohmann/json.git
    GIT_TAG v3.9.1)

FetchContent_MakeAvailable(spdlog)
FetchContent_MakeAvailable(json)

add_subdirectory(libs)

add_subdirectory(app)

add_subdirectory(src)

add_subdirectory(tests)

find_package(Doxygen)
if(Doxygen_FOUND)
    add_subdirectory(docs)
else()
    message(STATUS "Doxygen not found, not building docs")
endif()