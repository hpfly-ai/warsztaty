#include <iostream>
#include "model/Client.h"   //Class Client

using namespace std;

int main()
{
    Client* Osoba1;
    Osoba1 = new Client("Danylo","Zdoryk","233305");

    Client* Osoba2;
    Osoba2 = new Client("Anton","Karpetskyi","233304");

    delete Osoba1;
    delete Osoba2;

    return 0;
}
