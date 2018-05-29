#include "gto_d2_kit/d2_ne_pp_AC.hpp"
void vne_second_derivative_11_31(    double ae, double be,
    double xA, double yA, double zA,
    double xB, double yB, double zB,
    double xC, double yC, double zC,
    const double* bs,
    double* const d2nexx,
    double* const d2nexy,
    double* const d2nexz,
    double* const d2neyx,
    double* const d2neyy,
    double* const d2neyz,
    double* const d2nezx,
    double* const d2nezy,
    double* const d2nezz,
    std::size_t matrix_size,
    std::size_t Ai, std::size_t Bi){
 vne_second_derivative_11_13( ae, be, xA, yA, zA, xB, yB, zB, xC, yC, zC, bs, d2nexx, d2neyx, d2nezx, d2nexy, d2neyy, d2nezy, d2nexz, d2neyz, d2nezz, matrix_size,  Ai, Bi );
}
