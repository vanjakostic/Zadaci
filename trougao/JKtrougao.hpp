#ifndef JKTROUGAO_HPP_INCLUDED
#define JKTROUGAO_HPP_INCLUDED

#include "trogao.hpp"

class JKTrougao: public Trougao{
public:
    JKTrougao(): Trougao(3,4,4){}
    JKTrougao(double aa, double bb): Trougao(aa,bb,bb){}
    JKTrougao(const JKTrougao &k): Trougao(k.a,k.b,k.c){}


};


#endif // JKTROUGAO_HPP_INCLUDED
