#ifndef PRELIV_HPP_INCLUDED
#define PRELIV_HPP_INCLUDED


enum TipPreliva {cokoladni,cokoladni_sa_slagom};

class Preliv{

private:
    TipPreliva tip;

public:
    Preliv(TipPreliva t=cokoladni){tip=t; }

    bool dodajSlag(){
        if(tip==cokoladni){
            tip=cokoladni_sa_slagom;
            return true;
        }
        else
            return false;
    }

    bool ukloniSlag(){
        if(tip==cokoladni_sa_slagom){
            tip=cokoladni;
            return true;
        }
        else
            return false;
    }

    TipPreliva const getTip(){return tip; }

    friend void ispisPreliv(const Preliv&);

};



#endif // PRELIV_HPP_INCLUDED
