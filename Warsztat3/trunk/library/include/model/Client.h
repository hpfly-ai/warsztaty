#include <string>

using namespace std;
class Client{   //Class
//  Default private
    string firstName;
    string lastName;
    string personalID;

public:
//    Client();  //Konstruktor
    Client(string imie, string nazwisko, string PESSEL);    // На кострукторы действует перегрузка
    ~Client();

    string getClientInfo() const;
    string get_firstName() const;
    string get_lastName() const;
    string get_personalID() const;
    bool set_firstName(string imie);
    bool set_lastName(string nazwisko);
};