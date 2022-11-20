#include "Data.h"
#include <iostream>
#include <string>
// costruttore di data che gestisce tutti i possibili casi
Data::Data(int giorno, int mese, int anno)
    : giorno_{giorno}, mese_{mese}, anno_{anno}

// funzione che controlla se data è coretta
{
  if (!(is_data(giorno, mese, anno)))
    throw data_non_valida();
}

// Assegnazione
Data &Data::operator=(Data a)
{
  giorno_ = a.giorno();
  mese_ = a.mese();
  anno_ = a.anno();
  return *this;
}
// controllo validità anno
// sistemare queste  costanti

bool is_data(int giorno, int mese, int anno)
{
  if ((anno >= 1800) && (anno <= 2250)) // se anno è giusto prosegue
  {
    if ((mese >= 1) && (mese <= 12)) // se mese è giusto prosegue
    {
      int giorni_nel_mese = 31;
      switch (mese)
      {
      case 2:
        giorni_nel_mese = (annobisestile(anno)) ? 29 : 28;
        break;
      case 4:
      case 6:
      case 9:
      case 11:
        giorni_nel_mese = 30;
        break;
      }
      if ((giorno > 0) && (giorno <= giorni_nel_mese)) // controllo giorno
        return true;
      else
        return false;
    }
    else
      return false; // mese non valido ritorna falso
  }
  else
    return false; // anno non valido ritorna falso
}

// Helper function

// anno è bisestile se è divisibile per 4  o 400
bool operator==(Data a, Data b)
{
  return a.giorno() == b.giorno() && a.mese() == b.mese() && a.anno() == b.anno();
}
bool annobisestile(int anno)
{
  if ((anno % 4) == 0)
    return true;
  else if (((anno % 100) == 0) && ((anno % 400) == 0))
    return true;
  else
    return false;
}
// funzione che ritorna la data in forma di stringa
std::string to_string(Data a)
{
  std::string string_data;
  std::string string_mese;
  std::string string_giorno;
  if (a.mese() < 10)
    string_mese = "0" + std::to_string(a.mese());
  else
    string_mese = std::to_string(a.mese());
  if (a.giorno() < 10)
    string_giorno = "0" + std::to_string(a.giorno());
  else
    string_giorno = std::to_string(a.giorno());
  return string_data = string_giorno + "/" + string_mese + "/" + std::to_string(a.anno());
}
std::ostream &operator<<(std::ostream &os, Data d1)
{
  return os << to_string(d1);
}
