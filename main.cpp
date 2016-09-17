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
#include <iostream>
#include "cipher.h"
using std::cout;
using std::endl;
using std::cin;

int main(){
    char shift_char;
    int shift_amount;
    cout << "Plesae enter a character to be shifted" << endl;
    cin >> shift_char;
    cout << "Please enter shift amount" << endl;
    cin >> shift_amount;
    cout << shift_letter(shift_char, shift_amount) << endl;
}
