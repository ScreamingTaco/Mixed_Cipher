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
    /*char shift_char;
    int shift_amount;
    cout << "Plesae enter a character to be shifted" << endl;
    cin >> shift_char;
    cout << "Please enter shift amount" << endl;
    cin >> shift_amount;
    cout << shift_letter(shift_char, shift_amount) << endl;
    */
    /*srand (time(NULL)); //seed random # generator
    string message;
    cout << "Enter message for encryption with only lowercase alphabetic characters and no spaces" << endl;
    cin >> message;
    message = one_time_pad(message);
    cout << message << endl;*/
    cout << "Mixed_Cipher Copyright (C) 2016 Carlos Vaquez" << endl;
    cout << "This program comes with ABSOLUTELY NO WARRANTY" << endl << endl;
    char continue_encrypting = 'y';
    string message;
    while (tolower(continue_encrypting) == 'y'){
        char choice;
        cout << "NOTE: This program currently only supports lowercase alphabetic letters" << endl;
        cout << "Would you like to encrypt with a one_time_pad, or a polyalphabetic shift cipher? (o/p)" << endl;
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

