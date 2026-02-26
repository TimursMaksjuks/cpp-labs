#include <iostream>
#include <string> // Library is included to use necessary string functions
using namespace std;


/*
Timurs Maksjuks
C37. Without using built-in hexadecimal output functions,
print the multiplication table in hexadecimal number system (from 1*1 to F*F).
Program created: 11.11.2025
*/


string trans(int num){ // Function that converts a decimal number into hexadecimal

    int divider = 16, remainder = 0, quotient = 0; // Divider is set to 16 to convert number to base-16
    string remainder_s, quotient_s, new_num;

    char letters[6] = {'A', 'B', 'C', 'D', 'E', 'F'}; // Array to replace numbers 10–15 with hexadecimal letters

    if (num<=9) {
        new_num = to_string(num); // Convert integer digit to string
        return new_num; // Digits 1–9 are identical in decimal and hexadecimal systems
    }

    else if (num<=15) {
        new_num = string(1,letters[num - 10]); // Corresponding number equals corresponding letter in array
        return new_num;
    }

    else {

        quotient = num / 16; // Integer division result for base-16 conversion
        remainder = num - (16 * quotient); // Calculate division remainder

        if (quotient<=9) {quotient_s = to_string(quotient);} // Digits 1–9 stay the same
        else {
            quotient_s = string(1,letters[quotient-10]);
        }

        if (remainder<=9) {remainder_s = to_string(remainder);}
        else {
            remainder_s = string(1,letters[remainder-10]);
        }

        new_num = quotient_s + remainder_s; // Final hexadecimal number formed by concatenation

        return new_num;
    }
}


void table (string arr[16][16]){ // Function that prints multiplication table from 1*1 to F*F in hexadecimal

    for (int i = 1; i<16; i++){
        for (int j = 1; j<16; j++){
            arr[i][j] = trans(i*j); // Each multiplication result is converted to base-16
            cout<< arr[i][j] << '\t';
        }
        cout << endl << endl; // After two new lines, next row of table is printed
    }
}


int main(){

    int answer = 1;
    string arr[16][16]; // Static 2D array used as multiplication table (1*1 to F*F)

    do {

        table(arr); // Call function that prints hexadecimal multiplication table

        cout << "Continue (1) or exit (0)?" << endl; // Ask user whether to continue the program
        cin >> answer;
        cout << endl;

    } while (answer==1); // Program runs while user chooses to continue

    return 0;
}
