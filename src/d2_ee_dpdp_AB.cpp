#include "gto_d2_kit/d2_ee_dpdp_AB.hpp"
#include "gto_d2_kit/d2_ee_pdpd_AB.hpp"

void second_derivative_ee_2121_12( 
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
	double txx [225]= {};
	double txy [225]= {};
	double txz [225]= {};
	double tyx [225]= {};
	double tyy [225]= {};
	double tyz [225]= {};
	double tzx [225]= {};
	double tzy [225]= {};
	double tzz [225]= {};
	second_derivative_ee_1212_12( be, xB, yB, zB, ae, xA, yA, zA, de, xD, yD, zD, ce, xC, yC, zC,  bs, txx, tyx, tzx, txy, tyy, tzy, txz, tyz, tzz );
 	for( int j = 0 ; j<3; j++){ 
		for( int i = 0 ; i<5; i++){ 
			for( int l = 0 ; l<3; l++){ 
				for( int k = 0 ; k<5; k++){ 
					int destinyInd = (((i)*3+j)*5+k)*3+l;
					int sourceInd = (((j)*5+i)*3+l)*5+k;
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
