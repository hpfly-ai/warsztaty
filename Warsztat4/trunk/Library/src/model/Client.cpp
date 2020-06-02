#include <string>
#include "model/Client.h"
#include <iostream>
#include <sstream>
#include "model/Address.h"
#include "model/Rent.h"

using namespace std;

Client::Client(const string &firstName, const string &lastName, const string &personalId, Address *addressPtr)
        : firstName(firstName), lastName(lastName), personalID(personalId), Address_ptr(addressPtr) {}

Client::Client(const string &firstName, const string &lastName, const string &personalId) : firstName(firstName),
                                                                                            lastName(lastName),
                                                                                            personalID(personalId) {}
Client::~Client() {

}

string Client::getClientInfo() const {
    ostringstream out;
    out << "Client information: "  << endl << "Imie: " << getFirstName()  << endl << "Nazwisko: " << getLastName() << endl << "Numer PESSEL: " << getPersonalId() << endl << endl << (*getAddressPtr()).getAddressInfo() << endl << endl ;
    return out.str();
}

std::string Client::getFullClientInfo() const {
    ostringstream fout;
    fout << getClientInfo() << endl << endl;
    for (int i = 0; i < getCurrentRentsNumber(); i++)
        fout << (*getCurrentRentPtr(i)).getRentInfo();
    return fout.str();
}

const string &Client::getFirstName() const {
    return firstName;
}

bool Client::setFirstName(const string &firstName) {

    if (firstName.empty()){
        cout << "Niemozliwa zmiana imia" << endl;
        return false;
    }
    else {
        cout << "Zmiana imia z : " << Client::firstName << " na " << firstName << " ..." << endl << endl;
        Client::firstName = firstName;
        cout << "Imie zostalo zmienione" << endl << endl;
        return true;
    }

}

const string &Client::getLastName() const {
    return lastName;
}

bool Client::setLastName(const string &lastName) {

    if (lastName.empty()){
        cout << "Niemozliwa zmiana nazwiska" << endl;
        return false;
    }
    else {
        cout << "Zmiana nazwiska z : " << Client::lastName << " na " << lastName << " ..." << endl << endl;
        Client::lastName = lastName;
        cout << "Nazwisko zostalo zmienione" << endl << endl;
        return true;
    }

}

Address *Client::getAddressPtr() const {
    return Address_ptr;
}

bool Client::setAddressPtr(Address *addressPtr) {

    if(addressPtr == nullptr){
        cout << "Niemozliwa zmiana adresu" << endl << endl;
        return false;
    }
    else{
        cout << "Zmiana adresu ..."  << endl;
        Address_ptr = addressPtr;;
        cout << "Adres zostalo zmienione" << endl << endl;
        return true;
    }

}

const string &Client::getPersonalId() const {
    return personalID;
}




bool Client::setCurrentRents(Rent* RentPtr) {

    if(RentPtr == nullptr){
        cout << "Niemozliwe dodawanie Renty" << endl << endl;
        return false;
    }
    else{
        cout << "Dodanie renty ..."  << endl;
        Client::currentRents.push_back(RentPtr) ;
        cout << "Adres zostalo zmienione" << endl << endl;
        return true;
    }

}

unsigned int Client::getCurrentRentsNumber() const {
    return currentRents.size();
}

Rent *Client::getCurrentRentPtr(unsigned int number) const {
    return currentRents[number];
}

bool Client::eraseCurrentRentPtr(unsigned int i) {
    if (i<getCurrentRentsNumber() && i>=0){
        currentRents.erase(currentRents.begin() + i);
        return true;
    }
    else return false;
}




