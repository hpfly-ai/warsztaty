#include <boost/test/unit_test.hpp>
#include "model/Client.h"
#include <string>

namespace tt = boost::test_tools;
using namespace std;

BOOST_AUTO_TEST_SUITE(TestSuiteClient)

    Client* Osoba1 = new Client("Danylo", "Zdoryk", "233305");

BOOST_AUTO_TEST_CASE(Getter_test) {

        BOOST_TEST(Osoba1->get_firstName() == "Danylo");    // get_firstName check
        BOOST_TEST(Osoba1->get_lastName() == "Zdoryk");     // get_lastName check
        BOOST_TEST(Osoba1->get_personalID() == "233305");   // get_personalID check

    }

//BOOST_AUTO_TEST_CASE(setfirstname_test) {
//        Osoba1->set_firstName("Anton");
//        Osoba1->set_lastName("");
//        BOOST_TEST(Osoba1->get_firstName() == "Anton");
//        BOOST_TEST(Osoba1->get_lastName() == "Karpetskyi");
//}

BOOST_AUTO_TEST_CASE(setfirstname_test) {
        BOOST_TEST(Osoba1->set_firstName("") == false);
        BOOST_TEST(Osoba1->set_firstName("Anton"));
}

BOOST_AUTO_TEST_CASE(setlastname_test) {
        BOOST_TEST(Osoba1->set_lastName("") == false);
        BOOST_TEST(Osoba1->set_lastName("Karpetskyi"));
}
BOOST_AUTO_TEST_SUITE_END()
