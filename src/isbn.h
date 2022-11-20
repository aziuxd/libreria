#ifndef ISBN_H
#define ISBN_H

#include <string>
#include <ostream>

class Isbn
{
public:
    // costruttori
    Isbn();
    Isbn(std::string isbn_);
    // overload assignament
    Isbn &operator=(Isbn a);
    // get
    std::string get(void) const { return code_; }
    // set
    void set_isbn(std::string code);
    // eccezioni
    class NotIsbnException
    {
    };

private:
    // variabili
    std::string code_;
    // costanti di default
    std::string default_isbn = "N/A";
};

// overload ==
bool operator==(Isbn code1, Isbn code2);
// overload dell'output
std::ostream &operator<<(std::ostream &os, Isbn a);
// is_isbn
bool is_isbn(const std::string &code_);

#endif // ISBN_H
