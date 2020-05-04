#include <boost/test/unit_test.hpp>
namespace tt = boost::test_tools;

BOOST_AUTO_TEST_SUITE(TestSuiteClient)

BOOST_AUTO_TEST_CASE(AssertionsTests) {
        BOOST_TEST(1.0/3.0 == 0.333, tt::tolerance(0.003));
        BOOST_TEST(true);
    }

BOOST_AUTO_TEST_SUITE_END()