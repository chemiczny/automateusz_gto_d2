#include "gto_d2_kit/d2_ee_dsss_BD.hpp"
#include "gto_d2_kit/d2_ee_sssd_AC.hpp"

void second_derivative_ee_2000_24( 
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
	second_derivative_ee_0002_13( de, xD, yD, zD, ce, xC, yC, zC, be, xB, yB, zB, ae, xA, yA, zA,  bs, d2eexx, d2eeyx, d2eezx, d2eexy, d2eeyy, d2eezy, d2eexz, d2eeyz, d2eezz );
 }
