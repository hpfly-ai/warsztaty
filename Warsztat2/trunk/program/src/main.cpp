#include "model/Client.h"   //Class Client

using namespace std;

int main()
{
    Client* Osoba1;
    Osoba1 = new Client("Danylo","Zdoryk","233305");

    Client* Osoba2;
    Osoba2 = new Client("Anton","Karpetskyi","233304");

    Osoba1->set_firstName("Michal");
    Osoba1->get_firstName();

    Osoba2->set_lastName("Duda");
    Osoba2->get_lastName();

    Osoba1->set_lastName("");

    delete Osoba1;
    delete Osoba2;

    return 0;
}
