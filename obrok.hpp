#ifndef OBROK_HPP_INCLUDED
#define OBROK_HPP_INCLUDED

enum StanjeObroka{pocetak_odabira,odabrano_meso,odabran_prilog,spreman,zagoreo};

class Obrok{
private:
    Meso m;
    Prilog p;
    StanjeObroka  stanje;

public:
    Obrok: m(),p(),stanje(pocetak_odabira){}
    Obrok(const Obrok &o):m(o.m),p(o.m),stanje(o.stanje)




};


#endif // OBROK_HPP_INCLUDED
