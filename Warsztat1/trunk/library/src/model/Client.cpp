#include <string>
#include <iostream>
#include "model/Client.h"
#include <sstream>

using namespace std;


//Client::Client(){   // Konstruktor
//    cout << "Konstruktor bezparametrowy zostal wywolany" << endl << endl;   //Cout komunikat
//}

Client::Client(string imie, string nazwisko, string PESSEL) : firstName(imie), lastName(nazwisko), personalID(PESSEL){  //Обьявляем переменные класса к функции
    cout << getClientInfo();
}

Client::~Client() { // Destrukor
    cout << "Destruktor zostal wylolany" << endl << endl;   //Cout komunikat
    cout << getClientInfo() << endl;    // Etap 3.3
}




string Client::getClientInfo() const {  //Zwraca informacje
    ostringstream out;// Кароче тут за это как раз отвечает та библиотека sstream она собирает все в одну штуку а потом выдает через cout
    // Сверху видно что с помощью ostringstream мы обьявляем нашу сумку out её можно назвать как угодно вместо out можем написать jepa и будет работать
    // Дальше все складываем в out как в обычный cout
    out << "Client information: "  << endl << "Imie: " << get_firstName()  << endl;   // Передаем в нашу шту
    out << "Nazwisko: " << get_lastName() << endl << "Numer PESSEL: " << get_personalID() << endl << endl;
    return out.str();   /// Выводим нашу корзину
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


void Client::set_firstName(std::string imie){   //setter имени
    if (imie == ""){
        cout << "Niemozliwa zmiana imia" << endl;
    }
    else{
        cout << "Zmiana imia z : " << firstName << " na " << imie << " ..." << endl << endl;
        firstName = imie;
        cout << "Imie zostalo zmienione" << endl << endl;
    }
}

void Client::set_lastName(std::string nazwisko){    //setter Фмилии
    if(nazwisko == ""){
        cout << "Niemozliwa zmiana nazwiska" << endl << endl;
    }
    else{
        cout << "Zmiana nazwiska z : " << lastName << " na " << nazwisko << " ..."  << endl;
        lastName = nazwisko;
        cout << "Nazwisko zostalo zmienione" << endl << endl;
    }
}
