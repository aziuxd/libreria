#ifndef DATA_H
#define DATA_H

#include <iostream>
#include <string>

class Data
{
public:
  // costruttore di datat che gestisce anche il cao sin cui l'utente non inserisca dati per la data
  Data(int giorno = default_giorno, int mese = default_mese, int anno = default_anno);

  Data &operator=(Data a);

  // in caso di errori
  class data_non_valida
  {
  };
  // get
  int giorno(void) const { return giorno_; }
  int mese(void) const { return mese_; }
  int anno(void) const { return anno_; }

private:
  /*variabili di esempare della classe Data*/
  int giorno_;
  int mese_;
  int anno_;
  // costanti usate per inizializzare la data di default
  static const int default_giorno = 1;
  static const int default_mese = 1;
  static const int default_anno = 2001;
};
// overload degli operatori == e <<;
bool operator==(Data a, Data b);
bool is_data(int giorno, int mese, int anno); // vero se la data è nel formato  coretto

bool annobisestile(int m); // verifica se anno è bisestile

std::ostream &operator<<(std::ostream &os, Data d1);
std::string to_string(Data a); // restituisce la data in formato stringa

#endif // DATA_H
