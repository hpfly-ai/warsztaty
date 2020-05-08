#include <boost/test/unit_test.hpp>
#include "model/Address.h"
#include <string>

namespace tt = boost::test_tools;
using namespace std;

BOOST_AUTO_TEST_SUITE(TestSuiteClient)

    Address* x = new Address("Lodz", "Al Politechniki", "7");

    BOOST_AUTO_TEST_CASE(Getter_test) {

        BOOST_TEST(x->get_city() == "Lodz");    // get_firstName check
        BOOST_TEST(x->get_street() == "Al Politechniki");     // get_lastName check
        BOOST_TEST(x->get_number() == "7");   // get_personalID check

    }

//BOOST_AUTO_TEST_CASE(setfirstname_test) {
//        Osoba1->set_firstName("Anton");
//        Osoba1->set_lastName("");
//        BOOST_TEST(Osoba1->get_firstName() == "Anton");
//        BOOST_TEST(Osoba1->get_lastName() == "Karpetskyi");
//}

    BOOST_AUTO_TEST_CASE(setcity_test) {
        BOOST_TEST(x->set_city("") == false);
        BOOST_TEST(x->set_city("Odessa"));
    }

    BOOST_AUTO_TEST_CASE(setstreet_test) {
        BOOST_TEST(x->set_street("") == false);
        BOOST_TEST(x->set_street("Sakharova street"));
    }

    BOOST_AUTO_TEST_CASE(setnumber_test) {
        BOOST_TEST(x->set_number("") == false);
        BOOST_TEST(x->set_number("42"));
    }

BOOST_AUTO_TEST_SUITE_END()

