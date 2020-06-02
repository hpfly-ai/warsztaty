#include <boost/test/unit_test.hpp>
#include <string>
#include "model/Address.h"

using namespace std;

struct TestSuiteAddressFixture {

    const std::string testCity = "London";
    const std::string testStreet = "Accacia Avenue";
    const std::string testNumber = "22";

};

BOOST_FIXTURE_TEST_SUITE(TestSuiteAddress, TestSuiteAddressFixture)

BOOST_AUTO_TEST_CASE(Getter_test) {

        Address Adres1(testCity,testStreet, testNumber);
        BOOST_TEST(Adres1.getcity() == testCity);
        BOOST_TEST(Adres1.getstreet() == testStreet);
        BOOST_TEST(Adres1.getnumber() == testNumber);

}

//BOOST_AUTO_TEST_CASE(setcity_test) {
//
//        Address Adres1(testCity,testStreet, testNumber);
//        BOOST_TEST(Adres1.setcity("") == false);
//        BOOST_TEST(Adres1.setcity("Poznan"));
//
//}
//
//BOOST_AUTO_TEST_CASE(setstreet_test) {
//
//        Address Adres1(testCity,testStreet, testNumber);
//        BOOST_TEST(Adres1.setstreet("") == false);
//        BOOST_TEST(Adres1.setstreet("Mickiewicza"));
//
//}
//
//BOOST_AUTO_TEST_CASE(setnumber_test) {
//
//        Address Adres1(testCity,testStreet, testNumber);
//        BOOST_TEST(Adres1.setnumber("") == false);
//        BOOST_TEST(Adres1.setnumber("105"));
//
//}

BOOST_AUTO_TEST_SUITE_END()