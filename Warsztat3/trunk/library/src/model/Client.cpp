#include <string>
#include <iostream>
#include "model/Client.h"
#include <sstream>

using namespace std;

Client::Client(string imie, string nazwisko, string PESSEL) : firstName(imie), lastName(nazwisko), personalID(PESSEL){
}

Client::Client(string imie, string nazwisko, string PESSEL, Address* address_ptr) : firstName(imie), lastName(nazwisko), personalID(PESSEL), addressptr(address_ptr){
}

string Client::getClientInfo() const {  //Zwraca informacje
    ostringstream out;
    out << "Client information: "  << endl << "Imie: " << &Client::getFirstName()  << endl;   // Передаем в нашу шту
    out << "Nazwisko: " << getLastName() << endl << "Numer PESSEL: " << getPersonalId() << endl << endl;
    if(addressptr->getNumber().empty() || addressptr->getCity().empty() || addressptr->getStreet().empty()){
    }
    else {
        out << addressptr->getAddressInfo() << endl;
    }

    return out.str();
}

Client::~Client() {

}


bool Client::setLastName(const string &lastName) {
    if(lastName == ""){
        cout << "Niemozliwa zmiana nazwiska" << endl << endl;
    }
    else{
        cout << "Zmiana nazwiska z : " << Client::lastName << " na " << lastName << " ..."  << endl;
        Client::lastName = lastName;
        cout << "Nazwisko zostalo zmienione" << endl << endl;
        return true;
    }
}

bool Client::setPersonalId(const string &personalId) {
    if (personalId == ""){
        cout << "Niemozliwa zmiana PESSEL" << endl;
    }
    else{
        cout << "Zmiana PESSEL z : " << Client::personalID << " na " << personalId << " ..." << endl << endl;
        Client::personalID = personalId;
        cout << "Imie zostalo zmienione" << endl << endl;
        return true;
    }
    personalID = personalId;
}

bool Client::setAddressptr(Address *addressptr) {
    if(addressptr->getNumber().empty() || addressptr->getCity().empty() || addressptr->getStreet().empty())
    {
        cout<<"NiemoĹźliwa zmiana adresu" << endl;
        return false;
    }
    addressptr = Client::addressptr;
    return true;
}

bool Client::setFirstName(const string &firstName){
    if (firstName == ""){
        cout << "Niemozliwa zmiana imia" << endl;
        return false;
    }
    else{
        cout << "Zmiana imia z : " << Client::firstName << " na " << firstName << " ..." << endl << endl;
        Client::firstName = firstName;
        cout << "Imie zostalo zmienione" << endl << endl;
        return true;
    }
}

Address *Client::getAddressptr() const {
    return addressptr;
}

const string &Client::getLastName() const {
    return lastName;
}

const string &Client::getFirstName() const {
    return firstName;
}



const string &Client::getPersonalId() const {
    return personalID;
}

const Address* Client::get_address() const{
    return addressptr;
}