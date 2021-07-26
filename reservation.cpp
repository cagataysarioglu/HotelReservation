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
  void YatakOdasiRaporu();
  void SeminerOdasiRaporu();
  void Gelir();
};
