/*
Timurs Maksjuks

Given a binary file f whose components are records with the following structure: key (int), name (does not exceed 30 characters).
Create two other binary files with the same structure, where the records are sorted in ascending order respectively by:
(1) key, (2) name.
In both cases, use the STL map structure for reading the information and ensuring sorting.
Additionally, create helper programs for generating the binary file and printing its contents.
It may be assumed that the records are unique both by key and by value.

A file component is understood as a fixed-length record.

Program created: 31.03.2026
*/



#include <iostream>
#include <fstream>
#include <map>
#include <cstring>
using namespace std;


struct Person{ // Structure that describes one binary file record
int key;
char name[31]; // Maximum 30 characters + '\0' for the end of the string
};


int main(){

int answer = 0;

do {

ifstream inputFile("main.bin", ios::binary); // Binary file reading mode

if (!inputFile){ // Check whether the file exists before opening it
    cout << "File 'main.bin' was not found!" << endl;
    return 1;
}

ofstream keyFile("key.bin", ios::binary); // Binary file writing mode
if (!keyFile){
    cout << "File 'key.bin' was not created!" << endl;
    return 1;
}

ofstream nameFile("name.bin", ios::binary);
if (!nameFile){
    cout << "File 'name.bin' was not created!" << endl;
    return 1;
}


Person person; // Declaration of a structure object for reading data from the binary file
map <int, string> keyDictionary; // Declaration of two separate maps to sort records separately according to the conditions
map <string, int> nameDictionary;



while(inputFile.read((char*)&person, sizeof(person))) { // The fields of the 'Person' object are read using the byte memory address and byte size

    keyDictionary.insert({person.key, person.name}); // Data is added to the map and automatically sorted in ascending order by default
    nameDictionary.insert({person.name, person.key});

}

Person personByKey;
Person personByName;

for (auto x: keyDictionary){
personByKey.key = x.first; // Assign the map key value to the 'key' field of the 'Person' structure
memset(personByKey.name, 0, sizeof(personByKey.name)); // The array becomes empty to remove possible extra symbols
strcpy(personByKey.name, x.second.c_str()); // The high-level string is converted into a low-level C-string and copied into the 'personByKey.name' variable

keyFile.write((char*)&personByKey, sizeof(personByKey)); // Writing the record into the binary file

}



for (auto y: nameDictionary){
memset(personByName.name, 0, sizeof(personByName.name));
strcpy(personByName.name, y.first.c_str());
personByName.key = y.second;
nameFile.write((char*)&personByName, sizeof(personByName));


}



cout << "File 'key.bin' was created. Records were sorted by key." << endl;
cout << "File 'name.bin' was created. Records were sorted by name." << endl;



inputFile.close();
keyFile.close();
nameFile.close();



    cout << "Program finished. Do you want to continue? 1 - yes, 0 - no" << endl;
    cin >> answer;

} while(answer == 1);

return 0;
}
