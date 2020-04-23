#include <iostream>

using namespace std;

class Zivotinja{
public:
    void ispis(){ cout<<"Ova životinja govori :"<<endl;}
};
class Pas : public Zivotinja{
public:
    void ispis(){
        cout<<"av-av"<<endl;
    }
};
class Krava:public Zivotinja{
public:
    void ispis(){
        cout<<"muu"<<endl;
    }
};
class Macka: public Zivotinja{
public:
    void ispis(){
    cout<<"Mjau"<<endl;
    }
};

int main()
{
    Pas p;
    Krava k;
    Macka m;

    Zivotinja *z1=&p;
    Zivotinja *z2=&k;
    Zivotinja *z3=&m;

    cout<<"Pas :";
    z1->ispis();
    p.ispis();

    cout<<"Krava :";
    z2->ispis();
    k.ispis();

    cout<<"Macka :";
    z3->ispis();
    m.ispis();

    return 0;
}
