#include <boost/test/unit_test.hpp>
#include "automateusz/d2_kinetic_matrix.hpp"

 using namespace boost::unit_test; 
 
void kinetic_ss(){
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
	ad2k[0][0]( ae, be, cc, xAB, yAB, zAB, hxx, hxy, hxz, hyy, hyz, hzz, same_atom, matrix_size, Ai, Bi );
	double* result [] = { hxx, hxy, hxz, hyy, hyz, hzz };
	double true_result [6]  = {-0.80977780360381868 ,-12.206932610645746 ,-8.4917792074057381 ,-20.495265966226206 ,-17.75553834275745 ,-7.3233584456479939 };
	for (int test_ind = 0; test_ind < 6; test_ind ++) 
		for (int element_ind = 0; element_ind <1; element_ind ++) 
			BOOST_CHECK_CLOSE( result[test_ind][element_ind], true_result[test_ind*1+element_ind] , 0.00001); 
}
void kinetic_sp(){
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
	ad2k[0][1]( ae, be, cc, xAB, yAB, zAB, hxx, hxy, hxz, hyy, hyz, hzz, same_atom, matrix_size, Ai, Bi );
	double* result [] = { hxx, hxy, hxz, hyy, hyz, hzz };
	double true_result [18]  = {3.1491388659503206 ,0.056791633807489958 ,0.039507223518253712 ,0.05679163380748907 ,-5.1447533653069044 ,-4.6648641323114184 ,0.039507223518253115 ,-4.6648641323114193 ,-1.6841340497606614 ,-5.1447533653069035 ,-4.2294401324621642 ,-7.4832776222645867 ,-4.6648641323114184 ,-7.4832776222645885 ,-3.5213711949541096 ,-1.6841340497606614 ,-3.5213711949541118 ,2.0914088727576128 };
	for (int test_ind = 0; test_ind < 6; test_ind ++) 
		for (int element_ind = 0; element_ind <3; element_ind ++) 
			BOOST_CHECK_CLOSE( result[test_ind][element_ind], true_result[test_ind*3+element_ind] , 0.00001); 
}
void kinetic_ps(){
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
	ad2k[1][0]( ae, be, cc, xAB, yAB, zAB, hxx, hxy, hxz, hyy, hyz, hzz, same_atom, matrix_size, Ai, Bi );
	double* result [] = { hxx, hxy, hxz, hyy, hyz, hzz };
	double true_result [18]  = {-4.8668509746504949 ,0 ,0 ,-0.087768888611576057 ,0 ,-0.061056618164573612 ,-0.061056618164574576 ,0 ,7.2093354772085565 ,7.9509824736561239 ,0 ,2.6027526223573854 ,7.2093354772085547 ,0 ,11.565065416227089 ,2.6027526223573858 ,0 ,5.4421191194745315 };
	for (int test_ind = 0; test_ind < 6; test_ind ++) 
		for (int element_ind = 0; element_ind <3; element_ind ++) 
			BOOST_CHECK_CLOSE( result[test_ind][element_ind], true_result[test_ind*3+element_ind] , 0.00001); 
}
void kinetic_pp(){
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
	ad2k[1][1]( ae, be, cc, xAB, yAB, zAB, hxx, hxy, hxz, hyy, hyz, hzz, same_atom, matrix_size, Ai, Bi );
	double* result [] = { hxx, hxy, hxz, hyy, hyz, hzz };
	double true_result [54]  = {-1.503944542236809 ,-3.2150141674135209 ,-2.2365315947224498 ,-3.2150141674135222 ,-1.1691430126232609 ,-0.82112463003006564 ,-2.2365315947224502 ,-0.82112463003006586 ,-0.55999349088900052 ,-3.2150141674135218 ,-1.1691430126232611 ,-0.82112463003006586 ,-1.16914301262326 ,-0.64993398503989797 ,1.3916918255498811 ,-0.82112463003006531 ,1.3916918255498816 ,0.28421658308089565 ,-2.2365315947224498 ,-0.82112463003006619 ,-0.55999349088900063 ,-0.82112463003006531 ,1.39169182554988 ,0.28421658308089615 ,-0.55999349088900052 ,0.28421658308089587 ,-1.646103931260491 ,-1.1691430126232594 ,-0.64993398503989974 ,1.39169182554988 ,-0.64993398503989852 ,-7.7367463058771078 ,-0.94535852369439655 ,1.3916918255498809 ,-0.94535852369439755 ,-0.10165212370715805 ,-0.82112463003006608 ,1.3916918255498807 ,0.28421658308089559 ,1.3916918255498809 ,-0.94535852369439666 ,-0.10165212370715805 ,0.28421658308089526 ,-0.10165212370715805 ,-3.4418536744537533 ,-0.55999349088900019 ,0.28421658308089615 ,-1.6461039312604899 ,0.28421658308089676 ,-0.10165212370715923 ,-3.441853674453752 ,-1.6461039312604904 ,-3.441853674453752 ,-4.4821024740987223 };
	for (int test_ind = 0; test_ind < 6; test_ind ++) 
		for (int element_ind = 0; element_ind <9; element_ind ++) 
			BOOST_CHECK_CLOSE( result[test_ind][element_ind], true_result[test_ind*9+element_ind] , 0.00001); 
}

test_suite* test_kinetic(){ 
	test_suite * ts=BOOST_TEST_SUITE("Automateusz kinetic test");
	ts->add( BOOST_TEST_CASE( & kinetic_ss));
	ts->add( BOOST_TEST_CASE( & kinetic_sp));
	ts->add( BOOST_TEST_CASE( & kinetic_ps));
	ts->add( BOOST_TEST_CASE( & kinetic_pp));
	return ts;
}