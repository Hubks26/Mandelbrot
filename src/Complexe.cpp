#include "Complexe.hpp"

Complexe::Complexe(float re, float im)
: m_re(re)
, m_im(im)
{}

Complexe Complexe::operator+(const Complexe& other) const 
{
    Complexe resultat(m_re + other.getRe(), m_im + other.getIm());
    return resultat;
}

Complexe Complexe::operator*(const Complexe& other) const 
{
    Complexe resultat(m_re*other.getRe() - m_im*other.getIm(), m_re*other.getIm() + m_im*other.getRe());
    return resultat;
}

Complexe Complexe::operator*(float lambda) const 
{
    Complexe resultat(lambda*m_re, lambda*m_im);
    return resultat;
}

float Complexe::getRe() const
{
    return m_re;
}

float Complexe::getIm() const
{
    return m_im;
}

float Complexe::getNormal() const
{
    return sqrt(m_re*m_re + m_im*m_im);
}