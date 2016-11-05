/*  Mixed_Cipher - a cipher I made for a school project
    Copyright (C) 2016  Carlos Vazquez
    
    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.
    
    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.
    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
    
    Contact me at fwcarlitos@icloud.com
*/
#include <iostream>
#include <cctype>
#include "cipher.h"
using std::cout;
using std::endl;
using std::cin;
using std::string;

int main(){
    srand (time(NULL));
    cout << "Mixed_Cipher Copyright (C) 2016 Carlos Vaquez" << endl;
    cout << "This program comes with ABSOLUTELY NO WARRANTY" << endl << endl;
    char continue_encrypting = 'y';
    string message;
    while (tolower(continue_encrypting) == 'y'){
        char choice;
        cout << "NOTE: This program currently only supports lowercase alphabetic letters" << endl;
        cout << "Would you like to encrypt with a one time pad, or a polyalphabetic shift cipher? (o/p)" << endl
        << "Or decrypt by shifts (d), decrypt one time pad (t)" << endl;
        cin >> choice;
        switch (tolower(choice)){
            case 'p':
            {string encryption_word;//the brackets were necessary to fix an error
                cout << "Please enter the message to be encrypted:" << endl;
                cin >> message;
                cout << "Please enter the word to encrypt it with" << endl;
                cin >> encryption_word;
                message = polyalphabetic(message, encryption_word); 
                cout << message << endl;
                break;}
            case 'o':
            {cout << "Please enter the message to be encrypted:" << endl;
                cin >> message;
                message = one_time_pad(message);
                cout << message << endl;
                break;}
            case 'd':
            {
            char shifted_char;
            int shift_amount;
            cout << "Enter the shifted letter:" << endl;
            cin >> shifted_char;
            cout << "Enter the amount to shift down by" << endl;
            cin >> shift_amount;
            char decrypted_char = shift_letter_down(shifted_char, shift_amount);
            cout << "That decrypts to " << decrypted_char << endl;
            break;}
            case 't':
            {
                message = decrypt_one_time_pad();
                cout << "Decrypted message: " << message << endl;
                break;
            }
            default:
            {cout << "Invalid input" << endl;
                break;}
        }
        message.clear();
        cout << "Would you like to contine?" << endl;
        cin >> continue_encrypting;
    }
    return 0;
}

