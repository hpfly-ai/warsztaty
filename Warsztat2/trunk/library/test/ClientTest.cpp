#include <boost/test/unit_test.hpp>
#include "model/Client.h"

namespace tt = boost::test_tools;


BOOST_AUTO_TEST_SUITE(TestSuiteClient)

BOOST_AUTO_TEST_CASE(AssertionsTests) {
        Client* Osoba1 = new Client("Danylo", "Zdoryk", "233305");
//  Getter check
        BOOST_TEST(Osoba1->get_firstName() == "Danylo");
        BOOST_TEST(Osoba1->get_lastName() == "Zdoryk");
        BOOST_TEST(Osoba1->get_personalID() == "233305");
    }

BOOST_AUTO_TEST_SUITE_END()