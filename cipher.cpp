/*  Cipher - a cipher I made for a school project
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

#include "cipher.h"
#include <cctype>
#include <iostream>
//#include <random>
#include <string>
#include <cstdlib>
using std::cout;
using std::endl;
using std::string;

char shift_letter (char unshifted_char, int shift_amount){
    char alphabet[26] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
    char shifted_char;
    if (isalpha(unshifted_char) == false){
        cout << "Invalid character detected" << endl;
        return '1';
    }
    else {
        int unshifted_char_index;
        for (int i = 0; i <= 26; i++){ // find index position of alphabet letter
            if (alphabet[i] == unshifted_char){
                //cout << "index = " << i << endl; //for debugging
                unshifted_char_index = i + 1; 
                break;
            }
            else {
            }
        }
        tolower(unshifted_char);
        if (unshifted_char_index + shift_amount <= 26){
            shifted_char = alphabet[unshifted_char_index + shift_amount - 1]; //I know it seems redundant to subract 1 after adding it, but the program didnt work quite right without it
            //cout << "less than 26" << endl; //for debugging
            return shifted_char;
        }
        else if (unshifted_char_index + shift_amount > 26){
            shifted_char = alphabet[(unshifted_char_index + shift_amount) - 27];// -27 instead of -26 was necessary
            //cout << "greater than 26" << endl; //for debugging
            return shifted_char;
        }
        
    }
}

std::string one_time_pad (string message){
    for (int i = 0; i < message.length(); i++){// loop through each character
        char individual_char = message[i];
        if (isalpha(individual_char) == false) {
            cout << "Error: Invalid Character" << endl;
            continue;
        }
        else {
        //int shift_amount = distribution(generator);
        int shift_amount = rand() % 27 + 0;
        cout << "Shifting " << individual_char << " by " << shift_amount << endl;
        message[i] = shift_letter (individual_char, shift_amount);// shift char by random amount
        }
    }
    return message;
}

