#include <string>

class Address {
private:
    std::string city;
    std::string street;
    std::string number;
public:
    Address(const std::string &miasto, const std::string &ulica, const std::string &numer);
    ~Address();

    std::string getAddressInfo() const;
    const std::string &getcity() const;
    const std::string &getstreet() const;
    const std::string &getnumber() const;

//    int setcity(const std::string &miasto);
//    int setstreet(const std::string &ulica);
//    int setnumber(const std::string &numer);
};