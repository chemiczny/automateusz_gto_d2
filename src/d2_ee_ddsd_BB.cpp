#include "gto_d2_kit/d2_ee_ddsd_BB.hpp"
#include "gto_d2_kit/d2_ee_ddsd_AA.hpp"

void second_derivative_ee_2202_22( 
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
	double txx [125]= {};
	double txy [125]= {};
	double txz [125]= {};
	double tyx [125]= {};
	double tyy [125]= {};
	double tyz [125]= {};
	double tzx [125]= {};
	double tzy [125]= {};
	double tzz [125]= {};
	second_derivative_ee_2202_11( be, xB, yB, zB, ae, xA, yA, zA, ce, xC, yC, zC, de, xD, yD, zD,  bs, txx, txy, txz, tyx, tyy, tyz, tzx, tzy, tzz );
 	for( int j = 0 ; j<5; j++){ 
		for( int i = 0 ; i<5; i++){ 
			for( int l = 0 ; l<5; l++){ 
				int destinyInd = ((i)*5+j)*5+l;
				int sourceInd = ((j)*5+i)*5+l;
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
