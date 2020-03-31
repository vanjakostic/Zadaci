#ifndef PRILOG_HPP_INCLUDED
#define PRILOG_HPP_INCLUDED

enum TipPriloga{pasulj, riza, pomfrit, testenina, bez_priloga};

class Prilog{
private:

    TipPriloga tip;
public:

    Prilog(){tip=bez_priloga;}
    Prilog(const Prilog &p){tip=p.tip; }

    void setTip(){tip=bez_priloga;}
    TipPriloga getTip(){return tip; }


};


#endif // PRILOG_HPP_INCLUDED
