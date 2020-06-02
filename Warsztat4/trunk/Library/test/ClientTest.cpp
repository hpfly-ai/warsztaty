#include <boost/test/unit_test.hpp>
#include "model/Client.h"
#include "model/Address.h"
#include "model/Rent.h"
#include <string>

using namespace std;
namespace pt = boost::posix_time;
namespace gr = boost::gregorian;

struct TestSuiteClientFixture {

    const std::string testFirstName = "Jon";
    const std::string testLastName = "Arbuckle";
    const std::string testPersonalID = "0123456789";
    Address *testaddress1;
    Address *testaddress2;
    Rent* testrent1;
    Rent* testrent2;

    TestSuiteClientFixture() {

        testaddress1 = new Address("London", "Accacia Avenue", "22");
        testaddress2 = new Address("London", "Rue Morgue", "13");

    }


    ~TestSuiteClientFixture() {

        delete testaddress1;
        delete testaddress2;

    }


};

BOOST_FIXTURE_TEST_SUITE(TestSuiteClient, TestSuiteClientFixture)

    BOOST_AUTO_TEST_CASE(ParameterConstrutorTest) {

        Client c(testFirstName, testLastName, testPersonalID, testaddress1);
        testrent1 = new Rent(50, nullptr, &c, pt::not_a_date_time);
        testrent2 = new Rent(100, nullptr, &c, pt::not_a_date_time);
        BOOST_TEST(testFirstName == c.getFirstName());
        BOOST_TEST(testLastName == c.getLastName());
        BOOST_TEST(testPersonalID == c.getPersonalId());
        BOOST_TEST(testaddress1 == c.getAddressPtr());
        BOOST_TEST(2 == c.getCurrentRentsNumber());
        BOOST_TEST(testrent1 == c.getCurrentRentPtr(0));
        delete testrent1;
        delete testrent2;

    }

    BOOST_AUTO_TEST_CASE(setfirstname_test) {

        Client c(testFirstName, testLastName, testPersonalID, testaddress1);
        BOOST_TEST(c.setFirstName(""));
        BOOST_TEST(c.setFirstName("Roy"));

    }

    BOOST_AUTO_TEST_CASE(setlastname_test) {

        Client c(testFirstName, testLastName, testPersonalID, testaddress1);
        BOOST_TEST(c.setLastName(""));
        BOOST_TEST(c.setLastName("Brown"));

    }

    BOOST_AUTO_TEST_CASE(setAddress_test) {

        Client c(testFirstName, testLastName, testPersonalID, testaddress1);
        BOOST_TEST(c.setAddressPtr(nullptr));
        BOOST_TEST(c.setAddressPtr(testaddress2));

    }

    BOOST_AUTO_TEST_CASE(setCurrentRentsNumber_test){

        Client c(testFirstName, testLastName, testPersonalID, testaddress1);
        testrent1 = new Rent(50, nullptr, &c, pt::not_a_date_time);
        BOOST_TEST(c.setCurrentRents(nullptr));
        BOOST_TEST(c.setCurrentRents(testrent1));
        delete testrent1;

    }

    BOOST_AUTO_TEST_CASE(eraseCurrentRentptr_test){
        Client c(testFirstName, testLastName, testPersonalID, testaddress1);
        testrent1 = new Rent(50, nullptr, &c, pt::not_a_date_time);
        testrent2 = new Rent(100, nullptr, &c, pt::not_a_date_time);
        BOOST_TEST(2 == c.getCurrentRentsNumber());
        BOOST_TEST(testrent2 == c.getCurrentRentPtr(1));
        c.eraseCurrentRentPtr(1);
        BOOST_TEST(1 == c.getCurrentRentsNumber());
    }

BOOST_AUTO_TEST_SUITE_END()






