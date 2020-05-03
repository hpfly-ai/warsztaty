#include <iostream>

using namespace std;

Client(){   //Class
public:
    Client(){   //Kostruktor
        cout << "Kostruktor zostal wylolany" << endl << endl;   //Cout komunikat
    }

    ~Client(){  //Destruktor
        cout << "Destruktor zostal wywolany" << endl << endl;   //Cout komunikat
    }
}