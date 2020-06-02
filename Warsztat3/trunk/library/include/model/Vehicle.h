#include <string>


class Vehicle {
private:

    std::string plateNumber;
    unsigned int basePrice;
    bool isRented = false;

public:

    Vehicle(const std::string &numer, const unsigned int &cena);
    ~Vehicle();

    std::string getVehicleinfo() const;
    const std::string &getplateNumber() const;
    const unsigned int &getbasePrice() const;
    bool isRented1() const;

    bool setplateNumber(const std::string &numer);
    bool setbasePrice(const unsigned int &cena);
    bool setIsRented(bool Rented);
};
