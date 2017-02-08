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

#include "cipher.h"
#include <cctype>
#include <iostream>
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

char shift_letter_down (char unshifted_char, int shift_amount){
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
        if (unshifted_char_index - shift_amount <= 26 && unshifted_char_index - shift_amount >= 0){
            shifted_char = alphabet[(unshifted_char_index - shift_amount) - 1]; //I know it seems redundant to subract 1 after adding it, but the program didnt work quite right without it
            //cout << "less than 26" << endl; //for debugging
            cout << shifted_char << endl; //for debugging
            return shifted_char;
        }
        else if (unshifted_char_index - shift_amount > 26){
            shifted_char = alphabet[(unshifted_char_index - shift_amount) - 27];// -27 instead of -26 was necessary
            //cout << "greater than 26" << endl; //for debugging
            cout << shifted_char << endl; //for debugging
            return shifted_char;
        }
        else if (unshifted_char_index - shift_amount < 0){
			while (unshifted_char_index - shift_amount <= -26){
				unshifted_char_index += 26;} 
            shifted_char = alphabet[(unshifted_char_index - shift_amount) + 25];//this works, so I dont touch it or question it
            cout << shifted_char << endl; //for debugging
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
        int shift_amount = rand() % 27 + 0; //set shift amount to random amount
        cout << "Shifting " << individual_char << " by " << shift_amount << endl;
        message[i] = shift_letter (individual_char, shift_amount);// shift char by random amount
        }
    }
    return message;
}

std::string polyalphabetic (std::string message, std::string word_key){
    char alphabet[26] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
    int word_key_index;
    int k = 0;
    for (int i = 0; i < message.length(); i++){// loop through each character
        char individual_char = message[i];
        if (isalpha(individual_char) == false) {
            cout << "Error: Invalid Character" << endl;
            continue;
        }
        else {
        for (int j = 0; j <= 26; j++){ // find index position of word_key letter
            if (alphabet[j] == word_key[k]){
                word_key_index = j + 1; 
                break;
            }
            else {
            }
        }
        int shift_amount = word_key_index;//set shift amount to current letter of word_key
        cout << "Shifting " << individual_char << " by " << shift_amount << endl;
        message[i] = shift_letter (individual_char, shift_amount);// shift char by word_key letter
        }
        k++; // go to next letter of word_key
        if (k > word_key.length()){//reset k when it reaches the end of the word 
            k = 0;
            continue;
        }
    }
    return message;
}

std::string decrypt_one_time_pad (){
    string message;
    string shifts;
    int shift_amount = 0;
    cout << "Please enter the encrypted message" << endl;
    std::cin >> message;
    int* shift_array; 
    shift_array = new int[message.size()];//number of shifts because one time pad has the same number of shifts as characters
    for (int i = 0; i < message.size(); i++){
        cout << "Please enter the " << i + 1 << " shift:" << endl;
        std::cin >> shift_array[i];
    } 
    for (int k = 0; k < message.size(); k++){//shift
        char individual_char = message[k];
        int shift_amount = shift_array[k];
        cout << "Shifting " << individual_char << " by " << shift_amount << endl; //for debugging
        message[k] = shift_letter_down(individual_char, shift_amount);
    }
    //cout << "Message: " << message << endl;//for debug
    delete[] shift_array;
    return message;
}


