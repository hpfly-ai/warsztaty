#include <boost/test/unit_test.hpp>
#include "model/Rent.h"
#include "model/Client.h"
#include "model/Vehicle.h"
#include <string>
#include <boost/date_time.hpp>

using namespace std;
namespace pt = boost::posix_time;
namespace gr = boost::gregorian;

struct TestSuiteRentFixture {

    unsigned int id = 123456;
    Client *testclient1;
    Client *testclient2;
    Vehicle *testvehicle1;
    Vehicle *testvehicle2;

    TestSuiteRentFixture() {

        testclient1 = new Client("Dave", "Strider", "546");
        testclient2 = new Client("Jade", "English", "1234");
        testvehicle1 = new Vehicle("2345", 75);
        testvehicle2 = new Vehicle("31231", 456);
    }


    ~TestSuiteRentFixture() {

        delete testvehicle1;
        delete testvehicle2;
        delete testclient1;
        delete testclient2;
    }


};

BOOST_FIXTURE_TEST_SUITE(TestSuiteRent, TestSuiteRentFixture)

    BOOST_AUTO_TEST_CASE(ParameterConstrutorTest) {

        Rent c(id, testvehicle1, testclient1, pt::not_a_date_time);
        BOOST_TEST(id == c.getid());
        BOOST_TEST(testvehicle1 == c.getVehicle_ptr());
        BOOST_TEST(testclient1 == c.getClient_ptr());
        BOOST_TEST(&c == testclient1->getCurrentRentPtr(0));
        BOOST_TEST(true == testvehicle1->isRented1());

    }

    BOOST_AUTO_TEST_CASE(setid_test) {

        Rent c(id, testvehicle1, testclient1, pt::not_a_date_time);
        BOOST_TEST(c.setid(0));
        BOOST_TEST(c.setid(50));

    }

    BOOST_AUTO_TEST_CASE(setvehicleptr_test) {

        Rent c(id, testvehicle1, testclient1, pt::not_a_date_time);
        BOOST_TEST(c.setVehicle_ptr(nullptr));
        BOOST_TEST(c.setVehicle_ptr(testvehicle2));

    }

    BOOST_AUTO_TEST_CASE(setclientptr_test) {

        Rent c(id, testvehicle1, testclient1, pt::not_a_date_time);
        BOOST_TEST(c.setClient_ptr(nullptr));
        BOOST_TEST(c.setClient_ptr(testclient2));

    }

    BOOST_AUTO_TEST_CASE(ParameterConstrutorTestDefaultBeginTime) {

        Rent *r = new Rent(id, testvehicle1, testclient1, pt::not_a_date_time);
        pt::ptime now = pt::second_clock::local_time();
        BOOST_TEST_REQUIRE(!r->getBeginTime().is_not_a_date_time());
        pt::time_period skew = pt::time_period(r->getBeginTime(), now);
        BOOST_TEST((skew.length().hours()==0 && skew.length().minutes()==0));
        delete r;
    }

    BOOST_AUTO_TEST_CASE(getRentDays_test){

        pt::ptime rozpczas = pt::ptime(gr::date(2020,5,13),pt::hours(9)+pt::minutes(25));
        pt::ptime endtime1 = pt::ptime(gr::date(2020,5,13),pt::hours(9)+pt::minutes(26));
        pt::ptime endtime2 = pt::ptime(gr::date(2020,5,14),pt::hours(9)+pt::minutes(24));
        pt::ptime endtime3 = pt::ptime(gr::date(2020,5,14),pt::hours(9)+pt::minutes(25));
        Rent *r = new Rent(id, testvehicle1, testclient1, rozpczas);
        r->setEndTime(endtime1);
        BOOST_TEST(0 == r->getRentDays());
        r->setEndTime(endtime2);
        BOOST_TEST(1 == r->getRentDays());
        r->setEndTime(endtime3);
        BOOST_TEST(2 == r->getRentDays());

    }

    BOOST_AUTO_TEST_CASE(endRent_test){

        pt::ptime endtime = pt::ptime(gr::date(2020,5,13),pt::hours(10)+pt::minutes(26));
        Rent *r = new Rent(id, testvehicle1, testclient1, pt::not_a_date_time);
        BOOST_TEST(r->getEndTime() == pt::not_a_date_time);
        BOOST_TEST(r == testclient1->getCurrentRentPtr(0));
        BOOST_TEST (true == testvehicle1->isRented1());
        r->endRent(endtime);
        BOOST_TEST(endtime == r->getEndTime());
        BOOST_TEST(false == testvehicle1->isRented1());
        BOOST_TEST(0 == testclient1->getCurrentRentsNumber());
        BOOST_TEST(r == testclient1->getCurrentRentPtr(0));
    }

    BOOST_AUTO_TEST_CASE(getRentCost_test){

        pt::ptime begintime = pt::ptime(gr::date(2020,5,13),pt::hours(10)+pt::minutes(26));
        pt::ptime endtime = pt::ptime(gr::date(2020,5,14),pt::hours(10)+pt::minutes(25));
        Rent *r = new Rent(id, testvehicle1, testclient1, begintime);
        r->endRent(endtime);
        BOOST_TEST(75 == r->getRentCost());

    }

BOOST_AUTO_TEST_SUITE_END()