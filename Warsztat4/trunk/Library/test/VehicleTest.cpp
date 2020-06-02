#include <boost/test/unit_test.hpp>
#include <string>
#include "model/Vehicle.h"

using namespace std;

struct TestSuiteVehicleFixture {

    const std::string testplateNumber = "10210212";
    const unsigned int testbasePrice = 50;

};

BOOST_FIXTURE_TEST_SUITE(TestSuiteVehicle, TestSuiteVehicleFixture)

    BOOST_AUTO_TEST_CASE(Getter_test) {

        Vehicle c(testplateNumber, testbasePrice);
        BOOST_TEST(c.getplateNumber() == testplateNumber);
        BOOST_TEST(c.getbasePrice() == testbasePrice);

    }

    BOOST_AUTO_TEST_CASE(setplatenumber_test) {

        Vehicle c(testplateNumber, testbasePrice);
        BOOST_TEST(c.setplateNumber(""));
        BOOST_TEST(c.setplateNumber("12341234"));

    }

    BOOST_AUTO_TEST_CASE(setbaseprice_test) {

        Vehicle c(testplateNumber, testbasePrice);
        BOOST_TEST(c.setbasePrice(0));
        BOOST_TEST(c.setbasePrice(100));

    }

BOOST_AUTO_TEST_SUITE_END()