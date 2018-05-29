#include <boost/test/unit_test.hpp>
#include "automateusz/d2_overlap_matrix.hpp"

 using namespace boost::unit_test; 
 
void overlap_ss(){
	double ae = 1.1; 
	double be = 1.7;
	double cc = ae*be/(ae+be);
	double xAB = 1.1;
	double yAB = 2.3;
	double zAB = 1.6;
	double hxx[1]= {0};
	double hxy[1]= {0};
	double hxz[1]= {0};
	double hyy[1]= {0};
	double hyz[1]= {0};
	double hzz[1]= {0};
	bool same_atom = true;
	std::size_t matrix_size =1 ; 
	std::size_t Ai = 0 ;
	std::size_t Bi = 0 ;
	ad2s[0][0]( ae, be, cc, xAB, yAB, zAB, hxx, hxy, hxz, hyy, hyz, hzz, same_atom, matrix_size, Ai, Bi );
	double* result [] = { hxx, hxy, hxz, hyy, hyz, hzz };
	double true_result [6]  = {0.65330603557102618 ,3.582770586403246 ,2.4923621470631274 ,6.4310546492173639 ,5.2113026711319934 ,2.5650610915569474 };
	for (int test_ind = 0; test_ind < 6; test_ind ++) 
		for (int element_ind = 0; element_ind <1; element_ind ++) 
			BOOST_CHECK_CLOSE( result[test_ind][element_ind], true_result[test_ind*1+element_ind] , 0.00001); 
}
void overlap_sp(){
	double ae = 1.1; 
	double be = 1.7;
	double cc = ae*be/(ae+be);
	double xAB = 1.1;
	double yAB = 2.3;
	double zAB = 1.6;
	double hxx[3]= {0,0,0};
	double hxy[3]= {0,0,0};
	double hxz[3]= {0,0,0};
	double hyy[3]= {0,0,0};
	double hyz[3]= {0,0,0};
	double hzz[3]= {0,0,0};
	bool same_atom = true;
	std::size_t matrix_size =3 ; 
	std::size_t Ai = 0 ;
	std::size_t Bi = 0 ;
	ad2s[0][1]( ae, be, cc, xAB, yAB, zAB, hxx, hxy, hxz, hyy, hyz, hzz, same_atom, matrix_size, Ai, Bi );
	double* result [] = { hxx, hxy, hxz, hyy, hyz, hzz };
	double true_result [18]  = {-0.63398807609051933 ,0.59030866785524883 ,0.41064950807321654 ,0.59030866785524883 ,2.7791343305546476 ,2.2520272257391833 ,0.41064950807321665 ,2.2520272257391833 ,1.1084728288513959 ,2.7791343305546472 ,3.894997136933382 ,4.0423772080794871 ,2.2520272257391833 ,4.0423772080794871 ,2.3177159148711 ,1.1084728288513959 ,2.3177159148710995 ,0.27951013230623989 };
	for (int test_ind = 0; test_ind < 6; test_ind ++) 
		for (int element_ind = 0; element_ind <3; element_ind ++) 
			BOOST_CHECK_CLOSE( result[test_ind][element_ind], true_result[test_ind*3+element_ind] , 0.00001); 
}
void overlap_ps(){
	double ae = 1.1; 
	double be = 1.7;
	double cc = ae*be/(ae+be);
	double xAB = 1.1;
	double yAB = 2.3;
	double zAB = 1.6;
	double hxx[3]= {0,0,0};
	double hxy[3]= {0,0,0};
	double hxz[3]= {0,0,0};
	double hyy[3]= {0,0,0};
	double hyz[3]= {0,0,0};
	double hzz[3]= {0,0,0};
	bool same_atom = true;
	std::size_t matrix_size =3 ; 
	std::size_t Ai = 0 ;
	std::size_t Bi = 0 ;
	ad2s[1][0]( ae, be, cc, xAB, yAB, zAB, hxx, hxy, hxz, hyy, hyz, hzz, same_atom, matrix_size, Ai, Bi );
	double* result [] = { hxx, hxy, hxz, hyy, hyz, hzz };
	double true_result [18]  = {0.97979975395807517 ,0 ,0 ,-0.91229521395811153 ,0 ,-0.63464014884042563 ,-0.63464014884042541 ,0 ,-3.4804057125060104 ,-4.2950257835844532 ,0 ,-1.7130943718612475 ,-3.4804057125060104 ,0 ,-6.2473102306682966 ,-1.7130943718612475 ,0 ,-3.5819245957098804 };
	for (int test_ind = 0; test_ind < 6; test_ind ++) 
		for (int element_ind = 0; element_ind <3; element_ind ++) 
			BOOST_CHECK_CLOSE( result[test_ind][element_ind], true_result[test_ind*3+element_ind] , 0.00001); 
}
void overlap_pp(){
	double ae = 1.1; 
	double be = 1.7;
	double cc = ae*be/(ae+be);
	double xAB = 1.1;
	double yAB = 2.3;
	double zAB = 1.6;
	double hxx[9]= {0,0,0,0,0,0,0,0,0};
	double hxy[9]= {0,0,0,0,0,0,0,0,0};
	double hxz[9]= {0,0,0,0,0,0,0,0,0};
	double hyy[9]= {0,0,0,0,0,0,0,0,0};
	double hyz[9]= {0,0,0,0,0,0,0,0,0};
	double hzz[9]= {0,0,0,0,0,0,0,0,0};
	bool same_atom = true;
	std::size_t matrix_size =3 ; 
	std::size_t Ai = 0 ;
	std::size_t Bi = 0 ;
	ad2s[1][1]( ae, be, cc, xAB, yAB, zAB, hxx, hxy, hxz, hyy, hyz, hzz, same_atom, matrix_size, Ai, Bi );
	double* result [] = { hxx, hxy, hxz, hyy, hyz, hzz };
	double true_result [54]  = {0.77339884130207515 ,0.88531906339783228 ,0.61587413105936162 ,0.88531906339783228 ,-0.70766209768875332 ,-0.57344270591652735 ,0.61587413105936162 ,-0.57344270591652746 ,-0.28225487291915574 ,0.88531906339783251 ,-0.7076620976887531 ,-0.57344270591652724 ,-0.70766209768875321 ,-2.6013016593090814 ,-2.6997304925388002 ,-0.57344270591652757 ,-2.6997304925388006 ,-1.5479031288603415 ,0.61587413105936184 ,-0.57344270591652724 ,-0.28225487291915574 ,-0.57344270591652735 ,-2.699730492538801 ,-1.547903128860342 ,-0.28225487291915574 ,-1.5479031288603413 ,-0.18667283836166745 ,-0.70766209768875321 ,-2.6013016593090801 ,-2.6997304925388002 ,-2.6013016593090805 ,-1.9938774398512411 ,-3.7837115044495713 ,-2.6997304925388006 ,-3.7837115044495717 ,-2.7784781004884009 ,-0.57344270591652757 ,-2.6997304925388002 ,-1.547903128860342 ,-2.6997304925388006 ,-3.783711504449573 ,-2.7784781004884014 ,-1.547903128860342 ,-2.7784781004884014 ,-0.39031593475621373 ,-0.28225487291915574 ,-1.5479031288603415 ,-0.1866728383616674 ,-1.5479031288603415 ,-2.7784781004884014 ,-0.39031593475621362 ,-0.1866728383616674 ,-0.39031593475621362 ,1.1026157419508746 };
	for (int test_ind = 0; test_ind < 6; test_ind ++) 
		for (int element_ind = 0; element_ind <9; element_ind ++) 
			BOOST_CHECK_CLOSE( result[test_ind][element_ind], true_result[test_ind*9+element_ind] , 0.00001); 
}

test_suite* test_overlap(){ 
	test_suite * ts=BOOST_TEST_SUITE("Automateusz overlap test");
	ts->add( BOOST_TEST_CASE( & overlap_ss));
	ts->add( BOOST_TEST_CASE( & overlap_sp));
	ts->add( BOOST_TEST_CASE( & overlap_ps));
	ts->add( BOOST_TEST_CASE( & overlap_pp));
	return ts;
}