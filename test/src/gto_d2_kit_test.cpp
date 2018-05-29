#include <boost/test/included/unit_test.hpp>

using namespace boost::unit_test;

test_suite * test_overlap();
test_suite * test_kinetic();
test_suite * test_vne();
test_suite * test_vee();
test_suite * test_vee_numerical();
test_suite *

init_unit_test_suite( int argc, char * argv[] ) {
    
    test_suite* ts_overlap = test_overlap();
    framework::master_test_suite().add( ts_overlap );
    
    test_suite* ts_kinetic = test_kinetic();
    framework::master_test_suite().add( ts_kinetic );

    test_suite* ts_vne = test_vne();
    framework::master_test_suite().add( ts_vne );

    //test_suite* ts_vee = test_vee();
    //framework::master_test_suite().add( ts_vee );
    
    test_suite* ts_vee_numerical = test_vee_numerical();
    framework::master_test_suite().add( ts_vee_numerical );

    return 0;
}
