#include "CaesarSubstitution.h"

int main()
{
    CaesarSubstitution cs;
    string input;
    cout << "Caesar Encryption" << endl;
    cout << "Do you want to encrypt (0) or decrypt a text(1): ";
    cin >> input;

    if (input == "0") {
        cs.handleUserInput("plain");
        system("CLS");
        cs.encrypt();
    }
    else if (input == "1") {
        cs.handleUserInput("cipher");
        system("CLS");
        cs.decrypt();
    }
    else if (input == "exit") {
        exit(0);
    }
}
