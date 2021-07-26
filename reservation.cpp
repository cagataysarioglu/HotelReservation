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
  void SunumOdasiSorgu();
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
  
  int sayi;
  
  do{
    cout<<"\n\t\t--- Altıntepe Oteli ---"<<endl;
    cout<<"\t\t1. Oda Rezervasyonu"<<endl;
    cout<<"\t\t2. Oda Boşaltma"<<endl;
    cout<<"\t\t3. Dolu Oda Sayısı"<<endl;
    cout<<"\t\t4. Yatak Odası Sorgula"<<endl;
    cout<<"\t\t5. Sunum Odası Sorgula"<<endl;
    cout<<"\t\t6. Günlük Toplam Gelir"<<endl;
    cout<<"\t\t7. Çıkış Yap"<<endl;
    cout<<"Seçiminizin sayısını giriniz: ";
    cin>>sayi;
    
    switch(sayi){
      case 1: OdaRezervasyonu();
        break;
      case 2: OdaBosaltma();
        break;
      case 3: MusteriSayisi();
        break;
      case 4: YatakOdasiSorgu();
        break;
      case 5: SunumOdasiSorgu();
        break;
      case 6: Gelir();
        break;
      case 7: exit(1);
      default: cout<<"\nYanlış bir sayı girildi. Yeniden deneyiniz: "<<endl;
    }
  } while(sayi!=7);
}

void Otel::OdaRezervasyonu()
{
  int sayi, x2, i=1, j=6, k=16;
  string ad, soyad;
  
  cout<<"\n\t\t- Oda Türü Seçiniz -"<<endl;
  cout<<"\t\t1. Tek Kişilik Oda (50₺)"<<endl;
  cout<<"\t\t2. Çift Kişilik Oda (70₺)"<<endl;
  cout<<"\t\t3. Sunum Odası (300₺)"<<endl;
  cin>>sayi;
  
  switch(sayi){
    case 1:
      for(;j<16;j++)
      {
        if(Odalar[j]!=Bos)
        {
          Odalar[j]=Dolu;
          cout<<"Adınız: ";
          cin>>ad;
          cout<<"Soyadınız: ";
          cin>>soyad;
          cout<<"Kalacağınız gün sayısı: ";
          cin>>x2;
          Toplam += x2*50;
          SayacIki++;
          MusteriAdi[j] = new string;
          *MusteriAdi[j] = ad;
          MusteriSoyadi[j] = new string;
          *MusteriSoyadi[j] = soyad;
          break;
        }
      }
      if(j==16)
        cout<<"Ne yazık ki bütün tek kişilik odalar dolu."<<endl;
      break;
    case 2:
      for(;k<46;k++)
      {
        if(Odalar[k]!=Dolu)
        {
          Odalar[k]=Dolu;
          cout<<"Adınız: ";
          cin>>ad;
          cout<<"Soyadınız: ";
          cin>>soyad;
          cout<<"Kalacağınız gün sayısı: ";
          cin>>x2;
          Toplam += x2*70;
          SayacIki++;
          MusteriAdi[j] = new string;
          *MusteriAdi[j] = ad;
          MusteriSoyadi[j] = new string;
          *MusteriSoyadi[j] = soyad;
          break;
        }
      }
      if(k==46)
        cout<<"Ne yazık ki bütün odalar dolu."<<endl;
      break;
    case 3:
      for(;i<6;i++)
      {
        if(Odalar[i]!=Dolu)
        {
          Odalar[i]=Dolu;
          cout<<"Adınız: ";
          cin>>ad;
          cout<<"Soyadınız: ";
          cin>>soyad;
          cout<<"Kalacağınız gün sayısı: ";
          cin>>x2;
          Toplam += x2*300;
          SayacBir++;
          MusteriAdi[j] = new string;
          *MusteriAdi[j] = ad;
          MusteriSoyadi[j] = new string;
          *MusteriSoyadi[j] = soyad;
          break;
        }
      }
      if(i==6)
        cout<<"Ne yazık ki bütün sunum odalar dolu."<<endl;
      break;
    default: cout<<"Lütfen doğru düğmeye basınız."<<endl;
  }
}
