#include <iostream>
#include <cmath>

using namespace std;

class Figura{
protected:
    double a;
    double b;
public:
    virtual double Povrsina()=0;
    virtual double Obim()=0;

};

class Pravougaonik: public Figura{

public:

    Pravougaonik(){a=8.00; b=2.00; }
    Pravougaonik(double aa, double bb){a=aa; b=bb; }
    Pravougaonik(const Pravougaonik &p){a=p.a; b=p.b; }

    double getA()const{return a;}
    double getB()const {return b;}

    void setA(double aa) {a=aa; }
    void setB(double bb) {b=bb; }

    double Povrsina(){return a*b; }
    double Obim(){return 2.00*a+2.00*b; }
};

class Elipsa: public Figura{

public:

    Elipsa(){a=1.00; b=4.00; }
    Elipsa(double xx, double yy){a=xx; b=yy; }
    Elipsa(const Elipsa &e){a=e.a; b=e.b; }

    double getX() {return a;}
    double getY() {return b;}

    void setX(double xx) {a=xx;}
    void setY(double yy) {b=yy;}

    double Povrsina(){return a*b*M_PI; }
    double Obim(){return M_PI*(3*(a+b)-sqrt((3.00*a+b)*(a+3.00*b))); }

};

class Kvadrat: public Pravougaonik{
public:
    Kvadrat():Pravougaonik(4.00,4.00){}
    Kvadrat(double x): Pravougaonik(x,x){}
    Kvadrat(const Kvadrat &k): Pravougaonik(k.a,k.a){}
};

class Krug: public Elipsa{
public:
    Krug(): Elipsa(2.00,2.00){}
    Krug(double y): Elipsa(y,y){}
    Krug(const Krug &c): Elipsa(c.a,c.a){}
};

class Oblik{
private:
    Kvadrat A;
    Krug B;
public:
    Oblik(): A(),B() {}
    Oblik(double x,double y): A(x),B(y){}
    Oblik(const Oblik &o):A(o.A),B(o.B){}

    double Obim(){ return A.Obim()+B.Obim(); }
    double Povrsina(){ return abs(A.Povrsina()-B.Povrsina());}
};


int main()
{
    Pravougaonik p1;
    Pravougaonik p2(6.00,1.00);
    Pravougaonik p3(p1);

    cout<<"Obimi pravougaonika"<<endl;
    cout<<p1.Obim()<<endl;
    cout<<p2.Obim()<<endl;
    cout<<p3.Obim()<<endl;

    cout<<"Povrsina pravougaonika"<<endl;
    cout<<p1.Povrsina()<<endl;
    cout<<p2.Povrsina()<<endl;
    cout<<p3.Povrsina()<<endl;

    Elipsa e1;
    Elipsa e2(5.00,3.00);
    Elipsa e3(e1);

    cout<<"Obimi elipsi"<<endl;
    cout<<e1.Obim()<<endl;
    cout<<e2.Obim()<<endl;
    cout<<e3.Obim()<<endl;

    cout<<"Povrsina elipsi"<<endl;
    cout<<e1.Povrsina()<<endl;
    cout<<e2.Povrsina()<<endl;
    cout<<e3.Povrsina()<<endl;

    Kvadrat k1;
    Kvadrat k2(4.00);
    Kvadrat k3(k1);

    cout<<"Obimi kvadrata"<<endl;
    cout<<k1.Obim()<<endl;
    cout<<k2.Obim()<<endl;
    cout<<k3.Obim()<<endl;

    cout<<"Povrsina kvadrata"<<endl;
    cout<<k1.Povrsina()<<endl;
    cout<<k2.Povrsina()<<endl;
    cout<<k3.Povrsina()<<endl;

    Krug kr1;
    Krug kr2(1.00);
    Krug kr3(kr1);

    cout<<"Obimi krugova"<<endl;
    cout<<kr1.Obim()<<endl;
    cout<<kr2.Obim()<<endl;
    cout<<kr3.Obim()<<endl;

    cout<<"Povrsine krugova"<<endl;
    cout<<kr1.Povrsina()<<endl;
    cout<<kr2.Povrsina()<<endl;
    cout<<kr3.Povrsina()<<endl;


    Oblik o1;
    Oblik o2(5.00,2.00);
    Oblik o3(o1);

    cout<<"Obimi oblika"<<endl;
    cout<<o1.Obim()<<endl;
    cout<<o2.Obim()<<endl;
    cout<<o3.Obim()<<endl;

    cout<<"Povrsine oblika"<<endl;
    cout<<o1.Povrsina()<<endl;
    cout<<o2.Povrsina()<<endl;
    cout<<o3.Povrsina()<<endl;






    return 0;
}


