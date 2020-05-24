//#include <iostream>
//#include "model/Client.h"   //Class Client
//
//using namespace std;
//
//int main(){
//    Address* address = new Address("Lodz","Al Politechniki","7");
//    Client* osoba2 = new Client("Anton", "Karpetskyi", "233304", address);
//    Client* osoba1 = new Client("Danylo", "Zdoryk", "233305", address);
//
////    address->set_city("Odessa");
//
//    cout << osoba1->getClientInfo();
//    cout << "-------------------------\n";
//    cout << osoba2->getClientInfo();
//
//    cout << osoba1->get_address();
//
//
//
//    delete osoba2;
//    delete osoba1;
//    delete address;
//  return 0;
//}

#include<iostream>
#include <model/Client.h>

using namespace std;

int main()
{
    string fname1 = "Jon";
    Client c(fname1, "Arbuckle", "0123456789");
    fname1.assign("Doc Boy");
    cout << c.getFirstName() << endl;

    string fname2 = "Garfield";
    c.setFirstName(fname2);
    fname2.assign("Liz");
    cout << c.getFirstName() << endl;

    return 0;
}