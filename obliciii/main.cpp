#include <iostream>

using namespace std;

class Oblik{
protected:
    int a;
    int b;

public:
     void setStranice(int aa, int bb){a=aa; b=bb; }

     int povrsina(){}
     int obim(){}
};

class Kvadrat: public Oblik{
public:
    int povrsina(){return a*a; }
    int obim(){return 4*a; }
};

class Pravougaonik: public Oblik{
public:
    int povrsina(){return a*b; }
    int obim(){return 2*a+2*b; }

};

class Krug: public Oblik{
public:
    int povrsina(){return 3.14*a*a; }
    int obim(){return 2*a*3.14; }
};

int main()
{
    Kvadrat k;
    Pravougaonik p;
    Krug g;

    Oblik *o1=&k;
    Oblik *o2=&p;
    Oblik *o3=&g;

    o1->setStranice(4,4);
    o2->setStranice(3,5);
    o3->setStranice(1,1);

    cout<<"Obim kvadrata :"<< k.obim()<<endl;
    cout<<"Provrsina kvadrata :"<< k.povrsina()<<endl;
    cout<<"Obim pravougaonika :"<< p.obim()<<endl;
    cout<<"Povrsina pravougaonika :"<< p.povrsina()<<endl;
    cout<<"Obim kruga :"<<g.obim()<<endl;
    cout<<"Povrsina kruga :"<<g.povrsina()<<endl;


    return 0;
}
