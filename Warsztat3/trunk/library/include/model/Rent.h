#include <string>
#include <boost/date_time/posix_time/ptime.hpp>


class Vehicle;
class Client;

namespace pt = boost::posix_time;
namespace gr = boost::gregorian;

class Rent {

private:

    unsigned int id;
    Vehicle*  Vehicle_ptr;
    Client* Client_ptr;
    pt::ptime beginTime;
    pt::ptime endTime;
    unsigned int rentCost = 0;

public:

    Rent(unsigned int identyfikator, Vehicle* Vehicleptr, Client* Clientptr, pt::ptime rozpczas);
    ~Rent();

    std::string getRentInfo() const;
    unsigned int getid() const;
    const Vehicle* getVehicle_ptr() const;
    const Client* getClient_ptr() const;
    const unsigned int getRentDays() const;
    const pt::ptime &getBeginTime() const;
    const pt::ptime &getEndTime() const;
    const unsigned int getRentCost() const;


    bool setid(unsigned int identyfikator);
    bool setVehicle_ptr(Vehicle* Vehicleptr);
    bool setClient_ptr(Client* Clientptr);
    bool endRent(pt::ptime endtime);
    bool setEndTime(pt::ptime endtime);
    bool setRentCost(unsigned int cost);

};
