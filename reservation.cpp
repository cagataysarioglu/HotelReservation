#include "stdafx.h"
#include "iostream"
#include <cstring>
#include <string>

using namespace std;

class Otel
{
  string *MusteriAdi[100], *MusteriSoyadi[100];
  int Toplam, SayacBir, SayacIki;
  
  enum Durum{
    Bos, Dolu
  }Odalar[45];
  
  public:
  Otel();
  void OdaIsletmesi();
  void OdaRezervasyonu();
  void OdaBosaltma();
  void MusteriSayisi();
  void YatakOdasiSorgu();
  void SeminerOdasiSorgu();
  void Gelir();
};

Otel::Otel()
{
  SayacBir = 0;
  SayacIki = 0;
  Toplam = 0;
  
  OdaIsletmesi();
}

void Otel::OdaIsletmesi()
{
  for (int i=1; i<46; i++)
    Odalar[i] = Bos;
  
  int Sayi;
  
  do{
    cout<<"\n\t\t--- Altıntepe Oteli ---"<<endl;
    cout<<"\t\t1. Oda Rezervasyonu"<<endl;
    cout<<"\t\t2. Oda Boşaltma"<<endl;
    cout<<"\t\t3. Dolu Oda Sayısı"<<endl;
    cout<<"\t\t4. Yatak Odası Sorgula"<<endl;
    cout<<"\t\t5. Seminer Odası Sorgula"<<endl;
    cout<<"\t\t6. Günlük Toplam Gelir"<<endl;
    cout<<"\t\t7. Çıkış Yap"<<endl;
    cout<<"Seçiminizin sayısını giriniz: ";
    cin>>Sayi;
    
    switch(Sayi){
      case 1: OdaRezervasyonu();
        break;
      case 2: OdaBosaltma();
        break;
      case 3: MusteriSayisi();
        break;
      case 4: YatakOdasiSorgu();
        break;
      case 5: SeminerOdasiSorgu();
        break;
      case 6: Gelir();
        break;
      case 7: exit(1);
      default: cout<<"\nYanlış bir sayı girildi. Yeniden deneyiniz: "<<endl;
    }
  } while(Sayi!=7);
}
