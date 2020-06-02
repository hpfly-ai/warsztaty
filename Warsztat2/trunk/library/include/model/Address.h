#include <string>

using namespace std;

class Address{
    string city;
    string street;
    string number;

public:
    Address(string miasto, string ulica, string numer);

    string getAdressInfo() const;
    string get_city() const;
    string get_street() const;
    string get_number() const;
    bool set_street(string ulica);
    bool set_city(string miasto);
    bool set_number(string numer);
};