#define BOOST_TEST_MODULE BaseTypes
#include <boost/test/included/unit_test.hpp>

#include "base/time.h"
#include "base/linear_algebra.h"

using namespace std;

BOOST_AUTO_TEST_CASE( time_test )
{
    double f = 0.5;
    base::Time t1 = base::Time::fromSeconds( f );
    BOOST_CHECK_EQUAL( t1.seconds, 0 );
    BOOST_CHECK_EQUAL( t1.microseconds, 500000 );
    
    f = 2.0;
    t1 = base::Time::fromSeconds( f );
    BOOST_CHECK_EQUAL( t1.seconds, 2 );
    BOOST_CHECK_EQUAL( t1.microseconds, 0 );

    f = -2.5;
    t1 = base::Time::fromSeconds( f );
    BOOST_CHECK_EQUAL( t1.seconds, -3 );
    BOOST_CHECK_EQUAL( t1.microseconds, 500000 );

    cout << t1 << endl;
    cout << base::Time(1,10) << endl;
}

BOOST_AUTO_TEST_CASE( linear_algebra )
{
    Eigen::Matrix3d em1 = Eigen::Matrix3d::Identity();
    em1(2,1) = 2;
    base::Matrix3 m1 = em1;

    BOOST_CHECK_EQUAL( 0, m1(0,1) );
    BOOST_CHECK_EQUAL( 1, m1(1,1) );
    BOOST_CHECK_EQUAL( 2, m1(2,1) );
    
    Eigen::Matrix3d em2 = m1.getEigenType();

    cout << em2 << endl;
}