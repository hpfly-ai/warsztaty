#include <string>
#include <vector>
#include "model/Address.h"


class Client{   //Class
//  Default private
    std::string firstName;
    std::string lastName;
    std::string personalID;
    Address* addressptr = new Address("","","");
public:
    //Client();
    Client(std::string imie, std::string nazwisko, std::string PESSEL, Address* address_ptr);
    Client(std::string imie, std::string nazwisko, std::string PESSEL);
    //Konstruktor ma overload
    virtual ~Client();
    std::string getClientInfo() const;
    std::string get_firstName() const;
    std::string get_lastName() const;
    std::string get_personalID() const;
    bool set_firstName(std::string imie);
    bool set_lastName(std::string nazwisko);
    bool set_address(Address* address_ptr);
};