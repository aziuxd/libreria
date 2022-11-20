#include "isbn.h"
#include <iostream>
// costruttore di default
Isbn::Isbn()
{
    code_ = default_isbn;
}
// costruttore che crea un isbn data una stringa e controlla se è corretto
Isbn::Isbn(std::string isbn_)
{
    code_ = isbn_;
    if (!is_isbn(code_))
        throw NotIsbnException();
}
// overload dell'operatore =
Isbn &Isbn::operator=(Isbn a)
{
    code_ = a.code_;

    return *this;
}
// overload dell'operatore ==
bool operator==(Isbn code1, Isbn code2)
{
    return code1.get() == code2.get();
}
// overload dell'operatore <<
std::ostream &operator<<(std::ostream &os, Isbn a)
{
    return os << a.get();
}
// funzione che controlla se l'isbn è corretto tramite la scansione carattere per carattere della stringa inserita
bool is_isbn(const std::string &code_)
{ // bool tmp1,tmp2,tmp3;
    if (code_.length() != 13)
        return false;

    for (int i = 0; i < code_.length(); i++)
    {
        if ((isdigit(code_[i])) && (i < 11))
        {
        }
        else if (((code_[i]) == '-') && ((i == 3) || (i == 7) || (i == 11)))
        {
        }
        else if (isalnum(code_[i]) && (i == 12))
        {
        }
        else
            return false;
    };
    return true;
};
