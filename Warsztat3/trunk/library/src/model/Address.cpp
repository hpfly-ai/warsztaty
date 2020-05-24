#include "model/Address.h"
#include <string>
#include <iostream>
#include <sstream>

using namespace std;


Address::Address(string miasto, string ulica, string numer) : city(miasto), street(ulica), number(numer){
    getAddressInfo();
}


string Address::getAddressInfo() const {
    ostringstream out;
    out << "Address information: "  << endl << "City: " << getCity()  << endl;
    out << "Ulica: " << getStreet() << " " << getNumber() << endl << endl;
    return out.str();
}


const string &Address::getCity() const {
    return city;
}

const string &Address::getStreet() const {
    return street;
}

const string &Address::getNumber() const {
    return number;
}

bool Address::setStreet(const string &street) {
    if(street == ""){
        cout << "Niemozliwa zmiana ulicy" << endl << endl;
    }
    else{
        cout << "Zmiana ulicy z : " << Address::street << " na " << street << " ..."  << endl;
        Address::street = street;
        cout << "Ulica zostala zmieniona" << endl << endl;
        return true;
    }
}

bool Address::setNumber(const string &number) {
    if(number == ""){
        cout << "Niemozliwa zmiana numera" << endl << endl;
    }
    else{
        cout << "Zmiana numera z : " << Address::number << " na " << number << " ..."  << endl;
        Address::number = number;
        cout << "Numer zostal zmieniony" << endl << endl;
        return true;
    }
}

bool Address::setCity(const string &city) {
    if (city == ""){
        cout << "Niemozliwa zmiana miasta" << endl;
    }
    else{
        cout << "Zmiana mista z : " << Address::city << " na " << city << " ..." << endl << endl;
        Address::city = city;
        cout << "Miasto zostalo zmienione" << endl << endl;
        return true;
    }
}



