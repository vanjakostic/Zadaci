#ifndef MESO_HPP_INCLUDED
#define MESO_HPP_INCLUDED

enum VrstaMesa{svinjetina, junetina, piletina, bez_mesa};

class Meso{
private:
    int gramaza;
    VrstaMesa vrsta;
public:

    Meso(){gramaza=0; vrsta=bez_mesa;}
    Meso(const Meso &m){gramaza=m.gramaza; vrsta=m.vrsta;}

    bool setGramaza(int g)
    {
        if(g>=0 && g<=1000)
        {
            gramaza = g;
            return true;
        }else
            return false;
    }
    void setVrsta(int v){vrsta=v;}

    int getGramaza(){return gramaza;}
    VrstaMesa getVrsta(){return vrsta:}

};


#endif // MESO_HPP_INCLUDED
