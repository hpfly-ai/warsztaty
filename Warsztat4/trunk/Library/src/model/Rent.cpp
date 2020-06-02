#include "model/Rent.h"
#include <string>
#include <iostream>
#include <sstream>
#include "model/Client.h"
#include "model/Vehicle.h"
#include <boost/date_time.hpp>


using namespace std;
namespace pt = boost::posix_time;
namespace gr = boost::gregorian;

Rent::Rent(unsigned int identyfikator, Vehicle *Vehicleptr, Client *Clientptr, pt::ptime rozpczas): id(identyfikator), Vehicle_ptr(Vehicleptr), Client_ptr(Clientptr), beginTime(rozpczas) {
    (*Clientptr).setCurrentRents(this);
    if (Vehicleptr != nullptr) (*Vehicleptr).setIsRented(true);
    if (rozpczas == pt::not_a_date_time) beginTime = pt::second_clock::local_time() ;
}

Rent::~Rent() {

}

std::string Rent::getRentInfo() const {
    ostringstream out;
    out << "Rent information: "  << endl << "Id: " << getid()  << endl << endl << "Czas rozpoczecia renty: " << getBeginTime() << endl << "Czas ukonczenia renty: " << getEndTime() << endl << "Ilosc dni renty: " << getRentDays()<< endl << endl<< (*getVehicle_ptr()).getVehicleinfo() << endl << endl << (*getClient_ptr()).getClientInfo() << endl << endl ;
    return out.str();
}

unsigned int Rent::getid() const {
    return id;
}

const Vehicle *Rent::getVehicle_ptr() const {
    return Vehicle_ptr;
}

const Client *Rent::getClient_ptr() const {
    return Client_ptr;
}

bool Rent::setid(unsigned int identyfikator) {
    if (identyfikator == 0){
        cout << "Niemozliwa zmiana id" << endl;
        return false;
    }
    else {
        cout << "Zmiana id z : " <<  id << " na " << identyfikator << " ..." << endl << endl;
        id = identyfikator;
        cout << "Id zostal zmieniony" << endl << endl;
        return true;
    };

}

bool Rent::setVehicle_ptr(Vehicle *Vehicleptr) {
    if(Vehicleptr == nullptr){
        cout << "Niemozliwa zmiana vehicle" << endl << endl;
        return false;
    }
    else{
        cout << "Zmiana vehicle ..."  << endl;
        Vehicle_ptr = Vehicleptr;
        cout << "Vehicle zostalo zmienione" << endl << endl;
        return true;
    }

}

bool Rent::setClient_ptr (Client *Clientptr) {
    if(Clientptr == nullptr){
        cout << "Niemozliwa zmiana clienta" << endl << endl;
        return false;
    }
    else{
        cout << "Zmiana clienta z ..."  << endl;
        Client_ptr = Clientptr;
        cout << "Client zostal zmieniony" << endl << endl;
        return true;
    }

}

const unsigned int Rent::getRentDays() const {
    if(endTime == pt::not_a_date_time){
        return 0;
    }
    else{
        pt::time_period period(beginTime, endTime);
        if (period.length() <= pt::minutes(1)){
            return 0;
        }
        else {
            return ((period.length().hours()+1)%24)+1;
        }
    }

}

const pt::ptime &Rent::getBeginTime() const {
    return beginTime;
}

const pt::ptime &Rent::getEndTime() const {
    return endTime;
}

bool Rent::endRent(pt::ptime endtime) {
    if (endTime == pt::not_a_date_time){
        if (endtime == pt::not_a_date_time) {
            Rent::endTime = pt::second_clock::local_time();
        }
        else setEndTime(endtime);
        Vehicle_ptr->setIsRented(false);
        setRentCost((Vehicle_ptr->getbasePrice()*getRentDays()));
        for (int i = 0; i < Client_ptr->getCurrentRentsNumber() ; i++)
        {
            if(Client_ptr->getCurrentRentPtr(i) == this)
            {
                Client_ptr->eraseCurrentRentPtr(i);
            };
        };
        if (endTime > beginTime) return true;
        else {
            setRentCost(0);
            setEndTime(beginTime);
            return false;
        }

    }
    else return false;
}

bool Rent::setEndTime(pt::ptime endtime) {
    endTime = endtime;
    return true;
}

const unsigned int Rent::getRentCost() const{
    return rentCost;
}

bool Rent::setRentCost(unsigned int cost) {
    rentCost = cost;
    return true;
}




