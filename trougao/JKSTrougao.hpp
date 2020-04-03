#ifndef JKSTROUGAO_HPP_INCLUDED
#define JKSTROUGAO_HPP_INCLUDED

#include "JKtrougao.hpp"

class JKSTrougao: public JKTrougao{
public:
    JKSTrougao():JKTrougao(3,3){}
    JKSTrougao(double aa):JKTrougao(aa,aa){}
    JKSTrougao(const JKTrougao &s): JKTrougao(s.a,s.b){}
};


#endif // JKSTROUGAO_HPP_INCLUDED
