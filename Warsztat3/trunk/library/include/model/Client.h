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

    const std::string &getPersonalId() const;

    const Address* get_address() const;

    Address *getAddressptr() const;

    const std::string &getLastName() const;

    const std::string &getFirstName() const;

    bool setLastName(const std::string &lastName);

    bool setPersonalId(const std::string &personalId);

    bool setAddressptr(Address *addressptr);

    bool setFirstName(const std::string &firstName);

};