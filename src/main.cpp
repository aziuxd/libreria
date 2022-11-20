#include <iostream>
#include <vector>
#include "Book.h"

int main(void)
{
     int size = 0;
     std::vector<Book> shelf(10);
     char c;
     std::cout << "Software di getione libri della biblioteca" << std::endl
               << "Che operazione desideri effettuare nella tua libreria?" << std::endl
               << "Premi q per uscire iscire dal programma" << std::endl
               << "Premi a per aggiungere un libo alla libreria" << std::endl
               << "Premi c per cercare un libro nella libreria e verificare se è disponibile o meno" << std::endl
               << "Premi m per modificare lo stato di un libro" << std::endl;
     /*funzione che permette di inserire e modificare i libri all'interno di un vettore shelf.*/
     while (std::cin >> c && c != 'q')
     {

          if (c == 'a')
          {
               if (size > 9)
               {
                    std::cout << "Ops libreria piena!";
               }
               else
               {
                    // grazie Ncola
                    std::string token;
                    std::getline(std::cin, token);
                    std::string nome, cognome, titolo, isbn;
                    int giorno, mese, anno;
                    std::string stato;
                    std::cout << "Inserire i dati del libro:" << std::endl
                              << "Nome Autore: ";
                    std::cin >> nome;
                    std::cout << std::endl
                              << "Cognome autore:";
                    std::getline(std::cin, cognome);
                    std::cout << std::endl
                              << "Titolo:";
                    std::getline(std::cin, titolo);
                    std::cout << std::endl
                              << "ISBN:";
                    std::getline(std::cin, isbn);
                    std::cout << std::endl
                              << "giorno di pubblicazione:";
                    std::cin >> giorno;
                    std::cout << std::endl
                              << "mese di pubblicazione:";
                    std::cin >> mese;
                    std::cout << std::endl
                              << "anno di pubblicazione:";
                    std::cin >> anno;
                    std::cout << std::endl
                              << "statto del ibro(disponibile/prenotato):";
                    std::cin >> stato;

                    Book libro(nome, cognome, titolo, isbn, giorno, mese, anno, false);

                    libro.set_stato(stato);
                    shelf.push_back(libro);
                    size++;
                    for (int i = 0; i <= 9; ++i)
                    {
                         std::cout << shelf[i] << std::endl;
                    }
               }
          }
          else if (c == 'c')
          {
               std::string isbn;
               std::cout << "Inseire isbn del libro cecato" << std::endl;
               std::getline(std::cin, isbn);
               int h;
               Isbn is(isbn);
               for (int i = 0; i < shelf.size(); ++i)
               {
                    if (shelf[i].get_isbn() == is)
                    {
                         std::cout << "lo stato del libro è: " << shelf[i].get_stato() << std::endl;
                         h += 1;
                    }
               }
               if (h == 0)
               {
                    std::cout << "Ops! libro non trovato!" << std::endl;
               }
          }
          else if (c == 'm')
          {
               std::string stato;
               std::string isbn;
               int g = 0;
               std::cout << "Inseire isbn del libro da  modificare" << std::endl;
               std::getline(std::cin, isbn);
               Isbn is(isbn);
               for (int i = 0; i < shelf.size(); ++i)
               {
                    if (shelf[i].get_isbn() == is)
                    {
                         std::cout << "inserire il nuovo stato del libro: " << std::endl;
                         std::getline(std::cin, stato);
                         shelf[i].set_stato(stato);
                         std::cout << "libro aagiornato!";
                         std::cout << shelf[i];
                         g += 1;
                    }
               }
               if (g == 0)
               {
                    std::cout << "Ops! libro non trovato!" << std::endl;
               }
          }
          else
          {
               std::cout << "comando non accettao! inserire 'q' , 'a' , 'c' o 'm' !" << std::endl;
          }
          std::cout << "Che operazione desideri effettuare nella tua libreria?" << std::endl
                    << "Premi q per uscire iscire dal programma" << std::endl
                    << "Premi a per aggiungere un libo alla libreria" << std::endl
                    << "Premi c per cercare un libro nella libreria e verificare se è disponibile o meno" << std::endl
                    << "Premi m per modificare lo stato di un libro" << std::endl;
     }
     /*test vari e gesione delle eccezioni*/
     Book libro_vuoto;
     Book libro_prova1;
     Book libro_prova2;
     std::cout << "test libro vuoto: " << std::endl
               << libro_vuoto << std::endl;
     try
     {
          libro_prova1("Riccardo", "Granozio", "Poesie, l'amore nelle parole", "123-456-789-a", 25, 8, 1993, false);
          libro_prova2("Riccardo", "Granozio", "Poesie, l'amore nelle parole", "123-456-789-a", 26, 8, 1993, true);
     }
     catch (Isbn::NotIsbnException)
     {
          std::cout << "Ops! isbn incorretto! Utilizzare il formato ###-###-###-#!" << std::endl;
     }
     catch (Data::data_non_valida)
     {
          std::cout << "Ops! data nonn corretta1! utilizzare il formato giorno / mese / anno!" << std::endl;
     }
     std::cout << "Libro prova 1" << std::endl
               << libro_prova1 << std::endl
               << "Libro prova 1" << std::endl
               << libro_prova2 << std::endl;
     libro_prova1.set_stato("disponibile");
     std::cout << "verifica uguaglianza dei libri" << std::endl;
     if (libro_prova1 == libro_prova2)
     {
          std::cout << "I libri sono uguali" << std::endl;
     }
     if (libro_prova1 != libro_prova2)
     {
          std::cout << "I libri sono diversi" << std::endl;
     }
     std::vector<Book> pollo(10);
     Book my_favourite_book;
     try
     {
          Book my_favourite_book("David", "Foster", "Una cosa divertente che non farò mai più", "887-521-837-4");
     }
     catch (Isbn::NotIsbnException)
     {
          std::cout << "Ops! isbn incorretto! Utilizzare il formato ###-###-###-#!" << std::endl;
     }
     catch (Data::data_non_valida)
     {
          std::cout << "Ops! data nonn corretta1! utilizzare il formato giorno / mese / anno!" << std::endl;
     }

     std::cout << "test libro senza date e stato" << std::endl
               << my_favourite_book << std::endl;
}