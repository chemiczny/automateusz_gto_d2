#include "gto_d2_kit/d2_ee_pppd_CC.hpp"
#include "gto_d2_kit/d2_ee_pdpp_AA.hpp"

void second_derivative_ee_1112_33( 
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
	double txx [135]= {};
	double txy [135]= {};
	double txz [135]= {};
	double tyx [135]= {};
	double tyy [135]= {};
	double tyz [135]= {};
	double tzx [135]= {};
	double tzy [135]= {};
	double tzz [135]= {};
	second_derivative_ee_1211_11( ce, xC, yC, zC, de, xD, yD, zD, ae, xA, yA, zA, be, xB, yB, zB,  bs, txx, txy, txz, tyx, tyy, tyz, tzx, tzy, tzz );
 	for( int k = 0 ; k<3; k++){ 
		for( int l = 0 ; l<5; l++){ 
			for( int i = 0 ; i<3; i++){ 
				for( int j = 0 ; j<3; j++){ 
					int destinyInd = (((i)*3+j)*3+k)*5+l;
					int sourceInd = (((k)*5+l)*3+i)*3+j;
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
