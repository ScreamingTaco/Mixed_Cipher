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
#ifndef cipher_h
#define cipher_h
#include <random>
#include <string>

char shift_letter (char unshifted_char, int shift_amount);
char shift_letter_down (char unshifted_char, int shift_amount);
std::string one_time_pad (std::string message);
std::string polyalphabetic (std::string message, std::string word_key);
std::string decrypt_one_time_pad ();
//std::string decrypt_polyalphabetic (std::string shifts, message);
//int rsa_encrypt (int encryption_target, int public_key); 



#endif
