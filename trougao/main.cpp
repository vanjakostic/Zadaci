#include <iostream>

using namespace std;

#include "JKSTrougao.hpp"

int main()
{
    Trougao t(5,6,7);
    JKTrougao k(3,4);
    JKSTrougao s(2);

    cout << t.getP()<< endl;
    cout << k.getP()<< endl;
    cout << s.getP()<< endl;

    cout << t.getO()<< endl;
    cout << k.getO()<< endl;
    cout << s.getO()<< endl;
    return 0;
}
