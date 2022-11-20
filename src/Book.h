#ifndef BOOK_H
#define BOOK_H
#include "isbn.h"
#include "Data.h"
#include <ostream>
#include <string>
class Book
{
public:
	/*costruttore di book che accetta isbn come oggetto di tipo Isbn e gestisce il fatto che non
	vengano inseriti parametri nel costruttore, assegnando dei valori di default predefiniti*/
	Book();
	Book(std::string nome, std::string cognome, std::string titolo, std::string isbn);
	/*costruttore di book che accetta isbn come stringa e gestisce il fatto che non vengano
	inseriti parametri nel costruttore, assegnando dei valori di default predefiniti*/
	Book(std::string nome, std::string cognome, std::string titolo, std::string isbn, int g, int m, int y, bool stato);
	/*metodo set set*/
	void set_stato(std::string stato);
	// metodi get
	Isbn get_isbn(void) const { return isbn_; }
	std::string get_stato(void) const
	{
		if (!stato_)
			return "prenotato";
		else
			return "disponibile";
	}
	std::string get_titolo(void) const { return titolo_; }
	std::string get_nome(void) const { return nome_; }
	std::string get_cognome(void) const { return cognome_; }
	Data get_data(void) const { return data_; }

	// eccezione che viene la nciata se isbn e data sono in un formato scorretto
	class data_o_ISBN_invalidi
	{
	};

private:
	// variabili private della classe Book
	Isbn isbn_;
	std::string titolo_;
	std::string nome_;
	std::string cognome_;
	Data data_;
	bool stato_;
	// variabili usate cpe l'inizializzazione di default
	std::string default_titolo = "N/A";
	std::string default_nome = "N/A";
	std::string default_cognome = "N/A";
	bool default_stato = false;
};
// metodi di overload degli operatori <<, == ,!=
bool operator==(const Book &b1, const Book &b2);
bool operator!=(const Book &b1, const Book &b2);
std::ostream &operator<<(std::ostream &os, Book b1);
#endif // BOOK_H