#ifndef KOLAC_HPP_INCLUDED
#define KOLAC_HPP_INCLUDED

#include "preliv.hpp"

enum KolacStanje{u_pripremi,pece_se,zagoreo,pripremljen};

class Kolac{
private:
    KolacStanje stanje;
    int temperatura;
    Preliv preliv;

public:

    Kolac():stanje(u_pripremi),temperatura(20),preliv(cokoladni){}
    Kolac(Kolac &k):stanje(k.stanje),temperatura(k.temperatura),preliv(k.preliv){}

    bool staviDaSePece(){
        if(stanje==u_pripremi && preliv.getTip()==cokoladni){
            stanje=pece_se;
            temperatura+=20;
            return true;
        }
        else
            return false;
    }

    bool ispeciKolac(){
        if(stanje==pece_se){
            stanje=u_pripremi;
            temperatura=20;
            return true;
        }
        else
            return false;
    }

    bool zavrsiKolac(){
        if(stanje==u_pripremi){
            stanje=pripremljen;
            return true;
        }
        else
            return  false;
    }

    bool povecajTemperaturu(){
        if(stanje==pece_se){
            temperatura+=20;
            if(temperatura>=100){
                stanje=zagoreo;
                temperatura=20;
            }
            return true;
        }
        else
            return false;
    }

    bool smanjiTemperaturu(){
        if(stanje==pece_se && temperatura>=60){
                temperatura-=20;
                return true;
        }
        else
            return false;

    }

    bool dodajSlag(){
        if(stanje==u_pripremi && preliv.getTip()==cokoladni){
            preliv=cokoladni_sa_slagom;
            return true;
        }
        else
            return false;
    }

    bool ukloniSlag(){
        if(stanje==u_pripremi && preliv.getTip()==cokoladni_sa_slagom){
            preliv=cokoladni;
            return true;
        }
        else
            return false;

    }

    KolacStanje getStanjeKolaca(){return stanje;}
    int getTemperaturaKolaca(){return temperatura;}
    Preliv getTip(){return preliv.getTip();}

    friend void ispisiKolac(const Kolac &);

};

#endif // KOLAC_HPP_INCLUDED
