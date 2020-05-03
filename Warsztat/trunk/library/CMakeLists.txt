cmake_minimum_required(VERSION 3.4)
project(CarRental)

set(SOURCE_FILES
        src/math_helpers.cpp
        src/model/Client.cpp
        )

add_library(CarRental ${SOURCE_FILES})

target_include_directories(CarRental PUBLIC include)

enable_testing()

find_package (Boost 1.60.0 COMPONENTS "unit_test_framework" REQUIRED)

include_directories(
        ${CMAKE_CURRENT_SOURCE_DIR}/include
        ${Boost_INCLUDE_DIRS}
)


