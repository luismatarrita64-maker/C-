#include <iostream>
using namespace std;

int main() {
    cout << "hola" << endl;

    int x = 10;
    int* numer = &x;

  

    delete &x;


    cout << "numero = " << x << endl;
    return 0;

    
}