#ifndef COMPLEXE_HPP
#define COMPLEXE_HPP

#include <math.h>

class Complexe
{
public :
    Complexe(float re, float im);
    Complexe operator+(const Complexe&) const;
    Complexe operator*(const Complexe&) const;
    Complexe operator*(float) const;

    float getRe() const;
    float getIm() const;
    float getNormal() const;

private :
    float m_re;
    float m_im;
};

#endif //COMPLEXE_HPP