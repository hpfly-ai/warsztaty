#include <string>

using namespace std;
class Client{   //Class
//  Default private
    string firstName;
    string lastName;
    string personalID;
    //Destruktor
public:
//    Client();  //Konstruktor
    Client(string imie, string nazwisko, string PESSEL);    // На кострукторы действует перегрузка
    ~Client();

    std::string getClientInfo() const;
    std::string get_firstName() const;
    std::string get_lastName() const;
    std::string get_personalID() const;
    void set_firstName(std::string imie);
    void set_lastName(std::string nazwisko);
};