#include "gto_d2_kit/d2_ee_dddd_BD.hpp"
#include "gto_d2_kit/d2_ee_dddd_AC.hpp"

void second_derivative_ee_2222_24( 
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
	double txx [625]= {};
	double txy [625]= {};
	double txz [625]= {};
	double tyx [625]= {};
	double tyy [625]= {};
	double tyz [625]= {};
	double tzx [625]= {};
	double tzy [625]= {};
	double tzz [625]= {};
	second_derivative_ee_2222_13( be, xB, yB, zB, ae, xA, yA, zA, de, xD, yD, zD, ce, xC, yC, zC,  bs, txx, txy, txz, tyx, tyy, tyz, tzx, tzy, tzz );
 	for( int j = 0 ; j<5; j++){ 
		for( int i = 0 ; i<5; i++){ 
			for( int l = 0 ; l<5; l++){ 
				for( int k = 0 ; k<5; k++){ 
					int destinyInd = (((i)*5+j)*5+k)*5+l;
					int sourceInd = (((j)*5+i)*5+l)*5+k;
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
