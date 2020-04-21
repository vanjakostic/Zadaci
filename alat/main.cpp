#include <iostream>

using namespace std;

class DinString{
private:
    int duzina;
    char *text;

public:

    DinString(){duzina=0; text=NULL; }
    DinString(const char ulaz[]){
        duzina=0;
        while(ulaz[duzina]!='\0'){
            duzina++;
        }
        text=new char [duzina+1];

        for(int i=0;i<duzina;i++){
            text[i]=ulaz[i];
        }
        text[duzina]='\0';
    }
    DinString(const DinString &d){
        duzina=d.duzina;

        text=new char [duzina+1];

        for(int i=0;i<duzina;i++){
            text[i]=d.text[i];
        }
        text[duzina]='\0';
    }
     ~DinString(){delete[] text;}
     int length()const{return duzina;}
     char& operator[] (int i){return text[i];}
     char operator[] (int i) const {return text[i];}

     DinString& operator=(const DinString &d){
            if(this!=&d) {
                delete[] text;
                duzina=d.duzina;
                text=new char[duzina+1];
                for(int i=0;i<duzina;i++){
                    text[i]=d.text[i];
                }
                text[duzina]='\0';
        }
            return *this;
    }

    DinString& operator+=(const DinString &d){
            int i;
            char *tempText=new char[duzina+d.duzina+1];
            for(i=0;i<duzina;i++){
                 tempText[i]=text[i];
            }
            for(i=0;i<d.duzina;i++){
                tempText[duzina+i]=d.text[i];
            }
            tempText[duzina+d.duzina]='\0';
            duzina+=d.duzina;
            delete[] text;
            text=tempText;

            return *this;
        }

    friend bool operator==(const DinString &d1,const DinString &d2){
        if(d1.duzina!=d2.duzina){
            return false;
        }
        for(int i=1;i<d1.duzina;i++){
            if(d1.text[i]!=d2.text[i]){
                return false;
            }
        }
    }

    friend bool operator!=(const DinString &d1 ,const DinString &d2){
        if(d1.duzina!=d2.duzina){
            return true;
        }
        for(int i=1;i<d1.duzina;i++){
            if(d1.text[i]!=d2.text[i]){
                return true;
            }
        }
    }

    friend DinString operator+(const DinString &d1,const DinString &d2){
        DinString t;
        t.duzina=d1.duzina+d2.duzina;
        t.text=new char[t.duzina+1];
        for(int i=0;i<d1.duzina;i++){
            t.text[i]=d1.text[i];
        }
        for(int i=0;i<d2.duzina;i++){
            t.text[d1.duzina+i]=d2.text[i];
        }
        t.text[t.duzina] = '\0';
        return t;
    }

    friend ostream& operator<<(ostream &out,const DinString &d){
        if(d.duzina>0){
            cout<<d.text;
        }
        return out;
    }
};
class Alat{
protected:
    DinString proizvodjac;
    DinString serijskiBroj;

public:
    void ispis(){
        cout<<"Proizvodjac :"<<proizvodjac<<endl;
        cout<<"Serijski broj :"<<serijskiBroj<<endl;
    }
};

class Cekic: public Alat{
private:
    double tezina;
    int upotrebljivost;

public:

    Cekic(){proizvodjac="AlatiiMasine"; serijskiBroj="25063"; tezina=675; upotrebljivost=9;}
    Cekic(DinString p, DinString sb, double t, double u){proizvodjac=p; serijskiBroj=sb; tezina=t;
    if(u>0){
            upotrebljivost = u;
        }
    }
    Cekic(const Cekic &c){proizvodjac=c.proizvodjac; serijskiBroj=c.serijskiBroj; tezina=c.tezina; upotrebljivost=c.upotrebljivost; }
    ~Cekic(){}

    void ispis(){

        Alat::ispis();
        cout<<"Tezina :"<<tezina<<endl;
        cout<<"Upotrebljivost :"<<upotrebljivost<<endl;
    }

    bool upotrebi(){
        if(upotrebljivost>0){
            upotrebljivost--;
            return true;
        }else
            return false;
    }
};

class Testera: public Alat{
private:
    double otupljenost;
public:

    Testera(){proizvodjac="AlatiiMasine"; serijskiBroj="460528"; otupljenost=0.00;}
    Testera(DinString p, DinString sb, double o){ proizvodjac=p; serijskiBroj=sb;
        if(otupljenost>0 && otupljenost<1 ){
            otupljenost=o;
        }
    }
    Testera(const Testera &t){proizvodjac=t.proizvodjac; serijskiBroj=t.serijskiBroj; otupljenost=t.otupljenost; }

    void ispis(){
        Alat::ispis();
        cout<<"Otupljenost :"<<otupljenost<<endl;
    }

    bool Upotrebi(){
        if(otupljenost>0){
            otupljenost=otupljenost+0.05;
            return true;
        }else
            return false;
    }

    bool naostri(){
        if(otupljenost<1){
            otupljenost=otupljenost-0.05;
            return true;
        }else
            return false;
    }

};
int main()
{
    Cekic c1;
    Cekic c2("Alati Klisa","161616",600.00,10);
    Cekic c3(c2);

    c1.ispis();
    c2.ispis();
    c3.upotrebi();
    c3.ispis();

    Testera t1;
    Testera t2("Alati Klisa","232323",0.00);
    Testera t3(t2);

    t1.ispis();
    t2.ispis();
    t3.ispis();
    t3.Upotrebi();
    t3.Upotrebi();
    t3.ispis();
    t3.naostri();
    t3.ispis();

    return 0;
}
