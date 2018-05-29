#include <boost/test/unit_test.hpp>
#include "gto_d2_kit/d2_ne_matrix.hpp"

 using namespace boost::unit_test; 
 
void vne_ss_AA(){
	double ae = 1.1; 
	double be = 1.7;
	double xA = 1.1;
	double yA = 2.3;
	double zA = 1.6;
	double xB = 0.1;
	double yB = 0.3;
	double zB = 0.6;
	double xC = 1.4;
	double yC = 2.7;
	double zC = 1.2;
	double bs[] = { 0.7, 1.3, 1.5, 1.1, 0.8, 0.2};
	double hxx[1]= {};
	double hxy[1]= {};
	double hxz[1]= {};
	double hyx[1]= {};
	double hyy[1]= {};
	double hyz[1]= {};
	double hzx[1]= {};
	double hzy[1]= {};
	double hzz[1]= {};
	std::size_t matrix_size = 1 ; 
	std::size_t Ai = 0 ;
	std::size_t Bi = 0 ;
	vned2[0][0][0][0]( ae, be, xA, yA, zA, xB, yB, zB, xC, yC, zC, bs, hxx, hxy, hxz, hyx, hyy,hyz, hzx, hzy, hzz, matrix_size, Ai, Bi );
	double* result [] = { hxx, hxy, hxz, hyx, hyy, hyz, hzx, hzy, hzz };
	double true_result [9]  = {-0.072074341426658597 ,0.0012898555179309014 ,-0.067072486932409262 ,0.0012898555179310294 ,-0.11472018948825044 ,-0.11524052893014312 ,-0.067072486932409262 ,-0.11524052893014315 ,-0.084912434628564973 };
	for (int test_ind = 0; test_ind < 9; test_ind ++) 
		for (int element_ind = 0; element_ind <1; element_ind ++) 
			BOOST_CHECK_CLOSE( result[test_ind][element_ind], true_result[test_ind*1+element_ind] , 0.00001); 
}
void vne_ss_AB(){
	double ae = 1.1; 
	double be = 1.7;
	double xA = 1.1;
	double yA = 2.3;
	double zA = 1.6;
	double xB = 0.1;
	double yB = 0.3;
	double zB = 0.6;
	double xC = 1.4;
	double yC = 2.7;
	double zC = 1.2;
	double bs[] = { 0.7, 1.3, 1.5, 1.1, 0.8, 0.2};
	double hxx[1]= {};
	double hxy[1]= {};
	double hxz[1]= {};
	double hyx[1]= {};
	double hyy[1]= {};
	double hyz[1]= {};
	double hzx[1]= {};
	double hzy[1]= {};
	double hzz[1]= {};
	std::size_t matrix_size = 1 ; 
	std::size_t Ai = 0 ;
	std::size_t Bi = 0 ;
	vned2[0][0][0][1]( ae, be, xA, yA, zA, xB, yB, zB, xC, yC, zC, bs, hxx, hxy, hxz, hyx, hyy,hyz, hzx, hzy, hzz, matrix_size, Ai, Bi );
	double* result [] = { hxx, hxy, hxz, hyx, hyy, hyz, hzx, hzy, hzz };
	double true_result [9]  = {0.21597384764582975 ,0.462471832974514 ,0.1265817301460416 ,0.38310907499909264 ,0.68205874181545756 ,0.20301666267025079 ,-0.15118792276793458 ,-0.27315988518227996 ,-0.081636494762001743 };
	for (int test_ind = 0; test_ind < 9; test_ind ++) 
		for (int element_ind = 0; element_ind <1; element_ind ++) 
			BOOST_CHECK_CLOSE( result[test_ind][element_ind], true_result[test_ind*1+element_ind] , 0.00001); 
}
void vne_ss_BA(){
	double ae = 1.1; 
	double be = 1.7;
	double xA = 1.1;
	double yA = 2.3;
	double zA = 1.6;
	double xB = 0.1;
	double yB = 0.3;
	double zB = 0.6;
	double xC = 1.4;
	double yC = 2.7;
	double zC = 1.2;
	double bs[] = { 0.7, 1.3, 1.5, 1.1, 0.8, 0.2};
	double hxx[1]= {};
	double hxy[1]= {};
	double hxz[1]= {};
	double hyx[1]= {};
	double hyy[1]= {};
	double hyz[1]= {};
	double hzx[1]= {};
	double hzy[1]= {};
	double hzz[1]= {};
	std::size_t matrix_size = 1 ; 
	std::size_t Ai = 0 ;
	std::size_t Bi = 0 ;
	vned2[0][0][1][0]( ae, be, xA, yA, zA, xB, yB, zB, xC, yC, zC, bs, hxx, hxy, hxz, hyx, hyy,hyz, hzx, hzy, hzz, matrix_size, Ai, Bi );
	double* result [] = { hxx, hxy, hxz, hyx, hyy, hyz, hzx, hzy, hzz };
	double true_result [9]  = {0.21597384764582975 ,0.38310907499909264 ,-0.15118792276793458 ,0.462471832974514 ,0.68205874181545756 ,-0.27315988518227996 ,0.1265817301460416 ,0.20301666267025079 ,-0.081636494762001743 };
	for (int test_ind = 0; test_ind < 9; test_ind ++) 
		for (int element_ind = 0; element_ind <1; element_ind ++) 
			BOOST_CHECK_CLOSE( result[test_ind][element_ind], true_result[test_ind*1+element_ind] , 0.00001); 
}
void vne_ss_BB(){
	double ae = 1.1; 
	double be = 1.7;
	double xA = 1.1;
	double yA = 2.3;
	double zA = 1.6;
	double xB = 0.1;
	double yB = 0.3;
	double zB = 0.6;
	double xC = 1.4;
	double yC = 2.7;
	double zC = 1.2;
	double bs[] = { 0.7, 1.3, 1.5, 1.1, 0.8, 0.2};
	double hxx[1]= {};
	double hxy[1]= {};
	double hxz[1]= {};
	double hyx[1]= {};
	double hyy[1]= {};
	double hyz[1]= {};
	double hzx[1]= {};
	double hzy[1]= {};
	double hzz[1]= {};
	std::size_t matrix_size = 1 ; 
	std::size_t Ai = 0 ;
	std::size_t Bi = 0 ;
	vned2[0][0][1][1]( ae, be, xA, yA, zA, xB, yB, zB, xC, yC, zC, bs, hxx, hxy, hxz, hyx, hyy,hyz, hzx, hzy, hzz, matrix_size, Ai, Bi );
	double* result [] = { hxx, hxy, hxz, hyx, hyy, hyz, hzx, hzy, hzz };
	double true_result [9]  = {0.92269541313639469 ,1.9641574710751695 ,0.45238584239693252 ,1.9641574710751695 ,3.4558250758621005 ,0.82727208846921518 ,0.45238584239693252 ,0.82727208846921518 ,0.033471784002692198 };
	for (int test_ind = 0; test_ind < 9; test_ind ++) 
		for (int element_ind = 0; element_ind <1; element_ind ++) 
			BOOST_CHECK_CLOSE( result[test_ind][element_ind], true_result[test_ind*1+element_ind] , 0.00001); 
}
void vne_sp_AA(){
	double ae = 1.1; 
	double be = 1.7;
	double xA = 1.1;
	double yA = 2.3;
	double zA = 1.6;
	double xB = 0.1;
	double yB = 0.3;
	double zB = 0.6;
	double xC = 1.4;
	double yC = 2.7;
	double zC = 1.2;
	double bs[] = { 0.7, 1.3, 1.5, 1.1, 0.8, 0.2};
	double hxx[3]= {};
	double hxy[3]= {};
	double hxz[3]= {};
	double hyx[3]= {};
	double hyy[3]= {};
	double hyz[3]= {};
	double hzx[3]= {};
	double hzy[3]= {};
	double hzz[3]= {};
	std::size_t matrix_size = 3 ; 
	std::size_t Ai = 0 ;
	std::size_t Bi = 0 ;
	vned2[0][1][0][0]( ae, be, xA, yA, zA, xB, yB, zB, xC, yC, zC, bs, hxx, hxy, hxz, hyx, hyy,hyz, hzx, hzy, hzz, matrix_size, Ai, Bi );
	double* result [] = { hxx, hxy, hxz, hyx, hyy, hyz, hzx, hzy, hzz };
	double true_result [27]  = {-0.17568502339904099 ,-0.34183233475905866 ,-0.064911700186602472 ,-0.08430095464489111 ,-0.16891873005137401 ,-0.022126290961975197 ,-0.0738893877403832 ,-0.15756112034472466 ,-0.033356282709177239 ,-0.084300954644891096 ,-0.16891873005137406 ,-0.022126290961975163 ,-0.35393604526686084 ,-0.6111566717563901 ,-0.1155974221105244 ,-0.1386566754100492 ,-0.24533783253059019 ,-0.052287546849543606 ,-0.073889387740383242 ,-0.15756112034472464 ,-0.033356282709177232 ,-0.13865667541004922 ,-0.24533783253059016 ,-0.052287546849543592 ,-0.11891364509670767 ,-0.21896472891944996 ,-0.03012066914936061 };
	for (int test_ind = 0; test_ind < 9; test_ind ++) 
		for (int element_ind = 0; element_ind <3; element_ind ++) 
			BOOST_CHECK_CLOSE( result[test_ind][element_ind], true_result[test_ind*3+element_ind] , 0.00001); 
}
void vne_sp_AB(){
	double ae = 1.1; 
	double be = 1.7;
	double xA = 1.1;
	double yA = 2.3;
	double zA = 1.6;
	double xB = 0.1;
	double yB = 0.3;
	double zB = 0.6;
	double xC = 1.4;
	double yC = 2.7;
	double zC = 1.2;
	double bs[] = { 0.7, 1.3, 1.5, 1.1, 0.8, 0.2};
	double hxx[3]= {};
	double hxy[3]= {};
	double hxz[3]= {};
	double hyx[3]= {};
	double hyy[3]= {};
	double hyz[3]= {};
	double hzx[3]= {};
	double hzy[3]= {};
	double hzz[3]= {};
	std::size_t matrix_size = 3 ; 
	std::size_t Ai = 0 ;
	std::size_t Bi = 0 ;
	vned2[0][1][0][1]( ae, be, xA, yA, zA, xB, yB, zB, xC, yC, zC, bs, hxx, hxy, hxz, hyx, hyy,hyz, hzx, hzy, hzz, matrix_size, Ai, Bi );
	double* result [] = { hxx, hxy, hxz, hyx, hyy, hyz, hzx, hzy, hzz };
	double true_result [27]  = {0.078519657578962579 ,0.30166440174955539 ,0.10178115750160116 ,0.30166440174955517 ,0.59617003208734831 ,0.21896828335084881 ,0.10178115750160119 ,0.21896828335084886 ,0.0073136967223020304 ,0.14073293971406861 ,0.42100252264515248 ,0.16882148572901653 ,0.42100252264515264 ,0.67498868984897953 ,0.30290027335909103 ,0.16882148572901648 ,0.30290027335909087 ,0.010115793978036598 ,-0.25140107086413321 ,-0.51666343480594512 ,-0.13318711349436652 ,-0.51666343480594534 ,-0.91149869677289652 ,-0.24408101647329805 ,-0.13318711349436652 ,-0.24408101647329811 ,-0.038689568300856507 };
	for (int test_ind = 0; test_ind < 9; test_ind ++) 
		for (int element_ind = 0; element_ind <3; element_ind ++) 
			BOOST_CHECK_CLOSE( result[test_ind][element_ind], true_result[test_ind*3+element_ind] , 0.00001); 
}
void vne_sp_BA(){
	double ae = 1.1; 
	double be = 1.7;
	double xA = 1.1;
	double yA = 2.3;
	double zA = 1.6;
	double xB = 0.1;
	double yB = 0.3;
	double zB = 0.6;
	double xC = 1.4;
	double yC = 2.7;
	double zC = 1.2;
	double bs[] = { 0.7, 1.3, 1.5, 1.1, 0.8, 0.2};
	double hxx[3]= {};
	double hxy[3]= {};
	double hxz[3]= {};
	double hyx[3]= {};
	double hyy[3]= {};
	double hyz[3]= {};
	double hzx[3]= {};
	double hzy[3]= {};
	double hzz[3]= {};
	std::size_t matrix_size = 3 ; 
	std::size_t Ai = 0 ;
	std::size_t Bi = 0 ;
	vned2[0][1][1][0]( ae, be, xA, yA, zA, xB, yB, zB, xC, yC, zC, bs, hxx, hxy, hxz, hyx, hyy,hyz, hzx, hzy, hzz, matrix_size, Ai, Bi );
	double* result [] = { hxx, hxy, hxz, hyx, hyy, hyz, hzx, hzy, hzz };
	double true_result [27]  = {0.078519657578962579 ,0.30166440174955539 ,0.10178115750160116 ,0.14073293971406861 ,0.42100252264515248 ,0.16882148572901653 ,-0.25140107086413321 ,-0.51666343480594512 ,-0.13318711349436652 ,0.30166440174955517 ,0.59617003208734831 ,0.21896828335084881 ,0.42100252264515264 ,0.67498868984897953 ,0.30290027335909103 ,-0.51666343480594534 ,-0.91149869677289652 ,-0.24408101647329805 ,0.10178115750160119 ,0.21896828335084886 ,0.0073136967223020304 ,0.16882148572901648 ,0.30290027335909087 ,0.010115793978036598 ,-0.13318711349436652 ,-0.24408101647329811 ,-0.038689568300856507 };
	for (int test_ind = 0; test_ind < 9; test_ind ++) 
		for (int element_ind = 0; element_ind <3; element_ind ++) 
			BOOST_CHECK_CLOSE( result[test_ind][element_ind], true_result[test_ind*3+element_ind] , 0.00001); 
}
void vne_sp_BB(){
	double ae = 1.1; 
	double be = 1.7;
	double xA = 1.1;
	double yA = 2.3;
	double zA = 1.6;
	double xB = 0.1;
	double yB = 0.3;
	double zB = 0.6;
	double xC = 1.4;
	double yC = 2.7;
	double zC = 1.2;
	double bs[] = { 0.7, 1.3, 1.5, 1.1, 0.8, 0.2};
	double hxx[3]= {};
	double hxy[3]= {};
	double hxz[3]= {};
	double hyx[3]= {};
	double hyy[3]= {};
	double hyz[3]= {};
	double hzx[3]= {};
	double hzy[3]= {};
	double hzz[3]= {};
	std::size_t matrix_size = 3 ; 
	std::size_t Ai = 0 ;
	std::size_t Bi = 0 ;
	vned2[0][1][1][1]( ae, be, xA, yA, zA, xB, yB, zB, xC, yC, zC, bs, hxx, hxy, hxz, hyx, hyy,hyz, hzx, hzy, hzz, matrix_size, Ai, Bi );
	double* result [] = { hxx, hxy, hxz, hyx, hyy, hyz, hzx, hzy, hzz };
	double true_result [27]  = {0.64049108963965007 ,2.0628871876490775 ,0.53416648543727985 ,2.062887187649078 ,4.3771787618152764 ,1.1656776172841632 ,0.53416648543728007 ,1.1656776172841632 ,0.044774769846249861 ,2.0628871876490771 ,4.3771787618152764 ,1.1656776172841632 ,4.3771787618152764 ,7.2198566819581798 ,2.0471452717585343 ,1.1656776172841632 ,2.0471452717585348 ,0.082577067789622691 ,0.53416648543728007 ,1.1656776172841632 ,0.044774769846249882 ,1.1656776172841634 ,2.0471452717585348 ,0.082577067789622732 ,0.044774769846249909 ,0.082577067789622732 ,-0.17735620411379471 };
	for (int test_ind = 0; test_ind < 9; test_ind ++) 
		for (int element_ind = 0; element_ind <3; element_ind ++) 
			BOOST_CHECK_CLOSE( result[test_ind][element_ind], true_result[test_ind*3+element_ind] , 0.00001); 
}
void vne_ps_AA(){
	double ae = 1.1; 
	double be = 1.7;
	double xA = 1.1;
	double yA = 2.3;
	double zA = 1.6;
	double xB = 0.1;
	double yB = 0.3;
	double zB = 0.6;
	double xC = 1.4;
	double yC = 2.7;
	double zC = 1.2;
	double bs[] = { 0.7, 1.3, 1.5, 1.1, 0.8, 0.2};
	double hxx[3]= {};
	double hxy[3]= {};
	double hxz[3]= {};
	double hyx[3]= {};
	double hyy[3]= {};
	double hyz[3]= {};
	double hzx[3]= {};
	double hzy[3]= {};
	double hzz[3]= {};
	std::size_t matrix_size = 3 ; 
	std::size_t Ai = 0 ;
	std::size_t Bi = 0 ;
	vned2[1][0][0][0]( ae, be, xA, yA, zA, xB, yB, zB, xC, yC, zC, bs, hxx, hxy, hxz, hyx, hyy,hyz, hzx, hzy, hzz, matrix_size, Ai, Bi );
	double* result [] = { hxx, hxy, hxz, hyx, hyy, hyz, hzx, hzy, hzz };
	double true_result [27]  = {-0.23904551135513183 ,0 ,0 ,-0.19768365190574155 ,0 ,0.0071626412400561121 ,0.0071626412400561086 ,0 ,-0.023416146479906037 ,-0.19768365190574155 ,0 ,-0.034001210468142667 ,-0.2392158557786104 ,0 ,-0.023416146479906065 ,-0.023416146479906065 ,0 ,-0.00087723262227395408 ,0.0071626412400560687 ,0 ,-0.049139859662320054 ,-0.023416146479906079 ,0 ,-0.034001210468142674 ,-0.034001210468142674 ,0 ,-0.049139859662320054 };
	for (int test_ind = 0; test_ind < 9; test_ind ++) 
		for (int element_ind = 0; element_ind <3; element_ind ++) 
			BOOST_CHECK_CLOSE( result[test_ind][element_ind], true_result[test_ind*3+element_ind] , 0.00001); 
}
void vne_ps_AB(){
	double ae = 1.1; 
	double be = 1.7;
	double xA = 1.1;
	double yA = 2.3;
	double zA = 1.6;
	double xB = 0.1;
	double yB = 0.3;
	double zB = 0.6;
	double xC = 1.4;
	double yC = 2.7;
	double zC = 1.2;
	double bs[] = { 0.7, 1.3, 1.5, 1.1, 0.8, 0.2};
	double hxx[3]= {};
	double hxy[3]= {};
	double hxz[3]= {};
	double hyx[3]= {};
	double hyy[3]= {};
	double hyz[3]= {};
	double hzx[3]= {};
	double hzy[3]= {};
	double hzz[3]= {};
	std::size_t matrix_size = 3 ; 
	std::size_t Ai = 0 ;
	std::size_t Bi = 0 ;
	vned2[1][0][0][1]( ae, be, xA, yA, zA, xB, yB, zB, xC, yC, zC, bs, hxx, hxy, hxz, hyx, hyy,hyz, hzx, hzy, hzz, matrix_size, Ai, Bi );
	double* result [] = { hxx, hxy, hxz, hyx, hyy, hyz, hzx, hzy, hzz };
	double true_result [27]  = {-0.2715132179803359 ,0 ,0 ,-0.52828633553672688 ,0 ,-0.11419269014422856 ,-0.1003180821065674 ,0 ,-0.24350354962366527 ,-0.13028329354210419 ,0 ,-0.0515506187323648 ,-0.26105621917030514 ,0 ,-0.21428758927007607 ,-0.034195176941234307 ,0 ,-0.3791584684563668 ,-0.11419269014422863 ,0 ,-0.080808026949294634 ,-0.24350354962366541 ,0 ,-0.18377563333127539 ,-0.051550618732364786 ,0 ,-0.33840003560278625 };
	for (int test_ind = 0; test_ind < 9; test_ind ++) 
		for (int element_ind = 0; element_ind <3; element_ind ++) 
			BOOST_CHECK_CLOSE( result[test_ind][element_ind], true_result[test_ind*3+element_ind] , 0.00001); 
}
void vne_ps_BA(){
	double ae = 1.1; 
	double be = 1.7;
	double xA = 1.1;
	double yA = 2.3;
	double zA = 1.6;
	double xB = 0.1;
	double yB = 0.3;
	double zB = 0.6;
	double xC = 1.4;
	double yC = 2.7;
	double zC = 1.2;
	double bs[] = { 0.7, 1.3, 1.5, 1.1, 0.8, 0.2};
	double hxx[3]= {};
	double hxy[3]= {};
	double hxz[3]= {};
	double hyx[3]= {};
	double hyy[3]= {};
	double hyz[3]= {};
	double hzx[3]= {};
	double hzy[3]= {};
	double hzz[3]= {};
	std::size_t matrix_size = 3 ; 
	std::size_t Ai = 0 ;
	std::size_t Bi = 0 ;
	vned2[1][0][1][0]( ae, be, xA, yA, zA, xB, yB, zB, xC, yC, zC, bs, hxx, hxy, hxz, hyx, hyy,hyz, hzx, hzy, hzz, matrix_size, Ai, Bi );
	double* result [] = { hxx, hxy, hxz, hyx, hyy, hyz, hzx, hzy, hzz };
	double true_result [27]  = {-0.2715132179803359 ,0 ,0 ,-0.13028329354210419 ,0 ,-0.11419269014422856 ,-0.11419269014422863 ,0 ,-0.21428758927007607 ,-0.52828633553672688 ,0 ,-0.18377563333127539 ,-0.26105621917030514 ,0 ,-0.24350354962366527 ,-0.24350354962366541 ,0 ,-0.3791584684563668 ,-0.1003180821065674 ,0 ,-0.33840003560278625 ,-0.034195176941234307 ,0 ,-0.0515506187323648 ,-0.051550618732364786 ,0 ,-0.080808026949294634 };
	for (int test_ind = 0; test_ind < 9; test_ind ++) 
		for (int element_ind = 0; element_ind <3; element_ind ++) 
			BOOST_CHECK_CLOSE( result[test_ind][element_ind], true_result[test_ind*3+element_ind] , 0.00001); 
}
void vne_ps_BB(){
	double ae = 1.1; 
	double be = 1.7;
	double xA = 1.1;
	double yA = 2.3;
	double zA = 1.6;
	double xB = 0.1;
	double yB = 0.3;
	double zB = 0.6;
	double xC = 1.4;
	double yC = 2.7;
	double zC = 1.2;
	double bs[] = { 0.7, 1.3, 1.5, 1.1, 0.8, 0.2};
	double hxx[3]= {};
	double hxy[3]= {};
	double hxz[3]= {};
	double hyx[3]= {};
	double hyy[3]= {};
	double hyz[3]= {};
	double hzx[3]= {};
	double hzy[3]= {};
	double hzz[3]= {};
	std::size_t matrix_size = 3 ; 
	std::size_t Ai = 0 ;
	std::size_t Bi = 0 ;
	vned2[1][0][1][1]( ae, be, xA, yA, zA, xB, yB, zB, xC, yC, zC, bs, hxx, hxy, hxz, hyx, hyy,hyz, hzx, hzy, hzz, matrix_size, Ai, Bi );
	double* result [] = { hxx, hxy, hxz, hyx, hyy, hyz, hzx, hzy, hzz };
	double true_result [27]  = {0.1213485617129423 ,0 ,0 ,0.46620862088567655 ,0 ,-0.38852892769911473 ,0.15729815250247461 ,0 ,-0.79847985379100606 ,0.46620862088567644 ,0 ,-0.20583462994583918 ,0.92135368595317557 ,0 ,-0.79847985379100594 ,0.33840552881494806 ,0 ,-1.4086798041035669 ,0.15729815250247459 ,0 ,-0.37721611636782437 ,0.33840552881494829 ,0 ,-0.20583462994583918 ,0.01130298584355771 ,0 ,-0.37721611636782437 };
	for (int test_ind = 0; test_ind < 9; test_ind ++) 
		for (int element_ind = 0; element_ind <3; element_ind ++) 
			BOOST_CHECK_CLOSE( result[test_ind][element_ind], true_result[test_ind*3+element_ind] , 0.00001); 
}
void vne_pp_AA(){
	double ae = 1.1; 
	double be = 1.7;
	double xA = 1.1;
	double yA = 2.3;
	double zA = 1.6;
	double xB = 0.1;
	double yB = 0.3;
	double zB = 0.6;
	double xC = 1.4;
	double yC = 2.7;
	double zC = 1.2;
	double bs[] = { 0.7, 1.3, 1.5, 1.1, 0.8, 0.2};
	double hxx[9]= {};
	double hxy[9]= {};
	double hxz[9]= {};
	double hyx[9]= {};
	double hyy[9]= {};
	double hyz[9]= {};
	double hzx[9]= {};
	double hzy[9]= {};
	double hzz[9]= {};
	std::size_t matrix_size = 3 ; 
	std::size_t Ai = 0 ;
	std::size_t Bi = 0 ;
	vned2[1][1][0][0]( ae, be, xA, yA, zA, xB, yB, zB, xC, yC, zC, bs, hxx, hxy, hxz, hyx, hyy,hyz, hzx, hzy, hzz, matrix_size, Ai, Bi );
	double* result [] = { hxx, hxy, hxz, hyx, hyy, hyz, hzx, hzy, hzz };
	double true_result [81]  = {-0.10193164611541759 ,-0.30181178186709989 ,-0.10853781160878141 ,-0.020231815137185822 ,-0.10470803203210984 ,-0.073563412999890762 ,0.076695352866034489 ,0.13844552138596297 ,0.038535408519529114 ,-0.020231815137185943 ,-0.10470803203210979 ,-0.073563412999890776 ,0.03205893960913006 ,0.0040718807432598919 ,-0.074403416608276318 ,0.048322033821334209 ,0.087492652150336039 ,0.024178588775676343 ,0.076695352866034475 ,0.13844552138596294 ,0.038535408519529094 ,0.048322033821334077 ,0.087492652150335984 ,0.024178588775676368 ,-0.0084639400986271339 ,-0.0209939836433988 ,-0.01337853022658789 ,-0.02023181513718595 ,-0.10470803203210977 ,-0.073563412999890776 ,0.032058939609129998 ,0.0040718807432598833 ,-0.074403416608276346 ,0.048322033821334195 ,0.087492652150336081 ,0.024178588775676333 ,0.032058939609130095 ,0.0040718807432600836 ,-0.074403416608276304 ,-0.12457097989063927 ,-0.15321242735667173 ,-0.21212428742566206 ,0.16393520654806021 ,0.28725910638629726 ,0.077483011868028168 ,0.048322033821334154 ,0.087492652150335984 ,0.024178588775676323 ,0.16393520654806018 ,0.28725910638629731 ,0.077483011868028195 ,-0.0021314223694335311 ,-0.0063704953526626772 ,-0.019775562643068796 ,0.076695352866034475 ,0.13844552138596292 ,0.0385354085195291 ,0.048322033821334195 ,0.087492652150335942 ,0.024178588775676343 ,-0.0084639400986271339 ,-0.020993983643398818 ,-0.013378530226587903 ,0.048322033821334147 ,0.087492652150335942 ,0.024178588775676326 ,0.16393520654806032 ,0.28725910638629715 ,0.077483011868028195 ,-0.0021314223694335354 ,-0.0063704953526627084 ,-0.01977556264306881 ,-0.0084639400986271235 ,-0.020993983643398811 ,-0.01337853022658788 ,-0.0021314223694335215 ,-0.0063704953526627101 ,-0.019775562643068741 ,0.16434851793719127 ,0.29963011337900097 ,0.067650202636174897 };
	for (int test_ind = 0; test_ind < 9; test_ind ++) 
		for (int element_ind = 0; element_ind <9; element_ind ++) 
			BOOST_CHECK_CLOSE( result[test_ind][element_ind], true_result[test_ind*9+element_ind] , 0.00001); 
}
void vne_pp_AB(){
	double ae = 1.1; 
	double be = 1.7;
	double xA = 1.1;
	double yA = 2.3;
	double zA = 1.6;
	double xB = 0.1;
	double yB = 0.3;
	double zB = 0.6;
	double xC = 1.4;
	double yC = 2.7;
	double zC = 1.2;
	double bs[] = { 0.7, 1.3, 1.5, 1.1, 0.8, 0.2};
	double hxx[9]= {};
	double hxy[9]= {};
	double hxz[9]= {};
	double hyx[9]= {};
	double hyy[9]= {};
	double hyz[9]= {};
	double hzx[9]= {};
	double hzy[9]= {};
	double hzz[9]= {};
	std::size_t matrix_size = 3 ; 
	std::size_t Ai = 0 ;
	std::size_t Bi = 0 ;
	vned2[1][1][0][1]( ae, be, xA, yA, zA, xB, yB, zB, xC, yC, zC, bs, hxx, hxy, hxz, hyx, hyy,hyz, hzx, hzy, hzz, matrix_size, Ai, Bi );
	double* result [] = { hxx, hxy, hxz, hyx, hyy, hyz, hzx, hzy, hzz };
	double true_result [81]  = {-0.19994301801401859 ,-0.57429378662723185 ,-0.15298403627828269 ,0.012003546464591048 ,-0.1128510223947214 ,-0.055603786727315044 ,-0.033897797458323199 ,-0.1537058734736681 ,-0.02910339409400247 ,-0.57429378662723196 ,-1.1856331108382328 ,-0.31432507521296604 ,-0.11285102239472146 ,-0.30619136016621568 ,-0.12584030221069484 ,-0.15370587347366799 ,-0.32130368822753441 ,-0.065734327538684398 ,-0.15298403627828272 ,-0.31432507521296593 ,-0.0080022955642685724 ,-0.055603786727315113 ,-0.12584030221069489 ,0.0025854350221150547 ,-0.029103394094002453 ,-0.065734327538684426 ,0.015798115044022464 ,0.01200354646459097 ,-0.11285102239472135 ,-0.055603786727315085 ,-0.44530089534001566 ,-0.93822194974756445 ,-0.2936376598381466 ,-0.087226023850676335 ,-0.24394255149675659 ,-0.043441117023249438 ,-0.11285102239472122 ,-0.30619136016621556 ,-0.12584030221069492 ,-0.93822194974756445 ,-1.4536136126531674 ,-0.50056896466287026 ,-0.24394255149675667 ,-0.38615257079397269 ,-0.078977078630728434 ,-0.055603786727315078 ,-0.12584030221069478 ,0.0025854350221150325 ,-0.29363765983814649 ,-0.5005689646628706 ,-0.0067585478801076597 ,-0.043441117023249459 ,-0.078977078630728337 ,0.03329209969341447 ,-0.033897797458323199 ,-0.15370587347366815 ,-0.02910339409400247 ,-0.087226023850676362 ,-0.24394255149675687 ,-0.043441117023249452 ,-0.15825970683435148 ,-0.37084528305167541 ,-0.06722603539919314 ,-0.15370587347366799 ,-0.32130368822753463 ,-0.065734327538684481 ,-0.24394255149675662 ,-0.38615257079397269 ,-0.078977078630728406 ,-0.37084528305167541 ,-0.64804882101034 ,-0.12366248327367543 ,-0.02910339409400246 ,-0.065734327538684356 ,0.015798115044022468 ,-0.043441117023249425 ,-0.078977078630728406 ,0.033292099693414443 ,-0.06722603539919314 ,-0.12366248327367543 ,0.022381754072604575 };
	for (int test_ind = 0; test_ind < 9; test_ind ++) 
		for (int element_ind = 0; element_ind <9; element_ind ++) 
			BOOST_CHECK_CLOSE( result[test_ind][element_ind], true_result[test_ind*9+element_ind] , 0.00001); 
}
void vne_pp_BA(){
	double ae = 1.1; 
	double be = 1.7;
	double xA = 1.1;
	double yA = 2.3;
	double zA = 1.6;
	double xB = 0.1;
	double yB = 0.3;
	double zB = 0.6;
	double xC = 1.4;
	double yC = 2.7;
	double zC = 1.2;
	double bs[] = { 0.7, 1.3, 1.5, 1.1, 0.8, 0.2};
	double hxx[9]= {};
	double hxy[9]= {};
	double hxz[9]= {};
	double hyx[9]= {};
	double hyy[9]= {};
	double hyz[9]= {};
	double hzx[9]= {};
	double hzy[9]= {};
	double hzz[9]= {};
	std::size_t matrix_size = 3 ; 
	std::size_t Ai = 0 ;
	std::size_t Bi = 0 ;
	vned2[1][1][1][0]( ae, be, xA, yA, zA, xB, yB, zB, xC, yC, zC, bs, hxx, hxy, hxz, hyx, hyy,hyz, hzx, hzy, hzz, matrix_size, Ai, Bi );
	double* result [] = { hxx, hxy, hxz, hyx, hyy, hyz, hzx, hzy, hzz };
	double true_result [81]  = {-0.19994301801401859 ,-0.57429378662723185 ,-0.15298403627828269 ,0.012003546464591048 ,-0.1128510223947214 ,-0.055603786727315044 ,-0.033897797458323199 ,-0.1537058734736681 ,-0.02910339409400247 ,0.01200354646459097 ,-0.11285102239472135 ,-0.055603786727315085 ,-0.44530089534001566 ,-0.93822194974756445 ,-0.2936376598381466 ,-0.087226023850676335 ,-0.24394255149675659 ,-0.043441117023249438 ,-0.033897797458323199 ,-0.15370587347366815 ,-0.02910339409400247 ,-0.087226023850676362 ,-0.24394255149675687 ,-0.043441117023249452 ,-0.15825970683435148 ,-0.37084528305167541 ,-0.06722603539919314 ,-0.57429378662723196 ,-1.1856331108382328 ,-0.31432507521296604 ,-0.11285102239472146 ,-0.30619136016621568 ,-0.12584030221069484 ,-0.15370587347366799 ,-0.32130368822753441 ,-0.065734327538684398 ,-0.11285102239472122 ,-0.30619136016621556 ,-0.12584030221069492 ,-0.93822194974756445 ,-1.4536136126531674 ,-0.50056896466287026 ,-0.24394255149675667 ,-0.38615257079397269 ,-0.078977078630728434 ,-0.15370587347366799 ,-0.32130368822753463 ,-0.065734327538684481 ,-0.24394255149675662 ,-0.38615257079397269 ,-0.078977078630728406 ,-0.37084528305167541 ,-0.64804882101034 ,-0.12366248327367543 ,-0.15298403627828272 ,-0.31432507521296593 ,-0.0080022955642685724 ,-0.055603786727315113 ,-0.12584030221069489 ,0.0025854350221150547 ,-0.029103394094002453 ,-0.065734327538684426 ,0.015798115044022464 ,-0.055603786727315078 ,-0.12584030221069478 ,0.0025854350221150325 ,-0.29363765983814649 ,-0.5005689646628706 ,-0.0067585478801076597 ,-0.043441117023249459 ,-0.078977078630728337 ,0.03329209969341447 ,-0.02910339409400246 ,-0.065734327538684356 ,0.015798115044022468 ,-0.043441117023249425 ,-0.078977078630728406 ,0.033292099693414443 ,-0.06722603539919314 ,-0.12366248327367543 ,0.022381754072604575 };
	for (int test_ind = 0; test_ind < 9; test_ind ++) 
		for (int element_ind = 0; element_ind <9; element_ind ++) 
			BOOST_CHECK_CLOSE( result[test_ind][element_ind], true_result[test_ind*9+element_ind] , 0.00001); 
}
void vne_pp_BB(){
	double ae = 1.1; 
	double be = 1.7;
	double xA = 1.1;
	double yA = 2.3;
	double zA = 1.6;
	double xB = 0.1;
	double yB = 0.3;
	double zB = 0.6;
	double xC = 1.4;
	double yC = 2.7;
	double zC = 1.2;
	double bs[] = { 0.7, 1.3, 1.5, 1.1, 0.8, 0.2};
	double hxx[9]= {};
	double hxy[9]= {};
	double hxz[9]= {};
	double hyx[9]= {};
	double hyy[9]= {};
	double hyz[9]= {};
	double hzx[9]= {};
	double hzy[9]= {};
	double hzz[9]= {};
	std::size_t matrix_size = 3 ; 
	std::size_t Ai = 0 ;
	std::size_t Bi = 0 ;
	vned2[1][1][1][1]( ae, be, xA, yA, zA, xB, yB, zB, xC, yC, zC, bs, hxx, hxy, hxz, hyx, hyy,hyz, hzx, hzy, hzz, matrix_size, Ai, Bi );
	double* result [] = { hxx, hxy, hxz, hyx, hyy, hyz, hzx, hzy, hzz };
	double true_result [81]  = {0.035412860166156843 ,0.26124805887116126 ,0.068961056550079045 ,-0.11223368045033753 ,0.16620743592545928 ,0.082692506334333601 ,-0.30347286670931023 ,-0.91186171044018394 ,-0.21370510501747855 ,0.26124805887116109 ,0.65984118550413373 ,0.22866318006273492 ,0.16620743592545875 ,0.56995950950972596 ,0.27363813722933927 ,-0.91186171044018416 ,-1.9052400495461204 ,-0.47880553165488204 ,0.068961056550078934 ,0.22866318006273492 ,0.014150249063639016 ,0.082692506334333477 ,0.2736381372293395 ,0.019629172091143399 ,-0.21370510501747855 ,-0.47880553165488204 ,-0.035377700487834465 ,0.26124805887116109 ,0.65984118550413395 ,0.22866318006273492 ,0.16620743592545895 ,0.56995950950972596 ,0.27363813722933933 ,-0.91186171044018394 ,-1.9052400495461204 ,-0.47880553165488204 ,0.6598411855041334 ,0.94907360349082115 ,0.42479344051062212 ,0.56995950950972618 ,0.79061109099249016 ,0.4463830930850104 ,-1.9052400495461204 ,-3.1658136856321106 ,-0.8393802202731373 ,0.22866318006273464 ,0.42479344051062184 ,0.026601643994020405 ,0.2736381372293395 ,0.44638309308501056 ,0.036036418300443136 ,-0.47880553165488204 ,-0.83938022027313708 ,-0.068134511585552324 ,0.068961056550078961 ,0.22866318006273495 ,0.014150249063639013 ,0.082692506334333477 ,0.2736381372293395 ,0.019629172091143367 ,-0.21370510501747855 ,-0.47880553165488204 ,-0.035377700487834458 ,0.22866318006273476 ,0.42479344051062184 ,0.026601643994020374 ,0.27363813722933922 ,0.4463830930850104 ,0.036036418300443164 ,-0.47880553165488199 ,-0.83938022027313708 ,-0.068134511585552324 ,0.014150249063639028 ,0.026601643994020485 ,-0.079356045584809007 ,0.019629172091143433 ,0.036036418300443136 ,-0.11747567584434905 ,-0.035377700487834486 ,-0.068134511585552393 ,0.06422645688665414 };
	for (int test_ind = 0; test_ind < 9; test_ind ++) 
		for (int element_ind = 0; element_ind <9; element_ind ++) 
			BOOST_CHECK_CLOSE( result[test_ind][element_ind], true_result[test_ind*9+element_ind] , 0.00001); 
}

test_suite* test_vne(){ 
	test_suite * ts=BOOST_TEST_SUITE("Automateusz vne test");
	ts->add( BOOST_TEST_CASE( & vne_ss_AA));
	ts->add( BOOST_TEST_CASE( & vne_ss_AB));
	ts->add( BOOST_TEST_CASE( & vne_ss_BA));
	ts->add( BOOST_TEST_CASE( & vne_ss_BB));
	ts->add( BOOST_TEST_CASE( & vne_sp_AA));
	ts->add( BOOST_TEST_CASE( & vne_sp_AB));
	ts->add( BOOST_TEST_CASE( & vne_sp_BA));
	ts->add( BOOST_TEST_CASE( & vne_sp_BB));
	ts->add( BOOST_TEST_CASE( & vne_ps_AA));
	ts->add( BOOST_TEST_CASE( & vne_ps_AB));
	ts->add( BOOST_TEST_CASE( & vne_ps_BA));
	ts->add( BOOST_TEST_CASE( & vne_ps_BB));
	ts->add( BOOST_TEST_CASE( & vne_pp_AA));
	ts->add( BOOST_TEST_CASE( & vne_pp_AB));
	ts->add( BOOST_TEST_CASE( & vne_pp_BA));
	ts->add( BOOST_TEST_CASE( & vne_pp_BB));
	return ts;
}