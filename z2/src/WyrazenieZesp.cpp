#include "WyrazenieZesp.hh"
#include <iostream>

using namespace std;

ostream & operator << ( ostream & StrmWy, const LZespolona & Lz )
{
return StrmWy <<"("<< Lz.re << showpos << Lz.im << noshowpos << "i)"; }

/*!
 * Wyswietla wyrazenie zespolone na wyjsciu
 * Argument:
 * WyrZ - wyrazenie zespolone 
 * Nie zwraca nic
 */
void Wyswietl(WyrazenieZesp  WyrZ){
    //cout<<"( "<<noshowpos<<WyrZ.Arg1.re<<showpos<<WyrZ.Arg1.im<<"i ) "<<"+-*/"[WyrZ.Op]<<" ( "<<noshowpos<<WyrZ.Arg2.re<<showpos<<WyrZ.Arg2.im<<"i )"<<endl;
    cout<<WyrZ.Arg1<<" "<<"+-*/"[WyrZ.Op]<<" "<<WyrZ.Arg2<<" ="<<endl;
}
/*!
 * Wyswietla liczbe zespolona na wyjsciu
 * Argument:
 * l - liczba zespolona
 * nie zwraca nic
 */
void Wyswietll(LZespolona  l){
    cout<<"( "<<noshowpos<<l.re<<showpos<<l.im<<"i ) "<<endl;
}
/*!
 * Oblica wyraenia zespolone 
 * Argument:
 * WyrZ - wyrazenie zespolone
 * Zwraca:
 * liczbe zespolona bendaca wynikiem wyrazenia
 */

LZespolona Oblicz(WyrazenieZesp  WyrZ){

LZespolona wynik;
if(WyrZ.Op == 0)
    wynik=WyrZ.Arg1 + WyrZ.Arg2;
if(WyrZ.Op == 1)
    wynik=WyrZ.Arg1 - WyrZ.Arg2;
if(WyrZ.Op == 2)
    wynik=WyrZ.Arg1 * WyrZ.Arg2;
if(WyrZ.Op == 3)
    wynik=WyrZ.Arg1 / WyrZ.Arg2;
return wynik;
}
