#include "gto_d2_kit/d2_ee_sddd_AC.hpp"
#include "gto_d2_kit/d2_ee_sddd_AC_xx.hpp"
#include "gto_d2_kit/d2_ee_sddd_AC_xy.hpp"
#include "gto_d2_kit/d2_ee_sddd_AC_xz.hpp"
#include "gto_d2_kit/d2_ee_sddd_AC_yx.hpp"
#include "gto_d2_kit/d2_ee_sddd_AC_yy.hpp"
#include "gto_d2_kit/d2_ee_sddd_AC_yz.hpp"
#include "gto_d2_kit/d2_ee_sddd_AC_zx.hpp"
#include "gto_d2_kit/d2_ee_sddd_AC_zy.hpp"
#include "gto_d2_kit/d2_ee_sddd_AC_zz.hpp"
void second_derivative_ee_0222_13( 
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
   second_derivative_ee_0222_13_11( ae, xA, yA, zA, be, xB, yB, zB, ce, xC, yC, zC, de, xD, yD, zD, bs, d2eexx );
   second_derivative_ee_0222_13_12( ae, xA, yA, zA, be, xB, yB, zB, ce, xC, yC, zC, de, xD, yD, zD, bs, d2eexy );
   second_derivative_ee_0222_13_13( ae, xA, yA, zA, be, xB, yB, zB, ce, xC, yC, zC, de, xD, yD, zD, bs, d2eexz );
   second_derivative_ee_0222_13_21( ae, xA, yA, zA, be, xB, yB, zB, ce, xC, yC, zC, de, xD, yD, zD, bs, d2eeyx );
   second_derivative_ee_0222_13_22( ae, xA, yA, zA, be, xB, yB, zB, ce, xC, yC, zC, de, xD, yD, zD, bs, d2eeyy );
   second_derivative_ee_0222_13_23( ae, xA, yA, zA, be, xB, yB, zB, ce, xC, yC, zC, de, xD, yD, zD, bs, d2eeyz );
   second_derivative_ee_0222_13_31( ae, xA, yA, zA, be, xB, yB, zB, ce, xC, yC, zC, de, xD, yD, zD, bs, d2eezx );
   second_derivative_ee_0222_13_32( ae, xA, yA, zA, be, xB, yB, zB, ce, xC, yC, zC, de, xD, yD, zD, bs, d2eezy );
   second_derivative_ee_0222_13_33( ae, xA, yA, zA, be, xB, yB, zB, ce, xC, yC, zC, de, xD, yD, zD, bs, d2eezz );
 }