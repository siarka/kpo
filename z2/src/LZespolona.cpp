#include "LZespolona.hh"
#include <iostream>
using namespace std;

  



/*!
 * Realizuje dodanie dwoch liczb zespolonych.
 * Argumenty:
 *    Skl1 - pierwszy skladnik dodawania,
 *    Skl2 - drugi skladnik dodawania.
 * Zwraca:
 *    Sume dwoch skladnikow przekazanych jako parametry.
 */
LZespolona  operator + (LZespolona  Skl1,  LZespolona  Skl2)
{
  LZespolona  Wynik;

  Wynik.re = Skl1.re + Skl2.re;
  Wynik.im = Skl1.im + Skl2.im;
  return Wynik;
}
/*!
 * Realizuje dodanie odejmowanie liczb zespolonych.
 * Argumenty:
 *    Skl1 - odjemna,
 *    Skl2 - odjemnik.
 * Zwraca:
 *    roznice dwoch skladnikow przekazanych jako parametry.
 */
LZespolona  operator - (LZespolona  Skl1,  LZespolona  Skl2)
{
  LZespolona Wynik;


  Wynik.re = Skl1.re - Skl2.re;
  Wynik.im = Skl1.im - Skl2.im;
  return Wynik;

}
/*!
 * Realizuje dodanie mnozenia liczb zespolonych.
 * Argumenty:
 *    Skl1 - pierwszy skladnik mnozenia,
 *    Skl2 - drugi skladnik mnoenia.
 * Zwraca:
 *    Iloraz dwoch skladnikow przekazanych jako parametry.
 */
LZespolona  operator * (LZespolona  Skl1,  LZespolona  Skl2)
{
  LZespolona  Wynik;

  Wynik.re = Skl1.re * Skl2.re - Skl1.im * Skl2.im;
  Wynik.im = Skl1.re * Skl2.im + Skl2.re * Skl1.im;
  return Wynik;
}
/*!
 * Realizuje dzielenie dwoch liczb zespolonych.
 * Argumenty:
 *    Skl1 - licznik,
 *    Skl2 - mianownik.
 *    -nie sprawdzam czy jest zerowy poniwaz sam go ustalam
 * Zwraca:
 *    iloraz  dwoch skladnikow przekazanych jako parametry.
 */
LZespolona  operator / (LZespolona  Skl1,  LZespolona  Skl2)
{
  LZespolona  Wynik;

  Wynik.re = (Skl1.re * Skl2.re - Skl1.im * Skl2.im) / (Skl2.re * Skl2.re + Skl2.im * Skl2.im);
  Wynik.im = (Skl1.im * Skl2.re - Skl1.re * Skl2.im) / (Skl2.re * Skl2.re + Skl2.im * Skl2.im);
  return Wynik;
}



istream& operator>>(istream& StrmWe, LZespolona& Lz){
  int l = 1;
  char niep;
  /*
  StrmWe.clear();
  cout<<"Twoja odpowiedz: ";

  StrmWe >> niep;
  if(niep != '('){StrmWe.setstate(ios::failbit);}
  StrmWe >> Lz.re >> Lz.im;
  StrmWe >> niep;
  if(niep != 'i'){StrmWe.setstate(ios::failbit);}
  StrmWe >> niep;
  if(niep != ')'){StrmWe.setstate(ios::failbit);}
  StrmWe.ignore();*/



  do{
  
    if(l == 3){
      return StrmWe;
    }

    StrmWe.clear();
    StrmWe.ignore(1000, '\n');

    

    StrmWe >> niep;
    if(niep != '('){StrmWe.setstate(ios::failbit);}
    StrmWe >> Lz.re >> Lz.im;
    StrmWe >> niep;
    if(niep != 'i'){StrmWe.setstate(ios::failbit);}
    StrmWe >> niep;
    if(niep != ')'){StrmWe.setstate(ios::failbit);}
    StrmWe.ignore();

    cout<<endl;
    if(l!=0){
      cerr<<"Blad formatu liczby zespolonej sprobuj ponownie"<<endl;
    }
    

    

  }while(StrmWe.fail() && l++ );
  return StrmWe;
}