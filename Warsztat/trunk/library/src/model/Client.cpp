#include <iostream>

using namespace std;
class Client{   //Class
public:
    Client(){   //Kostruktor
        cout << "Kostruktor zostal wylolany" << endl << endl;   //Cout komunikat
    }

    ~Client(){  //Destruktor
        cout << "Destruktor zostal wywolany" << endl << endl;   //Cout komunikat
    }
};