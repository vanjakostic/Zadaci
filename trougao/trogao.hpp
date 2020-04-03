#ifndef TROGAO_HPP_INCLUDED
#define TROGAO_HPP_INCLUDED

#include <cmath>

class Trougao{

protected:
    double a;
    double b;
    double c;

public:

    Trougao(){a=3; b=4; c=5; }
    Trougao(double aa,double bb,double cc){a=aa; b=bb; c=cc; }
    Trougao(const Trougao &t){a=t.a; b=t.b; c=t.c; }

    double getA(){return a;}
    double getB(){return b;}
    double getC(){return c;}

    void setA(double aa) {a=aa;}
    void setB(double bb) {b=bb;}
    void setC(double cc) {c=cc;}

    double getO() const{return a+b+c;}

    double getP()const {
        double s=(a+b+c)/2;
        return sqrt( s*(s-a)*(s-b)*(s-c));
        }

};


#endif // TROGAO_HPP_INCLUDED
