#include <iostream>
#include "model/Client.h"   //Class Client

using namespace std;

int main()
{
  Address* address = new Address("","","");
  Client* osoba1 = new Client("Danylo", "Zdoryk", "233305", address);
  delete address;

  osoba1->set_address(address);
//  Address* address2 = new Address("lodz", "Politechnika", "7");
//  osoba1->set_address(address);
  osoba1->getClientInfo();


  delete osoba1;
  return 0;
}
