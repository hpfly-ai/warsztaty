#include "model/Address.h"
#include <string>
#include <iostream>
#include <sstream>

using namespace std;


Address::Address(string miasto, string ulica, string numer) : city(miasto), street(ulica), number(numer){
    getAdressInfo();
}


string Address::getAdressInfo() const {
    ostringstream out;
    out << "Address information: "  << endl << "City: " << get_city()  << endl;
    out << "Ulica: " << get_street() << " " << get_number() << endl << endl;
    return out.str();
}

string Address::get_city() const {
    return city;
}

string Address::get_street() const {   //Вывод Фамилии
    return street;
}

string Address::get_number() const {   // Вывод Песселя
    return number;
}

bool Address::set_city(string miasto){   //setter имени
    if (miasto == ""){
        cout << "Niemozliwa zmiana miasta" << endl;
    }
    else{
        cout << "Zmiana imia z : " << city << " na " << miasto << " ..." << endl << endl;
        city = miasto;
        cout << "Miasto zostalo zmienione" << endl << endl;
        return true;
    }
}

bool Address::set_street(string ulica){    //setter Фмилии
    if(ulica == ""){
        cout << "Niemozliwa zmiana nazwiska" << endl << endl;
    }
    else{
        cout << "Zmiana nazwiska z : " << city << " na " << ulica << " ..."  << endl;
        city = ulica;
        cout << "Nazwisko zostalo zmienione" << endl << endl;
        return true;
    }
}

