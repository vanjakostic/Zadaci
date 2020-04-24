#include <iostream>
using namespace std;
class DinString{
private:
    int duzina;
    char *text;
public:
    DinString(){
        duzina = 0;
        text = NULL;
    }
    DinString(const char ulaz[]) {
        duzina = 0;
        while(ulaz[duzina] != '\0')
            duzina++;
        text = new char[duzina + 1];
        for(int i = 0; i < duzina; i++)
            text[i] = ulaz[i];
        text[duzina] = '\0';
    }
    DinString(const DinString& ds) {
        duzina = ds.duzina;
        text = new char[duzina + 1];
        for(int i = 0; i < duzina; i++)
            text[i] = ds.text[i];
        text[duzina] = '\0';
    }
    ~DinString() {
        delete[] text;
    }
    int length() const {
            return duzina;
    }
    char& operator[] (int i) {
        return text[i];
    }
    DinString& operator=(const DinString& ds) {
        if(this != &ds) {
            delete[] text;
            duzina = ds.duzina;
            text = new char[duzina + 1];
            for (int i = 0; i < duzina; i++)
                text[i] = ds.text[i];
            text[duzina] = '\0';
        }
        return *this;
    }
    DinString& operator+=(const DinString& ds) {
        int i;
        char *tempText = new char[duzina + ds.duzina + 1];
        for (i = 0; i < duzina; i++)
            tempText[i] = text[i];
        for (i = 0; i < ds.duzina; i++)
            tempText[duzina + i] = ds.text[i];
        tempText[duzina + ds.duzina] = '\0';
        duzina += ds.duzina;
        delete[] text;
        text = tempText;
        return *this;
    }
    friend bool operator==(const DinString& ds1, const DinString& ds2){
    if(ds1.duzina != ds2.duzina)
        return false;
    for(int i = 0; i < ds1.duzina; i++)
        if(ds1.text[i] != ds2.text[i])
            return false;
    return true;
    }
    friend bool operator!=(const DinString& ds1, const DinString& ds2){
        if(ds1.duzina != ds2.duzina)
            return true;
    for(int i = 0; i < ds1.duzina; i++)
        if(ds1.text[i] != ds2.text[i])
            return true;
    return false;
    }
    friend DinString operator+(const DinString& ds1, const DinString& ds2){
        DinString temp;
        temp.duzina = ds1.duzina + ds2.duzina;
        temp.text = new char[temp.duzina + 1];
        int i;
        for(i = 0; i < ds1.duzina; i++)
            temp.text[i] = ds1.text[i];
        for(i = 0; i < ds2.duzina; i++)
            temp.text[ds1.duzina + i] = ds2.text[i];
        temp.text[temp.duzina] = '\0';
        return temp;
    }
    friend ostream& operator<<(ostream& out, const DinString& ds) {
        if(ds.duzina > 0)
            out << ds.text;
    return out;
    }
};

class Abs{
public:

    virtual int getTemperatura()const {}
    virtual void setTemperatura(int t)=0;
};

class Grejac: public Abs{
private:
    int temperatura;

public:
    Grejac(){temperatura=0; }
    Grejac(int t){temperatura=t;}
    Grejac(const Grejac &g ){temperatura=g.temperatura; }

    void setTemperatura(int t){
    if(t>0 && t<100)
        temperatura=t;
    }

    int getTemperatura(){ return temperatura; }

};

enum Modovi {hladno,toplo};

class Fen{
private:
    DinString marka;
    Modovi mod;
    Grejac grejac;
public:
    Fen(DinString mk, Modovi md){
        marka=mk;
        mod=md;
        if(mod==hladno)
            grejac.setTemperatura(0);
        else
            grejac.setTemperatura(1);
    }

    Fen(const Fen &f):grejac(f.grejac){marka=f.marka; mod=f.mod; }
    DinString getMarka(){return marka; }
    Modovi getMod(){return mod; }
    Grejac getGrejac(){return grejac; }

    void setMod(Modovi md){
        if(mod == HLADNO && md == TOPLO){
            grejac.setTemperatura(1);
        }else if(mod == TOPLO && md == HLADNO){
            grejac.setTemperatura(0);
        }
        mod = md;
    }

    void setMarka(DinString mk){marka=mk; }
    void setTemperatura(int t){
        if(t>=1){
            if(mod == TOPLO){
                grejac.setTemperatura(t);
            }
        }
    }

};
int main()
{
    Grejac g1;
    Grejac g2(70);
    Grejac g3(g2);

    cout<<"1: "< g1.getTemperatura()<<endl;
    cout<<"2: "< g2.getTemperatura()<<endl;
    cout<<"3: "< g3.getTemperatura()<<endl;

    g1.setTemperatura(20);
    g2.setTemperatura(40);
    g3.setTemperatura(60);

    cout<<"1: "< g1.getTemperatura()<<endl;
    cout<<"2: "< g2.getTemperatura()<<endl;
    cout<<"3: "< g3.getTemperatura()<<endl;

    Fen f1("Philips",toplo);
    Fen f2("Philips",hladno);
    Fen f3(f2);

    cout<<"1: "<<f1<<endl;
    cout<<"2: "<<f2<<endl;
    cout<<"3: "<<f3<<endl;





    return 0;
}
