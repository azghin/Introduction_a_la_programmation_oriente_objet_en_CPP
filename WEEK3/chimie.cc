#include <iostream>
#include <string>
#include <cmath>
using namespace std;

class Flacon
{
private:
  string nom;
  double volume;
  double pH;

public:
  /*****************************************************
    Compléter le code à partir d'ici
  *******************************************************/
 string getNom()const{return nom;};
 double getVolume()const{return volume;};
 double getPh()const{return pH;};

 Flacon (string Nom,double Volume,double PH) : nom(Nom) , volume(Volume) , pH(PH) {};

 ostream& etiquette(ostream& sortie)const {
  sortie << nom <<" : "<<volume<<" ml, pH "<<pH;
  return sortie;
 }
};
  ostream& operator<<(ostream& sortie,Flacon const& fl){
    return fl.etiquette(sortie);
  };
  const Flacon operator+(Flacon const& a,Flacon const& b){
    string n= a.getNom()+" + "+b.getNom();
    double v=a.getVolume()+b.getVolume();
    double p=-log10((a.getVolume()*pow(10,-a.getPh()) + b.getVolume()*pow(10,-b.getPh()))/(a.getVolume()+b.getVolume()));
    Flacon flac(n,v,p);
    return flac;
  }
/*******************************************
 * Ne rien modifier après cette ligne.
 *******************************************/

void afficher_melange(Flacon const& f1, Flacon const& f2)
{
  cout << "Si je mélange " << endl;
  cout << "\t\"" << f1 << "\"" << endl;
  cout << "avec" << endl;
  cout << "\t\"" << f2 << "\"" << endl;
  cout << "j'obtiens :" << endl;
  cout << "\t\"" << (f1 + f2) << "\"" << endl;
}

int main()
{
  Flacon flacon1("Eau", 600.0, 7.0);
  Flacon flacon2("Acide chlorhydrique", 500.0, 2.0);
  Flacon flacon3("Acide perchlorique",  800.0, 1.5);

  afficher_melange(flacon1, flacon2);
  afficher_melange(flacon2, flacon3);

  return 0;

}
