#include "gto_d2_kit/d2_ee_dpdd_DD.hpp"
#include "gto_d2_kit/d2_ee_ddpd_AA.hpp"

void second_derivative_ee_2122_44( 
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
	double txx [375]= {};
	double txy [375]= {};
	double txz [375]= {};
	double tyx [375]= {};
	double tyy [375]= {};
	double tyz [375]= {};
	double tzx [375]= {};
	double tzy [375]= {};
	double tzz [375]= {};
	second_derivative_ee_2212_11( de, xD, yD, zD, ce, xC, yC, zC, be, xB, yB, zB, ae, xA, yA, zA,  bs, txx, txy, txz, tyx, tyy, tyz, tzx, tzy, tzz );
 	for( int l = 0 ; l<5; l++){ 
		for( int k = 0 ; k<5; k++){ 
			for( int j = 0 ; j<3; j++){ 
				for( int i = 0 ; i<5; i++){ 
					int destinyInd = (((i)*3+j)*5+k)*5+l;
					int sourceInd = (((l)*5+k)*3+j)*5+i;
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
