#include <string>
#include <iostream>
#include "model/Client.h"
#include <sstream>

using namespace std;

// Etap 0

Client::Client(){   // Konstruktor
    cout << "Destruktor zostal wywolany" << endl << endl;   //Cout komunikat
}

Client::Client(string imie, string nazwisko, string PESSEL) : firstName(imie), lastName(nazwisko), personalID(PESSEL){  //Обьявляем переменные класса к функции
    cout << getClientInfo();
}

Client::~Client() { // Dekonstrukor
    cout << "Kostruktor zostal wylolany" << endl << endl;   //Cout komunikat
}



//Etap 1.1 1.2 1.3

string Client::getClientInfo() const {  //Zwraca informacje
    ostringstream out;// Кароче тут за это как раз отвечает та библиотека sstream она собирает все в одну штуку а потом выдает через cout
    // Сверху видно что с помощью ostringstream мы обьявляем нашу сумку out её можно назвать как угодно вместо out можем написать jepa и будет работать
    // Дальше все складываем в out как в обычный cout
    out << "Client information: " << endl << endl << "Imie: " << get_firstName() << endl << endl;   // Передаем в нашу шту
    out << "Nazwisko: " << get_lastName() << endl << endl << "Numer PESSEL: " << get_personalID() << endl << endl;
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
