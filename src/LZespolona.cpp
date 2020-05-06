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
  char n;
for( int i = 0; i < 4; i++){

if(i!=0)
{
  StrmWe.clear();
cerr<<"nie poprawna skladnia "<<endl;
}

   //StrmWe >> n;
StrmWe.ignore( );
 StrmWe >> Lz.re; 
 StrmWe >> Lz.im;
StrmWe.ignore( );
 StrmWe >> n;

}



  
 
 return StrmWe;
}