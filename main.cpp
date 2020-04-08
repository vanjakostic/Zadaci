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

    Pravougaonik(){a=6.00; b=2.00; }
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

    Elipsa(){a=1.00; b=3.00; }
    Elipsa(double xx, double yy){a=xx; b=yy; }
    Elipsa(const Elipsa &e){a=e.a; b=e.b; }

    double getX() {return a;}
    double getY() {return b;}

    void setX(double xx) {a=xx;}
    void setY(double yy) {b=yy;}

    double Povrsina(){return a*b*M_PI; }
    double Obim(){return M_PI*(3*(a+b)-sqrt((3.00*a+b)*(a+3.00*b))); }

};
 class Oblik{
 private:
    Pravougaonik A;
    Elipsa B;

 public:
    Oblik(): A(),B(){}
    Oblik(double c,double d, double x, double y): A(c,d),B(x,y){}
    Oblik(const Oblik &o): A(o.A), B(o.B){}

    double Obim(){return A.Obim()+B.Povrsina(); }
    double Povrsina(){return A.Povrsina()-B.Povrsina();}

 };

 class PravilanOblik : public Oblik{

 public:
     PravilanOblik():Oblik(2.00,2.00,1.00,1.00){}
     PravilanOblik(double z, double r):Oblik(z,z,r,r){}
     PravilanOblik(const PravilanOblik &c):Oblik((Oblik)c){}

 };

int main()
{
    Pravougaonik p1;
    Pravougaonik p2(4.00,2.00);
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
    Elipsa e2(2.00,1.00);
    Elipsa e3(e1);

    cout<<"Obimi elipsi"<<endl;
    cout<<e1.Obim()<<endl;
    cout<<e2.Obim()<<endl;
    cout<<e3.Obim()<<endl;

    cout<<"Povrsina elipsi"<<endl;
    cout<<e1.Povrsina()<<endl;
    cout<<e2.Povrsina()<<endl;
    cout<<e3.Povrsina()<<endl;

    Oblik o1;
    Oblik o2(4.00,2.00,2.00,1.00);
    Oblik o3(o1);

    cout<<"Obimi oblika"<<endl;
    cout<<o1.Obim()<<endl;
    cout<<o2.Obim()<<endl;
    cout<<o3.Obim()<<endl;

    cout<<"Povrsine oblika"<<endl;
    cout<<o1.Povrsina()<<endl;
    cout<<o2.Povrsina()<<endl;
    cout<<o3.Povrsina()<<endl;

    PravilanOblik po1;
    PravilanOblik po2(8.00,4.00);
    PravilanOblik po3(po1);

    cout<<"Obimi pravih oblika"<<endl;
    cout<<po1.Obim()<<endl;
    cout<<po2.Obim()<<endl;
    cout<<po3.Obim()<<endl;

    cout<<"Povrsine pravih oblika"<<endl;
    cout<<po1.Povrsina()<<endl;
    cout<<po2.Povrsina()<<endl;
    cout<<po3.Povrsina()<<endl;




    cout << "Hello world!" << endl;
    return 0;
}
