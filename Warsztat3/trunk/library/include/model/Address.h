#include <string>

class Address{
    std::string city;
    std::string street;
    std::string number;


public:
    Address(std::string miasto, std::string ulica, std::string numer);

    std::string getAddressInfo() const;
    std::string get_city() const;
    std::string get_street() const;
    std::string get_number() const;
    bool set_street(std::string ulica);
    bool set_city(std::string miasto);
    bool set_number(std::string numer);
};