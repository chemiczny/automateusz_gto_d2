#include "gto_d2_kit/d2_ee_sddd_BC.hpp"
#include "gto_d2_kit/d2_ee_dsdd_AC.hpp"

void second_derivative_ee_0222_23( 
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
	second_derivative_ee_2022_13( be, xB, yB, zB, ae, xA, yA, zA, ce, xC, yC, zC, de, xD, yD, zD,  bs, d2eexx, d2eexy, d2eexz, d2eeyx, d2eeyy, d2eeyz, d2eezx, d2eezy, d2eezz );
 }
