#ifndef D2_EE_DPPS_BB_HPP
#define D2_EE_DPPS_BB_HPP

void second_derivative_ee_2110_22(    const double ae,
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
    const double* const bs,    double* const d2eexx,    double* const d2eexy,    double* const d2eexz,    double* const d2eeyx,    double* const d2eeyy,    double* const d2eeyz,    double* const d2eezx,    double* const d2eezy,    double* const d2eezz);
#endif