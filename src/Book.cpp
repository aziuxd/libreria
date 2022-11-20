#include "Book.h"
#include "isbn.h"
#include "Data.h"
#include <string>

/* costruttore di book vuoto che inizializza le variabili di esemplare a un valore di default,
isbn e data sono gestiti dalle rispettive classe*/

Book::Book()
{
  nome_ = default_nome;
  cognome_ = default_cognome;
  titolo_ = default_titolo;
  stato_ = default_stato;
}
// costruttore di book che accetta isbn come stringa e poi lo trasforma in oggetto per poterlo usare
Book::Book(std::string nome, std::string cognome, std::string titolo, std::string isbn)
{
  nome_ = nome;
  cognome_ = cognome;
  titolo_ = titolo;
  isbn_ = {isbn};
}
/*costruttore che accetta tutti i parametri richiesti e iniziallizza le variabili di stato*/
Book::Book(std::string nome, std::string cognome, std::string titolo, std::string isbn, int g, int m, int y, bool stato)
{
  nome_ = nome;
  cognome_ = cognome;
  titolo_ = titolo;
  isbn_ = {isbn};
  data_ = {g, m, y};
  stato_ = stato;
}
/*funzione che setta lo stato disponibile/penitato del libro tramite una stringa passata nella funzione chiamante*/
void Book::set_stato(std::string stato)
{
  if (stato == "prenotato")
    stato_ = false;
  else
    stato_ = true;
}

/*overload degli operatori == e != che ritornano  vero se l'isbn dei due libri corrisponde
e falso nell'altro caso */
bool operator==(const Book &b1, const Book &b2)
{
  if ((b1.get_isbn() == b2.get_isbn()) && (b1.get_data() == b2.get_data()))
    return true;
  else
    return false;
}
bool operator!=(const Book &b1, const Book &b2)
{
  return !(b1 == b2);
}
/*overload dell'operatore<< che restituisce le caratteristiche del libri, distribuite una oer riga*/
std::ostream &operator<<(std::ostream &os, Book b1)
{
  return os << "Titolo: " << b1.get_titolo() << std::endl
            << "Nome Autore: " << b1.get_nome() << std::endl
            << "Cognome Autore: " << b1.get_cognome() << std::endl
            << "Isbn: " << b1.get_isbn() << std::endl
            << "Data Copyright: " << b1.get_data() << std::endl;
}
