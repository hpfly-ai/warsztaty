#include <iostream>
#include "model/Client.h"
#include "model/Address.h"
#include "model/Vehicle.h"
#include "model/Rent.h"
#include <boost/date_time.hpp>

using namespace std;
namespace pt = boost::posix_time;
namespace gr = boost::gregorian;

int main()
{

    pt::ptime begintime = pt::ptime(gr::date(2020,5,13),pt::hours(10)+pt::minutes(26));
    pt::ptime endtime = pt::ptime(gr::date(2020,5,14),pt::hours(10)+pt::minutes(25));

    Client* Osoba = new Client("Rose", "Lalonde", "413", nullptr);

    Vehicle* vehicle1 = new Vehicle("1-000-FF", 50);

    Rent* rent1 = new Rent(1, vehicle1, Osoba, begintime);

    rent1->endRent(endtime);

    cout<<rent1->getRentCost()<< endl<<endl;

    vehicle1->setbasePrice(70);

    cout << rent1 ->getRentCost();

    return 0;


}