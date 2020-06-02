#include <string>
#include <vector>

// deklaracja zapowiadajaca
class Address;

class Rent;

class Client
{
    private:

        std::string firstName;
        std::string lastName;
        std::string personalID;
        Address *Address_ptr;
        std::vector<Rent *> currentRents;

    public:

    Client(const std::string &firstName, const std::string &lastName, const std::string &personalId,
           Address *addressPtr);

    Client(const std::string &firstName, const std::string &lastName, const std::string &personalId);

     virtual ~Client();

    std::string getClientInfo() const;
    std::string getFullClientInfo() const;
    const std::string &getFirstName() const;
    const std::string &getLastName() const;
    Address *getAddressPtr() const;
    const std::string &getPersonalId() const;
    unsigned int getCurrentRentsNumber() const;
    Rent *getCurrentRentPtr(unsigned int number) const;

    bool setFirstName(const std::string &firstName);
    bool setLastName(const std::string &lastName);
    bool setAddressPtr(Address *addressPtr);
    bool setCurrentRents(Rent* RentPtr);
    bool eraseCurrentRentPtr(unsigned int i);

};