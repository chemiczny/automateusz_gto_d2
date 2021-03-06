#ifndef D2_NE_SS_AB_HPP
#define D2_NE_SS_AB_HPP

#include <cstdlib>
void vne_second_derivative_00_12(    double ae, double be,
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
    std::size_t Ai, std::size_t Bi);

void vne_second_derivative_00_21(    double ae, double be,
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
    std::size_t Ai, std::size_t Bi);
#endif