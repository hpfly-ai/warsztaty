#include <string>

class Address{
    std::string city;
    std::string street;
    std::string number;


public:
    Address(std::string miasto, std::string ulica, std::string numer);

    std::string getAddressInfo() const;
    std::string get_city() const;

    const std::string &getCity() const;
    const std::string &getStreet() const;
    const std::string &getNumber() const;

    bool setCity(const std::string &city);
    bool setStreet(const std::string &street);
    bool setNumber(const std::string &number);

};