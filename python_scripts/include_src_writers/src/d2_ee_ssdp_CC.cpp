#include "gto_d2_kit/d2_ee_ssdp_CC.hpp"
#include "gto_d2_kit/d2_ee_dpss_AA.hpp"

void second_derivative_ee_0021_33( 
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
	second_derivative_ee_2100_11( ce, xC, yC, zC, de, xD, yD, zD, ae, xA, yA, zA, be, xB, yB, zB,  bs, d2eexx, d2eexy, d2eexz, d2eeyx, d2eeyy, d2eeyz, d2eezx, d2eezy, d2eezz );
 }
