#include <iostream>

using namespace std;

class DinString{
private:
    int duzina;
    char *text;
public:

    DinString(){duzina=0; text=NULL; }
    DinString(const char ulaz[]) {
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
    int lenght()const {return duzina;}
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

class Tastatura{
protected:
    DinString proizvodjac;
    int brojTastera;

public:
    void ispis(){
        cout<<"Proizvodjac :"<<proizvodjac<<endl;
        cout<<"Broj tastera :"<<brojTastera<<endl;
    }
};

class GejmerskaTastatura: public Tastatura{
private:
    int brojPritisaka;
public:
    GejmerskaTastatura(){brojPritisaka=0; proizvodjac="tastature klisa"; brojTastera= 104; }
    GejmerskaTastatura(int bp, DinString p, int bt){ brojPritisaka=bp; proizvodjac=p; brojTastera=bt; }
    GejmerskaTastatura(const GejmerskaTastatura &gt){ brojPritisaka=gt.brojPritisaka ; proizvodjac=gt.proizvodjac; brojTastera=gt.brojTastera; }
    ~GejmerskaTastatura(){}

    void ispis(){
        Tastatura::ispis();
        cout<<"Broj pritisaka :"<<brojPritisaka<<endl;
    }

    void pritisniTaster(){
        brojPritisaka++;
    }

    void drziTaster(int sec){
        brojPritisaka += sec;
    }
};
class NumerickaTastatura: public Tastatura{
private:
    int brojPritisakaBrojeva;

public:
    NumerickaTastatura(){brojPritisakaBrojeva=0; proizvodjac="tastature klisa"; brojTastera=104; }
    NumerickaTastatura(int bpb, DinString p, int bt){ brojPritisakaBrojeva=bpb; proizvodjac=p; brojTastera=bt; }
    NumerickaTastatura(const NumerickaTastatura &nt){brojPritisakaBrojeva=nt.brojPritisakaBrojeva; proizvodjac=nt.proizvodjac;}
    ~NumerickaTastatura(){}

    void ispis(){
        Tastatura::ispis();
        cout<<"Broj pritisaka brojeva :"<<brojPritisakaBrojeva<<endl;
    }

    void pritisniTaster(bool PritisniBroj){

        if(PritisniBroj == true){
            brojPritisakaBrojeva++;
        }
    }

    void drziTaster(int sec,bool PritisnutBroj){
        if(PritisnutBroj == true){
            brojPritisakaBrojeva += sec;
        }
    }
};

int main()
{
    GejmerskaTastatura g1;
    GejmerskaTastatura g2(10,"proizvodjac neki",104);
    GejmerskaTastatura g3(g2);

    g1.ispis();
    g2.ispis();
    g3.ispis();

    g1.drziTaster(10);
    g2.pritisniTaster();
    g1.ispis();
    g2.ispis();

    NumerickaTastatura n1;
    NumerickaTastatura n2(10,"proizvodjac",104);
    NumerickaTastatura n3(n2);

    n1.ispis();
    n2.ispis();
    n3.ispis();

    n1.pritisniTaster(true);
    n2.drziTaster(5,true);
    n1.ispis();
    n2.ispis();

    return 0;
}
