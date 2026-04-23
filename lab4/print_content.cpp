#include <iostream>
#include <fstream>
using namespace std;

struct Person{
int key;
char name[31];
};



int main(){


ifstream file("main.bin", ios::binary);

if (!file){
    cout << "File 'main.bin' was not found!" << endl;
    return 1;
}

Person person;

while(file.read((char*)&person, sizeof(person))) {

cout << person.key << " " << person.name << endl;

}

file.close();
return 0;
}
