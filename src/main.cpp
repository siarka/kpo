#include <iostream>
#include<stdio.h>
#include "BazaTestu.hh"

using namespace std;



int main(int argc, char **argv)
{


  if (argc < 2) {
    cout << endl;
    cout << " Brak opcji okreslajacej rodzaj testu." << endl;
    cout << " Dopuszczalne nazwy to:  latwy, trudny." << endl;
    cout << endl;
    return 1;
  }


  BazaTestu   BazaT = { nullptr, 0, 0 };

  if (InicjalizujTest(&BazaT,argv[1]) == false) {
    cerr << " Inicjalizacja testu nie powiodla sie." << endl;
    return 1;
  }


  
  cout << endl;
  cout << " Start testu arytmetyki zespolonej: " << argv[1] << endl;
  cout << endl;

  


  WyrazenieZesp   WyrZ_PytanieTestowe;
  LZespolona odpop, odpu;
  int pkt=0,zlepkt=0;

  while (PobierzNastpnePytanie(&BazaT,&WyrZ_PytanieTestowe)) {
    cout << "podaj wynik rownania"<<endl;
    Wyswietl(WyrZ_PytanieTestowe);
    cin>>odpu;
    odpop=Oblicz(WyrZ_PytanieTestowe);

    if(cin.fail()){

      zlepkt++;
      cout<<"Zle poprawna odpowied to "<<odpop<<endl;
    
    }else{

      if(odpop.im == odpu.im && odpu.re == odpop.re)
      { 
        cout<<"dobrze"<<endl;
        pkt++;
             
      }else{
    
       cout<<"Zle poprawna odpowied to "<<odpop<<endl;
        zlepkt++;

      }
    }
    cout<<endl;
  }

  
  cout << endl;
  cout << " Koniec testu" << endl;
  cout << "twoje poprawne odpowiedzi : "<<noshowpos<<pkt<<endl;
  cout << "twoje nie poprawne odpowiedzi : "<<noshowpos<<zlepkt<<endl;
  cout << endl;

}
