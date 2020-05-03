#include <string>

using namespace std;
class Client{   //Class
//  Default private
    string firstName;
    string lastName;
    string personalID;
    string get_firstName() const;
    string get_lastName() const;
    string get_personalID() const;
    //Destruktor
public:
    Client();  //Konstruktor
    Client(string imie, string nazwisko, string PESSEL);    // На кострукторы действует перегрузка

    string getClientInfo() const;


    ~Client();
};