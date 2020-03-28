#include <iostream>

#include "kolac.hpp"

using namespace std;

void ispisPreliv (const Preliv& p){
    cout<<"Preliv : ";
    if(p.tip==cokoladni){
        cout<<"Cokoladni"<<endl;
    }
    else
        cout<<"Cokoladni sa slagom"<<endl;
};

 void ispisiKolac(const Kolac &k){
    cout<<"---------------"<<endl;
    cout<<"Stanje : ";

    switch(k.stanje){
        case u_pripremi:
            cout<<"U pripremi";
            break;

        case pece_se:
            cout<<"Pece se";
            break;

        case pripremljen:
            cout<<"Pripremljen";
            break;

        case zagoreo:
            cout<<"Zagoreo";
            break;
    }
    cout<<endl;
    cout<<"Temperatura : "<<k.temperatura<<endl;
    ispisPreliv(k.preliv);

    cout<<"---------------"<<endl;

};

void meni(){

    cout<<"1. Ispisi kolac"<<endl;
    cout<<"2. Stavi da se pece"<<endl;
    cout<<"3. Ispeci"<<endl;
    cout<<"4. Zavrsi kolac"<<endl;
    cout<<"5. Povecaj temperaturu"<<endl;
    cout<<"6. Smanji temperaturu"<<endl;
    cout<<"7. Dodaj slag"<<endl;
    cout<<"8. Skini slag"<<endl;
    cout<<"9. Kraj programa"<<endl;
}

int main()
{
    Kolac k1;

    int n=0;

    do{
        meni();
        cin>>n;

        switch(n){

    case 1:
        ispisiKolac(k1);
        break;
    case 2:
        if(k1.staviDaSePece())
            cout<<"Pece se";
        else
            cout<<"Greska";
        cout<<endl;
        break;

    case 3:
        if(k1.ispeciKolac())
            cout<<"Ispekao se";
        else
            cout<<"Greska";
        cout<<endl;
        break;

    case 4:
        if(k1.zavrsiKolac())
            cout<<"Zavrsen je";
        else
            cout<<"Greska";
        cout<<endl;
        break;

    case 5:
        if(k1.povecajTemperaturu())
            cout<<"Povecana je temperatura";
        else
            cout<<"Greska";
        cout<<endl;
        break;

    case 6:
        if(k1.smanjiTemperaturu())
            cout<<"Smanjena je temperatura";
        else
            cout<<"Greska";
        cout<<endl;
        break;

    case 7:
        if(k1.dodajSlag())
            cout<<"Slag je dodat";
        else
            cout<<"Greska";
        cout<<endl;
        break;
    case 8:
        if(k1.ukloniSlag())
            cout<<"Slag je skinut";
        else
            cout<<"Greska";
        cout<<endl;
        break;
        }



    }while(n!=9);

    return 0;
}
