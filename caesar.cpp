#include <iostream>
#include <cstring>

using namespace std;

char *Encrypt(char *message, int shift)
{
    for (int i = 0; i < strlen(message); ++i)
    {
        if (isalpha(message[i]))
        {
            char base = (islower(message[i])) ? 'a' : 'A';
            message[i] = (message[i] - base + shift) % 26 + base;
        }
    }
    return message;
}

int main()
{

    cout << "Welcome to the Caesar cipher program" << endl;

    char input[256];

    cout << "Enter a passphrase (q to quit): ";
    cin.getline(input, sizeof(input));

    while (input[0] != 'q' || input[1] != '\0')
    {
        cout << "Select an operation :\n";
        cout << "1. Encode\n";
        cout << "2. Decode\n";

        int choice;
        cin >> choice;
        cin.ignore();

        int shift;
        cout << "Enter shift value (a positive integer): ";
        cin >> shift;
        cin.ignore();

        if (choice == 1)
        {

            cout << "Encoded message: " << Encrypt(input, shift) << endl;
        }
        else if (choice == 2)
        {

            cout << "Decoded message: " << Encrypt(input, 26 - shift) << endl;
        }
        else
        {
            cout << "Invalid choice. Please try again.\n";
        }

        cout << "Enter a passphrase (q to quit): ";
        cin.getline(input, sizeof(input));
    }

    cout << "Goodbye!\n";

    return 0;
}