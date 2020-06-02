#include "model/Vehicle.h"
#include <string>
#include <iostream>
#include <sstream>

using namespace std;

Vehicle::Vehicle(const string &numer, const unsigned int &cena): plateNumber(numer), basePrice(cena) {

}

Vehicle::~Vehicle() {

}

std::string Vehicle::getVehicleinfo() const {
    ostringstream out;
    out << "Vehicle information: "  << endl << "Plate number: " << getplateNumber()  << endl << "Base price: " << getbasePrice() << endl << endl;
    return out.str();;
}

const std::string &Vehicle::getplateNumber() const {
    return plateNumber;
}

const unsigned int &Vehicle::getbasePrice() const {
    return basePrice;
}

bool Vehicle::setplateNumber(const std::string &numer) {
    if(numer.empty()){
        cout << "Niemozliwa zmiana numeru" << endl;
        return false;
    }
    else {
        cout << "Zmiana numeru z : " << plateNumber << " na " << numer << " ..." << endl << endl;
        plateNumber = numer;
        cout << "Numer zostal zmieniony" << endl << endl;
        return true;
    }

}

bool Vehicle::setbasePrice(const unsigned int &cena) {
    if(cena == 0){
        cout << "Niemozliwa zmiana ceny" << endl;
        return false;

    }
    else {
        cout << "Zmiana ceny z : " << basePrice << " na " << cena << " ..." << endl << endl;
        basePrice = cena;
        cout << "Cena zostal zmieniony" << endl << endl;
        return true;
    };

}

bool Vehicle::isRented1() const {
    return isRented;
}

bool Vehicle::setIsRented(bool Rented) {
    Vehicle::isRented = Rented;
    return true;
}
