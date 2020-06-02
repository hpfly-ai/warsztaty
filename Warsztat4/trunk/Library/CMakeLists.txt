cmake_minimum_required(VERSION 3.4)
project(CarRental)

set(SOURCE_FILES
        src/model/Client.cpp
        src/model/Address.cpp
        src/model/Vehicle.cpp
        src/model/Rent.cpp )

add_library(CarRental ${SOURCE_FILES})

target_include_directories(CarRental PUBLIC include)

enable_testing()

find_package (Boost 1.60.0 COMPONENTS "unit_test_framework" REQUIRED)

include_directories(
        ${CMAKE_CURRENT_SOURCE_DIR}/include
        ${Boost_INCLUDE_DIRS}
)

set(SOURCE_TEST_FILES
        test/master.cpp
        test/ClientTest.cpp
        test/AddressTest.cpp
        test/VehicleTest.cpp
        test/RentTest.cpp)

add_executable (LibraryTest ${SOURCE_TEST_FILES})

target_link_libraries (LibraryTest
        CarRental
        ${Boost_UNIT_TEST_FRAMEWORK_LIBRARY}
        )

add_custom_target(check ${CMAKE_COMMAND} -E env CTEST_OUTPUT_ON_FAILURE=1 BOOST_TEST_LOG_LEVEL=all
        ${CMAKE_CTEST_COMMAND} -C $<CONFIGURATION> --verbose
        WORKING_DIRECTORY ${CMAKE_BINARY_DIR})

add_test(LibraryTest1 LibraryTest
        --report_level=detailed
        --log_level=all
        --color_output=yes
        )