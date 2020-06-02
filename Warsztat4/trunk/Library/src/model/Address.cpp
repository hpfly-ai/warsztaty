#include <string>
#include "model/Address.h"
#include <iostream>
#include <sstream>

using namespace std;


Address::Address(const string &miasto, const string &ulica, const string &numer): city(miasto), street(ulica), number(numer) {

}

Address::~Address() {

}

string Address::getAddressInfo() const {
    ostringstream out;
    out << "Address information: "  << endl << "Miasto: " << getcity()  << endl << "Ulica: " << getstreet() << endl << "Numer domu: " << getnumber() << endl << endl;
    return out.str();
}

const string &Address::getcity() const {
    return city;
}

const string &Address::getstreet() const {
    return street;
}

const string &Address::getnumber() const {
    return number;
}

//int Address::setcity(const string &miasto) {
//    if (miasto.empty()){
//        cout << "Niemozliwa zmiana miasta" << endl;
//    }
//    else {
//        cout << "Zmiana miasta z : " << city << " na " << miasto << " ..." << endl << endl;
//        city = miasto;
//        cout << "Miasto zostalo zmienione" << endl << endl;
//    }
//    return 0;
//}
//
//int Address::setstreet(const string &ulica) {
//    if (ulica.empty()){
//        cout << "Niemozliwa zmiana ulicy" << endl;
//    }
//    else {
//        cout << "Zmiana ulicy z : " << street << " na " << ulica << " ..." << endl << endl;
//        street = ulica;
//        cout << "Ulica zostala zmieniona" << endl << endl;
//    }
//    return 0;
//}
//
//int Address::setnumber(const string &numer) {
//    if (numer.empty()){
//        cout << "Niemozliwa zmiana numeru" << endl;
//    }
//    else {
//        cout << "Zmiana numeru z : " << number << " na " << numer << " ..." << endl << endl;
//        number = numer;
//        cout << "Numer zostal zmieniony" << endl << endl;
//    }
//    return 0;
//}

