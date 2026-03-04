



/*
Timurs Maksjuks

Create a program in C++ that processes a text file in sequential mode.
Data from the file must be read one line at a time. The contents of the entire file must not be duplicated in the RAM.
F4. Given a text file f. Write a program that finds all words in the file f that contain the substring m. Output these words to the file f1.
Consider a word to be an arbitrary string of symbols separated by spaces or punctuation marks (period, comma, parentheses, exclamation mark, question mark).
It is assumed that the length of a word does not exceed 40.

Program created: 18.02.2026
*/



#include <iostream>
#include <fstream> // Library included to work with files
#include <string> // Library included to work with strings
using namespace std;

int main() {

    int answer = 0;
    string line, substring;

    do {
        cout << "Enter the desired substring: " << endl;
        cin >> substring;

        fstream inputFile("file_reading.txt", ios::in); // Opening the file to read its contents
        fstream outputFile("file_writing.txt", ios::out); // Opening another file to write the words that contain the specified substring


        while (getline(inputFile, line)) {  // Reading the file line by line
            string word = "";       // Variable 'word' to store characters that are not spaces or punctuation

            for (int i = 0; i <= line.size(); i++) { // Analyzing the line until its end
                char character = line[i]; // Variable used to analyze each character separately

                // Check if the character is punctuation or a space
                if (character == '.' || character == ',' || character == '(' || character == ')' ||
                    character == '!' || character == '?' || character == ' ' || i == line.size()) {

                    // Checking whether the word contains the required substring
                    if (word != "" && word.find(substring) != string::npos) {

                        // string::npos means 'no position' and returns a large value if the substring is not found

                        outputFile << word << "\n"; // Writing the word to the output file
                    }
                    word = ""; // Reset the variable because the complete word has already been analyzed
                } else {
                    word += character; // If the character is not a space or punctuation mark, add it to the word
                }
            }
        }

        inputFile.close(); // Closing files to free resources
        outputFile.close();

        cout << "Program finished. Do you want to run the program again? 1 - yes, 0 - no" << endl;
        cin >> answer;

    } while (answer == 1);

    return 0;
}
