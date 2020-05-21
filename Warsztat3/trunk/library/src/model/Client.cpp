#include <string>
#include <iostream>
#include "model/Client.h"
#include <sstream>

using namespace std;

Client::Client(string imie, string nazwisko, string PESSEL) : firstName(imie), lastName(nazwisko), personalID(PESSEL){
    cout << getClientInfo();
}

Client::Client(string imie, string nazwisko, string PESSEL, Address* address_ptr) : firstName(imie), lastName(nazwisko), personalID(PESSEL), addressptr(address_ptr){
    cout << getClientInfo();
}

string Client::getClientInfo() const {  //Zwraca informacje
    ostringstream out;
    out << "Client information: "  << endl << "Imie: " << get_firstName()  << endl;   // Передаем в нашу шту
    out << "Nazwisko: " << get_lastName() << endl << "Numer PESSEL: " << get_personalID() << endl << endl;
    if(addressptr->get_number().empty() || addressptr->get_city().empty() || addressptr->get_street().empty()){
    }
    else {
        out << addressptr->getAddressInfo() << endl;
    }

    return out.str();
}

Client::~Client() {

}

string Client::get_firstName() const {  //Вывод Имени
    return firstName;
}

string Client::get_lastName() const {   //Вывод Фамилии
    return lastName;
}

string Client::get_personalID() const {   // Вывод Песселя
    return personalID;
}

bool Client::set_firstName(std::string imie){   //setter имени
    if (imie == ""){
        cout << "Niemozliwa zmiana imia" << endl;
    }
    else{
        cout << "Zmiana imia z : " << firstName << " na " << imie << " ..." << endl << endl;
        firstName = imie;
        cout << "Imie zostalo zmienione" << endl << endl;
        return true;
    }
}

bool Client::set_lastName(std::string nazwisko){    //setter nazwiska
    if(nazwisko == ""){
        cout << "Niemozliwa zmiana nazwiska" << endl << endl;
    }
    else{
        cout << "Zmiana nazwiska z : " << lastName << " na " << nazwisko << " ..."  << endl;
        lastName = nazwisko;
        cout << "Nazwisko zostalo zmienione" << endl << endl;
        return true;
    }
}

bool Client::set_address(Address* address_ptr)
{
    if(address_ptr->get_number().empty() || address_ptr->get_city().empty() || address_ptr->get_street().empty())
    {
        cout<<"NiemoĹźliwa zmiana adresu" << endl;
        return false;
    }
    addressptr = address_ptr;
    return true;
}