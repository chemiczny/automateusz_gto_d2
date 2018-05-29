#include "gto_d2_kit/d2_ee_pppp_DD.hpp"
#include "gto_d2_kit/d2_ee_pppp_AA.hpp"

void second_derivative_ee_1111_44( 
     const double ae,             
     const double xA,	     
     const double yA,             
     const double zA,	     
     const double be,             
     const double xB,	     
     const double yB,             
     const double zB,	     
     const double ce,             
     const double xC,	     
     const double yC,             
     const double zC,	     
     const double de,             
     const double xD,	     
     const double yD,             
     const double zD,	     
     const double* const bs, 	    
     double* const d2eexx,   	    
     double* const d2eexy,   	    
     double* const d2eexz,   	    
     double* const d2eeyx,		  
     double* const d2eeyy,		  
     double* const d2eeyz,		  
     double* const d2eezx,		  
     double* const d2eezy,		  
     double* const d2eezz)		  
 { 		  
	double txx [81]= {};
	double txy [81]= {};
	double txz [81]= {};
	double tyx [81]= {};
	double tyy [81]= {};
	double tyz [81]= {};
	double tzx [81]= {};
	double tzy [81]= {};
	double tzz [81]= {};
	second_derivative_ee_1111_11( de, xD, yD, zD, ce, xC, yC, zC, ae, xA, yA, zA, be, xB, yB, zB,  bs, txx, txy, txz, tyx, tyy, tyz, tzx, tzy, tzz );
 	for( int l = 0 ; l<3; l++){ 
		for( int k = 0 ; k<3; k++){ 
			for( int i = 0 ; i<3; i++){ 
				for( int j = 0 ; j<3; j++){ 
					int destinyInd = (((i)*3+j)*3+k)*3+l;
					int sourceInd = (((l)*3+k)*3+i)*3+j;
					d2eexx[ destinyInd ] += txx[ sourceInd ]; 
					d2eexy[ destinyInd ] += txy[ sourceInd ]; 
					d2eexz[ destinyInd ] += txz[ sourceInd ]; 
					d2eeyx[ destinyInd ] += tyx[ sourceInd ]; 
					d2eeyy[ destinyInd ] += tyy[ sourceInd ]; 
					d2eeyz[ destinyInd ] += tyz[ sourceInd ]; 
					d2eezx[ destinyInd ] += tzx[ sourceInd ]; 
					d2eezy[ destinyInd ] += tzy[ sourceInd ]; 
					d2eezz[ destinyInd ] += tzz[ sourceInd ]; 
				}
			}
		}
	}
}
